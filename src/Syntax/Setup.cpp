/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <filesystem>

#include <src/Scrift.hpp>
#include <src/Syntax/Setup.hpp>

// Libraries
#include <FileSystemPlusPlus.h>
#include <ExecutePlusPlus.hpp>
#include <Colorized.hpp>

/*
        TODO: Add Stage2, Stage3 for install instruction.
*/

/*
        Path() for Settings
*/

/*constexpr*/ std::string Path() {
    std::string settings_path(getenv("HOME"));
    settings_path.append("/.scrift_settings");

    return settings_path;
}

/*
        Welcome message, checking etc.
*/

void
FSetup::Stage1() {
    /* Setting variables */
    std::string pass, felog_clean_line, welcome_emoji, bg_color,
            ascii_art_color, scrift_theme, input_customize,
            welcome_message, local_git_branch, scrift_setup, auto_clear, sign_1, sign_2;

    /*  Welcome
        FHelpFunction welcome;
        welcome.Welcome();
    */

    colorized::PrintWhReset(colorized::Colorize(BOLD, MAGENTA), "Welcome!\n");

    if (fsplusplus::IsExistFile("/bin/scrift"))
        colorized::PrintWith(colorized::Colorize(BOLD, BLUE),
                             "Thank you for choosing Fegeya Scrift!\n");


    /* Information */
    colorized::PrintWith(colorized::Colorize(BOLD, YELLOW), "Fegeya Scrift Configuration & Setup\n");
    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA), "Press ");
    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_BLUE), "'n' ");
    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA), "for pass any question\n");

    colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_MAGENTA),
                         "Do you want to pass Configuration? (y | n)\n -> ");

    BOLD_LIGHT_WHITE_COLOR
    std::cin >> pass;
    if (pass == "n" || pass == "NO" || pass == "no" || pass == "No" || pass == "no_thanks") {
        /* FeLog Cleaner */
        colorized::PrintWith(colorized::Colorize(BOLD, CYAN),
                             "FeLog Cleaner [50, 100, 300] (Default: Once every 100 lines)\n -> ");

        BOLD_LIGHT_WHITE_COLOR
        std::cin >> felog_clean_line;

        /* Pass */
        if (felog_clean_line == "n" || felog_clean_line == "N") felog_clean_line = "100";

        /* Welcome Emoji */
        colorized::PrintWith(colorized::Colorize(BOLD, CYAN),
                             "Welcome Emoji [:bike:, :question:, :bug: etc.] (Default :thinking_face:)\n -> ");

        BOLD_LIGHT_WHITE_COLOR
        std::cin >> welcome_emoji;

        /* Pass */
        if (welcome_emoji == "n" || welcome_emoji == "N") welcome_emoji = ":thinking_face:";

        /* Background Color */
        colorized::PrintWith(colorized::Colorize(BOLD, CYAN),
                             "Background Color [0,1,2,3,4,5,6,7] (Default : 12)\n -> ");

        BOLD_LIGHT_WHITE_COLOR
        std::cin >> bg_color;

        /* Pass */
        if (bg_color == "n" || bg_color == "N") bg_color = "12";

        /* ASCII Art Color */
        colorized::PrintWith(colorized::Colorize(BOLD, CYAN),
                             "ASCII Art Color [colornumber, no_thanks, random] (Default: random)\n -> ");

        BOLD_LIGHT_WHITE_COLOR
        std::cin >> ascii_art_color;

        /* Pass */
        if (ascii_art_color == "n" || ascii_art_color == "N") ascii_art_color = "random";

        /* Scrift Theme */
        colorized::PrintWith(colorized::Colorize(BOLD, CYAN),
                             "Scrift Theme [default, classic, halloween 🎃]\n -> ");

        BOLD_LIGHT_WHITE_COLOR
        std::cin >> scrift_theme;

        /* Pass */
        if (scrift_theme == "n" || scrift_theme == "N") scrift_theme = "default";

        if (scrift_theme == "🎃") scrift_theme = "halloween";

        /* Input Customization */
        colorized::PrintWith(colorized::Colorize(BOLD, CYAN),
                             "Input Customization [▶, #>, $# etc.] (Default: ▶)\n -> ");

        BOLD_LIGHT_WHITE_COLOR
        std::cin >> input_customize;

        /* Pass */
        if (input_customize == "n" || input_customize == "N") input_customize = "▶ ";

        /* Welcome Message */
        colorized::PrintWith(colorized::Colorize(BOLD, CYAN),
                             "Welcome Message [yes, no_thanks] (Default: yes)\n -> ");

        BOLD_LIGHT_WHITE_COLOR
        std::cin >> welcome_message;

        /* Pass */
        if (welcome_message == "n" || welcome_message == "N") welcome_message = "yes";

        /* Local Git Branch */
        colorized::PrintWith(colorized::Colorize(BOLD, CYAN),
                             "Local Git Branch Detection [yes, no_thanks] (Default: yes)\n -> ");

        BOLD_LIGHT_WHITE_COLOR
        std::cin >> local_git_branch;

        /* Pass */
        if (local_git_branch == "n" || local_git_branch == "N") local_git_branch = "yes";

        /* Local Git Branch */
        colorized::PrintWith(colorized::Colorize(BOLD, CYAN),
                             "Auto terminal buffer clear (line) [10, 20, no_thanks] (Default: 40)\n -> ");

        BOLD_LIGHT_WHITE_COLOR
        std::cin >> auto_clear;

        /* Auto buffer clear */
        if (auto_clear == "n" || auto_clear == "N") auto_clear = "40";

        /* Sign_1 */
        colorized::PrintWith(colorized::Colorize(BOLD, CYAN),
                             "Sign 1 (ferhatgec[@]fegeya) [@, ~, #, &]\n -> ");

        BOLD_LIGHT_WHITE_COLOR
        std::cin >> sign_1;

        if (sign_1 == "n" || sign_1 == "N") sign_1 = "@";

        /* Sign 2 */
        colorized::PrintWith(colorized::Colorize(BOLD, CYAN),
                             "Sign 2 (@fegeya[:~]/home/) [:~, ~>, +_]\n -> ");

        BOLD_LIGHT_WHITE_COLOR
        std::cin >> sign_2;

        if (sign_2 == "n" || sign_2 == "N") sign_2 = ":~";

        /* Check Is Fpm available */

        if (!fsplusplus::IsExistFile("/bin/fpm")) {
            colorized::PrintWith(colorized::Colorize(BOLD, CYAN),
                                 "Do you want to install fpm (Fegeya Package Manager) from source? (Y/n) \n -> ");

            char ch;

            BOLD_LIGHT_WHITE_COLOR
            std::cin >> ch;

            if (ch == 'n' || ch == 'N') std::cout << "Ok!\n";
            else {
                const std::string old_path = fsplusplus::GetCurrentWorkingDir();

                ExecutePlusPlus exec;

                /* Clone repository */
                exec.RunFunction("git clone " + STR(FPM_REPOSITORY) + " " + STR(getenv("HOME")) + "/scrift_fpm");

                /* Change directory with $HOME/scrift_fpm */
                chdir((STR(getenv("HOME")) + "/scrift_fpm").c_str());

                /* Install Fpm */
                exec.RunFunction("sudo sh install.sh");

                /* Return old path */
                chdir(old_path.c_str());

                /* Cleaning */
                std::filesystem::remove_all(STR(getenv("HOME")) + "/scrift_fpm/");

                if (fsplusplus::IsExistFile("/bin/fpm")) {
                    std::cout << "Fpm installed!\n";
                }
            }
        }

        /* Tip */
        colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_GREEN),
                             "Tip: You can change Scrift's prompt (.scrift_settings)\n");

        /* Example */
        colorized::PrintWith(colorized::Colorize(BOLD, LIGHT_GREEN),
                             "Example: @definition@[color]\n");

        colorized::PrintWith(colorized::Colorize(BOLD, RED),
                             "Erasing old settings data.\n");
    } else {
        felog_clean_line = "100";
        welcome_emoji = ":thinking_face:";
        bg_color = "12";
        ascii_art_color = "random";
        scrift_theme = "default";
        input_customize = "$#";
        welcome_message = "yes";
        local_git_branch = "yes";
        auto_clear = "40";
        sign_1 = "@";
        sign_2 = ":~";
    }

    std::ofstream erase_settings;
    erase_settings.open(Path().c_str(), std::ofstream::out | std::ofstream::trunc);
    erase_settings.close();
    erase_settings.open(Path().c_str(), std::ios_base::app); // append instead of overwrite
    erase_settings << "[CUSTOMIZE]\nfelog_cleaner " + felog_clean_line + "\n";
    erase_settings << "welcome_emoji " + welcome_emoji + "\n";
    erase_settings << "bg_color " + bg_color + "\n";
    erase_settings << "ascii_art_color " + ascii_art_color + "\n";
    erase_settings << "scrift_theme " + scrift_theme + "\n";
    erase_settings << "input_customize " + input_customize + " \n";
    erase_settings << "welcome_message " + welcome_message + "\n";
    erase_settings << "local_git_branch " + local_git_branch + "\n";
    erase_settings << "scrift_setup no_thanks\n";
    erase_settings << "auto_clear " + auto_clear + "\n";
    erase_settings << "date_info yes\n";
    erase_settings << "sign_1 " + sign_1 + "\n";
    erase_settings << "sign_2 " + sign_2 + "\n";
    erase_settings
            << "\n[PROMPT] @username@[1;34m] @sign_1@[1;36m] @hostname@[1;35m] @sign_2@[1;36m] @directory@[1;33m] @whitespace@[1;36m] @branch@[1;36m] @clock@[1;93m] @whspace@[1;36m] @incognito@[1;96m] @newline@[1;95m] @input_sign@[1;31m]";

    erase_settings.close();

    colorized::PrintWith(colorized::Colorize(BOLD, GREEN),
                         "Good luck!\n");
}

void
FSetup::Config() {
    Stage1();
}
