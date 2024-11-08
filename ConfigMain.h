#pragma once
#include "SimpleIni.h"
#include "Setting.h"

struct ConfigMain
{
	float fround(float var)
	{
		float value = (int)(var * 100 + .5);
		return (float)value / 100;
	}

	void WriteConfiguratiton(std::string Path) {
		CSimpleIniA ini;
		ini.SetUnicode();
		SI_Error rc = ini.LoadFile(Path.c_str());
		if (rc < 0)
		{
			std::cout << "File not found";
		};

		ini.SetBoolValue("esp", "0", Setting::TotalEnemy, "Enemy Around");
		ini.SetBoolValue("esp", "1", Setting::BombAlert, "Grenade Warning");
		ini.SetBoolValue("esp", "2", Setting::Item, "Show Items");
		ini.SetBoolValue("esp", "3", Setting::Vehicle, "Show Vehicle");
		ini.SetBoolValue("esp", "4", Setting::Name, "Player Name");
		ini.SetBoolValue("esp", "5", Setting::Health, "Player Health");
		ini.SetBoolValue("esp", "6", Setting::Distance, "Player Distance");
		ini.SetBoolValue("esp", "7", Setting::Box, "Player Box");
		ini.SetBoolValue("esp", "8", Setting::Line, "Player Line");
		ini.SetBoolValue("esp", "9", Setting::Bone, "Player Bone");
		ini.SetBoolValue("esp", "10", Setting::country, "Player Country");
		ini.SetBoolValue("esp", "11", Setting::TeamId, "Player Team ID");
		ini.SetLongValue("esp", "12", Setting::ItemSize, "Item Size");
		ini.SetLongValue("esp", "13", Setting::carsize, "Vehicle Size");
		ini.SetLongValue("esp", "14", Setting::playernamesize, "Player Name Size");
		ini.SetLongValue("esp", "17", Setting::GranadeWarningSize, "Grenade Warning Size");
		ini.SetLongValue("esp", "20", Setting::TotalEnemySize, "TotalEnemySize");
		ini.SetLongValue("esp", "21", Setting::G_warningType, "G_warningType");

		ini.SetLongValue("esp", "38", Setting::DistanceSize, "DistanceSize");
		ini.SetLongValue("esp", "39", Setting::MagicPositionKey, "MagicPositionKey");
		ini.SetLongValue("esp", "40", Setting::EnableMagicKey, "EnableMagicKey");
		ini.SetLongValue("esp", "41", Setting::AimbotKey, "AimbotKey");
		ini.SetLongValue("esp", "42", Setting::Aimspeed, "Aimspeed");
		ini.SetLongValue("esp", "43", Setting::Magic360deg, "Magic360deg");
		ini.SetLongValue("esp", "44", Setting::MidMagicButton, "MidMagicButton");

		ini.SetBoolValue("esp", "22", Setting::G_Warning_Frag, "G_Warning_Frag");
		ini.SetBoolValue("esp", "23", Setting::G_Warning_Molotof, "G_Warning_Molotof");
		ini.SetBoolValue("esp", "24", Setting::G_Warning_Smoke, "G_Warning_Smoke");

		ini.SetBoolValue("esp", "25", Setting::BoneColorSameAsLineBool, "BoneColorSameAsLineBool");
		ini.SetBoolValue("esp", "26", Setting::enemyIndicator, "enemyIndicator");
		ini.SetBoolValue("esp", "27", Setting::EnemyStatus, "EnemyStatus");
		ini.SetLongValue("esp", "28", Setting::carDist, "carDist");


		ini.SetBoolValue("esp", "29", Setting::radar, "radar");
		ini.SetLongValue("esp", "30", Setting::RadarWidth, "RadarWidth");
		ini.SetLongValue("esp", "31", Setting::RadarLength, "RadarLength");


		ini.SetBoolValue("esp", "32", Setting::fovcircle, "fovcircle");
		ini.SetLongValue("esp", "33", Setting::fovcircleredus, "fovcircleredus");


		ini.SetBoolValue("esp", "34", Setting::MagicBullet, "MagicBullet");
		ini.SetBoolValue("esp", "35", Setting::Aimbot, "Aimbot");
		ini.SetBoolValue("esp", "36", Setting::deadbox, "deadbox");
		ini.SetBoolValue("esp", "37", Setting::deadboxBG, "deadboxBG");

		//ini.SetLongValue("esp", "18", PlayerWeaponSize, "PlayerWeapon Size");
		ini.SetBoolValue("esp", "19", Setting::PlayerWeapon, "PlayerWeapon");


		ini.SetLongValue("esp", "15", Setting::redzoneSize, "RedZone Size");
		ini.SetBoolValue("esp", "16", Setting::Redzone, "Redzone");

		ini.SetLongValue("esp", "45", Setting::gameInfo, "gameInfo");
		ini.SetLongValue("esp", "46", Setting::MAgicline, "MAgicline");

		for (int i = 0; i < 4; i++) { std::string str = "PlayerNameColor"; ini.SetLongValue("PlayerNameColor", str.append(std::to_string(i)).c_str(), fround(Setting::PlayerNameColor[i] * 255)); }
		for (int i = 0; i < 4; i++) { std::string str = "fovcirclecolor"; ini.SetLongValue("fovcirclecolor", str.append(std::to_string(i)).c_str(), fround(Setting::fovcirclecolor[i] * 255)); }
		for (int i = 0; i < 4; i++) { std::string str = "VehhilceColor"; ini.SetLongValue("VehhilceColor", str.append(std::to_string(i)).c_str(), fround(Setting::VehhilceColor[i] * 255)); }
		for (int i = 0; i < 4; i++) { std::string str = "VehhilceUsedColor"; ini.SetLongValue("VehhilceUsedColor", str.append(std::to_string(i)).c_str(), fround(Setting::VehhilceUsedColor[i] * 255)); }
		for (int i = 0; i < 4; i++) { std::string str = "hpFuel"; ini.SetLongValue("hpFuel", str.append(std::to_string(i)).c_str(), fround(Setting::hpFuel[i] * 255)); }


		ini.SetLongValue("RedZoneColor", "1", Setting::RedZoneColor[0], "RedZoneColor");
		ini.SetLongValue("RedZoneColor", "2", Setting::RedZoneColor[1], "RedZoneColor");
		ini.SetLongValue("RedZoneColor", "3", Setting::RedZoneColor[2], "RedZoneColor");
		ini.SetLongValue("RedZoneColor", "4", Setting::RedZoneColor[3], "RedZoneColor");

		ini.SetLongValue("G_warningColor", "1", Setting::G_warningColor[0], "G_warningColor");
		ini.SetLongValue("G_warningColor", "2", Setting::G_warningColor[1], "G_warningColor");
		ini.SetLongValue("G_warningColor", "3", Setting::G_warningColor[2], "G_warningColor");
		ini.SetLongValue("G_warningColor", "4", Setting::G_warningColor[3], "G_warningColor");

		ini.SetLongValue("TotalEnemyColor", "1", Setting::TotalEnemyColor[0], "TotalEnemyColor");
		ini.SetLongValue("TotalEnemyColor", "2", Setting::TotalEnemyColor[1], "TotalEnemyColor");
		ini.SetLongValue("TotalEnemyColor", "3", Setting::TotalEnemyColor[2], "TotalEnemyColor");
		ini.SetLongValue("TotalEnemyColor", "4", Setting::TotalEnemyColor[3], "TotalEnemyColor");

		ini.SetLongValue("BoxColor", "1", Setting::BoxColor[0], "Box Color");
		ini.SetLongValue("BoxColor", "2", Setting::BoxColor[1], "Box Color");
		ini.SetLongValue("BoxColor", "3", Setting::BoxColor[2], "Box Color");
		ini.SetLongValue("BoxColor", "4", Setting::BoxColor[3], "Box Color");

		ini.SetLongValue("BoneColor", "1", Setting::BoneColor[0], "Bone Color");
		ini.SetLongValue("BoneColor", "2", Setting::BoneColor[1], "Bone Color");
		ini.SetLongValue("BoneColor", "3", Setting::BoneColor[2], "Bone Color");
		ini.SetLongValue("BoneColor", "4", Setting::BoneColor[3], "Bone Color");

		ini.SetBoolValue("Setting::Esp_Item_AKM", "0", Setting::Esp_Item_AKM, "Setting::Esp_Item_AKM");
		ini.SetDoubleValue("Setting::Esp_Item_AKM_Color", "1", Setting::Esp_Item_AKM_Color[0], "Setting::Esp_Item_AKM_Color");
		ini.SetDoubleValue("Setting::Esp_Item_AKM_Color", "2", Setting::Esp_Item_AKM_Color[1], "Setting::Esp_Item_AKM_Color");
		ini.SetDoubleValue("Setting::Esp_Item_AKM_Color", "3", Setting::Esp_Item_AKM_Color[2], "Setting::Esp_Item_AKM_Color");
		ini.SetDoubleValue("Setting::Esp_Item_AKM_Color", "4", Setting::Esp_Item_AKM_Color[3], "Setting::Esp_Item_AKM_Color");

		ini.SetBoolValue("Setting::Esp_Item_M762", "0", Setting::Esp_Item_M762, "Setting::Esp_Item_M762");
		ini.SetDoubleValue("Setting::Esp_Item_M762_Color", "1", Setting::Esp_Item_M762_Color[0], "Setting::Esp_Item_M762_Color");
		ini.SetDoubleValue("Setting::Esp_Item_M762_Color", "2", Setting::Esp_Item_M762_Color[1], "Setting::Esp_Item_M762_Color");
		ini.SetDoubleValue("Setting::Esp_Item_M762_Color", "3", Setting::Esp_Item_M762_Color[2], "Setting::Esp_Item_M762_Color");
		ini.SetDoubleValue("Setting::Esp_Item_M762_Color", "4", Setting::Esp_Item_M762_Color[3], "Setting::Esp_Item_M762_Color");

		ini.SetBoolValue("Setting::Esp_Item_PlayerDeadBox", "0", Setting::Esp_Item_PlayerDeadBox, "Setting::Esp_Item_PlayerDeadBox");
		ini.SetDoubleValue("Setting::Esp_Item_PlayerDeadBox_Color", "1", Setting::Esp_Item_PlayerDeadBox_Color[0], "Setting::Esp_Item_PlayerDeadBox_Color");
		ini.SetDoubleValue("Setting::Esp_Item_PlayerDeadBox_Color", "2", Setting::Esp_Item_PlayerDeadBox_Color[1], "Setting::Esp_Item_PlayerDeadBox_Color");
		ini.SetDoubleValue("Setting::Esp_Item_PlayerDeadBox_Color", "3", Setting::Esp_Item_PlayerDeadBox_Color[2], "Setting::Esp_Item_PlayerDeadBox_Color");
		ini.SetDoubleValue("Setting::Esp_Item_PlayerDeadBox_Color", "4", Setting::Esp_Item_PlayerDeadBox_Color[3], "Setting::Esp_Item_PlayerDeadBox_Color");

		ini.SetBoolValue("Setting::Esp_Item_Groza", "0", Setting::Esp_Item_Groza, "Setting::Esp_Item_Groza");
		ini.SetDoubleValue("Setting::Esp_Item_Groza_Color", "1", Setting::Esp_Item_Groza_Color[0], "Setting::Esp_Item_Groza_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Groza_Color", "2", Setting::Esp_Item_Groza_Color[1], "Setting::Esp_Item_Groza_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Groza_Color", "3", Setting::Esp_Item_Groza_Color[2], "Setting::Esp_Item_Groza_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Groza_Color", "4", Setting::Esp_Item_Groza_Color[3], "Setting::Esp_Item_Groza_Color");

		ini.SetBoolValue("Setting::Esp_Item_Mk47Mutant", "0", Setting::Esp_Item_Mk47Mutant, "Setting::Esp_Item_Mk47Mutant");
		ini.SetDoubleValue("Setting::Esp_Item_Mk47Mutant_Color", "1", Setting::Esp_Item_Mk47Mutant_Color[0], "Setting::Esp_Item_Mk47Mutant_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Mk47Mutant_Color", "2", Setting::Esp_Item_Mk47Mutant_Color[1], "Setting::Esp_Item_Mk47Mutant_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Mk47Mutant_Color", "3", Setting::Esp_Item_Mk47Mutant_Color[2], "Setting::Esp_Item_Mk47Mutant_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Mk47Mutant_Color", "4", Setting::Esp_Item_Mk47Mutant_Color[3], "Setting::Esp_Item_Mk47Mutant_Color");

		ini.SetBoolValue("Setting::Esp_Item_DP28", "0", Setting::Esp_Item_DP28, "Setting::Esp_Item_DP28");
		ini.SetDoubleValue("Setting::Esp_Item_DP28_Color", "1", Setting::Esp_Item_DP28_Color[0], "Setting::Esp_Item_DP28_Color");
		ini.SetDoubleValue("Setting::Esp_Item_DP28_Color", "2", Setting::Esp_Item_DP28_Color[1], "Setting::Esp_Item_DP28_Color");
		ini.SetDoubleValue("Setting::Esp_Item_DP28_Color", "3", Setting::Esp_Item_DP28_Color[2], "Setting::Esp_Item_DP28_Color");
		ini.SetDoubleValue("Setting::Esp_Item_DP28_Color", "4", Setting::Esp_Item_DP28_Color[3], "Setting::Esp_Item_DP28_Color");

		ini.SetBoolValue("Setting::Esp_Item_SCARL", "0", Setting::Esp_Item_SCARL, "Setting::Esp_Item_SCARL");
		ini.SetDoubleValue("Setting::Esp_Item_SCARL_Color", "1", Setting::Esp_Item_SCARL_Color[0], "Setting::Esp_Item_SCARL_Color");
		ini.SetDoubleValue("Setting::Esp_Item_SCARL_Color", "2", Setting::Esp_Item_SCARL_Color[1], "Setting::Esp_Item_SCARL_Color");
		ini.SetDoubleValue("Setting::Esp_Item_SCARL_Color", "3", Setting::Esp_Item_SCARL_Color[2], "Setting::Esp_Item_SCARL_Color");
		ini.SetDoubleValue("Setting::Esp_Item_SCARL_Color", "4", Setting::Esp_Item_SCARL_Color[3], "Setting::Esp_Item_SCARL_Color");

		ini.SetBoolValue("Setting::Esp_Item_M416", "0", Setting::Esp_Item_M416, "Setting::Esp_Item_M416");
		ini.SetDoubleValue("Setting::Esp_Item_M416_Color", "1", Setting::Esp_Item_M416_Color[0], "Setting::Esp_Item_M416_Color");
		ini.SetDoubleValue("Setting::Esp_Item_M416_Color", "2", Setting::Esp_Item_M416_Color[1], "Setting::Esp_Item_M416_Color");
		ini.SetDoubleValue("Setting::Esp_Item_M416_Color", "3", Setting::Esp_Item_M416_Color[2], "Setting::Esp_Item_M416_Color");
		ini.SetDoubleValue("Setting::Esp_Item_M416_Color", "4", Setting::Esp_Item_M416_Color[3], "Setting::Esp_Item_M416_Color");

		ini.SetBoolValue("Setting::Esp_Item_AUG", "0", Setting::Esp_Item_AUG, "Setting::Esp_Item_AUG");
		ini.SetDoubleValue("Setting::Esp_Item_AUG_Color", "1", Setting::Esp_Item_AUG_Color[0], "Setting::Esp_Item_AUG_Color");
		ini.SetDoubleValue("Setting::Esp_Item_AUG_Color", "2", Setting::Esp_Item_AUG_Color[1], "Setting::Esp_Item_AUG_Color");
		ini.SetDoubleValue("Setting::Esp_Item_AUG_Color", "3", Setting::Esp_Item_AUG_Color[2], "Setting::Esp_Item_AUG_Color");
		ini.SetDoubleValue("Setting::Esp_Item_AUG_Color", "4", Setting::Esp_Item_AUG_Color[3], "Setting::Esp_Item_AUG_Color");

		ini.SetBoolValue("Setting::Esp_Item_M249", "0", Setting::Esp_Item_M249, "Setting::Esp_Item_M249");
		ini.SetDoubleValue("Setting::Esp_Item_M249_Color", "1", Setting::Esp_Item_M249_Color[0], "Setting::Esp_Item_M249_Color");
		ini.SetDoubleValue("Setting::Esp_Item_M249_Color", "2", Setting::Esp_Item_M249_Color[1], "Setting::Esp_Item_M249_Color");
		ini.SetDoubleValue("Setting::Esp_Item_M249_Color", "3", Setting::Esp_Item_M249_Color[2], "Setting::Esp_Item_M249_Color");
		ini.SetDoubleValue("Setting::Esp_Item_M249_Color", "4", Setting::Esp_Item_M249_Color[3], "Setting::Esp_Item_M249_Color");

		ini.SetBoolValue("Setting::Esp_Item_M16A4", "0", Setting::Esp_Item_M16A4, "Setting::Esp_Item_M16A4");
		ini.SetDoubleValue("Setting::Esp_Item_M16A4_Color", "1", Setting::Esp_Item_M16A4_Color[0], "Setting::Esp_Item_M16A4_Color");
		ini.SetDoubleValue("Setting::Esp_Item_M16A4_Color", "2", Setting::Esp_Item_M16A4_Color[1], "Setting::Esp_Item_M16A4_Color");
		ini.SetDoubleValue("Setting::Esp_Item_M16A4_Color", "3", Setting::Esp_Item_M16A4_Color[2], "Setting::Esp_Item_M16A4_Color");
		ini.SetDoubleValue("Setting::Esp_Item_M16A4_Color", "4", Setting::Esp_Item_M16A4_Color[3], "Setting::Esp_Item_M16A4_Color");

		ini.SetBoolValue("Setting::Esp_Item_G36C", "0", Setting::Esp_Item_G36C, "Setting::Esp_Item_G36C");
		ini.SetDoubleValue("Setting::Esp_Item_G36C_Color", "1", Setting::Esp_Item_G36C_Color[0], "Setting::Esp_Item_G36C_Color");
		ini.SetDoubleValue("Setting::Esp_Item_G36C_Color", "2", Setting::Esp_Item_G36C_Color[1], "Setting::Esp_Item_G36C_Color");
		ini.SetDoubleValue("Setting::Esp_Item_G36C_Color", "3", Setting::Esp_Item_G36C_Color[2], "Setting::Esp_Item_G36C_Color");
		ini.SetDoubleValue("Setting::Esp_Item_G36C_Color", "4", Setting::Esp_Item_G36C_Color[3], "Setting::Esp_Item_G36C_Color");

		ini.SetBoolValue("Setting::Esp_Item_QBZ", "0", Setting::Esp_Item_QBZ, "Setting::Esp_Item_QBZ");
		ini.SetDoubleValue("Setting::Esp_Item_QBZ_Color", "1", Setting::Esp_Item_QBZ_Color[0], "Setting::Esp_Item_QBZ_Color");
		ini.SetDoubleValue("Setting::Esp_Item_QBZ_Color", "2", Setting::Esp_Item_QBZ_Color[1], "Setting::Esp_Item_QBZ_Color");
		ini.SetDoubleValue("Setting::Esp_Item_QBZ_Color", "3", Setting::Esp_Item_QBZ_Color[2], "Setting::Esp_Item_QBZ_Color");
		ini.SetDoubleValue("Setting::Esp_Item_QBZ_Color", "4", Setting::Esp_Item_QBZ_Color[3], "Setting::Esp_Item_QBZ_Color");

		ini.SetBoolValue("Setting::Esp_Item_QBU", "0", Setting::Esp_Item_QBU, "Setting::Esp_Item_QBU");
		ini.SetDoubleValue("Setting::Esp_Item_QBU_Color", "1", Setting::Esp_Item_QBU_Color[0], "Setting::Esp_Item_QBU_Color");
		ini.SetDoubleValue("Setting::Esp_Item_QBU_Color", "2", Setting::Esp_Item_QBU_Color[1], "Setting::Esp_Item_QBU_Color");
		ini.SetDoubleValue("Setting::Esp_Item_QBU_Color", "3", Setting::Esp_Item_QBU_Color[2], "Setting::Esp_Item_QBU_Color");
		ini.SetDoubleValue("Setting::Esp_Item_QBU_Color", "4", Setting::Esp_Item_QBU_Color[3], "Setting::Esp_Item_QBU_Color");

		ini.SetBoolValue("Setting::Esp_Item_SLR", "0", Setting::Esp_Item_SLR, "Setting::Esp_Item_SLR");
		ini.SetDoubleValue("Setting::Esp_Item_SLR_Color", "1", Setting::Esp_Item_SLR_Color[0], "Setting::Esp_Item_SLR_Color");
		ini.SetDoubleValue("Setting::Esp_Item_SLR_Color", "2", Setting::Esp_Item_SLR_Color[1], "Setting::Esp_Item_SLR_Color");
		ini.SetDoubleValue("Setting::Esp_Item_SLR_Color", "3", Setting::Esp_Item_SLR_Color[2], "Setting::Esp_Item_SLR_Color");
		ini.SetDoubleValue("Setting::Esp_Item_SLR_Color", "4", Setting::Esp_Item_SLR_Color[3], "Setting::Esp_Item_SLR_Color");

		ini.SetBoolValue("Setting::Esp_Item_SKS", "0", Setting::Esp_Item_SKS, "Setting::Esp_Item_SKS");
		ini.SetDoubleValue("Setting::Esp_Item_SKS_Color", "1", Setting::Esp_Item_SKS_Color[0], "Setting::Esp_Item_SKS_Color");
		ini.SetDoubleValue("Setting::Esp_Item_SKS_Color", "2", Setting::Esp_Item_SKS_Color[1], "Setting::Esp_Item_SKS_Color");
		ini.SetDoubleValue("Setting::Esp_Item_SKS_Color", "3", Setting::Esp_Item_SKS_Color[2], "Setting::Esp_Item_SKS_Color");
		ini.SetDoubleValue("Setting::Esp_Item_SKS_Color", "4", Setting::Esp_Item_SKS_Color[3], "Setting::Esp_Item_SKS_Color");

		ini.SetBoolValue("Setting::Esp_Item_Mini14", "0", Setting::Esp_Item_Mini14, "Setting::Esp_Item_Mini14");
		ini.SetDoubleValue("Setting::Esp_Item_Mini14_Color", "1", Setting::Esp_Item_Mini14_Color[0], "Setting::Esp_Item_Mini14_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Mini14_Color", "2", Setting::Esp_Item_Mini14_Color[1], "Setting::Esp_Item_Mini14_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Mini14_Color", "3", Setting::Esp_Item_Mini14_Color[2], "Setting::Esp_Item_Mini14_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Mini14_Color", "4", Setting::Esp_Item_Mini14_Color[3], "Setting::Esp_Item_Mini14_Color");

		ini.SetBoolValue("Setting::Esp_Item_M24", "0", Setting::Esp_Item_M24, "Setting::Esp_Item_M24");
		ini.SetDoubleValue("Setting::Esp_Item_M24_Color", "1", Setting::Esp_Item_M24_Color[0], "Setting::Esp_Item_M24_Color");
		ini.SetDoubleValue("Setting::Esp_Item_M24_Color", "2", Setting::Esp_Item_M24_Color[1], "Setting::Esp_Item_M24_Color");
		ini.SetDoubleValue("Setting::Esp_Item_M24_Color", "3", Setting::Esp_Item_M24_Color[2], "Setting::Esp_Item_M24_Color");
		ini.SetDoubleValue("Setting::Esp_Item_M24_Color", "4", Setting::Esp_Item_M24_Color[3], "Setting::Esp_Item_M24_Color");

		ini.SetBoolValue("Setting::Esp_Item_Kar98k", "0", Setting::Esp_Item_Kar98k, "Setting::Esp_Item_Kar98k");
		ini.SetDoubleValue("Setting::Esp_Item_Kar98k_Color", "1", Setting::Esp_Item_Kar98k_Color[0], "Setting::Esp_Item_Kar98k_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Kar98k_Color", "2", Setting::Esp_Item_Kar98k_Color[1], "Setting::Esp_Item_Kar98k_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Kar98k_Color", "3", Setting::Esp_Item_Kar98k_Color[2], "Setting::Esp_Item_Kar98k_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Kar98k_Color", "4", Setting::Esp_Item_Kar98k_Color[3], "Setting::Esp_Item_Kar98k_Color");

		ini.SetBoolValue("Setting::Esp_Item_AWM", "0", Setting::Esp_Item_AWM, "Setting::Esp_Item_AWM");
		ini.SetDoubleValue("Setting::Esp_Item_AWM_Color", "1", Setting::Esp_Item_AWM_Color[0], "Setting::Esp_Item_AWM_Color");
		ini.SetDoubleValue("Setting::Esp_Item_AWM_Color", "2", Setting::Esp_Item_AWM_Color[1], "Setting::Esp_Item_AWM_Color");
		ini.SetDoubleValue("Setting::Esp_Item_AWM_Color", "3", Setting::Esp_Item_AWM_Color[2], "Setting::Esp_Item_AWM_Color");
		ini.SetDoubleValue("Setting::Esp_Item_AWM_Color", "4", Setting::Esp_Item_AWM_Color[3], "Setting::Esp_Item_AWM_Color");

		ini.SetBoolValue("Setting::Esp_Item_Crossbow", "0", Setting::Esp_Item_Crossbow, "Setting::Esp_Item_Crossbow");
		ini.SetDoubleValue("Setting::Esp_Item_Crossbow_Color", "1", Setting::Esp_Item_Crossbow_Color[0], "Setting::Esp_Item_Crossbow_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Crossbow_Color", "2", Setting::Esp_Item_Crossbow_Color[1], "Setting::Esp_Item_Crossbow_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Crossbow_Color", "3", Setting::Esp_Item_Crossbow_Color[2], "Setting::Esp_Item_Crossbow_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Crossbow_Color", "4", Setting::Esp_Item_Crossbow_Color[3], "Setting::Esp_Item_Crossbow_Color");

		ini.SetBoolValue("Setting::Esp_Item_PP19", "0", Setting::Esp_Item_PP19, "Setting::Esp_Item_PP19");
		ini.SetDoubleValue("Setting::Esp_Item_PP19_Color", "1", Setting::Esp_Item_PP19_Color[0], "Setting::Esp_Item_PP19_Color");
		ini.SetDoubleValue("Setting::Esp_Item_PP19_Color", "2", Setting::Esp_Item_PP19_Color[1], "Setting::Esp_Item_PP19_Color");
		ini.SetDoubleValue("Setting::Esp_Item_PP19_Color", "3", Setting::Esp_Item_PP19_Color[2], "Setting::Esp_Item_PP19_Color");
		ini.SetDoubleValue("Setting::Esp_Item_PP19_Color", "4", Setting::Esp_Item_PP19_Color[3], "Setting::Esp_Item_PP19_Color");

		ini.SetBoolValue("Setting::Esp_Item_TommyGun", "0", Setting::Esp_Item_TommyGun, "Setting::Esp_Item_TommyGun");
		ini.SetDoubleValue("Setting::Esp_Item_TommyGun_Color", "1", Setting::Esp_Item_TommyGun_Color[0], "Setting::Esp_Item_TommyGun_Color");
		ini.SetDoubleValue("Setting::Esp_Item_TommyGun_Color", "2", Setting::Esp_Item_TommyGun_Color[1], "Setting::Esp_Item_TommyGun_Color");
		ini.SetDoubleValue("Setting::Esp_Item_TommyGun_Color", "3", Setting::Esp_Item_TommyGun_Color[2], "Setting::Esp_Item_TommyGun_Color");
		ini.SetDoubleValue("Setting::Esp_Item_TommyGun_Color", "4", Setting::Esp_Item_TommyGun_Color[3], "Setting::Esp_Item_TommyGun_Color");

		ini.SetBoolValue("Setting::Esp_Item_MP5K", "0", Setting::Esp_Item_MP5K, "Setting::Esp_Item_MP5K");
		ini.SetDoubleValue("Setting::Esp_Item_MP5K_Color", "1", Setting::Esp_Item_MP5K_Color[0], "Setting::Esp_Item_MP5K_Color");
		ini.SetDoubleValue("Setting::Esp_Item_MP5K_Color", "2", Setting::Esp_Item_MP5K_Color[1], "Setting::Esp_Item_MP5K_Color");
		ini.SetDoubleValue("Setting::Esp_Item_MP5K_Color", "3", Setting::Esp_Item_MP5K_Color[2], "Setting::Esp_Item_MP5K_Color");
		ini.SetDoubleValue("Setting::Esp_Item_MP5K_Color", "4", Setting::Esp_Item_MP5K_Color[3], "Setting::Esp_Item_MP5K_Color");

		ini.SetBoolValue("Setting::Esp_Item_UMP9", "0", Setting::Esp_Item_UMP9, "Setting::Esp_Item_UMP9");
		ini.SetDoubleValue("Setting::Esp_Item_UMP9_Color", "1", Setting::Esp_Item_UMP9_Color[0], "Setting::Esp_Item_UMP9_Color");
		ini.SetDoubleValue("Setting::Esp_Item_UMP9_Color", "2", Setting::Esp_Item_UMP9_Color[1], "Setting::Esp_Item_UMP9_Color");
		ini.SetDoubleValue("Setting::Esp_Item_UMP9_Color", "3", Setting::Esp_Item_UMP9_Color[2], "Setting::Esp_Item_UMP9_Color");
		ini.SetDoubleValue("Setting::Esp_Item_UMP9_Color", "4", Setting::Esp_Item_UMP9_Color[3], "Setting::Esp_Item_UMP9_Color");

		ini.SetBoolValue("Setting::Esp_Item_Vector", "0", Setting::Esp_Item_Vector, "Setting::Esp_Item_Vector");
		ini.SetDoubleValue("Setting::Esp_Item_Vector_Color", "1", Setting::Esp_Item_Vector_Color[0], "Setting::Esp_Item_Vector_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Vector_Color", "2", Setting::Esp_Item_Vector_Color[1], "Setting::Esp_Item_Vector_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Vector_Color", "3", Setting::Esp_Item_Vector_Color[2], "Setting::Esp_Item_Vector_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Vector_Color", "4", Setting::Esp_Item_Vector_Color[3], "Setting::Esp_Item_Vector_Color");

		ini.SetBoolValue("Setting::Esp_Item_Uzi", "0", Setting::Esp_Item_Uzi, "Setting::Esp_Item_Uzi");
		ini.SetDoubleValue("Setting::Esp_Item_Uzi_Color", "1", Setting::Esp_Item_Uzi_Color[0], "Setting::Esp_Item_Uzi_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Uzi_Color", "2", Setting::Esp_Item_Uzi_Color[1], "Setting::Esp_Item_Uzi_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Uzi_Color", "3", Setting::Esp_Item_Uzi_Color[2], "Setting::Esp_Item_Uzi_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Uzi_Color", "4", Setting::Esp_Item_Uzi_Color[3], "Setting::Esp_Item_Uzi_Color");

		ini.SetBoolValue("Setting::Esp_Item_300Magnum", "0", Setting::Esp_Item_300Magnum, "Setting::Esp_Item_300Magnum");
		ini.SetDoubleValue("Setting::Esp_Item_300Magnum_Color", "1", Setting::Esp_Item_300Magnum_Color[0], "Setting::Esp_Item_300Magnum_Color");
		ini.SetDoubleValue("Setting::Esp_Item_300Magnum_Color", "2", Setting::Esp_Item_300Magnum_Color[1], "Setting::Esp_Item_300Magnum_Color");
		ini.SetDoubleValue("Setting::Esp_Item_300Magnum_Color", "3", Setting::Esp_Item_300Magnum_Color[2], "Setting::Esp_Item_300Magnum_Color");
		ini.SetDoubleValue("Setting::Esp_Item_300Magnum_Color", "4", Setting::Esp_Item_300Magnum_Color[3], "Setting::Esp_Item_300Magnum_Color");

		ini.SetBoolValue("Setting::Esp_Item_762mm", "0", Setting::Esp_Item_762mm, "Setting::Esp_Item_762mm");
		ini.SetDoubleValue("Setting::Esp_Item_762mm_Color", "1", Setting::Esp_Item_762mm_Color[0], "Setting::Esp_Item_762mm_Color");
		ini.SetDoubleValue("Setting::Esp_Item_762mm_Color", "2", Setting::Esp_Item_762mm_Color[1], "Setting::Esp_Item_762mm_Color");
		ini.SetDoubleValue("Setting::Esp_Item_762mm_Color", "3", Setting::Esp_Item_762mm_Color[2], "Setting::Esp_Item_762mm_Color");
		ini.SetDoubleValue("Setting::Esp_Item_762mm_Color", "4", Setting::Esp_Item_762mm_Color[3], "Setting::Esp_Item_762mm_Color");

		ini.SetBoolValue("Setting::Esp_Item_556mm", "0", Setting::Esp_Item_556mm, "Setting::Esp_Item_556mm");
		ini.SetDoubleValue("Setting::Esp_Item_556mm_Color", "1", Setting::Esp_Item_556mm_Color[0], "Setting::Esp_Item_556mm_Color");
		ini.SetDoubleValue("Setting::Esp_Item_556mm_Color", "2", Setting::Esp_Item_556mm_Color[1], "Setting::Esp_Item_556mm_Color");
		ini.SetDoubleValue("Setting::Esp_Item_556mm_Color", "3", Setting::Esp_Item_556mm_Color[2], "Setting::Esp_Item_556mm_Color");
		ini.SetDoubleValue("Setting::Esp_Item_556mm_Color", "4", Setting::Esp_Item_556mm_Color[3], "Setting::Esp_Item_556mm_Color");

		ini.SetBoolValue("Setting::Esp_Item_9mm", "0", Setting::Esp_Item_9mm, "Setting::Esp_Item_9mm");
		ini.SetDoubleValue("Setting::Esp_Item_9mm_Color", "1", Setting::Esp_Item_9mm_Color[0], "Setting::Esp_Item_9mm_Color");
		ini.SetDoubleValue("Setting::Esp_Item_9mm_Color", "2", Setting::Esp_Item_9mm_Color[1], "Setting::Esp_Item_9mm_Color");
		ini.SetDoubleValue("Setting::Esp_Item_9mm_Color", "3", Setting::Esp_Item_9mm_Color[2], "Setting::Esp_Item_9mm_Color");
		ini.SetDoubleValue("Setting::Esp_Item_9mm_Color", "4", Setting::Esp_Item_9mm_Color[3], "Setting::Esp_Item_9mm_Color");

		ini.SetBoolValue("Setting::Esp_Item_45ACP", "0", Setting::Esp_Item_45ACP, "Setting::Esp_Item_45ACP");
		ini.SetDoubleValue("Setting::Esp_Item_45ACP_Color", "1", Setting::Esp_Item_45ACP_Color[0], "Setting::Esp_Item_45ACP_Color");
		ini.SetDoubleValue("Setting::Esp_Item_45ACP_Color", "2", Setting::Esp_Item_45ACP_Color[1], "Setting::Esp_Item_45ACP_Color");
		ini.SetDoubleValue("Setting::Esp_Item_45ACP_Color", "3", Setting::Esp_Item_45ACP_Color[2], "Setting::Esp_Item_45ACP_Color");
		ini.SetDoubleValue("Setting::Esp_Item_45ACP_Color", "4", Setting::Esp_Item_45ACP_Color[3], "Setting::Esp_Item_45ACP_Color");

		ini.SetBoolValue("Setting::Esp_Item_Holo", "0", Setting::Esp_Item_Holo, "Setting::Esp_Item_Holo");
		ini.SetDoubleValue("Setting::Esp_Item_Holo_Color", "1", Setting::Esp_Item_Holo_Color[0], "Setting::Esp_Item_Holo_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Holo_Color", "2", Setting::Esp_Item_Holo_Color[1], "Setting::Esp_Item_Holo_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Holo_Color", "3", Setting::Esp_Item_Holo_Color[2], "Setting::Esp_Item_Holo_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Holo_Color", "4", Setting::Esp_Item_Holo_Color[3], "Setting::Esp_Item_Holo_Color");

		ini.SetBoolValue("Setting::Esp_Item_RedDot", "0", Setting::Esp_Item_RedDot, "Setting::Esp_Item_RedDot");
		ini.SetDoubleValue("Setting::Esp_Item_RedDot_Color", "1", Setting::Esp_Item_RedDot_Color[0], "Setting::Esp_Item_RedDot_Color");
		ini.SetDoubleValue("Setting::Esp_Item_RedDot_Color", "2", Setting::Esp_Item_RedDot_Color[1], "Setting::Esp_Item_RedDot_Color");
		ini.SetDoubleValue("Setting::Esp_Item_RedDot_Color", "3", Setting::Esp_Item_RedDot_Color[2], "Setting::Esp_Item_RedDot_Color");
		ini.SetDoubleValue("Setting::Esp_Item_RedDot_Color", "4", Setting::Esp_Item_RedDot_Color[3], "Setting::Esp_Item_RedDot_Color");

		ini.SetBoolValue("Setting::Esp_Item_x2", "0", Setting::Esp_Item_x2, "Setting::Esp_Item_x2");
		ini.SetDoubleValue("Setting::Esp_Item_x2_Color", "1", Setting::Esp_Item_x2_Color[0], "Setting::Esp_Item_x2_Color");
		ini.SetDoubleValue("Setting::Esp_Item_x2_Color", "2", Setting::Esp_Item_x2_Color[1], "Setting::Esp_Item_x2_Color");
		ini.SetDoubleValue("Setting::Esp_Item_x2_Color", "3", Setting::Esp_Item_x2_Color[2], "Setting::Esp_Item_x2_Color");
		ini.SetDoubleValue("Setting::Esp_Item_x2_Color", "4", Setting::Esp_Item_x2_Color[3], "Setting::Esp_Item_x2_Color");

		ini.SetBoolValue("Setting::Esp_Item_x3", "0", Setting::Esp_Item_x3, "Setting::Esp_Item_x3");
		ini.SetDoubleValue("Setting::Esp_Item_x3_Color", "1", Setting::Esp_Item_x3_Color[0], "Setting::Esp_Item_x3_Color");
		ini.SetDoubleValue("Setting::Esp_Item_x3_Color", "2", Setting::Esp_Item_x3_Color[1], "Setting::Esp_Item_x3_Color");
		ini.SetDoubleValue("Setting::Esp_Item_x3_Color", "3", Setting::Esp_Item_x3_Color[2], "Setting::Esp_Item_x3_Color");
		ini.SetDoubleValue("Setting::Esp_Item_x3_Color", "4", Setting::Esp_Item_x3_Color[3], "Setting::Esp_Item_x3_Color");

		ini.SetBoolValue("Setting::Esp_Item_x4", "0", Setting::Esp_Item_x4, "Setting::Esp_Item_x4");
		ini.SetDoubleValue("Setting::Esp_Item_x4_Color", "1", Setting::Esp_Item_x4_Color[0], "Setting::Esp_Item_x4_Color");
		ini.SetDoubleValue("Setting::Esp_Item_x4_Color", "2", Setting::Esp_Item_x4_Color[1], "Setting::Esp_Item_x4_Color");
		ini.SetDoubleValue("Setting::Esp_Item_x4_Color", "3", Setting::Esp_Item_x4_Color[2], "Setting::Esp_Item_x4_Color");
		ini.SetDoubleValue("Setting::Esp_Item_x4_Color", "4", Setting::Esp_Item_x4_Color[3], "Setting::Esp_Item_x4_Color");

		ini.SetBoolValue("Setting::Esp_Item_x6", "0", Setting::Esp_Item_x6, "Setting::Esp_Item_x6");
		ini.SetDoubleValue("Setting::Esp_Item_x6_Color", "1", Setting::Esp_Item_x6_Color[0], "Setting::Esp_Item_x6_Color");
		ini.SetDoubleValue("Setting::Esp_Item_x6_Color", "2", Setting::Esp_Item_x6_Color[1], "Setting::Esp_Item_x6_Color");
		ini.SetDoubleValue("Setting::Esp_Item_x6_Color", "3", Setting::Esp_Item_x6_Color[2], "Setting::Esp_Item_x6_Color");
		ini.SetDoubleValue("Setting::Esp_Item_x6_Color", "4", Setting::Esp_Item_x6_Color[3], "Setting::Esp_Item_x6_Color");

		ini.SetBoolValue("Setting::Esp_Item_x8", "0", Setting::Esp_Item_x8, "Setting::Esp_Item_x8");
		ini.SetDoubleValue("Setting::Esp_Item_x8_Color", "1", Setting::Esp_Item_x8_Color[0], "Setting::Esp_Item_x8_Color");
		ini.SetDoubleValue("Setting::Esp_Item_x8_Color", "2", Setting::Esp_Item_x8_Color[1], "Setting::Esp_Item_x8_Color");
		ini.SetDoubleValue("Setting::Esp_Item_x8_Color", "3", Setting::Esp_Item_x8_Color[2], "Setting::Esp_Item_x8_Color");
		ini.SetDoubleValue("Setting::Esp_Item_x8_Color", "4", Setting::Esp_Item_x8_Color[3], "Setting::Esp_Item_x8_Color");

		ini.SetBoolValue("Setting::Esp_Item_Bag1", "0", Setting::Esp_Item_Bag1, "Setting::Esp_Item_Bag1");
		ini.SetDoubleValue("Setting::Esp_Item_Bag1_Color", "1", Setting::Esp_Item_Bag1_Color[0], "Setting::Esp_Item_Bag1_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Bag1_Color", "2", Setting::Esp_Item_Bag1_Color[1], "Setting::Esp_Item_Bag1_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Bag1_Color", "3", Setting::Esp_Item_Bag1_Color[2], "Setting::Esp_Item_Bag1_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Bag1_Color", "4", Setting::Esp_Item_Bag1_Color[3], "Setting::Esp_Item_Bag1_Color");

		ini.SetBoolValue("Setting::Esp_Item_Bag2", "0", Setting::Esp_Item_Bag2, "Setting::Esp_Item_Bag2");
		ini.SetDoubleValue("Setting::Esp_Item_Bag2_Color", "1", Setting::Esp_Item_Bag2_Color[0], "Setting::Esp_Item_Bag2_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Bag2_Color", "2", Setting::Esp_Item_Bag2_Color[1], "Setting::Esp_Item_Bag2_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Bag2_Color", "3", Setting::Esp_Item_Bag2_Color[2], "Setting::Esp_Item_Bag2_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Bag2_Color", "4", Setting::Esp_Item_Bag2_Color[3], "Setting::Esp_Item_Bag2_Color");

		ini.SetBoolValue("Setting::Esp_Item_Bag3", "0", Setting::Esp_Item_Bag3, "Setting::Esp_Item_Bag3");
		ini.SetDoubleValue("Setting::Esp_Item_Bag3_Color", "1", Setting::Esp_Item_Bag3_Color[0], "Setting::Esp_Item_Bag3_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Bag3_Color", "2", Setting::Esp_Item_Bag3_Color[1], "Setting::Esp_Item_Bag3_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Bag3_Color", "3", Setting::Esp_Item_Bag3_Color[2], "Setting::Esp_Item_Bag3_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Bag3_Color", "4", Setting::Esp_Item_Bag3_Color[3], "Setting::Esp_Item_Bag3_Color");

		ini.SetBoolValue("Setting::Esp_Item_Armor1", "0", Setting::Esp_Item_Armor1, "Setting::Esp_Item_Armor1");
		ini.SetDoubleValue("Setting::Esp_Item_Armor1_Color", "1", Setting::Esp_Item_Armor1_Color[0], "Setting::Esp_Item_Armor1_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Armor1_Color", "2", Setting::Esp_Item_Armor1_Color[1], "Setting::Esp_Item_Armor1_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Armor1_Color", "3", Setting::Esp_Item_Armor1_Color[2], "Setting::Esp_Item_Armor1_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Armor1_Color", "4", Setting::Esp_Item_Armor1_Color[3], "Setting::Esp_Item_Armor1_Color");

		ini.SetBoolValue("Setting::Esp_Item_Armor2", "0", Setting::Esp_Item_Armor2, "Setting::Esp_Item_Armor2");
		ini.SetDoubleValue("Setting::Esp_Item_Armor2_Color", "1", Setting::Esp_Item_Armor2_Color[0], "Setting::Esp_Item_Armor2_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Armor2_Color", "2", Setting::Esp_Item_Armor2_Color[1], "Setting::Esp_Item_Armor2_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Armor2_Color", "3", Setting::Esp_Item_Armor2_Color[2], "Setting::Esp_Item_Armor2_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Armor2_Color", "4", Setting::Esp_Item_Armor2_Color[3], "Setting::Esp_Item_Armor2_Color");

		ini.SetBoolValue("Setting::Esp_Item_Armor3", "0", Setting::Esp_Item_Armor3, "Setting::Esp_Item_Armor3");
		ini.SetDoubleValue("Setting::Esp_Item_Armor3_Color", "1", Setting::Esp_Item_Armor3_Color[0], "Setting::Esp_Item_Armor3_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Armor3_Color", "2", Setting::Esp_Item_Armor3_Color[1], "Setting::Esp_Item_Armor3_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Armor3_Color", "3", Setting::Esp_Item_Armor3_Color[2], "Setting::Esp_Item_Armor3_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Armor3_Color", "4", Setting::Esp_Item_Armor3_Color[3], "Setting::Esp_Item_Armor3_Color");

		ini.SetBoolValue("Setting::Esp_Item_Helmet1", "0", Setting::Esp_Item_Helmet1, "Setting::Esp_Item_Helmet1");
		ini.SetDoubleValue("Setting::Esp_Item_Helmet1_Color", "1", Setting::Esp_Item_Helmet1_Color[0], "Setting::Esp_Item_Helmet1_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Helmet1_Color", "2", Setting::Esp_Item_Helmet1_Color[1], "Setting::Esp_Item_Helmet1_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Helmet1_Color", "3", Setting::Esp_Item_Helmet1_Color[2], "Setting::Esp_Item_Helmet1_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Helmet1_Color", "4", Setting::Esp_Item_Helmet1_Color[3], "Setting::Esp_Item_Helmet1_Color");

		ini.SetBoolValue("Setting::Esp_Item_Helmet2", "0", Setting::Esp_Item_Helmet2, "Setting::Esp_Item_Helmet2");
		ini.SetDoubleValue("Setting::Esp_Item_Helmet2_Color", "1", Setting::Esp_Item_Helmet2_Color[0], "Setting::Esp_Item_Helmet2_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Helmet2_Color", "2", Setting::Esp_Item_Helmet2_Color[1], "Setting::Esp_Item_Helmet2_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Helmet2_Color", "3", Setting::Esp_Item_Helmet2_Color[2], "Setting::Esp_Item_Helmet2_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Helmet2_Color", "4", Setting::Esp_Item_Helmet2_Color[3], "Setting::Esp_Item_Helmet2_Color");

		ini.SetBoolValue("Setting::Esp_Item_Helmet3", "0", Setting::Esp_Item_Helmet3, "Setting::Esp_Item_Helmet3");
		ini.SetDoubleValue("Setting::Esp_Item_Helmet3_Color", "1", Setting::Esp_Item_Helmet3_Color[0], "Setting::Esp_Item_Helmet3_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Helmet3_Color", "2", Setting::Esp_Item_Helmet3_Color[1], "Setting::Esp_Item_Helmet3_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Helmet3_Color", "3", Setting::Esp_Item_Helmet3_Color[2], "Setting::Esp_Item_Helmet3_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Helmet3_Color", "4", Setting::Esp_Item_Helmet3_Color[3], "Setting::Esp_Item_Helmet3_Color");

		ini.SetBoolValue("Setting::Esp_Item_Frag", "0", Setting::Esp_Item_Frag, "Setting::Esp_Item_Frag");
		ini.SetDoubleValue("Setting::Esp_Item_Frag_Color", "1", Setting::Esp_Item_Frag_Color[0], "Setting::Esp_Item_Frag_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Frag_Color", "2", Setting::Esp_Item_Frag_Color[1], "Setting::Esp_Item_Frag_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Frag_Color", "3", Setting::Esp_Item_Frag_Color[2], "Setting::Esp_Item_Frag_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Frag_Color", "4", Setting::Esp_Item_Frag_Color[3], "Setting::Esp_Item_Frag_Color");

		ini.SetBoolValue("Setting::Esp_Item_Smoke", "0", Setting::Esp_Item_Smoke, "Setting::Esp_Item_Smoke");
		ini.SetDoubleValue("Setting::Esp_Item_Smoke_Color", "1", Setting::Esp_Item_Smoke_Color[0], "Setting::Esp_Item_Smoke_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Smoke_Color", "2", Setting::Esp_Item_Smoke_Color[1], "Setting::Esp_Item_Smoke_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Smoke_Color", "3", Setting::Esp_Item_Smoke_Color[2], "Setting::Esp_Item_Smoke_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Smoke_Color", "4", Setting::Esp_Item_Smoke_Color[3], "Setting::Esp_Item_Smoke_Color");

		ini.SetBoolValue("Setting::Esp_Item_Molotof", "0", Setting::Esp_Item_Molotof, "Setting::Esp_Item_Molotof");
		ini.SetDoubleValue("Setting::Esp_Item_Molotof_Color", "1", Setting::Esp_Item_Molotof_Color[0], "Setting::Esp_Item_Molotof_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Molotof_Color", "2", Setting::Esp_Item_Molotof_Color[1], "Setting::Esp_Item_Molotof_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Molotof_Color", "3", Setting::Esp_Item_Molotof_Color[2], "Setting::Esp_Item_Molotof_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Molotof_Color", "4", Setting::Esp_Item_Molotof_Color[3], "Setting::Esp_Item_Molotof_Color");

		ini.SetBoolValue("Setting::Esp_Item_MedKit", "0", Setting::Esp_Item_MedKit, "Setting::Esp_Item_MedKit");
		ini.SetDoubleValue("Setting::Esp_Item_MedKit_Color", "1", Setting::Esp_Item_MedKit_Color[0], "Setting::Esp_Item_MedKit_Color");
		ini.SetDoubleValue("Setting::Esp_Item_MedKit_Color", "2", Setting::Esp_Item_MedKit_Color[1], "Setting::Esp_Item_MedKit_Color");
		ini.SetDoubleValue("Setting::Esp_Item_MedKit_Color", "3", Setting::Esp_Item_MedKit_Color[2], "Setting::Esp_Item_MedKit_Color");
		ini.SetDoubleValue("Setting::Esp_Item_MedKit_Color", "4", Setting::Esp_Item_MedKit_Color[3], "Setting::Esp_Item_MedKit_Color");

		ini.SetBoolValue("Setting::Esp_Item_FirstAidKit", "0", Setting::Esp_Item_FirstAidKit, "Setting::Esp_Item_FirstAidKit");
		ini.SetDoubleValue("Setting::Esp_Item_FirstAidKit_Color", "1", Setting::Esp_Item_FirstAidKit_Color[0], "Setting::Esp_Item_FirstAidKit_Color");
		ini.SetDoubleValue("Setting::Esp_Item_FirstAidKit_Color", "2", Setting::Esp_Item_FirstAidKit_Color[1], "Setting::Esp_Item_FirstAidKit_Color");
		ini.SetDoubleValue("Setting::Esp_Item_FirstAidKit_Color", "3", Setting::Esp_Item_FirstAidKit_Color[2], "Setting::Esp_Item_FirstAidKit_Color");
		ini.SetDoubleValue("Setting::Esp_Item_FirstAidKit_Color", "4", Setting::Esp_Item_FirstAidKit_Color[3], "Setting::Esp_Item_FirstAidKit_Color");

		ini.SetBoolValue("Setting::Esp_Item_Painkiller", "0", Setting::Esp_Item_Painkiller, "Setting::Esp_Item_Painkiller");
		ini.SetDoubleValue("Setting::Esp_Item_Painkiller_Color", "1", Setting::Esp_Item_Painkiller_Color[0], "Setting::Esp_Item_Painkiller_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Painkiller_Color", "2", Setting::Esp_Item_Painkiller_Color[1], "Setting::Esp_Item_Painkiller_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Painkiller_Color", "3", Setting::Esp_Item_Painkiller_Color[2], "Setting::Esp_Item_Painkiller_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Painkiller_Color", "4", Setting::Esp_Item_Painkiller_Color[3], "Setting::Esp_Item_Painkiller_Color");

		ini.SetBoolValue("Setting::Esp_Item_EnergyDrink", "0", Setting::Esp_Item_EnergyDrink, "Setting::Esp_Item_EnergyDrink");
		ini.SetDoubleValue("Setting::Esp_Item_EnergyDrink_Color", "1", Setting::Esp_Item_EnergyDrink_Color[0], "Setting::Esp_Item_EnergyDrink_Color");
		ini.SetDoubleValue("Setting::Esp_Item_EnergyDrink_Color", "2", Setting::Esp_Item_EnergyDrink_Color[1], "Setting::Esp_Item_EnergyDrink_Color");
		ini.SetDoubleValue("Setting::Esp_Item_EnergyDrink_Color", "3", Setting::Esp_Item_EnergyDrink_Color[2], "Setting::Esp_Item_EnergyDrink_Color");
		ini.SetDoubleValue("Setting::Esp_Item_EnergyDrink_Color", "4", Setting::Esp_Item_EnergyDrink_Color[3], "Setting::Esp_Item_EnergyDrink_Color");

		ini.SetBoolValue("Setting::Esp_Item_AdrenalineSyringe", "0", Setting::Esp_Item_AdrenalineSyringe, "Setting::Esp_Item_AdrenalineSyringe");
		ini.SetDoubleValue("Setting::Esp_Item_AdrenalineSyringe_Color", "1", Setting::Esp_Item_AdrenalineSyringe_Color[0], "Setting::Esp_Item_AdrenalineSyringe_Color");
		ini.SetDoubleValue("Setting::Esp_Item_AdrenalineSyringe_Color", "2", Setting::Esp_Item_AdrenalineSyringe_Color[1], "Setting::Esp_Item_AdrenalineSyringe_Color");
		ini.SetDoubleValue("Setting::Esp_Item_AdrenalineSyringe_Color", "3", Setting::Esp_Item_AdrenalineSyringe_Color[2], "Setting::Esp_Item_AdrenalineSyringe_Color");
		ini.SetDoubleValue("Setting::Esp_Item_AdrenalineSyringe_Color", "4", Setting::Esp_Item_AdrenalineSyringe_Color[3], "Setting::Esp_Item_AdrenalineSyringe_Color");

		ini.SetBoolValue("Setting::Esp_Item_FlareGun", "0", Setting::Esp_Item_FlareGun, "Setting::Esp_Item_FlareGun");
		ini.SetDoubleValue("Setting::Esp_Item_FlareGun_Color", "1", Setting::Esp_Item_FlareGun_Color[0], "Setting::Esp_Item_FlareGun_Color");
		ini.SetDoubleValue("Setting::Esp_Item_FlareGun_Color", "2", Setting::Esp_Item_FlareGun_Color[1], "Setting::Esp_Item_FlareGun_Color");
		ini.SetDoubleValue("Setting::Esp_Item_FlareGun_Color", "3", Setting::Esp_Item_FlareGun_Color[2], "Setting::Esp_Item_FlareGun_Color");
		ini.SetDoubleValue("Setting::Esp_Item_FlareGun_Color", "4", Setting::Esp_Item_FlareGun_Color[3], "Setting::Esp_Item_FlareGun_Color");

		ini.SetBoolValue("Setting::Esp_Item_Flare", "0", Setting::Esp_Item_Flare, "Setting::Esp_Item_Flare");
		ini.SetDoubleValue("Setting::Esp_Item_Flare_Color", "1", Setting::Esp_Item_Flare_Color[0], "Setting::Esp_Item_Flare_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Flare_Color", "2", Setting::Esp_Item_Flare_Color[1], "Setting::Esp_Item_Flare_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Flare_Color", "3", Setting::Esp_Item_Flare_Color[2], "Setting::Esp_Item_Flare_Color");
		ini.SetDoubleValue("Setting::Esp_Item_Flare_Color", "4", Setting::Esp_Item_Flare_Color[3], "Setting::Esp_Item_Flare_Color");

		ini.SetBoolValue("Setting::Esp_Item_GasCan", "0", Setting::Esp_Item_Flare, "Setting::Esp_Item_GasCan");
		ini.SetDoubleValue("Setting::Esp_Item_GasCan_Color", "1", Setting::Esp_Item_Flare_Color[0], "Setting::Esp_Item_GasCan_Color");
		ini.SetDoubleValue("Setting::Esp_Item_GasCan_Color", "2", Setting::Esp_Item_Flare_Color[1], "Setting::Esp_Item_GasCan_Color");
		ini.SetDoubleValue("Setting::Esp_Item_GasCan_Color", "3", Setting::Esp_Item_Flare_Color[2], "Setting::Esp_Item_GasCan_Color");
		ini.SetDoubleValue("Setting::Esp_Item_GasCan_Color", "4", Setting::Esp_Item_Flare_Color[3], "Setting::Esp_Item_GasCan_Color");

		ini.SetBoolValue("Setting::Esp_Item_AirDrop", "0", Setting::Esp_Item_AirDrop, "Setting::Esp_Item_AirDrop");
		ini.SetDoubleValue("Setting::Esp_Item_AirDrop_Color", "1", Setting::Esp_Item_AirDrop_Color[0], "Setting::Esp_Item_AirDrop_Color");
		ini.SetDoubleValue("Setting::Esp_Item_AirDrop_Color", "2", Setting::Esp_Item_AirDrop_Color[1], "Setting::Esp_Item_AirDrop_Color");
		ini.SetDoubleValue("Setting::Esp_Item_AirDrop_Color", "3", Setting::Esp_Item_AirDrop_Color[2], "Setting::Esp_Item_AirDrop_Color");
		ini.SetDoubleValue("Setting::Esp_Item_AirDrop_Color", "4", Setting::Esp_Item_AirDrop_Color[3], "Setting::Esp_Item_AirDrop_Color");

		ini.SetBoolValue("Setting::Esp_Item_PlayerBox", "0", Setting::Esp_Item_PlayerBox, "Setting::Esp_Item_PlayerBox");
		ini.SetDoubleValue("Setting::Esp_Item_PlayerBox_Color", "1", Setting::Esp_Item_PlayerBox_Color[0], "Setting::Esp_Item_PlayerBox_Color");
		ini.SetDoubleValue("Setting::Esp_Item_PlayerBox_Color", "2", Setting::Esp_Item_PlayerBox_Color[1], "Setting::Esp_Item_PlayerBox_Color");
		ini.SetDoubleValue("Setting::Esp_Item_PlayerBox_Color", "3", Setting::Esp_Item_PlayerBox_Color[2], "Setting::Esp_Item_PlayerBox_Color");
		ini.SetDoubleValue("Setting::Esp_Item_PlayerBox_Color", "4", Setting::Esp_Item_PlayerBox_Color[3], "Setting::Esp_Item_PlayerBox_Color");

		ini.SaveFile(Path.c_str());
	}

