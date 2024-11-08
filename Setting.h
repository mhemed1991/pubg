#pragma once

#include "Includes.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGui/imgui_internal.h"

namespace weapon {
	extern ImVec4 MG3;
	extern ImVec4 FAMAS;
	extern ImVec4 Mk14;
	extern ImVec4 G36;
	extern ImVec4 AN94;

	extern ImVec4 m16;
	extern ImVec4 AKM;
	extern ImVec4 AWM;
	extern ImVec4 AWMimmo;
	extern ImVec4 scarl;
	extern ImVec4 m762;
	extern ImVec4 M24;
	extern ImVec4 GROZZA;
	extern ImVec4 scope8x;
	extern ImVec4 kar98;
	extern ImVec4 Airdrop;
	extern ImVec4 Flare;
	extern ImVec4 Flaregun;
}


namespace Colors {

	extern ImVec4  dp;
	extern ImVec4  scope4x;
	extern ImVec4  scope3x;
	extern ImVec4  bag;
	extern ImVec4  armer;
	extern ImVec4  helmat;
	extern ImVec4  mosin;
	extern ImVec4  aug;
	extern ImVec4  g36;
	extern ImVec4  assm;

	extern ImVec4  bgcorner;

	extern ImVec4  Grandes;
	extern ImVec4  ammo7;
	extern ImVec4  ammo5;
	extern ImVec4  madkit;

	extern	ImVec4 scope6x;
	extern	ImVec4 M249;
}

namespace Setting
{
	extern bool ShowMenu;

	extern bool Name;
	extern bool Nation;
	extern bool PlayerWeapon;
	extern bool TeamId;
	extern bool Distance;
	extern bool TotalEnemy;
	extern bool Line;
	extern bool Box;
	extern bool Bone;
	extern bool Health;
	extern bool BombAlert;
	extern bool Item;
	extern bool Vehicle;
	extern bool country;
	extern bool Redzone;
	extern bool isOldUI;


	extern int ItemSize;
	extern int PlayerTotalKills;
	extern int DistanceSize;

	extern int redzoneSize;
	extern int carsize;
	extern int carDist;
	extern int playernamesize;
	extern int PlayerWeaponSize;
	extern int GranadeWarningSize;
	extern const char* GranadeWarningType[2];
	extern int G_warningType;

	extern const char* HackInjectType[3];
	extern int I_HackInjectType;

	extern int AlivePlayers;
	extern int TimeRemind;
	extern int AliveTeams;
	extern int RealPls;
	extern int ZoneID;
	extern int MyTeamID;
	extern int GameID;

	extern int instantv;
	extern int lineChose;
	extern bool lineTop;

	extern bool vehicleHpFuel;

	extern float G_warningColor[4];

	extern bool G_Warning_Frag;
	extern bool G_Warning_Molotof;
	extern bool G_Warning_Smoke;


	extern bool isAntiban;
	extern bool sideMenu;

	extern bool PlayerAiming;

	extern bool gameInfo;

	extern bool DeadsBox;



	extern int GameVersionL;



	extern bool Aimbot;
	extern bool MagicInsideFOV;
	extern float fovcircleredus;
	extern float Ipad;
	extern float bonesize;
	extern float fovcirclecolor[4];
	extern bool fovcircle;
	extern int curraim;
	extern int magicv;
	extern bool knocked;
	extern DWORD CurrentTargetAddress;


	extern bool Magic360deg;
	extern bool instanthit;
	extern bool NoRecoil;
	extern bool MagicBullet;
	extern bool IpadView;
	extern bool ownInfo;

	extern bool magicAutoLocation;




	extern int AimbotKey;
	extern int OnOffAimbotKey;

	extern int ItemOnOffKey;
	extern int MidMagicButton;
	extern int MagicPositionKey;
	extern bool MAgicline;
	extern bool SkipBots;
	extern bool aimbotposition;
	extern float Aimspeed;
	extern int EnableMagicKey;



	extern int matchInfo_TotalPlayer;



	extern float magicDistance;




	extern bool deadbox;
	extern bool deadboxBG;


	extern bool EnemyStatus;
	extern bool FightMode;

	extern bool fastrun;


	extern bool enemyIndicator;
	extern bool streamMode;

	extern bool fullLogin;


	extern bool fastCar;
	extern int carsv;



	extern bool memoryEnabled;

	extern bool Vng;


	extern bool radar;
	extern bool cameratracking;


	extern string versionString;
	extern string expiresString;
	extern string userKey;

	extern ImVec4 colorcode;
	extern ImVec4 linescolors;
	extern ImVec4 BoneColorSameAsLine;
	extern bool BoneColorSameAsLineBool;

	//--------

	extern int CurrentAim;


	extern int RadarLength;
	extern int instanthitsize;
	extern int RadarWidth;
	extern float PlayerMaxDistance;


	//--------

