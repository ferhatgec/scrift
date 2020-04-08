/* GPLv3 License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the GPLv3 License.
#
# */


#ifndef DEFAULT_SETTINGS_H
#define DEFAULT_SETTINGS_H

#include "../File/Directory.h"
#include "../File/File.h"
#include "../main.h"
#include "../File/Path.h"
#include "../File/Sync.h"
#include "../Syntax/Syntax.h"
#include <fstream>



class FDefaultSettingsClass {
public:
    FDefaultSettingsClass();
    ~FDefaultSettingsClass();
    void LoadSettings(char *default_username,  char *_default_language); 
};



#endif