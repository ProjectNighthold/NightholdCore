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

class sceneTrigger_deathwing_simulator : public SceneTriggerScript
{
public:
    sceneTrigger_deathwing_simulator() : SceneTriggerScript("sceneTrigger_deathwing_simulator") {}

    bool OnTrigger(Player* player, SpellScene const* trigger, std::string type) override
    {
        if (type == "BURN PLAYER")
            player->CastSpell(player, 201184, false);

        return true;
    }
};

class sceneTrigger_circuit_game : public SceneTriggerScript
{
public:
    sceneTrigger_circuit_game() : SceneTriggerScript("sceneTrigger_circuit_game") {}

    bool OnTrigger(Player* player, SpellScene const* trigger, std::string type) override
    {
        if (type == "achievement")
            player->CastSpell(player, 210636, true);

        if (type == "stage")
            if (auto aura = player->GetAuraEffect(200015, EFFECT_1))
                aura->SetAmount(aura->GetAmount() + 1);

        return true;
    }
};

class sceneTrigger_karabor_bombing_run : public SceneTriggerScript
{
public:
    sceneTrigger_karabor_bombing_run() : SceneTriggerScript("sceneTrigger_karabor_bombing_run") {}

    bool OnTrigger(Player* player, SpellScene const* trigger, std::string type) override
    {
        if (type == "Credit")
            player->KilledMonsterCredit(72458);

        if (type == "Teleport")
            player->CastSpell(player, 165484, true);

        return true;
    }
};

void AddSC_scene_scripts()
{
    new sceneTrigger_deathwing_simulator();
    new sceneTrigger_circuit_game();
    new sceneTrigger_karabor_bombing_run();
}

