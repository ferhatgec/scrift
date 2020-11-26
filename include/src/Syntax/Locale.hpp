/* MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#
# */

#ifndef LOCALE_HPP
#define LOCALE_HPP

#include <iostream>
#include <string>

/* Supported languages */
typedef struct {
	const std::string locale_en = "en_EN.UTF-8";
	const std::string locale_tr = "tr_TR.UTF-8";
} slocale_def_t;

typedef struct {
	std::string language		= "en_EN.UTF-8";
			
	std::string cmd_username    = "Show username.\n";
	std::string cmd_config	    = "Configure Scrift.\n";
	std::string cmd_castle	    = "Scrift's game.\n";
	std::string cmd_gitlink	    = "Show GitHub link.\n";
	std::string cmd_welcome	    = "Show welcome message.\n";
	std::string cmd_contr	    = "Show contributors.\n";
	std::string	cmd_fscrift	    = "Interpret <file>.\n";
	std::string	cmd_clearlog    = "Clear FeLog.\n";
	std::string cmd_history	    = "Show Scrift history.\n";
	std::string cmd_rmvhistory  = "Clear Scrift history.\n";
	std::string cmd_settings	= "Show settings.\n";
	std::string cmd_rmvsttngs	= "Clear settings.\n";
	std::string cmd_fetcheya	= "Show system-info-tool (fpm)\n";
	std::string cmd_version		= "Show version and license.\n";
	std::string cmd_now  		= "Show time.\n";
	std::string cmd_template	= "Create language template\n";
	std::string cmd_uptime		= "Show uptime.\n";
	std::string	cmd_asciiart	= "Show ASCII Art.\n";
	std::string cmd_felog		= "Show FeLog.\n";
	std::string cmd_calendar	= "Show calendar.\n";
	std::string	cmd_edifor		= "Open Edifor.\n";
	std::string cmd_addtext		= "Add text in <file>\n";
	std::string cmd_readtext	= "Read <file>\n";
	std::string cmd_ctxt		= "Create text-file.\n";
	std::string	cmd_pause		= "Stop Scrift.\n";
	std::string	cmd_cls			= "Close Scrift.\n";
	std::string	cmd_clear		= "Clear Scrift's buffer.\n";
	std::string	cmd_ip			= "Show local-IP address.\n";
} slocale_t;

class FLocale {
public:
	slocale_t Set();
};

#endif // LOCALE_HPP
