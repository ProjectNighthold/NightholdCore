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

#include "account_service.pb.h"
#include "authentication_service.pb.h"
#include "challenge_service.pb.h"
#include "channel_service.pb.h"
#include "connection_service.pb.h"
#include "friends_service.pb.h"
#include "game_utilities_service.pb.h"
#include "notification_types.pb.h"
#include "presence_service.pb.h"
#include "profanity_filter_config.pb.h"
#include "report_service.pb.h"
#include "resource_service.pb.h"
#include "user_manager_service.pb.h"
#include "Login.pb.h"
#include "RealmList.pb.h"

#include "ServiceBase.h"
#include "rpc_types.pb.h"
#include "attribute_types.pb.h"
#include "Debugging/Errors.h"
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/wire_format.h>