	extern float LineColor[4];
	extern float BoxColor[4];
	extern float BoneColor[4];
	extern float VehhilceColor[4];
	extern float VehhilceUsedColor[4];
	extern float hpFuel[4];

	extern float RedZoneColor[4];
	extern float PlayerNameColor[4];

	extern float TotalEnemyColor[4];
	extern int TotalEnemySize;

	extern bool Esp_Item_AKM;
	extern float Esp_Item_AKM_Color[4];
	extern float Esp_Item_AKM_TextSize;

	extern bool Esp_Item_PlayerDeadBox;
	extern float Esp_Item_PlayerDeadBox_Color[4];
	extern float Esp_Item_PlayerDeadBox_TextSize;

	extern bool Esp_Item_Groza;
	extern float Esp_Item_Groza_Color[4];
	extern float Esp_Item_Groza_TextSize;

	extern bool Esp_Item_M762;
	extern float Esp_Item_M762_Color[4];
	extern float Esp_Item_M762_TextSize;

	extern bool Esp_Item_Mk47Mutant;
	extern float Esp_Item_Mk47Mutant_Color[4];
	extern float Esp_Item_Mk47Mutant_TextSize;

	extern bool Esp_Item_DP28;
	extern float Esp_Item_DP28_Color[4];
	extern float Esp_Item_DP28_TextSize;

	extern bool Esp_Item_SCARL;
	extern float Esp_Item_SCARL_Color[4];
	extern float Esp_Item_SCARL_TextSize;

	extern bool Esp_Item_M416;
	extern float Esp_Item_M416_Color[4];
	extern float Esp_Item_M416_TextSize;

	extern bool Esp_Item_AUG;
	extern float Esp_Item_AUG_Color[4];
	extern float Esp_Item_AUG_TextSize;

	extern bool Esp_Item_M249;
	extern float Esp_Item_M249_Color[4];
	extern float Esp_Item_M249_TextSize;

	extern bool Esp_Item_M16A4;
	extern float Esp_Item_M16A4_Color[4];
	extern float Esp_Item_M16A4_TextSize;

	extern bool Esp_Item_G36C;
	extern float Esp_Item_G36C_Color[4];
	extern float Esp_Item_G36C_TextSize;

	extern bool Esp_Item_QBZ;
	extern float Esp_Item_QBZ_Color[4];
	extern float Esp_Item_QBZ_TextSize;


	extern bool Esp_Item_QBU;
	extern float Esp_Item_QBU_Color[4];
	extern float Esp_Item_QBU_TextSize;

	extern bool Esp_Item_SLR;
	extern float Esp_Item_SLR_Color[4];
	extern float Esp_Item_SLR_TextSize;

	extern bool Esp_Item_SKS;
	extern float Esp_Item_SKS_Color[4];
	extern float Esp_Item_SKS_TextSize;

	extern bool Esp_Item_Mini14;
	extern float Esp_Item_Mini14_Color[4];
	extern float Esp_Item_Mini14_TextSize;

	extern bool Esp_Item_M24;
	extern float Esp_Item_M24_Color[4];
	extern float Esp_Item_M24_TextSize;

	extern bool Esp_Item_Kar98k;
	extern float Esp_Item_Kar98k_Color[4];
	extern float Esp_Item_Kar98k_TextSize;

	extern bool Esp_Item_AWM;
	extern float Esp_Item_AWM_Color[4];
	extern float Esp_Item_AWM_TextSize;

	extern bool Esp_Item_Crossbow;
	extern float Esp_Item_Crossbow_Color[4];
	extern float Esp_Item_Crossbow_TextSize;

	extern bool Esp_Item_PP19;
	extern float Esp_Item_PP19_Color[4];
	extern float Esp_Item_PP19_TextSize;

	extern bool Esp_Item_TommyGun;
	extern float Esp_Item_TommyGun_Color[4];
	extern float Esp_Item_TommyGun_TextSize;

	extern bool Esp_Item_MP5K;
	extern float Esp_Item_MP5K_Color[4];
	extern float Esp_Item_MP5K_TextSize;

	extern bool Esp_Item_UMP9;
	extern float Esp_Item_UMP9_Color[4];
	extern float Esp_Item_UMP9_TextSize;

	extern bool Esp_Item_Vector;
	extern float Esp_Item_Vector_Color[4];
	extern float Esp_Item_Vector_TextSize;

	extern bool Esp_Item_Uzi;
	extern float Esp_Item_Uzi_Color[4];
	extern float Esp_Item_Uzi_TextSize;

	extern bool Esp_Item_300Magnum;
	extern float Esp_Item_300Magnum_Color[4];
	extern float Esp_Item_300Magnum_TextSize;

	extern bool Esp_Item_762mm;
	extern float Esp_Item_762mm_Color[4];
	extern float Esp_Item_762mm_TextSize;


	extern bool Esp_Item_556mm;
	extern float Esp_Item_556mm_Color[4];
	extern float Esp_Item_556mm_TextSize;


