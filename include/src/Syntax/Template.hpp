/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include "../synflang.hpp"
#include "../Scrift.hpp"

class FTemplate {
public:
	void LangTemplate();
	
	std::string CPlusPlusTemplate() {
		return "#include <iostream>\n\nint main(int argc, char** argv) {\nstd::cout << \"Hello C++!\";\nreturn 0;\n}";
	} 
	
	std::string CTemplate() {
		return "#include <stdio.h>\n\nint main(int argc, char** argv) {\nprintf(\"Hello C\");\nreturn 0;\n}";
	} 
	
	std::string GoTemplate() {
		return "package main\nimport \"fmt\"func main() {\nfmt.Print(\"Hello Go!\\n\")\n}";
	}
	
	std::string FlaScriptTemplate() {
		return "main() -> main {\nprint(string) -> \"Hello FlaScript!\"\n}";
	}
	
	std::string PythonTemplate() {
		return "print(\"Hello Python!\")";
	}
	
	std::string HaskellTemplate() {
		return "putStrLn \"Hello, Haskell!\"";
	}
	
	std::string DartTemplate() {
		return "main() {\nprint('Hello Dart!');\n}";
	}
	
	std::string LuaTemplate() {
		return "print(\"Hello Lua!\")";
	}
	
	std::string RustTemplate() {
		return "fn main() {\nprintln!(\"Hello Rust!\");\n}";
	}
};

#endif // LINKER_HPP
