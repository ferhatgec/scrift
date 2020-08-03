/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pwd.h>

#include <src/Scrift.hpp>
#include <src/Syntax/RunFunction.hpp>
#include <src/Syntax/Language.hpp>
#include <src/Syntax/CommandFunc.h>

// Libraries
#include <StringTools.h>
#include <Colorized.hpp>

#define MAXCOM 1000
#define MAXLIST 100

char inputString[1000], *parsedArgs[100];
char* parsedArgsPiped[MAXLIST];
int execFlag = 0;

std::string directory;

FRunFunction::FRunFunction() { }


FRunFunction::~FRunFunction() { }

int ParsePipe(char* str, char** strpiped) {
    int i;
    for (i = 0; i < 2; i++) {
        strpiped[i] = strsep(&str, "|");
        if (strpiped[i] == NULL)
            break;
    }

    if (strpiped[1] == NULL)
        return 0; // returns zero if no pipe is found.
    else {
        return 1;
    }
}

void ParseSpace(char* str, char** parsed) {
    int i;

    for (i = 0; i < MAXLIST; i++) {
        parsed[i] = strsep(&str, " ");

        if (parsed[i] == NULL)
            break;
        if (strlen(parsed[i]) == 0)
            i--;
    }
}

int ProcessString(char* str, char** parsed, char** parsedpipe) {

    char* strpiped[2];
    int piped = 0;

    piped = ParsePipe(str, strpiped);

    if (piped) {
        ParseSpace(strpiped[0], parsed);
        ParseSpace(strpiped[1], parsedpipe);

    } else {

        ParseSpace(str, parsed);
    }

    return 1 + piped;
}

void ExecuteArgs(char** parsed) {
    // Forking a child
    pid_t pid = fork();

    if (pid == -1) {
   	colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), "scrift : Failed forking child..\n");
        return;
    } else if (pid == 0) {
        if (execvp(parsed[0], parsed) < 0) {
            colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), "scrift : ");
            colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), parsed[0]);
            colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), " : command not found..\n");
        }
        exit(0);
    } else {
        // waiting for child to terminate
        wait(NULL);
        return;
    }
}

void ExecuteArgsPiped(char** parsed, char** parsedpipe) {
    // 0 is read end, 1 is write end
    int pipefd[2];
    pid_t p1, p2;

    if (pipe(pipefd) < 0) {
     	colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), "scrift : Pipe could not be initialized\n");
        return;
    }
    p1 = fork();
    if (p1 < 0) {
        colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), "scrift : Could not fork.\n");
        return;
    }

    if (p1 == 0) {
        // Child 1 executing..
        // It only needs to write at the write end
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        if (execvp(parsed[0], parsed) < 0) {
            colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), "scrift : ");
		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), parsed[0]);
		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), " : first command not found..\n");
            exit(0);
        }
    } else {
        // Parent executing
        p2 = fork();

        if (p2 < 0) {
            colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), "scrift : Could not fork.\n");
            return;
        }

        // Child 2 executing..
        // It only needs to read at the read end
        if (p2 == 0) {
            close(pipefd[1]);
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);
            if (execvp(parsedpipe[0], parsedpipe) < 0) {
		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), "scrift : ");
		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), parsed[0]);
		colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED).c_str(), " : second command not found..\n");
                exit(0);
            }
        } else {
            // parent executing, waiting for two children
            wait(NULL);
            wait(NULL);
        }
    }
}

void
FRunFunction::RunFunction(std::string name) {
    strcpy(inputString, stringtools::EraseAllSubString(name, "\n").c_str());
    execFlag = ProcessString(inputString,
        parsedArgs, parsedArgsPiped);
    if (strstr(name.c_str(), "|")) {
          ExecuteArgsPiped(parsedArgs, parsedArgsPiped);
    } else {
          ExecuteArgs(parsedArgs);
    }
}


void
FRunFunction::RunBinFunction(std::string name)
{
    directory = "/bin/";
    system(directory.c_str());
}

void
FRunFunction::RunGMakeFunction(std::string name)
{
    FCommand *command = new FCommand();
    directory = "/usr/bin" + name;
    directory.append(command->_file_path_cd_function);
    system(directory.c_str());
}

// For Fegeya Fusion and *nix
void
FRunFunction::RunJamFunction(std::string name)
{
    directory = "/usr/local/bin/jam " + name; // read-only!
    system(directory.c_str()); // jam + function
}

// For Fegeya Fusion and *nix
