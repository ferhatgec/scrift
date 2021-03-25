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

#include <src/Syntax/RunFunction.hpp>
// Libraries
#include <StringTools.h>
#include <Colorized.hpp>

#define MAXLIST 100

/*
* TODO: Clean C-like variable types, code blocks & replace with latest version of ExecutePlusPlus.
*/

char inputString[1000], *parsedArgs[100];
char* parsedArgsPiped[MAXLIST];

std::string directory;

FRunFunction::FRunFunction() = default;


FRunFunction::~FRunFunction() = default;

int ParsePipe(char* str, char** strpiped) {
    int i;
    for (i = 0; i < 2; i++) {
        strpiped[i] = strsep(&str, "|");
        if (strpiped[i] == nullptr)
            break;
    }

    if (strpiped[1] == nullptr)
        return 0; // returns zero if no pipe is found.
    else {
        return 1;
    }
}

void ParseSpace(char* str, char** parsed) {
    int i;

    for (i = 0; i < MAXLIST; i++) {
        parsed[i] = strsep(&str, " ");

        if (parsed[i] == nullptr)
            break;
        if (strlen(parsed[i]) == 0)
            i--;
    }
}

int ProcessString(char* str, char** parsed, char** parsedpipe) {

    char* strpiped[2];
    int piped;

    piped = ParsePipe(str, strpiped);

    if (piped) {
        ParseSpace(strpiped[0], parsed);
        ParseSpace(strpiped[1], parsedpipe);

    } else
        ParseSpace(str, parsed);

    return 1 + piped;
}

void ExecuteArgs(char** parsed) {
    // Forking a child
    pid_t pid = fork();

    if (pid == -1) {
   	    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED), "scrift : Failed forking child..\n");
        return;
    } else if (pid == 0) {
        if (execvp(parsed[0], parsed) < 0) {
            colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED), "scrift : ");
            colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED), parsed[0]);
            colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED), " : command not found..\n");
        }
        exit(0);
    } else {
        // waiting for child to terminate
        wait(nullptr);
        return;
    }
}

void ExecuteArgsPiped(char** parsed, char** parsedpipe) {
    // 0 is read end, 1 is write end
    int pipefd[2];
    pid_t p1, p2;

    if (pipe(pipefd) < 0) {
     	colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED), "scrift : Pipe could not be initialized\n");
        return;
    }
    p1 = fork();
    if (p1 < 0) {
        colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED), "scrift : Could not fork.\n");
        return;
    }

    if (p1 == 0) {
        // Child 1 executing..
        // It only needs to write at the write end
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        if (execvp(parsed[0], parsed) < 0) {
            colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED), "scrift : ");
		    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED), parsed[0]);
		    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED), " : first command not found..\n");
            exit(0);
        }
    } else {
        // Parent executing
        p2 = fork();

        if (p2 < 0) {
            colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED), "scrift : Could not fork.\n");
            return;
        }

        // Child 2 executing..
        // It only needs to read at the read end
        if (p2 == 0) {
            close(pipefd[1]);
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);
            if (execvp(parsedpipe[0], parsedpipe) < 0) {
		        colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED), "scrift : ");
		        colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED), parsed[0]);
		        colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_RED), " : second command not found..\n");
                exit(0);
            }
        } else {
            // parent executing, waiting for two children
            wait(nullptr);
            wait(nullptr);
        }
    }
}

void
FRunFunction::RunFunction(std::string command) {
    strcpy(inputString, stringtools::EraseAllSubString(command, "\n").c_str());

    ProcessString(inputString,
                  parsedArgs, parsedArgsPiped);

    if (command.find('|') == 0) {
        ExecuteArgsPiped(parsedArgs, parsedArgsPiped);
    } else {
        ExecuteArgs(parsedArgs);
    }
}
