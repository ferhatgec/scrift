/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#include <Fetcheya/Colors.h>
#include <Fetcheya/Logos.h>
#include <stdio.h>

char** OSLogo() {
#ifdef __FreeBSD__
	static char *logo[] = {"                                     " TNRM,
                        "   " TWHT "```                        " TLRD "`      " TNRM,
                        "  " TWHT "` `.....---..." TLRD "....--.```   -/      " TNRM,
                        "  " TWHT "+o   .--`         " TLRD "/y:`      +.     " TNRM,
                        "  " TWHT " yo`:.            " TLRD ":o      `+-      " TNRM,
                        "    " TWHT "y/               " TLRD "-/`   -o/       " TNRM,
                        "   " TWHT ".-                  " TLRD "::/sy+:.      " TNRM,
                        "   " TWHT "/                     " TLRD "`--  /      " TNRM,
                        "  " TWHT "`:                          " TLRD ":`     " TNRM,
                        "  " TWHT "`:                          " TLRD ":`     " TNRM,
                        "   " TWHT "/                          " TLRD "/      " TNRM,
                        "   " TWHT ".-                        " TLRD "-.      " TNRM,
                        "    " TWHT "--                      " TLRD "-.       " TNRM,
                        "     " TWHT "`:`                  " TLRD "`:`        " TNRM,
                        "       " TLRD ".--             `--.          " TNRM,
                        "         " TLRD " .---.....----.             " TNRM,
                        "                                     " TNRM,
                        "                                     " TNRM};
	return logo;
#elif __APPLE__
	static char *logo[] = {
 				"                               ",
				    TGRN "                 -/+:.         " TNRM,
				    TGRN "                :++++.         " TNRM,
				    TGRN "               /+++/.          " TNRM,
				    TGRN "       .:-::- .+/:-``.::-      " TNRM,
				    TGRN "    .:/++++++/::::/++++++/:`   " TNRM,
				    TBRN "  .:///////////////////////:`  " TNRM,
				    TBRN "  ////////////////////////`    " TNRM,
				    TLRD " -+++++++++++++++++++++++`     " TNRM,
				    TLRD " /++++++++++++++++++++++/      " TNRM,
				    TRED " /sssssssssssssssssssssss.     " TNRM,
				    TRED " :ssssssssssssssssssssssss-    " TNRM,
				    TPUR "  osssssssssssssssssssssssso/` " TNRM,
				    TPUR "  `syyyyyyyyyyyyyyyyyyyyyyyy+` " TNRM,
				    TBLU "   `ossssssssssssssssssssss/   " TNRM,
				    TBLU "     :ooooooooooooooooooo+.    " TNRM,
				    TBLU "      `:+oo+/:-..-:/+o+/-      " TNRM "",
	};
	return logo;
#elif ____ANDROID__
	static char *logo[] = {
    				TLGN "      ▀▄  ▂▂▂▂▂  ▄▀      " TNRM, TLGN "      ▗▟█████████▙▖      " TNRM,
    				TLGN "     ▟██▀▀█████▀▀██▙     " TNRM, TLGN "     ███▄▄█████▄▄███▌    " TNRM,
    				TLGN "    █████████████████    " TNRM, TLGN "▟█▙ ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄ ▟█▙" TNRM,
    				TLGN "███ █████████████████ ███" TNRM, TLGN "███ █████████████████ ███" TNRM,
    				TLGN "███ █████████████████ ███" TNRM, TLGN "███ █████████████████ ███" TNRM,
    				TLGN "███ █████████████████ ███" TNRM, TLGN "▜█▛ █████████████████ ▜█▛" TNRM,
    				TLGN "    ▀███████████████▀    " TNRM, TLGN "      ████     ████      " TNRM,
    				TLGN "      ████     ████      " TNRM, TLGN "      ▜██▛     ▜██▛      " TNRM};
	return logo;
#elif __OpenBSD__
	static char *logo[] = {
    				"                                       " TLCY " _  " TNRM "",
    				"                                       " TLCY "(_) " TNRM "",
    				TYLW "              |    .                       " TNRM "",
    				TYLW "          .   |L  /|   .           " TLCY "   _    " TNRM,
    				TYLW "      _ . |\\ _| \\--+._/| .           " TLCY "(_)   " TNRM,
    				TYLW "     / ||\\| Y J  )   / |/| ./              " TNRM,
    				TYLW "    J  |)'( |        ` F`.'/   " TLCY "     _      " TNRM,
	    			TYLW "  -<|  F         __     .-<        " TLCY "(_)     " TNRM,
	    			TYLW "    | /       .-'" TLCY ". " TYLW "`.  /" TLCY "-. " TYLW "L___            " TNRM,
	    			TYLW "    J \\      <    " TLCY "\\ " TYLW " | | " TDGY "O" TLCY "\\" TYLW "|.-' " TLCY
	   			     "  _        " TNRM,
	    			TYLW "  _J \\  .-    \\" TLCY "/ " TDGY "O " TLCY "| " TYLW "| \\   |" TYLW "F    " TLCY
	    			     "(_)       " TNRM,
	    			TYLW " '-F  -<_.     \\   .-'  `-' L__            " TNRM,
	    			TYLW "__J  _   _.     >-'  " TBRN ")" TLRD "._.   " TYLW "|-'            " TNRM,
	    			TYLW " `-|.'   /_.          " TLRD "\\_|  " TYLW " F              " TNRM,
    				TYLW "  /.-   .                _.<               " TNRM,
			    	TYLW " /'    /.'             .'  `\\              " TNRM,
			    	TYLW "  /L  /'   |/      _.-'-\\                  " TNRM,
			    	TYLW " /'J       ___.---'\\|                     " TNRM,
			    	TYLW "   |\\  .--' V  | `. `                     " TNRM,
	   		 	TYLW "   |/`. `-.     `._)                      " TNRM,
			   	TYLW "      / .-.\\                            " TNRM,
			   	TYLW "      \\ (  `\\                           " TNRM "",
	   			TYLW "       `.\\                                  " TNRM ""};
	return logo;
#elif __NetBSD__
	static char *logo[] = {
    				"                                  " TLRD "__,gnnnOCCCCCOObaau,_      " TNRM,
    				"   " TWHT "_._                    " TLRD "__,gnnCCCCCCCCOPF\"''               " TNRM,
    				"  " TWHT "(N\\\\\\" TLRD "XCbngg,._____.,gnnndCCCCCCCCCCCCF\"___,,,,___          " TNRM,
    				"   " TWHT "\\\\N\\\\" TLRD "XCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCOOOOPYvv.     " TNRM,
    				"    " TWHT "\\\\N\\\\" TLRD "XCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCPF\"''               " TNRM,
    				"     " TWHT "\\\\N\\\\" TLRD "XCCCCCCCCCCCCCCCCCCCCCCCCCOF\"'                     " TNRM,
    				"      " TWHT "\\\\N\\\\" TLRD "XCCCCCCCCCCCCCCCCCCCCOF\"'                         " TNRM,
    				"       " TWHT "\\\\N\\\\" TLRD "XCCCCCCCCCCCCCCCPF\"'                             " TNRM,
    				"        " TWHT "\\\\N\\\\" TLRD "\"PCOCCCOCCFP\"\"                                  " TNRM,
    				"         " TWHT "\\\\N\\                                                " TNRM,
    				"          " TWHT "\\\\N\\                                               " TNRM,
    				"           " TWHT "\\\\N\\                                              " TNRM,
    				"            " TWHT "\\\\NN\\                                            " TNRM,
    				"             " TWHT "\\\\NN\\                                           " TNRM,
    				"              " TWHT "\\\\NNA.                                         " TNRM,
    				"               " TWHT "\\\\NNA,                                        " TNRM,
    				"                " TWHT "\\\\NNN,                                       " TNRM,
    				"                 " TWHT "\\\\NNN\\                                      " TNRM,
    				"                  " TWHT "\\\\NNN\\ " TNRM,
    				"                   " TWHT "\\\\NNNA" TNRM};
	return logo;
#elif linux
	if(strstr(fsplusplus::ReadOSName().c_str(), "Fedora")) {
		static char *logo[] = {TLBL "           :/------------://          " TNRM,
                       TLBL "        :------------------://       " TNRM,
                       TLBL "      :-----------" TWHT "/shhdhyo/" TLBL "-://      " TNRM,
                       TLBL "    /-----------" TWHT "omMMMNNNMMMd/" TLBL "-:/     " TNRM,
                       TLBL "   :-----------" TWHT "sMMMdo:/" TLBL "       -:/    " TNRM,
                       TLBL "  :-----------" TWHT ":MMMd" TLBL "-------    --:/   " TNRM,
                       TLBL "  /-----------" TWHT ":MMMy" TLBL "-------    ---/   " TNRM,
                       TLBL " :------    --" TWHT "/+MMMh/" TLBL "--        ---:  " TNRM,
                       TLBL " :---     " TWHT "oNMMMMMMMMMNho" TLBL "     -----:  " TNRM,
                       TLBL " :--      " TWHT "+shhhMMMmhhy++" TLBL "   ------:   " TNRM,
                       TLBL " :-      -----" TWHT ":MMMy" TLBL "--------------/   " TNRM,
                       TLBL " :-     ------" TWHT "/MMMy" TLBL "-------------:    " TNRM,
                       TLBL " :-      ----" TWHT "/hMMM+" TLBL "------------:     " TNRM,
                       TLBL " :--" TWHT ":dMMNdhhdNMMNo" TLBL "-----------:       " TNRM,
                       TLBL " :---" TWHT ":sdNMMMMNds:" TLBL "----------:         " TNRM,
                       TLBL " :------" TWHT ":://:" TLBL "-----------://          " TNRM,
                       TLBL " :--------------------://            " TNRM,
                       "                                     " TNRM};
		return logo;
	} else if(strstr(fsplusplus::ReadOSName().c_str(), "Ubuntu")) {
		static char *logo[] = {TLRD "                          ./+o+-      " TNRM,
                       TWHT "                  yyyyy- " TLRD "-yyyyyy+     " TNRM,
                       TWHT "               " TWHT "://+//////" TLRD "-yyyyyyo     " TNRM,
                       TYLW "           .++ " TWHT ".:/++++++/-" TLRD ".+sss/`     " TNRM,
                       TYLW "         .:++o:  " TWHT "/++++++++/:--:/-     " TNRM,
                       TYLW "        o:+o+:++." TWHT "`..```.-/oo+++++/    " TNRM,
                       TYLW "       .:+o:+o/." TWHT "          `+sssoo+/   " TNRM,
                       TWHT "  .++/+:" TYLW "+oo+o:`" TWHT "             /sssooo.  " TNRM,
                       TWHT " /+++//+:" TYLW "`oo+o" TWHT "               /::--:.  " TNRM,
                       TWHT " +/+o+++" TYLW "`o++o" TLRD "               ++////.   " TNRM,
                       TWHT "  .++.o+" TYLW "++oo+:`" TLRD "             /dddhhh.  " TNRM,
                       TYLW "       .+.o+oo:." TLRD "          `oddhhhh+   " TNRM,
                       TYLW "        +.++o+o``-``" TLRD "``.:ohdhhhhh+     " TNRM,
                       TYLW "         `:o+++ " TLRD "`ohhhhhhhhyo++os:     " TNRM,
                       TYLW "           .o:" TLRD "`.syhhhhhhh/" TYLW ".oo++o`     " TNRM,
                       TLRD "               /osyyyyyyo" TYLW "++ooo+++/    " TNRM,
                       TLRD "                   ````` " TYLW "+oo+++o:     " TNRM,
                       TYLW "                          `oo++.      " TNRM};
		return logo;
	} else if(strstr(fsplusplus::ReadOSName.c_str(), "Arch")) {
		static char *logo[] = {"" TLCY "                   -`                 " TNRM,
                     "" TLCY "                  .o+`                " TNRM,
                     "" TLCY "                 `ooo/                " TNRM,
                     "" TLCY "                `+oooo:               " TNRM,
                     "" TLCY "               `+oooooo:              " TNRM,
                     "" TLCY "               -+oooooo+:             " TNRM,
                     "" TLCY "             `/:-:++oooo+:            " TNRM,
                     "" TLCY "            `/++++/+++++++:           " TNRM,
                     "" TLCY "           `/++++++++++++++:          " TNRM,
                     "" TLCY "          `/+++o" TCYN "oooooooo" TLCY "oooo/`        " TNRM,
                     "" TCYN "         " TLCY "./" TCYN "ooosssso++osssssso" TLCY "+`       " TNRM,
                     "" TCYN "        .oossssso-````/ossssss+`      " TNRM,
                     "" TCYN "       -osssssso.      :ssssssso.     " TNRM,
                     "" TCYN "      :osssssss/        osssso+++.    " TNRM,
                     "" TCYN "     /ossssssss/        +ssssooo/-    " TNRM,
                     "" TCYN "   `/ossssso+/:-        -:/+osssso+-  " TNRM,
                     "" TCYN "  `+sso+:-`                 `.-/+oso: " TNRM,
                     "" TCYN " `++:.                           `-/+/" TNRM,
                     "" TCYN " .`                                 `/" TNRM};
		return logo;
	} else if(strstr(fsplusplus::ReadOSName().c_str(), "Debian")) {
		static char *logo[] = {"  " TWHT "       _,met$$$$$gg.           " TNRM,
                       "  " TWHT "    ,g$$$$$$$$$$$$$$$P.       " TNRM,
                       "  " TWHT "  ,g$$P\"\"       \"\"\"Y$$.\".     " TNRM,
                       "  " TWHT " ,$$P'              `$$$.     " TNRM,
                       "  " TWHT "',$$P       ,ggs.     `$$b:   " TNRM,
                       "  " TWHT "`d$$'     ,$P\"\'   " TLRD "." TWHT "    $$$    " TNRM,
                       "  " TWHT " $$P      d$\'     " TLRD "," TWHT "    $$P    " TNRM,
                       "  " TWHT " $$:      $$.   " TLRD "-" TWHT "    ,d$$'    " TNRM,
                       "  " TWHT " $$;      Y$b._   _,d$P'      " TNRM,
                       "  " TWHT " Y$$.    " TLRD "`." TWHT "`\"Y$$$$P\"'         " TNRM,
                       "  " TWHT " `$$b      " TLRD "\"-.__              " TNRM,
                       "  " TWHT "  `Y$$                        " TNRM,
                       "  " TWHT "   `Y$$.                      " TNRM,
                       "  " TWHT "     `$$b.                    " TNRM,
                       "  " TWHT "       `Y$$b.                 " TNRM,
                       "  " TWHT "          `\"Y$b._             " TNRM,
                       "  " TWHT "              `\"\"\"\"           " TNRM,
                       "                                " TNRM};
		return logo;	
	} else if(strstr(fsplusplus::ReadOSName.c_str(), "Linux Mint")) {
		static char *logo[] = {"                                       " TNRM,
                     TLGN " MMMMMMMMMMMMMMMMMMMMMMMMMmds+.       " TNRM,
                     TLGN " MMm----::-://////////////oymNMd+`    " TNRM,
                     TLGN " MMd      " TWHT "/++                " TLGN "-sNMd:   " TNRM,
                     TLGN " MMNso/`  " TWHT "dMM    `.::-. .-::.` " TLGN ".hMN:  " TNRM,
                     TLGN " ddddMMh  " TWHT "dMM   :hNMNMNhNMNMNh: " TLGN "`NMm  " TNRM,
                     TLGN "     NMm  " TWHT "dMM  .NMN/-+MMM+-/NMN` " TLGN "dMM  " TNRM,
                     TLGN "     NMm  " TWHT "dMM  -MMm  `MMM   dMM. " TLGN "dMM  " TNRM,
                     TLGN "     NMm  " TWHT "dMM  -MMm  `MMM   dMM. " TLGN "dMM  " TNRM,
                     TLGN "     NMm  " TWHT "dMM  .mmd  `mmm   yMM. " TLGN "dMM  " TNRM,
                     TLGN "     NMm  " TWHT "dMM`  ..`   ...   ydm. " TLGN "dMM  " TNRM,
                     TLGN "     hMM- " TWHT "+MMd/-------...-:sdds  " TLGN "dMM  " TNRM,
                     TLGN "     -NMm- " TWHT ":hNMNNNmdddddddddy/`  " TLGN "dMM  " TNRM,
                     TLGN "      -dMNs-" TWHT "``-::::-------.``    " TLGN "dMM  " TNRM,
                     TLGN "       `/dMNmy+/:-------------:/yMMM  " TNRM,
                     TLGN "          ./ydNMMMMMMMMMMMMMMMMMMMMM  " TNRM,
                     TLGN "             .MMMMMMMMMMMMMMMMMMM    " TNRM,
                     "                                      " TNRM};
		return logo;
	} else if(strstr(fsplusplus::ReadOSName.c_str(), "Gentoo")) { // Gentoo/Linux
		char *logo[] = {
    			TLPR "         -/oyddmdhs+:.                " TNRM,
    			TLPR "     -o" TWHT "dNMMMMMMMMNNmhy+" TLPR "-`            " TNRM,
    			TLPR "   -y" TWHT "NMMMMMMMMMMMNNNmmdhy" TLPR "+-          " TNRM,
    			TLPR " `o" TWHT "mMMMMMMMMMMMMNmdmmmmddhhy" TLPR "/`       " TNRM,
    			TLPR " om" TWHT "MMMMMMMMMMMN" TLPR "hhyyyo" TWHT "hmdddhhhd" TLPR "o`     " TNRM,
    			TLPR ".y" TWHT "dMMMMMMMMMMd" TLPR "hs++so/s" TWHT "mdddhhhhdm" TLPR "+`   " TNRM,
    			TLPR " oy" TWHT "hdmNMMMMMMMN" TLPR "dyooy" TWHT "dmddddhhhhyhN" TLPR "d.  " TNRM,
    			TLPR "  :o" TWHT "yhhdNNMMMMMMMNNNmmdddhhhhhyym" TLPR "Mh  " TNRM,
   			TLPR "    .:" TWHT "+sydNMMMMMNNNmmmdddhhhhhhmM" TLPR "my  " TNRM,
    			TLPR "       /m" TWHT "MMMMMMNNNmmmdddhhhhhmMNh" TLPR "s:  " TNRM,
    			TLPR "   `o" TWHT "NMMMMMMMNNNmmmddddhhdmMNhs" TLPR "+`    " TNRM,
    			TLPR "  `s" TWHT "NMMMMMMMMNNNmmmdddddmNMmhs" TLPR "/.     " TNRM,
    			TLPR " /N" TWHT "MMMMMMMMNNNNmmmdddmNMNdso" TLPR ":`       " TNRM,
    			TLPR "+M" TWHT "MMMMMMNNNNNmmmmdmNMNdso" TLPR "/-          " TNRM,
    			TLPR "yM" TWHT "MNNNNNNNmmmmmNNMmhs+/" TLPR "-`            " TNRM,
    			TLPR "/h" TWHT "MMNNNNNNNNMNdhs++/" TLPR "-`               " TNRM,
    			TLPR "`/" TWHT "ohdmmddhys+++/:" TLPR ".`                  " TNRM,
    			TLPR "  `-//////:--.                       " TNRM};
		return logo;
	} else if(strstr(fsplusplus::ReadOSName.c_str(), "SUSE") { // openSUSE && SUSE Linux
		static char *logo[] = {
   			TWHT "             .;ldkO0000Okdl;.            " TNRM,
    			TWHT "         .;d00xl:,'....';:ok00d;.        " TNRM,
    			TWHT "       .d00l'                ,o00d.      " TNRM,
    			TWHT "     .d0Kd." TLGN " :Okxol:;'.          " TWHT ":O0d.    " TNRM,
    			TWHT "    'OK" TLGN "KKK0kOKKKKKKKKKKOxo:'      " TWHT "lKO'   " TNRM,
    			TWHT "   ,0K" TLGN "KKKKKKKKKKKKKKK0d:" TWHT ",,," TLGN ":dx:" TWHT "    ;00,  " TNRM,
    			TWHT "  .OK" TLGN "KKKKKKKKKKKKKKKk." TWHT ".oOkdl." TLGN "'0k." TWHT "   cKO. " TNRM,
    			TWHT "  :KK" TLGN "KKKKKKKKKKKKKKK: " TWHT "kKx..od " TLGN "lKd" TWHT "   .OK: " TNRM,
    			TWHT "  dKK" TLGN "KKKKKKKKKOx0KKKd " TWHT ";0KKKO, " TLGN "kKKc" TWHT "   dKd " TNRM,
    			TWHT "  dKK" TLGN "KKKKKKKKKK;.;oOKx,.." TWHT "'" TLGN "..;kKKK0." TWHT "  dKd " TNRM,
    			TWHT "  :KK" TLGN "KKKKKKKKKK0o;...;cdxxOK0Oxc,.  " TWHT ".0K: " TNRM,
    			TWHT "   kKK" TLGN "KKKKKKKKKKKKK0xl;'......,cdo  " TWHT "lKk  " TNRM,
    			TWHT "   '0K" TLGN "KKKKKKKKKKKKKKKKKKKK00KKOo;  " TWHT "c00'  " TNRM,
    			TWHT "    .kK" TLGN "KKOxddxkOO00000Okxoc;'.   " TWHT ".dKk.   " TNRM,
    			TWHT "      l0Ko.                    .c00l.    " TNRM,
    			TWHT "       .l0Kk:.              .;xK0l.      " TNRM,
    			TWHT "          ,lkK0xl:;,,,,;:ldO0kl,         " TNRM,
    			TWHT "              .':ldxkkkkxdl:'.           " TNRM};
		return logo;	
	} else if(strstr(fsplusplus::ReadOSName().c_str(), "Slackware")) {
		char *slackware_logo[] = {
    			TLBL "                   :::::::",
    			TLBL "             :::::::::::::::::::               " TNRM,
    			TLBL "          :::::::::::::::::::::::::           " TNRM,
    			TLBL "        ::::::::" TWHT "cllcccccllllllll" TLBL "::::::        " TNRM,
    			TLBL "     :::::::::" TWHT "lc               dc" TLBL ":::::::      " TNRM,
    			TLBL "    ::::::::" TWHT "cl   clllccllll    oc" TLBL ":::::::::    " TNRM,
    			TLBL "   :::::::::" TWHT "o   lc" TLBL "::::::::" TWHT "co   oc" TLBL "::::::::::   " TNRM,
    			TLBL "  ::::::::::" TWHT "o    cccclc" TLBL ":::::" TWHT "clcc" TLBL "::::::::::::  " TNRM,
    			TLBL "  :::::::::::" TWHT "lc        cclccclc" TLBL ":::::::::::::  " TNRM,
    			TLBL " ::::::::::::::" TWHT "lcclcc          lc" TLBL ":::::::::::: " TNRM,
    			TLBL " ::::::::::" TWHT "cclcc" TLBL ":::::" TWHT "lccclc     oc" TLBL "::::::::::: " TNRM,
    			TLBL " ::::::::::" TWHT "o    l" TLBL "::::::::::" TWHT "l    lc" TLBL "::::::::::: " TNRM,
    			TLBL "  :::::" TWHT "cll" TLBL ":" TWHT "o     clcllcccll     o" TLBL ":::::::::::  " TNRM,
    			TLBL "  :::::" TWHT "occ" TLBL ":" TWHT "o                  clc" TLBL ":::::::::::  " TNRM,
    			TLBL "   ::::" TWHT "ocl" TLBL ":" TWHT "ccslclccclclccclclc" TLBL ":::::::::::::   " TNRM,
    			TLBL "    :::" TWHT "oclcccccccccccccllllllllllllll" TLBL ":::::    " TNRM,
    			TLBL "     ::" TWHT "lcc1lcccccccccccccccccccccccco" TLBL "::::     " TNRM,
    			TLBL "       ::::::::::::::::::::::::::::::::       " TNRM,
    			TLBL "         ::::::::::::::::::::::::::::         " TNRM,
    			TLBL "            ::::::::::::::::::::::" TNRM,
    			TLBL "                 ::::::::::::" TNRM};
		return logo;
	} else if(strstr(fsplusplus::ReadOSName().c_str(), "elementary OS")) {
		static char *logo[] = {
    			"                                  ",          TWHT "           $?77777$$$IO          " TNRM,
    			TWHT "        $III777ZZZZ$$$ZZ$8       " TNRM, TWHT "      ZI777           OZZZ$      " TNRM,
    			TWHT "     Z777             O7ZZO8     " TNRM, TWHT "    Z777            O$ZZZ8       " TNRM,
    			TWHT "    I$$           O$ZZZD         " TNRM, TWHT "   0$$O         O$$ZZ            " TNRM,
    			TWHT "   0$$O       8$$$$              " TNRM, TWHT "   0$$O     8$$$$                " TNRM,
    			TWHT "    $ZZ   O$$ZZ           D      " TNRM, TWHT "     ZZZ8ZZZZ             O88    " TNRM,
    			TWHT "     DZZZZ8             D888     " TNRM, TWHT "       ZZZZDMMMMMMMMMMDO888      " TNRM,
    			TWHT "         ZOOOOOOOOOOOO888        " TNRM, TWHT "           N8OOOOOOO8D           " TNRM,
    			"                                 " TNRM,      "                                 " TNRM};
		return logo;
	} else { 
		static char *logo[] = {"                            " TNRM,
                	      "                            " TNRM,
                	      "                            " TNRM,
                	      TDGY "         #####              " TNRM,
                	      TDGY "        #######             " TNRM,
                	      TDGY "        ##" TWHT "O" TDGY "#" TWHT "O" TDGY "##             " TNRM,
                	      TDGY "        #" TYLW "#####" TDGY "#             " TNRM,
                	      TDGY "      ##" TWHT "##" TYLW "###" TWHT "##" TDGY "##           " TNRM,
                	      TDGY "     #" TWHT "##########" TDGY "##          " TNRM,
                	      TDGY "    #" TWHT "############" TDGY "##         " TNRM,
                	      TDGY "    #" TWHT "############" TDGY "###        " TNRM,
                	      TYLW "   ##" TDGY "#" TWHT "###########" TDGY "##" TYLW "#        " TNRM,
                	      TYLW " ######" TDGY "#" TWHT "#######" TDGY "#" TYLW "######      " TNRM,
                	      TYLW " #######" TDGY "#" TWHT "#####" TDGY "#" TYLW "#######      " TNRM,
                	      TYLW "   #####" TDGY "#######" TYLW "#####        " TNRM,
                	      "                            " TNRM,
                	      "                            " TNRM,
                	      "                            " TNRM};
		return logo;
	}	
#elif _WIN32
	static char *logo[] = {TLBL "                                  .., " TNRM,
                               TLBL "                      ....,,:;+ccllll " TNRM,
                               TLBL "        ...,,+:;  cllllllllllllllllll " TNRM,
                               TLBL "  ,cclllllllllll  lllllllllllllllllll " TNRM,
                               TLBL "  llllllllllllll  lllllllllllllllllll " TNRM,
                               TLBL "  llllllllllllll  lllllllllllllllllll " TNRM,
                               TLBL "  llllllllllllll  lllllllllllllllllll " TNRM,
                               TLBL "  llllllllllllll  lllllllllllllllllll " TNRM,
                               TLBL "  llllllllllllll  lllllllllllllllllll " TNRM,
                               TLBL "                                      " TNRM,
                               TLBL "  llllllllllllll  lllllllllllllllllll " TNRM,
                               TLBL "  llllllllllllll  lllllllllllllllllll " TNRM,
                               TLBL "  llllllllllllll  lllllllllllllllllll " TNRM,
                               TLBL "  llllllllllllll  lllllllllllllllllll " TNRM,
                               TLBL "  llllllllllllll  lllllllllllllllllll " TNRM,
                               TLBL "  `'ccllllllllll  lllllllllllllllllll " TNRM,
                               TLBL "         `'\"\"*::  :ccllllllllllllllll " TNRM,
                               TLBL "                        ````''\"*::cll " TNRM,
                               TLBL "                                   `` " TNRM};
		return logo;
#else
	control = true;
#endif
}
