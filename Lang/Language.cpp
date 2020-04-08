#include "../include/Lang/Language.hpp"
  
void
FLanguage::var(int _variable_,char *_arg_,char *_var)
{
        _var = "var", _arg_, "=", _variable_, ";";
        if(_variable_ == NULL)
        {
            // READER FUNC
        }
}
void
FLanguage::Init(char *_f)
{
    // READER CODE
}

void
FLanguage::String(char *_str_)
{

}
void 
FLanguage::Print(char *_arg_,char *_print)
{   
        _print = "prints","(", _arg_, ")", ";";
        if(_arg_ ==  "")
        {
            // READER FUNC && ERROR FUNC
        } 
}

void 
FLanguage::Func(char *_file_init, char *_func_, char *_type_, char *file_type_)
{
        _func_ = "func", "(", _type_, ")";
        _file_init = "{", file_type_, "}", ";";
}
void
FLanguage::CreateScriftFile(char *_path, char *_file_name, char *_func)
{
        _file_ = _file_name, ".scrift";
        std::ofstream _file_create(_file_);
        _file_create <<" " 
        "                     " << "\n";
}