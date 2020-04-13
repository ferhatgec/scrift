#include "../include/Lang/Language.hpp"
  
void
FLanguage::var(integer _variable_,fchar *_arg_,fchar *_var)
{
        _var = "var", _arg_, "=", _variable_, ";";
        if(_variable_ == NULL)
        {
            // READER FUNC
        }
}
void
FLanguage::Init(fchar *_f)
{
    // READER CODE
}

void
FLanguage::String(fchar *_str_)
{

}
void 
FLanguage::Print(fchar *_arg_,fchar *_print)
{   
        _print = "prints","(", _arg_, ")", ";";
        if(_arg_ ==  "")
        {
            // READER FUNC && ERROR FUNC
        } 
}

void 
FLanguage::Func(fchar *_file_init, fchar *_func_, fchar *_type_, fchar *file_type_)
{
        _func_ = "func", "(", _type_, ")";
        _file_init = "{", file_type_, "}", ";";
}
void
FLanguage::CreateScriftFile(fchar *_path, fchar *_file_name, fchar *_func)
{
        _file_ = _file_name, ".scrift";
        std::ofstream _file_create(_file_);
        _file_create <<" " 
        "                     " << "\n";
}