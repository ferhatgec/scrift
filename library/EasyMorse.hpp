/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef EASY_MORSE_HPP
#define EASY_MORSE_HPP

#include <iostream>
#include <string>


class EasyMorse {
public:
    static std::string charToMorse(char16_t letter) {
        switch (letter) {
            case 'a':
            case 'A':
                return ".-";
                break;
            case 'b':
            case 'B':
                return "-...";
                break;
            case 'c':
            case 'C':
                return "-.-.";
                break;
            case 'd':
            case 'D':
                return "-..";
                break;
            case 'e':
            case 'E':
                return ".";
                break;
            case 'f':
            case 'F':
                return "..-.";
                break;
            case 'g':
            case 'G':
                return "--.";
                break;
            case 'h':
            case 'H':
                return "....";
                break;
            case 'i':
            case 'I':
                return "..";
                break;
            case 'j':
            case 'J':
                return ".---";
                break;
            case 'k':
            case 'K':
                return "-.-";
                break;
            case 'l':
            case 'L':
                return ".-..";
                break;
            case 'm':
            case 'M':
                return "--";
                break;
            case 'n':
            case 'N':
                return "-.";
                break;
            case 'o':
            case 'O':
                return "---";
                break;
            case 'p':
            case 'P':
                return ".--.";
                break;
            case 'q':
            case 'Q':
                return "--.-";
                break;
            case 'r':
            case 'R':
                return ".-.";
                break;
            case 's':
            case 'S':
                return "...";
                break;
            case 't':
            case 'T':
                return "-";
                break;
            case 'u':
            case 'U':
                return "..-";
                break;
            case 'v':
            case 'V':
                return "...-";
                break;
            case 'w':
            case 'W':
                return ".--";
                break;
            case 'x':
            case 'X':
                return "-..-";
                break;
            case 'y':
            case 'Y':
                return "-.--";
                break;
            case 'z':
            case 'Z':
                return "--..";
                break;
            case L'ą':
            case L'Ą':
                return ".-.-";
                break;
            case L'ć':
            case L'Ć':
                return "-.-..";
                break;
            case L'ę':
            case L'Ę':
                return "..-..";
                break;
            case L'ł':
            case L'Ł':
                return ".-..-";
                break;
            case L'ń':
            case L'Ń':
                return "--.--";
                break;
            case L'ó':
            case L'Ó':
                return "---.";
                break;
            case L'ś':
            case L'Ś':
                return "...-...";
                break;
            case L'ż':
            case L'Ż':
                return "--..-.";
                break;
            case L'ź':
            case L'Ź':
                return "--..-";
                break;
            default:
                return " ";
                break;
        }
    }

    static std::string morseToChar(std::string morse) {
        if (morse == ".-") { return "a"; }
        else if (morse == "-...") { return "b"; }
        else if (morse == "-.-.") { return "c"; }
        else if (morse == "-..") { return "d"; }
        else if (morse == ".") { return "e"; }
        else if (morse == "..-.") { return "f"; }
        else if (morse == "--.") { return "g"; }
        else if (morse == "....") { return "h"; }
        else if (morse == "..") { return "i"; }
        else if (morse == ".---") { return "j"; }
        else if (morse == "-.-") { return "k"; }
        else if (morse == ".-..") { return "l"; }
        else if (morse == "--") { return "m"; }
        else if (morse == "-.") { return "n"; }
        else if (morse == "---") { return "o"; }
        else if (morse == ".--.") { return "p"; }
        else if (morse == "--.-") { return "q"; }
        else if (morse == ".-.") { return "r"; }
        else if (morse == "...") { return "s"; }
        else if (morse == "-") { return "t"; }
        else if (morse == "..-") { return "u"; }
        else if (morse == "...-") { return "v"; }
        else if (morse == ".--") { return "w"; }
        else if (morse == "-..-") { return "x"; }
        else if (morse == "-.--") { return "y"; }
        else if (morse == "--..") { return "z"; }
        else if (morse == ".-.-") { return "ą"; }
        else if (morse == "-.-..") { return "ć"; }
        else if (morse == "..-..") { return "ę"; }
        else if (morse == ".-..-") { return "ł"; }
        else if (morse == "--.--") { return "ń"; }
        else if (morse == "---.") { return "ó"; }
        else if (morse == "...-...") { return "ś"; }
        else if (morse == "--..-.") { return "ż"; }
        else if (morse == "--..-") { return "ź"; }
        else { return " "; }
    }

    static void MainMorse() {
        std::cout << "EasyMorse - Morse Code Converter" << std::endl;
        char key;
        bool loop = true;
        int len;
        while (loop) {
            std::string input;
            bool toMorse = true;
            std::string output = "";
            int node = 0;
            std::string sub;
            std::cout << "Type a word or morse code(using - and .): " << std::endl;
            std::getline(std::cin, input);
            len = input.length();
            if (len == 0) {
                return;
            } else {
                if (input[1] == '.' || input[1] == '-') {
                    toMorse = false;
                } else {
                    toMorse = true;
                }
                if (toMorse) {
                    for (int i = 0; i < len; i++) {
                        if (i != 0) {
                            output += " ";
                        }
                        output = output + charToMorse(input[i]);
                    }
                } else {
                    for (int i = 0; i <= len; i++) {
                        if (input[i] == ' ') {
                            sub = input.substr(node, i - node);
                            output += morseToChar(sub);
                            node = i + 1;
                        }
                        if (i == len - 1) {
                            sub = input.substr(node, i + 1 - node);
                            output += morseToChar(sub);
                            node = i + 1;
                        }
                    }
                }
                std::cout << output << std::endl;
                std::cout << "Press q to quit." << std::endl;
                std::cin >> key;
                if (key == 'q') {
                    return;
                } else {

                }
                std::cin.clear();
                std::cin.ignore();
                std::cout << std::endl;
            }
        }
    }
};

#endif // EASY_MORSE_HPP
