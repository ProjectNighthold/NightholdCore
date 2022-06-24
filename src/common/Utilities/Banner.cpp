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

#include "Banner.h"
#include "GitRevision.h"
#include "StringFormat.h"

void Trinity::Banner::Show(char const* applicationName, void(*log)(char const* text), void(*logExtraInfo)())
{
	log(Trinity::StringFormat("%s (%s)", GitRevision::GetFullVersion(), applicationName).c_str());
	log("<Ctrl-C> to stop.\n");
	log("   _ (`-.  _  .-')                           ('-.             .-') _                         ");
	log("  ( (OO  )( \( -O )                        _(  OO)           (  OO) )                        ");
	log(" _.`     \ ,------.  .-'),-----.      ,--.(,------.   .-----./     '._                       ");
	log("(__...--'' |   /`. '( OO'  .-.  ' .-')| ,| |  .---'  '  .--./|'--...__)                      ");
	log(" |  /  | | |  /  | |/   |  | |  |( OO |(_| |  |      |  |('-.'--.  .--'                      ");
	log(" |  |_.' | |  |_.' |\_) |  |\|  || `-'|  |(|  '--.  /_) |OO  )  |  |                         ");
	log(" |  .___.' |  .  '.'  \ |  | |  |,--. |  | |  .--'  ||  |`-'|   |  |                         ");
	log(" |  |      |  |\  \    `'  '-'  '|  '-'  / |  `---.(_'  '--'\   |  |                         ");
	log(" `--'      `--' '--'     `-----'  `-----'  `------'   `-----'   `--'                         ");
	log("     .-') _                     ('-. .-. .-') _    ('-. .-.                       _ .-') _   ");
	log("    ( OO ) )                   ( OO )  /(  OO) )  ( OO )  /                      ( (  OO) )  ");
	log(",--./ ,--,' ,-.-')   ,----.    ,--. ,--./     '._ ,--. ,--. .-'),-----.  ,--.     \     .'_  ");
	log("|   \ |  |\ |  |OO) '  .-./-') |  | |  ||'--...__)|  | |  |( OO'  .-.  ' |  |.-') ,`'--..._) ");
	log("|    \|  | )|  |  \ |  |_( O- )|   .|  |'--.  .--'|   .|  |/   |  | |  | |  | OO )|  |  \  ' ");
	log("|  .     |/ |  |(_/ |  | .--, \|       |   |  |   |       |\_) |  |\|  | |  |`-' ||  |   ' | ");
	log("|  |\    | ,|  |_.'(|  | '. (_/|  .-.  |   |  |   |  .-.  |  \ |  | |  |(|  '---.'|  |   / : ");
	log("|  | \   |(_|  |    |  '--'  | |  | |  |   |  |   |  | |  |   `'  '-'  ' |      | |  '--'  / ");
	log("`--'  `--'  `--'     `------'  `--' `--'   `--'   `--' `--'     `-----'  `------' `-------'  ");
	log("                                                                                             ");
	log("                         https://github.com/ProjectNighthold                                 ");

	if (logExtraInfo)
		logExtraInfo();
}
