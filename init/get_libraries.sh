#!/usr/bin/env bash

FETCH=curl
URL="https://raw.githubusercontent.com/ferhatgec/"

cd library

function is_exists {
  if [ -e "$1" ]
    then
      echo Found "$1"
    else
      $FETCH "${URL}$2" --output "$1"
  fi
}

is_exists "Colorized.hpp"        "colorized/master/Colorized.hpp"
is_exists "EmojiPlusPlus.h"      "emojiplusplus/master/EmojiPlusPlus.hpp"
is_exists "FileSystemPlusPlus.h" "fsplusplus/master/FileSystemPlusPlus.hpp"
is_exists "ExecutePlusPlus.hpp"  "execplusplus/master/ExecutePlusPlus.hpp"
# is_exists "StringTools.h"        "stringtools/master/StringTools.hpp"