	extern bool Esp_Item_9mm;
	extern float Esp_Item_9mm_Color[4];
	extern float Esp_Item_9mm_TextSize;

	extern bool Esp_Item_45ACP;
	extern float Esp_Item_45ACP_Color[4];
	extern float Esp_Item_45ACP_TextSize;

	extern bool Esp_Item_RedDot;
	extern float Esp_Item_RedDot_Color[4];
	extern float Esp_Item_RedDot_TextSize;

	extern bool Esp_Item_Holo;
	extern float Esp_Item_Holo_Color[4];
	extern float Esp_Item_Holo_TextSize;

	extern bool Esp_Item_x2;
	extern float Esp_Item_x2_Color[4];
	extern float Esp_Item_x2_TextSize;

	extern bool Esp_Item_x3;
	extern float Esp_Item_x3_Color[4];
	extern float Esp_Item_x3_TextSize;

	extern bool Esp_Item_x4;
	extern float Esp_Item_x4_Color[4];
	extern float Esp_Item_x4_TextSize;

	extern bool Esp_Item_x6;
	extern float Esp_Item_x6_Color[4];
	extern float Esp_Item_x6_TextSize;

	extern bool Esp_Item_x8;
	extern float Esp_Item_x8_Color[4];
	extern float Esp_Item_x8_TextSize;

	extern bool Esp_Item_Bag1;
	extern float Esp_Item_Bag1_Color[4];
	extern float Esp_Item_Bag1_TextSize;

	extern bool Esp_Item_Bag2;
	extern float Esp_Item_Bag2_Color[4];
	extern float Esp_Item_Bag2_TextSize;

	extern bool Esp_Item_Bag3;
	extern float Esp_Item_Bag3_Color[4];
	extern float Esp_Item_Bag3_TextSize;

	extern bool Esp_Item_Armor1;
	extern float Esp_Item_Armor1_Color[4];
	extern float Esp_Item_Armor1_TextSize;

	extern bool Esp_Item_Armor2;
	extern float Esp_Item_Armor2_Color[4];
	extern float Esp_Item_Armor2_TextSize;

	extern bool Esp_Item_Armor3;
	extern float Esp_Item_Armor3_Color[4];
	extern float Esp_Item_Armor3_TextSize;

	extern bool Esp_Item_Helmet1;
	extern float Esp_Item_Helmet1_Color[4];
	extern float Esp_Item_Helmet1_TextSize;

	extern bool Esp_Item_Helmet2;
	extern float Esp_Item_Helmet2_Color[4];
	extern float Esp_Item_Helmet2_TextSize;

	extern bool Esp_Item_Helmet3;
	extern float Esp_Item_Helmet3_Color[4];
	extern float Esp_Item_Helmet3_TextSize;

	extern bool Esp_Item_Frag;
	extern float Esp_Item_Frag_Color[4];
	extern float Esp_Item_Frag_TextSize;

	extern bool Esp_Item_Smoke;
	extern float Esp_Item_Smoke_Color[4];
	extern float Esp_Item_Smoke_TextSize;

	extern bool Esp_Item_Molotof;
	extern float Esp_Item_Molotof_Color[4];
	extern float Esp_Item_Molotof_TextSize;

	extern bool Esp_Item_MedKit;
	extern float Esp_Item_MedKit_Color[4];
	extern float Esp_Item_MedKit_TextSize;

	extern bool Esp_Item_FirstAidKit;
	extern float Esp_Item_FirstAidKit_Color[4];
	extern float Esp_Item_FirstAidKit_TextSize;

	extern bool Esp_Item_Painkiller;
	extern float Esp_Item_Painkiller_Color[4];
	extern float Esp_Item_Painkiller_TextSize;

	extern bool Esp_Item_EnergyDrink;
	extern float Esp_Item_EnergyDrink_Color[4];
	extern float Esp_Item_EnergyDrink_TextSize;

	extern bool Esp_Item_AdrenalineSyringe;
	extern float Esp_Item_AdrenalineSyringe_Color[4];
	extern float Esp_Item_AdrenalineSyringe_TextSize;

	extern bool Esp_Item_FlareGun;
	extern float Esp_Item_FlareGun_Color[4];
	extern float Esp_Item_FlareGun_TextSize;

	extern bool Esp_Item_GasCan;
	extern float Esp_Item_GasCan_Color[4];
	extern float Esp_Item_GasCan_TextSize;

	extern bool Esp_Item_Flare;
	extern float Esp_Item_Flare_Color[4];
	extern float Esp_Item_Flare_TextSize;

	extern bool Esp_Item_AirDrop;
	extern float Esp_Item_AirDrop_Color[4];
	extern float Esp_Item_AirDrop_TextSize;

	extern bool Esp_Item_PlayerBox;
	extern float Esp_Item_PlayerBox_Color[4];
	extern float Esp_Item_PlayerBox_TextSize;
}
