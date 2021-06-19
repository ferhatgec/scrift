/*# MIT License
#
# Copyright (c) 2020-2021 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#ifndef STRING_TOOLS_H
#define STRING_TOOLS_H

#include <iostream>

#ifdef _MSC_VER
#include <string>
#else

#include <cstring>

#endif

namespace stringtools {
    static std::string EraseAllSubString(std::string &mainString, const std::string &erase) {
        size_t pos = std::string::npos;
        while ((pos = mainString.find(erase)) != std::string::npos) {
            mainString.erase(pos, erase.length());
        }
        return mainString;
    }

    static void replaceAll(std::string &str, const std::string &from, const std::string &to) {
        if (from.empty())
            return;
        size_t start_pos = 0;
        while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
        }
    }

    static bool replace(std::string &str, const std::string &from, const std::string &to) {
        size_t start_pos = str.find(from);

        if (start_pos == std::string::npos)
            return false;

        str.replace(start_pos, from.length(), to);
        return true;
    }

    static int IntConverter(const char *s) {
        int sum = 0;
        char ch;
        char sign = *s;
        if (*s == '-' || *s == '+') s++;
        while ((ch = *s++) >= '0' && ch <= '9') {
            sum = sum * 10 - (ch - '0');
        }
        if (sign != '-') {
            sum = -sum;
        }
        return sum;
    }

    static int IntConverterWithWhitespace(char *s) {
        int sum = 0;
        char ch;
        std::string conv(s);
        s = const_cast<char *>(EraseAllSubString(conv, " ").c_str());
        char sign = *s;
        if (*s == '-' || *s == '+') s++;
        while ((ch = *s++) >= '0' && ch <= '9') {
            sum = sum * 10 - (ch - '0');
        }
        if (sign != '-') {
            sum = -sum;
        }
        return sum;
    }

    static int Count(std::string s, char ch) {
        int count = 0;

        for (int i = 0; i < s.size(); i++)
            if (s[i] == ch) count++;

        return count;
    }

    static int Counter(const char *str, int type) { // 1 = Vowel, 2 = Consonants, 3 = Numbers, 4 = Special characters
        int v = 0, c = 0, n = 0, s = 0;
        for (int i = 0; str[i] != '\0'; ++i) {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
                str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
                ++v;
            else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
                ++c;
            else if (str[i] >= '0' && str[i] <= '9')
                ++n;
            else
                ++s;
        }

        if (type == 1)
            return v;
        else if (type == 2)
            return c;
        else if (type == 3)
            return n;
        else if (type == 4)
            return s;
        else
            return v;

        return 0;
    }

    /* return as string */
    static std::string GetBetweenString(std::string oStr, std::string sStr1, std::string sStr2) {
        int start = oStr.find(sStr1);
        if (start >= 0) {
            std::string tstr = oStr.substr(start + sStr1.length());
            int stop = tstr.find(sStr2);
            if (stop > 1)
                return oStr.substr(start + sStr1.length(), stop);
            else
                return "error";
        } else
            return "error";
    }

    static void GetBtwString(std::string oStr, std::string sStr1, std::string sStr2, std::string &rStr) {
        int start = oStr.find(sStr1);
        if (start >= 0) {
            std::string tstr = oStr.substr(start + sStr1.length());
            int stop = tstr.find(sStr2);
            if (stop > 1)
                rStr = oStr.substr(start + sStr1.length(), stop);
            else
                rStr = "error";
        } else
            rStr = "error";
    }

    /* get first between string from 0.... position. */
    static std::string Between(const std::string &s, const std::string &start_delim, const std::string &stop_delim) {
        unsigned first_delim_pos = s.find(start_delim);
        unsigned end_pos_of_first_delim = first_delim_pos + start_delim.length();
        unsigned last_delim_pos = s.find_first_of(stop_delim, end_pos_of_first_delim);

        return s.substr(end_pos_of_first_delim,
                        last_delim_pos - end_pos_of_first_delim);
    }

    static std::string Add(std::string a, std::string b) {
        std::string temp = "";

        int carry = 0;

        while (a.length() < b.length()) {
            a = "0" + a;
        }

        while (b.length() < a.length()) {
            b = "0" + b;
        }

        for (int i = a.length() - 1; i >= 0; i--) {
            char val = static_cast<char>(((a[i] - 48) + (b[i] - 48)) + 48 + carry);
            if (val > 57) {
                carry = 1;
                val -= 10;
            } else {
                carry = 0;
            }
            temp = val + temp;
        }

        if (carry == 1) {
            temp = "1" + temp;
        }

        while (temp[0] == '0' && temp.length() > 1) {
            temp = temp.substr(1);
        }

        return temp;
    }

    static int Compare(const char *str_1, const char *str_2) {
        const unsigned char *unsigned_str_1 = (const unsigned char *) str_1;
        const unsigned char *unsigned_str_2 = (const unsigned char *) str_2;

        while (*unsigned_str_1 == *unsigned_str_2 &&
               *unsigned_str_1 != '\0') {

            unsigned_str_1++;
            unsigned_str_2++;
        }

        return (*unsigned_str_1 > *unsigned_str_2) - (*unsigned_str_1 < *unsigned_str_2);
    }

    static inline std::string &ltrim(std::string &s, const char *t = " \t\n\r\f\v") {
        s.erase(0, s.find_first_not_of(t));
        return s;
    }

    static inline std::string &rtrim(std::string &s, const char *t = " \t\n\r\f\v") {
        s.erase(s.find_last_not_of(t) + 1);
        return s;
    }

    static inline std::string &trim(std::string &s, const char *t = " \t\n\r\f\v") {
        rtrim(s);
        ltrim(s);

        return s;
    }

    static bool Find(std::string &data, std::string substring) {
        size_t check = data.find(substring);

        if (check != std::string::npos) return true; /* Found */
        else
            return false; /* Not found */

        return false;
    }

    /* try kmp algorithm for pattern searching to replace within it */
    static int CountSub(const std::string &str, const std::string &sub) {
        if (sub.length() == 0) return 0;

        int count = 0;

        for (size_t offset = str.find(sub); offset != std::string::npos; offset = str.find(sub, offset + sub.length()))
            ++count;

        return count;
    }

    static std::string EraseSub(std::string &mainString, const std::string &erase) {
        size_t pos = std::string::npos;

        if ((pos = mainString.find(erase)) != std::string::npos)
            mainString.erase(pos, erase.length());

        return mainString;
    }

    static std::string GetFirstArg(std::string str) {
        std::string word = "";
        if (!strstr(str.c_str(), " ")) return str;

        for (auto x : str) {
            if (x == ' ') {
                break;
            } else {
                word = word + x;
            }
        }

        return word;
    }
}

#endif // STRING_TOOLS_H