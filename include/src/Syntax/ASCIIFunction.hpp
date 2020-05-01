#ifndef ASCII_FUNCTION_HPP
#define ASCII_FUNCTION_HPP

#include "../synflang.hpp"
#include "../main.h"
#include "FileFunction.hpp"

using namespace FileFunction;

typedef struct {
public:
    FCommand *fegeyacommand = new FCommand();
    FCreateFileFunction *createfilefunc = new FCreateFileFunction();
    FReadFileFunction *readfilefunc = new FReadFileFunction();
    inline boolean InitFile()
    {
         struct stat buffer;
         std::string path;
         path.append(fegeyacommand->_file_path_cd_function);
         path.append("/");
         path.append(".scrift_ascii");   
         return (stat (path.c_str(), &buffer) == 0); 
    }

    virtual void GenerateString() 
    {
        if(InitFile() == true)
        {
            printlnf("File exists, nice!\n");
        }
        else {
            createfilefunc->CreateASCIIFileFunction();
        }
    }  

    virtual void ReadFile() 
    {
        readfilefunc->ReadASCIIFunction();
    }
    virtual void Allofthem() 
    {
        GenerateString();
        ReadFile();
        //delete createfilefunc, readfilefunc;
    }

} asciifunction;








#endif // ASCII_FUNCTION_HPP