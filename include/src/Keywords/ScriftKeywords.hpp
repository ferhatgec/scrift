/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef SCRIFT_KEYWORDS_HPP
#define SCRIFT_KEYWORDS_HPP

#include <iostream>
#include <cstring>

struct ScriftKeywords {
public:
	/* Help */
	std::string Help = "help";
	std::string Help_Short = "-h";
	std::string Help_Short_Biggest = "-H";
	std::string Help_Big = "Help";
	std::string Help_Biggest = "HELP";
	 
	/* GitLink */
	std::string GitLink = "gitlink";
	std::string GitLink_Big = "GitLink";
	
	/* Edifor */
	std::string Edifor = "edifor";
	
	/* Contributors */
	std::string Cont = "cont";
	std::string Cont_Big = "Cont";
	std::string Contr = "contr";
	std::string Contributors = "contributors";
	std::string Contributors_Big = "Contributors";
	
	/* Quotation Marks */
	std::string FeLog = "felog";
	std::string Show_Log = "show_log";
	std::string FeLog_Big = "FeLog";
	std::string FeLog_F_Big = "Felog";
	std::string FeLog_Biggest = "FELOG";
	std::string Show_Log_Big = "Show_Log";
	
	/* Clear Log */
	std::string ClearLog = "clear_log";
	std::string FeLogClear = "felog --clear";
	std::string Clear_Log_Big = "Clear_Log";
	std::string Clear_Log_Biggest = "CLEAR_LOG";
	std::string FeLogClearBig = "FeLog --Clear";
	std::string FeLogClearBiggest = "FELOG --CLEAR";
	
	/* GetDev */
	std::string GetDev = "getdev";
	
	/* Add Text */
	std::string AddText = "addtext";
	
	/* Castle */
	std::string Castle = "castle";
	std::string FCastle = "fcastle";
	
	/* Remove File */
	std::string RemoveFile = "rmvfile";
	
	/* Delete Text */
	std::string DeleteText = "deletetext";
	
	/* MKDir  */
	std::string MKDir = "mkdir";
	
	/* Create */
	std::string Create = "create";
	
	/* ReadText  */
	std::string ReadText = "readtext";
	
	/* Run */
	std::string RunDotSlash = "./";
	std::string RunST = "st";
	
	/* Fr */
	std::string Fr = "fr";
	std::string Cd = "cd";
	
	/* Back */
 	std::string Back = "back";
 	
 	/* Home */
 	std::string Home = "home";
 	std::string Default = "default";
 	std::string Home_Big = "Home";
 	std::string Home_Biggest = "HOME";
 	std::string Default_Big = "Default";
 	std::string Default_Biggest = "DEFAULT";
 	
 	/* Scrift */
 	std::string Scrift = "fscrift";
 	
 	/* Create Scrift Project  */
 	std::string CreateScriftProject = "create scrift_project";
 	
 	
 	/* Test Settings */
 	std::string TestSettings = "testsettings";
 	std::string ScrLang = "scrlang";
 	
 	/* List Dir */
 	std::string Lsd = "dls";
 	std::string Lsdir = "lsdir";
 	std::string ls_d = "ls -d";
 	std::string Lsd_Biggest = "LSD";
 	std::string Lsdir_Biggest = "LSDIR";
 	std::string Lsdir_Big = "Ls_Dir";
	
	/* Show Settings */
	std::string ShowSettings = "show_settings";
	std::string Settings = "settings";
	
	/* Clear Settings */
	std::string Clear_Settings = "rmvsettings";
	std::string DeleteSettings = "deletesettings";
	
	
	/* List */
	std::string Ls = "ls";
	std::string Dir = "dir";
	std::string Ls_Biggest = "LS";
	std::string Dir_Biggest = "DIR";
	std::string Ls_Big = "Ls";
	std::string Dir_Big = "Dir";
	
	/* List Objects */
	std::string LsObject = "objls";
	
	/* List File */ 
	std::string Lsf = "fls";
	std::string Lsfile = "lsfile";
	std::string Ls_f = "ls -f";
	std::string Lsf_Biggest = "LSF";
	std::string Lsfile_Biggest = "LSFILE";
	std::string Ls_File = "Ls File";
	
	/* Create Text */ 
	std::string CreateText = "ctxt";
	
	/* Printlnf */
	std::string Printlnf = "printlnf";
	std::string Echo = "echo";

	/* Clear */
	std::string Clear = "clear";
	std::string Clear___ = "clear!!!";
	
	/* Close */
	std::string Exit = "exit";
	std::string Close = "cls";
	
	/* Username */
	std::string Username = "username";
	std::string UName = "uname";
	
	/* History */
	std::string History = "history";
	std::string FHist = "fhist";
	
	/* Clear History */
	std::string Clear_History = "rmvhistory";
	std::string History_Cleaner = "history_cleaner";
	
	/* Scr */
	std::string Scr = "scr";
	
	/* Randomize String */
	std::string RandomizeString = "rstr";
	
	/* Pause */
	std::string Pause = "pause";
	
	/* Version */
	std::string Version = "version";
	std::string _V = "-v";
	
	/* Fetcheya */
	std::string Fetcheya = "fetcheya";
	std::string _f = "-f";
	
	/* Set Locale System */
	std::string SetLocaleSystem = "setlocale_system";
	
	/* Environment */
	std::string SetName = "setname";
	std::string SetTo = "setto";
	
	/* Arrow Sign */
	std::string ArrowSign = "->";	
	std::string Enter = "\n";
	
	/* IP */
	std::string IP = "ip";
	std::string MyIP = "myip";
	
	/* Scrift Run In Path */
	std::string Scrp = "scrp";
	
	/* Now */
	std::string Now = "now";
	std::string DateNow = "datenow";
	
	/* Find */ 
	std::string Find = "ffind";
	std::string Find_Big = "Ffind";
	std::string Find_Biggest = "FFIND";
	
	/* FName */
	std::string KName = "kname";
	
 	/* Emoji */
	std::string Emoji = "emoji";

	/* Random */
	std::string Random = "random";
	
	/* Set */
	std::string Set = "fset";
	
	/* Square and Sqrt (square root) */
	std::string SquareofNumber = "square";
	std::string SquareRootofNumber = "sqrt";
	
	/* Factorial */
	std::string Factorial = "fact";
	
	/* Set Background Color */
	std::string SetBgColor = "fset bg";
		
	/* Template */
	std::string LanguageTemplate = "template";	
		
	/* Welcome */
	std::string Welcome = "welcome";
		
	/* Uptime */
	std::string Uptime = "uptime";
	
	/* My ASCII Art */
	std::string MyASCIIArt = "asciiart";
	
	/* Morse */
	std::string Morse = "morse";
	std::string MorseinMorseCode = "-- --- .-. ... .";
	
	/* Uninstall */
	std::string Uninstall = "uninstall";
	
	/* FreeBrain Generator */
	std::string FreeBrainGen = "genfrbr";
	
	/* Parse */
	std::string Parse = "parse";
	
	/* Fegeya package installer */
	std::string Fpi = "fpi";
	
	/* Setup && Config */
	std::string Config = "config";
	
	/* Output of command */
	std::string Output = "output";
	
	/* Change title of terminal header */
	std::string Title = "title";
	
	/* Incognito mode for history */
	std::string Incognito = "incognito";
	
	/* Set or change alias */
	std::string Alias = "alias";
	
	/* Whitespace */
	std::string Whitespace = " ";
};

#endif // SCRIFT_KEYWORDS_HPP
