/*
 *###############################################################################
 *#                                                                             #
 *# Copyright (C) 2022 Project Nighthold <https://github.com/ProjectNighthold>  #
 *#                                                                             #
 *# This file is free software; as a special exception the author gives         #
 *# unlimited permission to copy and/or distribute it, with or without          #
 *# modifications, as long as this notice is preserved.                         #
 *#                                                                             #
 *# This program is distributed in the hope that it will be useful, but         #
 *# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the      #
 *# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.    #
 *#                                                                             #
 *# Read the THANKS file on the source root directory for more info.            #
 *#                                                                             #
 *###############################################################################
 */

#include "Common.h"

char const* localeNames[MAX_LOCALES] =
{
  "enUS",
  "koKR",
  "frFR",
  "deDE",
  "zhCN",
  "zhTW",
  "esES",
  "esMX",
  "ruRU",
  "none",
  "ptBR",
  "itIT"
};

LocaleConstant GetLocaleByName(const std::string& name)
{
    for (uint8 i = 0; i < MAX_LOCALES; ++i)
        if (name == localeNames[i])
            return LocaleConstant(i);

    return LOCALE_enUS;                                     // including enGB case
}

LocalizedString::LocalizedString()
{
    for (uint32 i = 0; i < TOTAL_LOCALES; i++)
        Str[i] = "";
}

LocalizedString::LocalizedString(char const* val)
{
    for (uint32 i = 0; i < TOTAL_LOCALES; i++)
        Str[i] = val;
}

char const* LocalizedString::Get(uint32 locale) const
{
    if ((Str[locale] == nullptr || strlen(Str[locale]) == 0) && Str[LOCALE_enUS] != nullptr)
        return Str[LOCALE_enUS];

    if (Str[locale] == nullptr)
        return "";

    return Str[locale];
}

