#include <Syntax/Log.hpp> // Get Log Header
#include <Syntax/FileFunction.hpp> // For  create file and folder 
#include <main.h>
#include <Syntax/CommandFunc.h>
#include <sys/stat.h>
// #include <Syntax/PrintErrorFunction.hpp>

FCommand *commandlog = new FCommand();
std::string filepath_with_path;
FeLog::FeLog()
{

}

FeLog::~FeLog()
{
    delete commandlog;
}
func
FeLog::WriteLog(fstr filepathw)
{
    std::string filepath_with_path;
    filepath_with_path.append(commandlog->_file_path_cd_function);
    filepath_with_path.append("/");
    filepath_with_path.append(".scrift_log");
    std::ofstream file;
    file.open(filepath_with_path, std::ios::out | std::ios::app);
    if(file.fail()) {
        printlnf("ERROR\n");
    }

    file.exceptions(file.exceptions() | std::ios::failbit | std::ifstream::badbit);

    file << filepathw << std::endl;
    printlnf("Done\n");
}




func
FeLog::CreateFile()
{   
    std::string path;
    path.append(commandlog->_file_path_cd_function);
    path.append(slash);
    path.append(".scrift_log");
    std::ofstream file;
    file.open(path, std::ios::app);
    file << "FeLog Started.\n";
    file.close();
}   

func 
FeLog::InitFile() 
{

}

boolean
FeLog::IsExist()
{
    struct stat buffer;
    return (stat(filepath_with_path.c_str(), &buffer) == 0);
}


func 
FeLog::AllofThem()
{
    if(IsExist() != true) {
    CreateFile();
    }
    else {
        printlnf("FeLog file is exists\n");
        WriteLog("Test\n");
    }
}