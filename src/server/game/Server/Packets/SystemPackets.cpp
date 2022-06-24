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

#include "SystemPackets.h"

WorldPacket const* WorldPackets::System::FeatureSystemStatus::Write()
{
    _worldPacket << uint8(ComplaintStatus);

    _worldPacket << uint32(ScrollOfResurrectionRequestsRemaining);
    _worldPacket << uint32(ScrollOfResurrectionMaxRequestsPerDay);

    _worldPacket << uint32(CfgRealmID);
    _worldPacket << int32(CfgRealmRecID);

    _worldPacket << uint32(TwitterPostThrottleLimit);
    _worldPacket << uint32(TwitterPostThrottleCooldown);

    _worldPacket << uint32(TokenPollTimeSeconds);
    _worldPacket << uint32(TokenRedeemIndex);
    _worldPacket << int64(TokenBalanceAmount);

    _worldPacket << uint32(BpayStoreProductDeliveryDelay);

    _worldPacket.WriteBit(VoiceEnabled);
    _worldPacket.WriteBit(EuropaTicketSystemStatus.is_initialized());
    _worldPacket.WriteBit(ScrollOfResurrectionEnabled);
    _worldPacket.WriteBit(BpayStoreEnabled);
    _worldPacket.WriteBit(BpayStoreAvailable);
    _worldPacket.WriteBit(BpayStoreDisabledByParentalControls);
    _worldPacket.WriteBit(ItemRestorationButtonEnabled);
    _worldPacket.WriteBit(BrowserEnabled);
    _worldPacket.WriteBit(SessionAlert.is_initialized());
    _worldPacket.WriteBit(RecruitAFriendSendingEnabled);
    _worldPacket.WriteBit(CharUndeleteEnabled);
    _worldPacket.WriteBit(RestrictedAccount);
    _worldPacket.WriteBit(TutorialsEnabled);
    _worldPacket.WriteBit(NPETutorialsEnabled);
    _worldPacket.WriteBit(TwitterEnabled);
    _worldPacket.WriteBit(CommerceSystemEnabled);
    _worldPacket.WriteBit(Unk67);
    _worldPacket.WriteBit(WillKickFromWorld);
    _worldPacket.WriteBit(KioskModeEnabled);
    _worldPacket.WriteBit(CompetitiveModeEnabled);
    _worldPacket.WriteBit(RaceClassExpansionLevels.is_initialized());
    _worldPacket.WriteBit(TokenBalanceEnabled);

    _worldPacket.FlushBits();

    _worldPacket.WriteBit(QuickJoinConfig.ToastsDisabled);
    _worldPacket << float(QuickJoinConfig.ToastDuration);
    _worldPacket << float(QuickJoinConfig.DelayDuration);
    _worldPacket << float(QuickJoinConfig.QueueMultiplier);
    _worldPacket << float(QuickJoinConfig.PlayerMultiplier);
    _worldPacket << float(QuickJoinConfig.PlayerFriendValue);
    _worldPacket << float(QuickJoinConfig.PlayerGuildValue);
    _worldPacket << float(QuickJoinConfig.ThrottleInitialThreshold);
    _worldPacket << float(QuickJoinConfig.ThrottleDecayTime);
    _worldPacket << float(QuickJoinConfig.ThrottlePrioritySpike);
    _worldPacket << float(QuickJoinConfig.ThrottleMinThreshold);
    _worldPacket << float(QuickJoinConfig.ThrottlePvPPriorityNormal);
    _worldPacket << float(QuickJoinConfig.ThrottlePvPPriorityLow);
    _worldPacket << float(QuickJoinConfig.ThrottlePvPHonorThreshold);
    _worldPacket << float(QuickJoinConfig.ThrottleLfgListPriorityDefault);
    _worldPacket << float(QuickJoinConfig.ThrottleLfgListPriorityAbove);
    _worldPacket << float(QuickJoinConfig.ThrottleLfgListPriorityBelow);
    _worldPacket << float(QuickJoinConfig.ThrottleLfgListIlvlScalingAbove);
    _worldPacket << float(QuickJoinConfig.ThrottleLfgListIlvlScalingBelow);
    _worldPacket << float(QuickJoinConfig.ThrottleRfPriorityAbove);
    _worldPacket << float(QuickJoinConfig.ThrottleRfIlvlScalingAbove);
    _worldPacket << float(QuickJoinConfig.ThrottleDfMaxItemLevel);
    _worldPacket << float(QuickJoinConfig.ThrottleDfBestPriority);

    if (SessionAlert)
    {
        _worldPacket << int32(SessionAlert->Delay);
        _worldPacket << int32(SessionAlert->Period);
        _worldPacket << int32(SessionAlert->DisplayTime);
    }

    if (RaceClassExpansionLevels)
    {
        _worldPacket << uint32(RaceClassExpansionLevels->size());
        if (!RaceClassExpansionLevels->empty())
            _worldPacket.append(RaceClassExpansionLevels->data(), RaceClassExpansionLevels->size());
    }

    if (EuropaTicketSystemStatus)
    {
        _worldPacket.WriteBit(EuropaTicketSystemStatus->TicketsEnabled);
        _worldPacket.WriteBit(EuropaTicketSystemStatus->BugsEnabled);
        _worldPacket.WriteBit(EuropaTicketSystemStatus->ComplaintsEnabled);
        _worldPacket.WriteBit(EuropaTicketSystemStatus->SuggestionsEnabled);

        _worldPacket << uint32(EuropaTicketSystemStatus->ThrottleState.MaxTries);
        _worldPacket << uint32(EuropaTicketSystemStatus->ThrottleState.PerMilliseconds);
        _worldPacket << uint32(EuropaTicketSystemStatus->ThrottleState.TryCount);
        _worldPacket << uint32(EuropaTicketSystemStatus->ThrottleState.LastResetTimeBeforeNow);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::System::FeatureSystemStatusGlueScreen::Write()
{
    _worldPacket.WriteBit(BpayStoreEnabled);
    _worldPacket.WriteBit(BpayStoreAvailable);
    _worldPacket.WriteBit(BpayStoreDisabledByParentalControls);
    _worldPacket.WriteBit(CharUndeleteEnabled);
    _worldPacket.WriteBit(CommerceSystemEnabled);
    _worldPacket.WriteBit(Unk14);
    _worldPacket.WriteBit(WillKickFromWorld);
    _worldPacket.WriteBit(IsExpansionPreorderInStore);
    _worldPacket.WriteBit(KioskModeEnabled);
    _worldPacket.WriteBit(CompetitiveModeEnabled);
    _worldPacket.WriteBit(false); // not accessed in handler
    _worldPacket.WriteBit(TrialBoostEnabled);
    _worldPacket.WriteBit(TokenBalanceEnabled);
    _worldPacket.WriteBit(LiveRegionCharacterListEnabled);
    _worldPacket.WriteBit(LiveRegionCharacterCopyEnabled);
    _worldPacket.WriteBit(LiveRegionAccountCopyEnabled);
    _worldPacket.FlushBits();

    _worldPacket << int32(TokenPollTimeSeconds);
    _worldPacket << int32(TokenRedeemIndex);
    _worldPacket << int64(TokenBalanceAmount);
    _worldPacket << uint32(BpayStoreProductDeliveryDelay);
    _worldPacket << uint32(UnkInt1);
    _worldPacket << uint32(UnkInt2);
    _worldPacket << uint32(UnkInt3);
    _worldPacket << uint32(UnkInt4);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::System::MOTD::Write()
{
    ASSERT(Text);
    _worldPacket.WriteBits(Text->size(), 4);
    _worldPacket.FlushBits();

    for (std::string const& line : *Text)
    {
        _worldPacket.WriteBits(line.length(), 7);
        _worldPacket.WriteString(line);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::System::SetTimeZoneInformation::Write()
{
    _worldPacket.WriteBits(ServerTimeTZ.length(), 7);
    _worldPacket.WriteBits(GameTimeTZ.length(), 7);
    _worldPacket.WriteString(ServerTimeTZ);
    _worldPacket.WriteString(GameTimeTZ);

    return &_worldPacket;
}
