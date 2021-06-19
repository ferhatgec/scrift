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
    void LangTemplate(const std::string &file);

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
        return "main() -> main {\nprint(string) -> \"Hello FlaScript!\"\n} main;";
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

    std::string RubyTemplate() {
        return "#!/usr/bin/env ruby\nputs \"Hello, Ruby!\"\n";
    }

    std::string BashTemplate() {
        return "#!/bin/bash\necho \"Hello Bash!\"";
    }

    std::string CSharpTemplate() {
        return "using System;\n\nclass Program\n{\nstatic void Main(string[] args)\n{\nConsole.WriteLine(\"Hello, CSharp!\");\n}\n}";
    }

    std::string FreeBrainTemplate() {
        return "!->:>_^>~++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++<^_<:\n!->:>_^>~+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++<^_<:\n!->:>_^>~++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++<^_<:\n!->:>_^>~++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++<^_<:\n!->:>_^>~+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++<^_<:\n!->:>_^>~++++++++++++++++++++++++++++++++++++++++++++<^_<:\n!->:>_^>~++++++++++++++++++++++++++++++++<^_<:\n!->:>_^>~++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++<^_<:\n!->:>_^>~++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++<^_<:\n!->:>_^>~+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++<^_<:\n!->:>_^>~+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++<^_<:\n!->:>_^>~++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++<^_<:\n!->:>_^>~++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++<^_<:\n!->:>_^>~+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++<^_<:\n!->:>_^>~+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++<^_<:\n!->:>_^>~++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++<^_<:\n!->:>_^>~+++++++++++++++++++++++++++++++++<^_<:\n[!->:>_^> ? <^_<:] ?* (~++++++++++++++++++++++++++++++++++++++++++++++++++) *? !->:>_^>(~++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++)<*>(~++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++)<^_<:";
    }

    std::string BrainfuckTemplate() {
        return "-[------->+<]>-.-[->+++++<]>++.+++++++..+++.[->+++++<]>+.------------.+[->++<]>.---[----->+<]>-.+++[->+++\n<]>++.++++++++.+++++.--------.-[--->+<]>--.+[->+++<]>+.++++++++.+[++>---<]>-.";
    }

    std::string DLangTemplate() {
        return "import std.stdio;\n\nvoid main()\n{\n	 writefln(\"Hello, D!\");\n}";
    }

    std::string OdinTemplate() {
        return "package main\n\nimport \"core:fmt\"\nmain :: proc() {\nfmt.println(\"Hello, Odin!\");\n}\n";
    }

    std::string FishTemplate() {
        return "#!/usr/bin/env fish\necho \"Hello, Fish!\"\n";
    }

    std::string WrenTemplate() {
        return "IO.print(\"Hello, Wren!\")\n";
    }

    std::string HolyCTemplate() {
        return "\"Rest in peace, Terry Davis.\";\n";
    }

    std::string ElixirTemplate() {
        return "#!/usr/bin/env elixir\nIO.puts \"Hello World\"\n";
    }
};

#endif // LINKER_HPP
