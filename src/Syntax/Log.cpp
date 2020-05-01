#include <Syntax/Log.hpp> // Get Log Header
#include <Syntax/FileFunction.hpp> // For  create file and folder 
#include <main.h>
#include <Syntax/CommandFunc.h>
#include <sys/stat.h>
// #include <Syntax/PrintErrorFunction.hpp>

FCommand *commandlog = new FCommand();

FeLog::FeLog()
{

}

FeLog::~FeLog()
{
    delete commandlog;
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
    file << "Test\n";
    file.close();
}   

func 
FeLog::InitFile() 
{

}

boolean
FeLog::IsExist()
{


}