	void LoadConfiguratiton(std::string Path) {

		CSimpleIniA ini;
		ini.SetUnicode();
		SI_Error rc = ini.LoadFile(Path.c_str());
		if (rc < 0)
		{
			std::cout << "File not found";
		};

		Setting::TotalEnemy = ini.GetBoolValue("esp", "0");
		Setting::BombAlert = ini.GetBoolValue("esp", "1");
		Setting::Item = ini.GetBoolValue("esp", "2");
		Setting::Vehicle = ini.GetBoolValue("esp", "3");
		Setting::Name = ini.GetBoolValue("esp", "4");
		Setting::Health = ini.GetBoolValue("esp", "5");
		Setting::Distance = ini.GetBoolValue("esp", "6");
		Setting::Box = ini.GetBoolValue("esp", "7");
		Setting::Line = ini.GetBoolValue("esp", "8");
		Setting::Bone = ini.GetBoolValue("esp", "9");
		Setting::country = ini.GetBoolValue("esp", "10");
		Setting::TeamId = ini.GetBoolValue("esp", "11");
		Setting::ItemSize = ini.GetLongValue("esp", "12");
		Setting::carsize = ini.GetLongValue("esp", "13");
		Setting::playernamesize = ini.GetLongValue("esp", "14");
		Setting::redzoneSize = ini.GetLongValue("esp", "15");
		Setting::Redzone = ini.GetBoolValue("esp", "16");
		Setting::GranadeWarningSize = ini.GetLongValue("esp", "17");
		//PlayerWeaponSize = ini.GetLongValue("esp", "18");
		Setting::PlayerWeapon = ini.GetBoolValue("esp", "19");
		Setting::TotalEnemySize = ini.GetLongValue("esp", "20");
		Setting::G_warningType = ini.GetLongValue("esp", "21");

		Setting::BoneColorSameAsLineBool = ini.GetBoolValue("esp", "25");
		Setting::enemyIndicator = ini.GetBoolValue("esp", "26");
		Setting::EnemyStatus = ini.GetBoolValue("esp", "27");
		Setting::carDist = ini.GetLongValue("esp", "28");
		Setting::DistanceSize = ini.GetLongValue("esp", "38");
		Setting::MagicPositionKey = ini.GetLongValue("esp", "39");
		Setting::EnableMagicKey = ini.GetLongValue("esp", "40");
		Setting::AimbotKey = ini.GetLongValue("esp", "41");
		Setting::Aimspeed = ini.GetLongValue("esp", "42");
		Setting::Magic360deg = ini.GetLongValue("esp", "43");
		Setting::gameInfo = ini.GetLongValue("esp", "45");
		Setting::MAgicline = ini.GetLongValue("esp", "46");

		Setting::radar = ini.GetLongValue("esp", "29");
		Setting::RadarWidth = ini.GetBoolValue("esp", "30");
		Setting::RadarLength = ini.GetBoolValue("esp", "31");

		Setting::G_Warning_Frag = ini.GetBoolValue("esp", "22");
		Setting::G_Warning_Molotof = ini.GetBoolValue("esp", "23");
		Setting::G_Warning_Smoke = ini.GetBoolValue("esp", "24");

		Setting::fovcircle = ini.GetBoolValue("esp", "32");

		Setting::fovcircleredus = ini.GetLongValue("esp", "33");
		Setting::MidMagicButton = ini.GetLongValue("esp", "44");

		Setting::MagicBullet = ini.GetBoolValue("esp", "34");
		Setting::Aimbot = ini.GetBoolValue("esp", "35");

		Setting::deadbox = ini.GetBoolValue("esp", "36");
		Setting::deadboxBG = ini.GetBoolValue("esp", "37");

		for (int i = 0; i < 4; i++) { std::string str = "PlayerNameColor"; Setting::PlayerNameColor[i] = fround(ini.GetLongValue("PlayerNameColor", str.append(std::to_string(i)).c_str()) / 255.0); }
		for (int i = 0; i < 4; i++) { std::string str = "fovcirclecolor"; Setting::fovcirclecolor[i] = fround(ini.GetLongValue("fovcirclecolor", str.append(std::to_string(i)).c_str()) / 255.0); }
		for (int i = 0; i < 4; i++) { std::string str = "VehhilceUsedColor"; Setting::VehhilceUsedColor[i] = fround(ini.GetLongValue("VehhilceUsedColor", str.append(std::to_string(i)).c_str()) / 255.0); }
		for (int i = 0; i < 4; i++) { std::string str = "VehhilceColor"; Setting::VehhilceColor[i] = fround(ini.GetLongValue("VehhilceColor", str.append(std::to_string(i)).c_str()) / 255.0); }
		for (int i = 0; i < 4; i++) { std::string str = "hpFuel"; Setting::hpFuel[i] = fround(ini.GetLongValue("hpFuel", str.append(std::to_string(i)).c_str()) / 255.0); }

		Setting::G_warningColor[0] = ini.GetLongValue("G_warningColor", "1");
		Setting::G_warningColor[1] = ini.GetLongValue("G_warningColor", "2");
		Setting::G_warningColor[2] = ini.GetLongValue("G_warningColor", "3");
		Setting::G_warningColor[3] = ini.GetLongValue("G_warningColor", "4");

		Setting::TotalEnemyColor[0] = ini.GetLongValue("TotalEnemyColor", "1");
		Setting::TotalEnemyColor[1] = ini.GetLongValue("TotalEnemyColor", "2");
		Setting::TotalEnemyColor[2] = ini.GetLongValue("TotalEnemyColor", "3");
		Setting::TotalEnemyColor[3] = ini.GetLongValue("TotalEnemyColor", "4");

		Setting::RedZoneColor[0] = ini.GetLongValue("RedZoneColor", "1");
		Setting::RedZoneColor[1] = ini.GetLongValue("RedZoneColor", "2");
		Setting::RedZoneColor[2] = ini.GetLongValue("RedZoneColor", "3");
		Setting::RedZoneColor[3] = ini.GetLongValue("RedZoneColor", "4");

		Setting::BoxColor[0] = ini.GetLongValue("BoxColor", "1");
		Setting::BoxColor[1] = ini.GetLongValue("BoxColor", "2");
		Setting::BoxColor[2] = ini.GetLongValue("BoxColor", "3");
		Setting::BoxColor[3] = ini.GetLongValue("BoxColor", "4");

		Setting::BoneColor[0] = ini.GetLongValue("BoneColor", "1");
		Setting::BoneColor[1] = ini.GetLongValue("BoneColor", "2");
		Setting::BoneColor[2] = ini.GetLongValue("BoneColor", "3");
		Setting::BoneColor[3] = ini.GetLongValue("BoneColor", "4");

		Setting::Esp_Item_AKM = ini.GetBoolValue("Setting::Esp_Item_AKM", "0");
		Setting::Esp_Item_AKM_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_AKM_Color", "1");
		Setting::Esp_Item_AKM_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_AKM_Color", "2");
		Setting::Esp_Item_AKM_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_AKM_Color", "3");
		Setting::Esp_Item_AKM_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_AKM_Color", "4");

		Setting::Esp_Item_M762 = ini.GetBoolValue("Setting::Esp_Item_M762", "0");
		Setting::Esp_Item_M762_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_M762_Color", "1");
		Setting::Esp_Item_M762_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_M762_Color", "2");
		Setting::Esp_Item_M762_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_M762_Color", "3");
		Setting::Esp_Item_M762_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_M762_Color", "4");

		Setting::Esp_Item_PlayerDeadBox = ini.GetBoolValue("Setting::Esp_Item_PlayerDeadBox", "0");
		Setting::Esp_Item_PlayerDeadBox_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_PlayerDeadBox_Color", "1");
		Setting::Esp_Item_PlayerDeadBox_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_PlayerDeadBox_Color", "2");
		Setting::Esp_Item_PlayerDeadBox_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_PlayerDeadBox_Color", "3");
		Setting::Esp_Item_PlayerDeadBox_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_PlayerDeadBox_Color", "4");

		Setting::Esp_Item_Groza = ini.GetBoolValue("Setting::Esp_Item_Groza", "0");
		Setting::Esp_Item_Groza_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Groza_Color", "1");
		Setting::Esp_Item_Groza_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Groza_Color", "2");
		Setting::Esp_Item_Groza_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Groza_Color", "3");
		Setting::Esp_Item_Groza_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Groza_Color", "4");

		Setting::Esp_Item_Mk47Mutant = ini.GetBoolValue("Setting::Esp_Item_Mk47Mutant", "0");
		Setting::Esp_Item_Mk47Mutant_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Mk47Mutant_Color", "1");
		Setting::Esp_Item_Mk47Mutant_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Mk47Mutant_Color", "2");
		Setting::Esp_Item_Mk47Mutant_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Mk47Mutant_Color", "3");
		Setting::Esp_Item_Mk47Mutant_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Mk47Mutant_Color", "4");

		Setting::Esp_Item_DP28 = ini.GetBoolValue("Setting::Esp_Item_DP28", "0");
		Setting::Esp_Item_DP28_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_DP28_Color", "1");
		Setting::Esp_Item_DP28_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_DP28_Color", "2");
		Setting::Esp_Item_DP28_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_DP28_Color", "3");
		Setting::Esp_Item_DP28_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_DP28_Color", "4");

		Setting::Esp_Item_SCARL = ini.GetBoolValue("Setting::Esp_Item_SCARL", "0");
		Setting::Esp_Item_SCARL_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_SCARL_Color", "1");
		Setting::Esp_Item_SCARL_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_SCARL_Color", "2");
		Setting::Esp_Item_SCARL_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_SCARL_Color", "3");
		Setting::Esp_Item_SCARL_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_SCARL_Color", "4");

		Setting::Esp_Item_M416 = ini.GetBoolValue("Setting::Esp_Item_M416", "0");
		Setting::Esp_Item_M416_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_M416_Color", "1");
		Setting::Esp_Item_M416_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_M416_Color", "2");
		Setting::Esp_Item_M416_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_M416_Color", "3");
		Setting::Esp_Item_M416_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_M416_Color", "4");

		Setting::Esp_Item_AUG = ini.GetBoolValue("Setting::Esp_Item_AUG", "0");
		Setting::Esp_Item_AUG_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_AUG_Color", "1");
		Setting::Esp_Item_AUG_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_AUG_Color", "2");
		Setting::Esp_Item_AUG_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_AUG_Color", "3");
		Setting::Esp_Item_AUG_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_AUG_Color", "4");

		Setting::Esp_Item_M249 = ini.GetBoolValue("Setting::Esp_Item_M249", "0");
		Setting::Esp_Item_M249_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_M249_Color", "1");
		Setting::Esp_Item_M249_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_M249_Color", "2");
		Setting::Esp_Item_M249_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_M249_Color", "3");
		Setting::Esp_Item_M249_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_M249_Color", "4");

		Setting::Esp_Item_M16A4 = ini.GetBoolValue("Setting::Esp_Item_M16A4", "0");
		Setting::Esp_Item_M16A4_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_M16A4_Color", "1");
		Setting::Esp_Item_M16A4_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_M16A4_Color", "2");
		Setting::Esp_Item_M16A4_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_M16A4_Color", "3");
		Setting::Esp_Item_M16A4_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_M16A4_Color", "4");

		Setting::Esp_Item_G36C = ini.GetBoolValue("Setting::Esp_Item_G36C", "0");
		Setting::Esp_Item_G36C_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_G36C_Color", "1");
		Setting::Esp_Item_G36C_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_G36C_Color", "2");
		Setting::Esp_Item_G36C_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_G36C_Color", "3");
		Setting::Esp_Item_G36C_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_G36C_Color", "4");

		Setting::Esp_Item_QBZ = ini.GetBoolValue("Setting::Esp_Item_QBZ", "0");
		Setting::Esp_Item_QBZ_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_QBZ_Color", "1");
		Setting::Esp_Item_QBZ_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_QBZ_Color", "2");
		Setting::Esp_Item_QBZ_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_QBZ_Color", "3");
		Setting::Esp_Item_QBZ_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_QBZ_Color", "4");

		Setting::Esp_Item_QBU = ini.GetBoolValue("Setting::Esp_Item_QBU", "0");
		Setting::Esp_Item_QBU_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_QBU_Color", "1");
		Setting::Esp_Item_QBU_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_QBU_Color", "2");
		Setting::Esp_Item_QBU_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_QBU_Color", "3");
		Setting::Esp_Item_QBU_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_QBU_Color", "4");

		Setting::Esp_Item_SLR = ini.GetBoolValue("Setting::Esp_Item_SLR", "0");
		Setting::Esp_Item_SLR_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_SLR_Color", "1");
		Setting::Esp_Item_SLR_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_SLR_Color", "2");
		Setting::Esp_Item_SLR_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_SLR_Color", "3");
		Setting::Esp_Item_SLR_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_SLR_Color", "4");

		Setting::Esp_Item_SKS = ini.GetBoolValue("Setting::Esp_Item_SKS", "0");
		Setting::Esp_Item_SKS_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_SKS_Color", "1");
		Setting::Esp_Item_SKS_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_SKS_Color", "2");
		Setting::Esp_Item_SKS_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_SKS_Color", "3");
		Setting::Esp_Item_SKS_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_SKS_Color", "4");

		Setting::Esp_Item_Mini14 = ini.GetBoolValue("Setting::Esp_Item_Mini14", "0");
		Setting::Esp_Item_Mini14_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Mini14_Color", "1");
		Setting::Esp_Item_Mini14_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Mini14_Color", "2");
		Setting::Esp_Item_Mini14_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Mini14_Color", "3");
		Setting::Esp_Item_Mini14_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Mini14_Color", "4");

		Setting::Esp_Item_M24 = ini.GetBoolValue("Setting::Esp_Item_M24", "0");
		Setting::Esp_Item_M24_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_M24_Color", "1");
		Setting::Esp_Item_M24_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_M24_Color", "2");
		Setting::Esp_Item_M24_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_M24_Color", "3");
		Setting::Esp_Item_M24_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_M24_Color", "4");

		Setting::Esp_Item_Kar98k = ini.GetBoolValue("Setting::Esp_Item_Kar98k", "0");
		Setting::Esp_Item_Kar98k_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Kar98k_Color", "1");
		Setting::Esp_Item_Kar98k_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Kar98k_Color", "2");
		Setting::Esp_Item_Kar98k_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Kar98k_Color", "3");
		Setting::Esp_Item_Kar98k_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Kar98k_Color", "4");

		Setting::Esp_Item_AWM = ini.GetBoolValue("Setting::Esp_Item_AWM", "0");
		Setting::Esp_Item_AWM_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_AWM_Color", "1");
		Setting::Esp_Item_AWM_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_AWM_Color", "2");
		Setting::Esp_Item_AWM_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_AWM_Color", "3");
		Setting::Esp_Item_AWM_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_AWM_Color", "4");

		Setting::Esp_Item_Crossbow = ini.GetBoolValue("Setting::Esp_Item_Crossbow", "0");
		Setting::Esp_Item_Crossbow_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Crossbow_Color", "1");
		Setting::Esp_Item_Crossbow_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Crossbow_Color", "2");
		Setting::Esp_Item_Crossbow_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Crossbow_Color", "3");
		Setting::Esp_Item_Crossbow_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Crossbow_Color", "4");

		Setting::Esp_Item_PP19 = ini.GetBoolValue("Setting::Esp_Item_PP19", "0");
		Setting::Esp_Item_PP19_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_PP19_Color", "1");
		Setting::Esp_Item_PP19_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_PP19_Color", "2");
		Setting::Esp_Item_PP19_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_PP19_Color", "3");
		Setting::Esp_Item_PP19_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_PP19_Color", "4");

		Setting::Esp_Item_TommyGun = ini.GetBoolValue("Setting::Esp_Item_TommyGun", "0");
		Setting::Esp_Item_TommyGun_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_TommyGun_Color", "1");
		Setting::Esp_Item_TommyGun_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_TommyGun_Color", "2");
		Setting::Esp_Item_TommyGun_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_TommyGun_Color", "3");
		Setting::Esp_Item_TommyGun_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_TommyGun_Color", "4");

		Setting::Esp_Item_MP5K = ini.GetBoolValue("Setting::Esp_Item_MP5K", "0");
		Setting::Esp_Item_MP5K_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_MP5K_Color", "1");
		Setting::Esp_Item_MP5K_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_MP5K_Color", "2");
		Setting::Esp_Item_MP5K_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_MP5K_Color", "3");
		Setting::Esp_Item_MP5K_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_MP5K_Color", "4");

		Setting::Esp_Item_UMP9 = ini.GetBoolValue("Setting::Esp_Item_UMP9", "0");
		Setting::Esp_Item_UMP9_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_UMP9_Color", "1");
		Setting::Esp_Item_UMP9_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_UMP9_Color", "2");
		Setting::Esp_Item_UMP9_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_UMP9_Color", "3");
		Setting::Esp_Item_UMP9_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_UMP9_Color", "4");

		Setting::Esp_Item_Vector = ini.GetBoolValue("Setting::Esp_Item_Vector", "0");
		Setting::Esp_Item_Vector_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Vector_Color", "1");
		Setting::Esp_Item_Vector_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Vector_Color", "2");
		Setting::Esp_Item_Vector_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Vector_Color", "3");
		Setting::Esp_Item_Vector_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Vector_Color", "4");

		Setting::Esp_Item_Uzi = ini.GetBoolValue("Setting::Esp_Item_Uzi", "0");
		Setting::Esp_Item_Uzi_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Uzi_Color", "1");
		Setting::Esp_Item_Uzi_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Uzi_Color", "2");
		Setting::Esp_Item_Uzi_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Uzi_Color", "3");
		Setting::Esp_Item_Uzi_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Uzi_Color", "4");

		Setting::Esp_Item_300Magnum = ini.GetBoolValue("Setting::Esp_Item_300Magnum", "0");
		Setting::Esp_Item_300Magnum_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_300Magnum_Color", "1");
		Setting::Esp_Item_300Magnum_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_300Magnum_Color", "2");
		Setting::Esp_Item_300Magnum_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_300Magnum_Color", "3");
		Setting::Esp_Item_300Magnum_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_300Magnum_Color", "4");

		Setting::Esp_Item_762mm = ini.GetBoolValue("Setting::Esp_Item_762mm", "0");
		Setting::Esp_Item_762mm_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_762mm_Color", "1");
		Setting::Esp_Item_762mm_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_762mm_Color", "2");
		Setting::Esp_Item_762mm_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_762mm_Color", "3");
		Setting::Esp_Item_762mm_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_762mm_Color", "4");

		Setting::Esp_Item_556mm = ini.GetBoolValue("Setting::Esp_Item_556mm", "0");
		Setting::Esp_Item_556mm_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_556mm_Color", "1");
		Setting::Esp_Item_556mm_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_556mm_Color", "2");
		Setting::Esp_Item_556mm_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_556mm_Color", "3");
		Setting::Esp_Item_556mm_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_556mm_Color", "4");

		Setting::Esp_Item_9mm = ini.GetBoolValue("Setting::Esp_Item_9mm", "0");
		Setting::Esp_Item_9mm_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_9mm_Color", "1");
		Setting::Esp_Item_9mm_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_9mm_Color", "2");
		Setting::Esp_Item_9mm_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_9mm_Color", "3");
		Setting::Esp_Item_9mm_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_9mm_Color", "4");

		Setting::Esp_Item_45ACP = ini.GetBoolValue("Setting::Esp_Item_45ACP", "0");
		Setting::Esp_Item_45ACP_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_45ACP_Color", "1");
		Setting::Esp_Item_45ACP_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_45ACP_Color", "2");
		Setting::Esp_Item_45ACP_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_45ACP_Color", "3");
		Setting::Esp_Item_45ACP_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_45ACP_Color", "4");

		Setting::Esp_Item_Holo = ini.GetBoolValue("Setting::Esp_Item_Holo", "0");
		Setting::Esp_Item_Holo_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Holo_Color", "1");
		Setting::Esp_Item_Holo_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Holo_Color", "2");
		Setting::Esp_Item_Holo_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Holo_Color", "3");
		Setting::Esp_Item_Holo_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Holo_Color", "4");

		Setting::Esp_Item_RedDot = ini.GetBoolValue("Setting::Esp_Item_RedDot", "0");
		Setting::Esp_Item_RedDot_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_RedDot_Color", "1");
		Setting::Esp_Item_RedDot_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_RedDot_Color", "2");
		Setting::Esp_Item_RedDot_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_RedDot_Color", "3");
		Setting::Esp_Item_RedDot_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_RedDot_Color", "4");

		Setting::Esp_Item_x2 = ini.GetBoolValue("Setting::Esp_Item_x2", "0");
		Setting::Esp_Item_x2_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_x2_Color", "1");
		Setting::Esp_Item_x2_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_x2_Color", "2");
		Setting::Esp_Item_x2_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_x2_Color", "3");
		Setting::Esp_Item_x2_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_x2_Color", "4");

		Setting::Esp_Item_x3 = ini.GetBoolValue("Setting::Esp_Item_x3", "0");
		Setting::Esp_Item_x3_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_x3_Color", "1");
		Setting::Esp_Item_x3_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_x3_Color", "2");
		Setting::Esp_Item_x3_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_x3_Color", "3");
		Setting::Esp_Item_x3_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_x3_Color", "4");

		Setting::Esp_Item_x4 = ini.GetBoolValue("Setting::Esp_Item_x4", "0");
		Setting::Esp_Item_x4_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_x4_Color", "1");
		Setting::Esp_Item_x4_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_x4_Color", "2");
		Setting::Esp_Item_x4_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_x4_Color", "3");
		Setting::Esp_Item_x4_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_x4_Color", "4");

		Setting::Esp_Item_x6 = ini.GetBoolValue("Setting::Esp_Item_x6", "0");
		Setting::Esp_Item_x6_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_x6_Color", "1");
		Setting::Esp_Item_x6_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_x6_Color", "2");
		Setting::Esp_Item_x6_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_x6_Color", "3");
		Setting::Esp_Item_x6_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_x6_Color", "4");

		Setting::Esp_Item_x8 = ini.GetBoolValue("Setting::Esp_Item_x8", "0");
		Setting::Esp_Item_x8_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_x8_Color", "1");
		Setting::Esp_Item_x8_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_x8_Color", "2");
		Setting::Esp_Item_x8_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_x8_Color", "3");
		Setting::Esp_Item_x8_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_x8_Color", "4");

		Setting::Esp_Item_Bag1 = ini.GetBoolValue("Setting::Esp_Item_Bag1", "0");
		Setting::Esp_Item_Bag1_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Bag1_Color", "1");
		Setting::Esp_Item_Bag1_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Bag1_Color", "2");
		Setting::Esp_Item_Bag1_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Bag1_Color", "3");
		Setting::Esp_Item_Bag1_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Bag1_Color", "4");

		Setting::Esp_Item_Bag2 = ini.GetBoolValue("Setting::Esp_Item_Bag2", "0");
		Setting::Esp_Item_Bag2_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Bag2_Color", "1");
		Setting::Esp_Item_Bag2_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Bag2_Color", "2");
		Setting::Esp_Item_Bag2_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Bag2_Color", "3");
		Setting::Esp_Item_Bag2_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Bag2_Color", "4");

		Setting::Esp_Item_Bag3 = ini.GetBoolValue("Setting::Esp_Item_Bag3", "0");
		Setting::Esp_Item_Bag3_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Bag3_Color", "1");
		Setting::Esp_Item_Bag3_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Bag3_Color", "2");
		Setting::Esp_Item_Bag3_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Bag3_Color", "3");
		Setting::Esp_Item_Bag3_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Bag3_Color", "4");

		Setting::Esp_Item_Armor1 = ini.GetBoolValue("Setting::Esp_Item_Armor1", "0");
		Setting::Esp_Item_Armor1_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Armor1_Color", "1");
		Setting::Esp_Item_Armor1_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Armor1_Color", "2");
		Setting::Esp_Item_Armor1_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Armor1_Color", "3");
		Setting::Esp_Item_Armor1_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Armor1_Color", "4");

		Setting::Esp_Item_Armor2 = ini.GetBoolValue("Setting::Esp_Item_Armor2", "0");
		Setting::Esp_Item_Armor2_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Armor2_Color", "1");
		Setting::Esp_Item_Armor2_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Armor2_Color", "2");
		Setting::Esp_Item_Armor2_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Armor2_Color", "3");
		Setting::Esp_Item_Armor2_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Armor2_Color", "4");

		Setting::Esp_Item_Armor3 = ini.GetBoolValue("Setting::Esp_Item_Armor3", "0");
		Setting::Esp_Item_Armor3_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Armor3_Color", "1");
		Setting::Esp_Item_Armor3_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Armor3_Color", "2");
		Setting::Esp_Item_Armor3_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Armor3_Color", "3");
		Setting::Esp_Item_Armor3_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Armor3_Color", "4");

		Setting::Esp_Item_Helmet1 = ini.GetBoolValue("Setting::Esp_Item_Helmet1", "0");
		Setting::Esp_Item_Helmet1_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Helmet1_Color", "1");
		Setting::Esp_Item_Helmet1_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Helmet1_Color", "2");
		Setting::Esp_Item_Helmet1_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Helmet1_Color", "3");
		Setting::Esp_Item_Helmet1_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Helmet1_Color", "4");

		Setting::Esp_Item_Helmet2 = ini.GetBoolValue("Setting::Esp_Item_Helmet2", "0");
		Setting::Esp_Item_Helmet2_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Helmet2_Color", "1");
		Setting::Esp_Item_Helmet2_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Helmet2_Color", "2");
		Setting::Esp_Item_Helmet2_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Helmet2_Color", "3");
		Setting::Esp_Item_Helmet2_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Helmet2_Color", "4");

		Setting::Esp_Item_Helmet3 = ini.GetBoolValue("Setting::Esp_Item_Helmet3", "0");
		Setting::Esp_Item_Helmet3_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Helmet3_Color", "1");
		Setting::Esp_Item_Helmet3_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Helmet3_Color", "2");
		Setting::Esp_Item_Helmet3_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Helmet3_Color", "3");
		Setting::Esp_Item_Helmet3_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Helmet3_Color", "4");

		Setting::Esp_Item_Frag = ini.GetBoolValue("Setting::Esp_Item_Frag", "0");
		Setting::Esp_Item_Frag_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Frag_Color", "1");
		Setting::Esp_Item_Frag_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Frag_Color", "2");
		Setting::Esp_Item_Frag_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Frag_Color", "3");
		Setting::Esp_Item_Frag_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Frag_Color", "4");

		Setting::Esp_Item_Smoke = ini.GetBoolValue("Setting::Esp_Item_Smoke", "0");
		Setting::Esp_Item_Smoke_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Smoke_Color", "1");
		Setting::Esp_Item_Smoke_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Smoke_Color", "2");
		Setting::Esp_Item_Smoke_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Smoke_Color", "3");
		Setting::Esp_Item_Smoke_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Smoke_Color", "4");

		Setting::Esp_Item_Molotof = ini.GetBoolValue("Setting::Esp_Item_Molotof", "0");
		Setting::Esp_Item_Molotof_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Molotof_Color", "1");
		Setting::Esp_Item_Molotof_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Molotof_Color", "2");
		Setting::Esp_Item_Molotof_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Molotof_Color", "3");
		Setting::Esp_Item_Molotof_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Molotof_Color", "4");

		Setting::Esp_Item_MedKit = ini.GetBoolValue("Setting::Esp_Item_MedKit", "0");
		Setting::Esp_Item_MedKit_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_MedKit_Color", "1");
		Setting::Esp_Item_MedKit_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_MedKit_Color", "2");
		Setting::Esp_Item_MedKit_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_MedKit_Color", "3");
		Setting::Esp_Item_MedKit_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_MedKit_Color", "4");

		Setting::Esp_Item_FirstAidKit = ini.GetBoolValue("Setting::Esp_Item_FirstAidKit", "0");
		Setting::Esp_Item_FirstAidKit_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_FirstAidKit_Color", "1");
		Setting::Esp_Item_FirstAidKit_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_FirstAidKit_Color", "2");
		Setting::Esp_Item_FirstAidKit_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_FirstAidKit_Color", "3");
		Setting::Esp_Item_FirstAidKit_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_FirstAidKit_Color", "4");

		Setting::Esp_Item_Painkiller = ini.GetBoolValue("Setting::Esp_Item_Painkiller", "0");
		Setting::Esp_Item_Painkiller_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Painkiller_Color", "1");
		Setting::Esp_Item_Painkiller_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Painkiller_Color", "2");
		Setting::Esp_Item_Painkiller_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Painkiller_Color", "3");
		Setting::Esp_Item_Painkiller_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Painkiller_Color", "4");

		Setting::Esp_Item_EnergyDrink = ini.GetBoolValue("Setting::Esp_Item_EnergyDrink", "0");
		Setting::Esp_Item_EnergyDrink_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_EnergyDrink_Color", "1");
		Setting::Esp_Item_EnergyDrink_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_EnergyDrink_Color", "2");
		Setting::Esp_Item_EnergyDrink_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_EnergyDrink_Color", "3");
		Setting::Esp_Item_EnergyDrink_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_EnergyDrink_Color", "4");

		Setting::Esp_Item_AdrenalineSyringe = ini.GetBoolValue("Setting::Esp_Item_AdrenalineSyringe", "0");
		Setting::Esp_Item_AdrenalineSyringe_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_AdrenalineSyringe_Color", "1");
		Setting::Esp_Item_AdrenalineSyringe_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_AdrenalineSyringe_Color", "2");
		Setting::Esp_Item_AdrenalineSyringe_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_AdrenalineSyringe_Color", "3");
		Setting::Esp_Item_AdrenalineSyringe_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_AdrenalineSyringe_Color", "4");

		Setting::Esp_Item_FlareGun = ini.GetBoolValue("Setting::Esp_Item_FlareGun", "0");
		Setting::Esp_Item_FlareGun_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_FlareGun_Color", "1");
		Setting::Esp_Item_FlareGun_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_FlareGun_Color", "2");
		Setting::Esp_Item_FlareGun_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_FlareGun_Color", "3");
		Setting::Esp_Item_FlareGun_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_FlareGun_Color", "4");

		Setting::Esp_Item_GasCan = ini.GetBoolValue("Setting::Esp_Item_GasCan", "0");
		Setting::Esp_Item_GasCan_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_GasCan_Color", "1");
		Setting::Esp_Item_GasCan_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_GasCan_Color", "2");
		Setting::Esp_Item_GasCan_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_GasCan_Color", "3");
		Setting::Esp_Item_GasCan_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_GasCan_Color", "4");

		Setting::Esp_Item_Flare = ini.GetBoolValue("Setting::Esp_Item_Flare", "0");
		Setting::Esp_Item_Flare_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_Flare_Color", "1");
		Setting::Esp_Item_Flare_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_Flare_Color", "2");
		Setting::Esp_Item_Flare_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_Flare_Color", "3");
		Setting::Esp_Item_Flare_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_Flare_Color", "4");

		Setting::Esp_Item_AirDrop = ini.GetBoolValue("Setting::Esp_Item_AirDrop", "0");
		Setting::Esp_Item_AirDrop_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_AirDrop_Color", "1");
		Setting::Esp_Item_AirDrop_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_AirDrop_Color", "2");
		Setting::Esp_Item_AirDrop_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_AirDrop_Color", "3");
		Setting::Esp_Item_AirDrop_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_AirDrop_Color", "4");

		Setting::Esp_Item_PlayerBox = ini.GetBoolValue("Setting::Esp_Item_PlayerBox", "0");
		Setting::Esp_Item_PlayerBox_Color[0] = ini.GetDoubleValue("Setting::Esp_Item_PlayerBox_Color", "1");
		Setting::Esp_Item_PlayerBox_Color[1] = ini.GetDoubleValue("Setting::Esp_Item_PlayerBox_Color", "2");
		Setting::Esp_Item_PlayerBox_Color[2] = ini.GetDoubleValue("Setting::Esp_Item_PlayerBox_Color", "3");
		Setting::Esp_Item_PlayerBox_Color[3] = ini.GetDoubleValue("Setting::Esp_Item_PlayerBox_Color", "4");
	}
};

