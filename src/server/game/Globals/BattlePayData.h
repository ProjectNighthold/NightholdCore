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

#ifndef _BATTLE_PAY_DATA_STORE_H
#define _BATTLE_PAY_DATA_STORE_H

#include "BattlePayPackets.h"
#include "BattlePayMgr.h"

struct BattlePayDisplayInfoLocale
{
	StringVector Name1;
	StringVector Name2;
	StringVector Name3;
	StringVector Name4;
};

class BattlePayDataStoreMgr
{
	BattlePayDataStoreMgr();
	~BattlePayDataStoreMgr();

public:
	static BattlePayDataStoreMgr* instance();

	void Initialize();
	std::vector<Battlepay::ProductGroup> const& GetProductGroups() const;
	std::vector<Battlepay::ShopEntry> const& GetShopEntries() const;
	uint32 GetProductGroupId(uint32 productId);
	std::map<uint32, Battlepay::Product> const& GetProducts() const;
	bool ProductExist(uint32 productID) const;
	Battlepay::Product const& GetProduct(uint32 productID) const;
	Battlepay::DisplayInfo const* GetDisplayInfo(uint32 id) const;
	std::vector<WorldPackets::BattlePay::ProductDisplayVisualData> const* GetDisplayInfoVisuals(uint32 id) const;
	Battlepay::ProductGroupLocale const* GetProductGroupLocale(uint32 entry) const;
	BattlePayDisplayInfoLocale const* GetDisplayInfoLocale(uint32 entry) const;

private:
	void LoadProductGroups();
	void LoadProduct();
	void LoadShopEntires();
	void LoadDisplayInfos();
	void LoadDisplayInfoVisuals();
	void LoadProductGroupLocales();
	void LoadDisplayInfoLocales();
};

#define sBattlePayDataStore BattlePayDataStoreMgr::instance()

#endif
