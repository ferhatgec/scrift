/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <stdio.h>

/* C Template */
char *C_HL_extensions[] = { ".c", ".h", NULL }; 
char *C_HL_keywords[] = {
  "switch", "if", "while", "#ifndef", "#define", "#endif", "#include" ,"for", "break", "continue", "return", "else",
  "struct", "union", "typedef", "static", "enum", "case",

  "[", "]", "<", ">", "{", "}", "(", ")", "#", ".", "->", "<-", "++", "+=", "-=", "--", "<<", ">>", "==", "!=", "||", "&&",

  "int|", "long|", "double|", "float|", "char|", "unsigned|", "signed|",
  "void|", NULL
};

/* C++ Template */
char *Cpp_HL_extensions[] = { ".cpp", ".hpp", ".cc", ".hh", NULL }; 
char *Cpp_HL_keywords[] = {
  "switch", "if", "while", "#ifndef", "#define", "#endif", "#include", "for", "break", "continue", "return", "else",
  "struct", "union", "typedef", "namespace", "static", "virtual", "try", "class", "enum", "case",
  
  "[", "]", "<", ">", "{", "}", "(", ")", "#", ".", "->", "<-", "++", "+=", "-=", "--", "<<", ">>", "==", "!=", "||", "&&",

  "int|", "long|", "double|", "auto|", "goto|", "float|", "volatile|" , "asm|", "string|", "char|", "unsigned|", "signed|",
  "void|", NULL
};

/* FlaScript Template */
char *FlaScript_HL_extensions[] = { ".fls", ".flsh", NULL }; 
char *FlaScript_HL_keywords[] = {
  "import", "if", "env", "EraseAllSubstring", "exec", "system", "executepp", "func", "ifdef", "endif}", "input", "var",
  "newline", "main()", "main", "random", "print", "[this]", "read", "defin", "put", "arch", "osname", "uptime", "username",

  "[", "]", "<", ">", "{", "}", "(", ")", "#", ".", "->", "<-",

  "int|", "int&|", "string&|", "get|", "float|", "volatile|" , "asm|", "string|", "colorized|", "rcolorized|", "signed|",
  "type|", NULL
};

/* Python Template */
char *Python_HL_extensions[] = { ".py", ".pyc", ".pyw", ".pyi", ".pyd", NULL }; 
char *Python_HL_keywords[] = {
  "and", "as", "assert", "break", "class", "continue", "def", "del", "elif", "else",
  "except", "False", "finally", "for", "from", "if", "in", "is", "lambda", "None", 
  "nonlocal", "not", "or", "pass", "raise", "return", "True", "try", "while", "with", "yield"
  "print", "repr", "eval", "list", "set", "chr", "ord", "hex", "oct",

  "[", "]", "<", ">", "{", "}", "(", ")", ".", "=",

  "int|", "long|", "float|", "complex|", "global|" , "import|", "str|", NULL
};

/* Bash Script Template */
char *Bash_HL_extensions[] = { ".sh", ".bash", NULL }; 
char *Bash_HL_keywords[] = {
  "if", "set", "function", "fi", "exec", "printf", "then", "else", "exit", "cd",
  "elif", "while", "case", "esac", "done", "return", "in", "source", "trap", "echo", 
  "break", "read", "for", "rm", "cat", "return", "sleep", "do", "shopt", "declare", "gcc", "-o", "-I", "$",

  "[", "]", "<", ">", "{", "}", "(", ")", "#", ".", "->", "<-", "++", "+=", "-=", "--", "<<", ">>", "==", "!=", "||", "&&",

  "local|", "readonly|", "sudo|", NULL
};

/* Lua Template */
char *Lua_HL_extensions[] = { ".lua", NULL }; 
char *Lua_HL_keywords[] = {
  "and", "break", "do", "else", "elseif", "end", "false", "for", "function", "if", "in",
  "nil", "not", "or", "repeat", "return", "then", "true", "until", "while", "print", "sqrt", "read", "sin",
  
  "[", "]", "<", ">", "{", "}", "(", ")", "#", ".", "..", "...", ",", ":", ";", "=", "<", ">", "==", "~=", ">=", "<=",
  "^", "%", "/", "*", "-", "+",

  "local|", NULL
};

#endif // LANGUAGE_H
