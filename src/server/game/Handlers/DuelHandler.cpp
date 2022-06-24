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

#include "DuelPackets.h"

void WorldSession::HandleDuelResponse(WorldPackets::Duel::DuelResponse& packet)
{
    if (GameObject* arbiter = ObjectAccessor::FindGameObject(packet.ArbiterGUID))
    {
        if (!_player->duel)
            return;

        auto dueler = ObjectAccessor::FindPlayer(_player->duel->opponent);

        if (!dueler)
            return;

        if (_player->duel->arbiter != arbiter->GetGUID())
            return;

        if (packet.Accepted)
        {
            if (_player->duel->state != DUEL_NOT_STARTED || dueler->duel->state != DUEL_NOT_STARTED)
                return;

            if (_player->GetGUID() == _player->duel->initiator)
                return;

            TC_LOG_DEBUG(LOG_FILTER_NETWORKIO, "Player 1 is: %s (%s)", _player->GetGUID().ToString().c_str(), _player->GetName());
            TC_LOG_DEBUG(LOG_FILTER_NETWORKIO, "Player 2 is: %s (%s)", dueler->GetGUID().ToString().c_str(), dueler->GetName());

            _player->SendDuelCountdown(_player->duel->countdownTimer);
            dueler->SendDuelCountdown(dueler->duel->countdownTimer);

            _player->duel->state = DUEL_COUNTDOWN;
            dueler->duel->state = DUEL_COUNTDOWN;

			if (sWorld->getBoolConfig(CONFIG_PLAYER_ALLOW_PVP_TALENTS_ALL_THE_TIME) && _player->getLevel() >= 110 && dueler->getLevel() >= 110)
			{
				if (!_player->HasPvpRulesEnabled())
					_player->EnablePvpRules(false);
				if (!dueler->HasPvpRulesEnabled())
					dueler->EnablePvpRules(false);
			}
			else
			{
				_player->EnablePvpRules();
				dueler->EnablePvpRules();
			}

            if (sWorld->getBoolConfig(CONFIG_IS_TEST_SERVER))
            {
                _player->AddAura(SPELL_PRINCIPLES_OF_WAR, _player);
                dueler->AddAura(SPELL_PRINCIPLES_OF_WAR, dueler);
            }
        }
        else
        {
            // player surrendered in a duel using /forfeit
            if (_player->duel->state == DUEL_STARTED)
            {
                _player->CombatStopWithPets(true);
                dueler->CombatStopWithPets(true);

                _player->CastSpell(GetPlayer(), 7267, true);    // beg
                _player->DuelComplete(DUEL_FINISHED);
                return;
            }

            _player->DuelComplete(DUEL_INTERRUPTED);
        }
    }
}

void WorldSession::HandleCanDuel(WorldPackets::Duel::CanDuel& packet)
{
    Player* dueler = ObjectAccessor::FindPlayer(packet.TargetGUID);
    if (!dueler)
        return;

    if (!_player->IsWithinDistInMap(dueler, TRADE_DISTANCE, false))
        return;

    WorldPackets::Duel::CanDuelResult response;
    response.TargetGUID = packet.TargetGUID;
    response.Result = !dueler->duel;
    SendPacket(response.Write());

    // after this packet client initiated CMSG_CAST_SPELL with known spell CGSpellBook::m_duelSpell
}
