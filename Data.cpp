#include "Data.h"
#include <thread>
#include "Scanner.h"
#include "Esp.h"
#include <fstream>
#include <iostream>
#include <Aimbot.h>
#include <DiscordR.h>

DWORD Data::ViewMatrixBase;
DWORD Data::UWorld = 0;
Espp* g_pEsp = new Espp();

BYTE ViewMatrixSearch[] =
{
	0x02, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x01
};

DWORD Data::GetViewMatrixBase(DWORD StartAddress, DWORD EndAddress)
{
	DWORD ViewMatrixBase = 0;
	std::vector<DWORD_PTR> FoundedBase;
	Utility::MemSearch(ViewMatrixSearch, sizeof(ViewMatrixSearch), StartAddress, EndAddress, 0, 0, FoundedBase);

	for (int i = 0; i < FoundedBase.size(); i++)
	{
		DWORD Cand = FoundedBase[i] - 0x20;
		DWORD Eng = Utility::ReadMemoryEx<DWORD>(Cand) + 0x20;
		DWORD Tmp = Utility::ReadMemoryEx<DWORD>(Eng) + 0x200;

		float v1, v2, v3, v4;
		v1 = Utility::ReadMemoryEx<float>(Tmp + 0x8);
		v2 = Utility::ReadMemoryEx<float>(Tmp + 0x18);
		v3 = Utility::ReadMemoryEx<float>(Tmp + 0x28);
		v4 = Utility::ReadMemoryEx<float>(Tmp + 0x38);

		if (v1 == 0 && v2 == 0 && v3 == 0 && v4 >= 3)
		{
			ViewMatrixBase = Cand;
			FoundedBase.clear();
			break;
		}
	}

	FoundedBase.clear();
	return ViewMatrixBase;
}



string GetString(DWORD BaseAddress)
{
	char* String = new char[34];
	for (int i = 0; i < 34; i++)
	{
		String[i] = Utility::ReadMemoryEx<char>(BaseAddress + i);
	}

	string Result = String;

	delete[] String;
	return Result;
}

string GetEntityType(LONG GNames, LONG Id)
{
	string Result = "";

	DWORD GName = Utility::ReadMemoryEx<DWORD>(GNames);

	if (Id > 0 && Id < 2000000)
	{
		DWORD Page = Id / 16384;
		DWORD Index = Id % 16384;
		DWORD SecPartAddv = Utility::ReadMemoryEx<DWORD>(GName + Page * 4);

		if (SecPartAddv > 0)
		{
			LONG NameAddv = Utility::ReadMemoryEx<DWORD>(SecPartAddv + Index * 4);

			if (NameAddv > 0)
			{
				Result = GetString(NameAddv + 0x8);
			}
		}
	}

	return Result;
}

struct ObjectName
{
	char Data[64];
};



string GetEntityType2(LONG GNames, LONG Id)
{
	DWORD GName = Utility::ReadMemoryEx<DWORD>(GNames);
	DWORD NamePtr = Utility::ReadMemoryEx<DWORD>(GName + int(Id / 16384) * 0x4);
	DWORD Name = Utility::ReadMemoryEx<DWORD>(NamePtr + int(Id % 16384) * 0x4);
	ObjectName pBuffer = Utility::ReadMemoryEx<ObjectName>(Name + 0x8);

	return string(pBuffer.Data);
}

string GetPlayerName(DWORD BaseAddress)
{
	char* String = new char[34];
	for (int i = 0; i < 34; i++)
	{
		String[i] = Utility::ReadMemoryEx<char>(BaseAddress + i * 2);
	}

	string Name = String;

	delete[] String;
	return Name;
}

string GetPlayerUID(DWORD BaseAddress)
{
	char* String = new char[34];
	for (int i = 0; i < 34; i++)
	{
		String[i] = Utility::ReadMemoryEx<char>(BaseAddress + i * 2);
	}

	string Name = String;

	delete[] String;
	return Name;
}

BOOL IsPlayer(string EntityType)
{
	//if (EntityType.find("BP_TreasureChestActor_Medicine_C") != string::npos)
	//{
	//	return TRUE;
	//}

	//if (EntityType.find("BP_TreasureChestActor_Gold_C") != string::npos)
	//{
	//	return TRUE;
	//}

	//if (EntityType.find("BP_TreasureChestActor_Weapon_C") != string::npos)
	//{
	//	return TRUE;
	//}


	if (EntityType.find("BP_PlayerPawn") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("BP_PlayerCharacter") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("PlanET_FakePlayer") != string::npos)
	{
		return TRUE;
	}

	if (EntityType.find("PlayerPawn_Infec") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("BP_PlayerPawn_FM_C") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("BP_PlayerPawn_C") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("BP_PlayerPawn_Rune_C") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("PlayerPawn_Infec_InvisibleZombie_C") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("PlayerPawn_Infec_Human_C") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("BP_PlayerPawn_ZombieBase_C") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("BP_PlayerPawn_TDM_TPP_C") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("BP_PlayerPawn_FM_Bot_C") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("BP_PlayerCharacter_SlayTheBot_C") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("PlanET_FakePlayer_AIPawn_C") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("BP_PlayerPawn_SI_C") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("BP_PlayerPawn_Heavy_C") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("PlayerPawn_Infec_Revenger_C") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("PlayerPawn_Infec_NormalZombie_C") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("PlayerPawn_Infec_KingZombie_C") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("BP_PlayerCharacter_FourMaps_ZNQ4th_C") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("BP_PlayerCharacter_PlanX_C") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("PlanX_PlayerCharacter_AI_C") != string::npos)
	{
		return TRUE;
	}
	if (EntityType.find("BP_PlayerCharacter_PlanA_C") != string::npos)
	{
		return TRUE;
	}
	//if (EntityType.find("BP_PlayerPawn_ST_AI_C") != string::npos)
	//{
	//	return TRUE;
	//}
	//if (EntityType.find("BP_PlayerPawn_ST_C") != string::npos)
	//{
	//	return TRUE;
	//}
	if (EntityType.find("BP_CharacterModelTaget_C") != string::npos)
	{
		return TRUE;
	}

	return FALSE;
}


D3DMATRIX1 ToMatrix(FRotator rot = { 0,0,0 }, FRotator origin = { 0,0,0 })
{
	float radPitch = (rot.Pitch * float(M_PI) / 180.f);
	float radYaw = (rot.Yaw * float(M_PI) / 180.f);
	float radRoll = (rot.Roll * float(M_PI) / 180.f);

	float SP = sinf(radPitch);
	float CP = cosf(radPitch);
	float SY = sinf(radYaw);
	float CY = cosf(radYaw);
	float SR = sinf(radRoll);
	float CR = cosf(radRoll);

	D3DMATRIX1 matrix;
	matrix.m[0][0] = CP * CY;
	matrix.m[0][1] = CP * SY;
	matrix.m[0][2] = SP;
	matrix.m[0][3] = 0.f;

	matrix.m[1][0] = SR * SP * CY - CR * SY;
	matrix.m[1][1] = SR * SP * SY + CR * CY;
	matrix.m[1][2] = -SR * CP;
	matrix.m[1][3] = 0.f;

	matrix.m[2][0] = -(CR * SP * CY + SR * SY);
	matrix.m[2][1] = CY * SR - CR * SP * SY;
	matrix.m[2][2] = CR * CP;
	matrix.m[2][3] = 0.f;

	matrix.m[3][0] = origin.Pitch;
	matrix.m[3][1] = origin.Yaw;
	matrix.m[3][2] = origin.Roll;
	matrix.m[3][3] = 1.f;

	return matrix;
}

bool WorldToScreenWithoutMatrix(VECTOR3 WorldLocation, VECTOR3& Screenlocation)
{
	FRotator Rotation = Data::CameraCache.POV.Rotation;
	D3DMATRIX1 tempMatrix = ToMatrix(Rotation);

	VECTOR3 vAxisX, vAxisY, vAxisZ;

	vAxisX.X = tempMatrix.m[0][0];
	vAxisX.Y = tempMatrix.m[0][1];
	vAxisX.Z = tempMatrix.m[0][2];
	vAxisY.X = tempMatrix.m[1][0];
	vAxisY.Y = tempMatrix.m[1][1];
	vAxisY.Z = tempMatrix.m[1][2];
	vAxisZ.X = tempMatrix.m[2][0];
	vAxisZ.Y = tempMatrix.m[2][1];
	vAxisZ.Z = tempMatrix.m[2][2];
	VECTOR3 vDelta = Algorithm::Subtract(WorldLocation, Data::CameraCache.POV.Location);

	VECTOR3 vTransformed;

	vTransformed.X = (vDelta.X * vAxisY.X) + (vDelta.Y * vAxisY.Y) + (vDelta.Z * vAxisY.Z);
	vTransformed.Y = (vDelta.X * vAxisZ.X) + (vDelta.Y * vAxisZ.Y) + (vDelta.Z * vAxisZ.Z);
	vTransformed.Z = (vDelta.X * vAxisX.X) + (vDelta.Y * vAxisX.Y) + (vDelta.Z * vAxisX.Z);


	if (vTransformed.Z < 0.0001f) return false;


	float FovAngle = Data::CameraCache.POV.FOV;

	float ScreenCenterX = DX11::Width / 2;
	float ScreenCenterY = DX11::Height / 2;

	Screenlocation.X = ScreenCenterX + vTransformed.X * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;
	Screenlocation.Y = ScreenCenterY - vTransformed.Y * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;
	if (Screenlocation.X > DX11::Width || Screenlocation.Y > DX11::Height || Screenlocation.X < 0 || Screenlocation.Y < 0)
		return false;
	return true;
}

string GetGrenadeType(string Name)
{
	if (Name.find("BP_Grenade_Smoke_C") != string::npos) return "Smoke";
	if (Name.find("BP_Grenade_Burn_C") != string::npos) return "Burn";
	if (Name.find("BP_Grenade_tun_C") != string::npos) return "Flash";
	if (Name.find("BP_Grenade_Shoulei_C") != string::npos) return "Frag";
	return "Unknown";
}

string GetItemType(string Name)
{
	//Sniper
	if (Setting::Esp_Item_M24) if (Name.find("BP_Sniper_M24_Wrapper_C") != string::npos) return "M24";
	if (Setting::Esp_Item_Kar98k) if (Name.find("BP_Sniper_Kar98k_Wrapper_C") != string::npos) return "Kar98k";
	if (Setting::Esp_Item_AWM) if (Name.find("BP_Sniper_AWM_Wrapper_C") != string::npos || Name.find("BP_Sniper_AWM_C") != string::npos) return "AWM";
	if (Setting::Esp_Item_QBU) if (Name.find("BP_Sniper_QBU_Wrapper_C") != string::npos) return "QBU";
	if (Setting::Esp_Item_SLR) if (Name.find("BP_Sniper_SLR_Wrapper_C") != string::npos) return "SLR";
	if (Setting::Esp_Item_SKS) if (Name.find("BP_Sniper_SKS_Wrapper_C") != string::npos) return "SKS";
	if (Setting::Esp_Item_Mini14) if (Name.find("BP_Sniper_Mini14_Wrapper_C") != string::npos) return "Mini-14";
	//AR
	if (Setting::Esp_Item_AUG) if (Name.find("BP_Rifle_AUG_Wrapper_C") != string::npos) return "AUG";
	if (Setting::Esp_Item_Groza) if (Name.find("BP_Rifle_Groza_Wrapper_C") != string::npos) return "Groza";
	if (Setting::Esp_Item_AKM) if (Name.find("BP_Rifle_AKM_Wrapper_C") != std::string::npos) return "AKM";
	if (Setting::Esp_Item_SCARL) if (Name.find("BP_Rifle_SCAR_Wrapper_C") != string::npos) return "SCAR-L";
	if (Setting::Esp_Item_M416) if (Name.find("BP_Rifle_M416_Wrapper_C") != std::string::npos) return "M416";
	if (Setting::Esp_Item_M762) if (Name.find("BP_Rifle_M762_Wrapper_C") != string::npos) return "M762";
	if (Setting::Esp_Item_Mk47Mutant) if (Name.find("BP_Rifle_Mk47_Wrapper_C") != string::npos) return "Mk47 Mutant";
	if (Setting::Esp_Item_M16A4) if (Name.find("BP_Rifle_M16A4_Wrapper_C") != string::npos) return "M16A4";
	if (Setting::Esp_Item_G36C) if (Name.find("BP_Rifle_G36_Wrapper_C") != string::npos) return "G36C";
	if (Setting::Esp_Item_QBZ) if (Name.find("BP_Rifle_QBZ_Wrapper_C") != string::npos) return "QBZ";
	//
	if (Setting::Esp_Item_M249) if (Name.find("BP_Other_M249_Wrapper_C") != std::string::npos)return "M249";
	if (Setting::Esp_Item_DP28) if (Name.find("BP_Other_DP28_Wrapper_C") != string::npos) return "DP28";
	//MachineGun
	if (Setting::Esp_Item_PP19) if (Name.find("BP_MachineGun_PP19_Wrapper_C") != string::npos) return "PP19";
	if (Setting::Esp_Item_TommyGun) if (Name.find("BP_MachineGun_TommyGun_Wrapper_C") != string::npos) return "Tommy Gun";
	if (Setting::Esp_Item_MP5K) if (Name.find("BP_MachineGun_MP5K_Wrapper_C") != string::npos) return "MP5K";
	if (Setting::Esp_Item_UMP9) if (Name.find("BP_MachineGun_UMP9_Wrapper_C") != string::npos) return "UMP9";
	if (Setting::Esp_Item_Vector) if (Name.find("BP_MachineGun_Vector_Wrapper_C") != string::npos) return "Vector";
	if (Setting::Esp_Item_Uzi) if (Name.find("BP_MachineGun_Uzi_Wrapper_C") != string::npos) return "Uzi";
	//BP_Pistol
	if (Setting::Esp_Item_FlareGun) if (Name.find("BP_Pistol_Flaregun_Wrapper_C") != string::npos) return "Flare Gun";
	//BP_Ammo
	if (Setting::Esp_Item_Flare) if (Name.find("BP_Ammo_Flare_Pickup_C") != string::npos) return "Flare Ammo";
	if (Setting::Esp_Item_300Magnum) if (Name.find("BP_Ammo_300Magnum_Pickup_C") != std::string::npos) return "300Magnum";
	if (Setting::Esp_Item_762mm) if (Name.find("BP_Ammo_762mm_Pickup_C") != string::npos) return "7.62mm";
	if (Setting::Esp_Item_556mm) if (Name.find("BP_Ammo_556mm_Pickup_C") != string::npos) return "5.56mm";
	//BP_MZJ
	if (Setting::Esp_Item_RedDot) if (Name.find("BP_MZJ_HD_Pickup_C") != string::npos) return "Red Dot";
	if (Setting::Esp_Item_Holo) if (Name.find("BP_MZJ_QX_Pickup_C") != string::npos) return "Holo";
	if (Setting::Esp_Item_x2) if (Name.find("BP_MZJ_2X_Pickup_C") != string::npos) return "2x";
	if (Setting::Esp_Item_x3) if (Name.find("BP_MZJ_3X_Pickup_C") != string::npos) return "3x";
	if (Setting::Esp_Item_x4) if (Name.find("BP_MZJ_4X_Pickup_C") != string::npos) return "4x";
	if (Setting::Esp_Item_x6) if (Name.find("BP_MZJ_6X_Pickup_C") != string::npos) return "6x";
	if (Setting::Esp_Item_x8) if (Name.find("BP_MZJ_8X_Pickup_C") != string::npos) return "8x";
	///
	if (Setting::Esp_Item_Helmet1) if (Name.find("PickUp_BP_Helmet_Lv1") != string::npos) return "Helmet Lv1";
	if (Setting::Esp_Item_Helmet2) if (Name.find("PickUp_BP_Helmet_Lv2") != string::npos) return "Helmet Lv2";
	if (Setting::Esp_Item_Helmet3) if (Name.find("PickUp_BP_Helmet_Lv3") != string::npos) return "Helmet Lv3";

	if (Setting::Esp_Item_Armor1) if (Name.find("PickUp_BP_Armor_Lv1") != string::npos) return "Armor Lv1";
	if (Setting::Esp_Item_Armor2) if (Name.find("PickUp_BP_Armor_Lv2") != string::npos) return "Armor Lv2";
	if (Setting::Esp_Item_Armor3) if (Name.find("PickUp_BP_Armor_Lv3") != string::npos) return "Armor Lv3";

	if (Setting::Esp_Item_Bag1) if (Name.find("PickUp_BP_Bag_Lv1") != string::npos) return "Bag Lv1";
	if (Setting::Esp_Item_Bag2) if (Name.find("PickUp_BP_Bag_Lv2") != string::npos) return "Bag Lv2";
	if (Setting::Esp_Item_Bag3) if (Name.find("PickUp_BP_Bag_Lv3") != string::npos) return "Bag Lv3";

	if (Setting::Esp_Item_MedKit) if (Name.find("FirstAidbox_Pickup_C") != string::npos) return "Med Kit";
	if (Setting::Esp_Item_FirstAidKit) if (Name.find("Firstaid_Pickup_C") != string::npos) return "First Aid Kit";
	if (Setting::Esp_Item_Painkiller) if (Name.find("Pills_Pickup_C") != string::npos) return "Painkiller";
	if (Setting::Esp_Item_EnergyDrink) if (Name.find("Drink_Pickup_C") != string::npos) return "Energy Drink";
	if (Setting::Esp_Item_AdrenalineSyringe) if (Name.find("Injection_Pickup_C") != string::npos) return "Adrenaline Syringe";

	if (Setting::Esp_Item_Frag) if (Name.find("BP_Grenade_Shoulei_Weapon_Wrapper_C") != string::npos) return "Frag";
	if (Setting::G_Warning_Frag) if (Name.find("BP_Grenade_Shoulei_C") != string::npos) return "Frag Granade!";
	if (Setting::Esp_Item_Smoke) if (Name.find("BP_Grenade_Smoke_Weapon_Wrapper_C") != string::npos) return "Smoke";
	if (Setting::G_Warning_Smoke) if (Name.find("BP_Grenade_Smoke_C") != string::npos) return "Smoke Granade!";
	if (Setting::Esp_Item_Molotof) if (Name.find("BP_Grenade_Burn_Weapon_Wrapper_C") != string::npos) return "Molotof";
	if (Setting::G_Warning_Molotof) if (Name.find("BP_Grenade_Burn_C") != std::string::npos)return "Molotof Granade!";
	if (Setting::Esp_Item_PlayerDeadBox) if (Name.find("PlayerDeadBox_C") != string::npos)return "Dead-Box";
	if (Setting::Esp_Item_GasCan) 	if (Name.find("GasCan_Destructible_Pickup_C") != std::string::npos)return "GasCan";

	if (Name.find("AirAttackBomb_Livik_C") != std::string::npos || Name.find("AirAttackBomb_C") != std::string::npos) return "RedZone";
	if (Name.find("BP_AirDropBox_C") != std::string::npos ||
		Name.find("AirDropListWrapperActor") != std::string::npos ||
		Name.find("BP_AirDropBox_New_C") != std::string::npos)
		return "Air Drop";

	return "Unknown";
}

std::string GetBoxItems(int code)
{
	if (code == 101008)
	{
		Setting::colorcode = weapon::m762;
		return "M762";

	}
	else if (code == 306001)
	{
		Setting::colorcode = weapon::AWMimmo;
		return "AWM Ammo";
	}

	else if (code == 101003)
	{
		Setting::colorcode = weapon::scarl;
		return "SCAR-L";
	}
	else if (code == 302001)
	{

		Setting::colorcode = Colors::ammo7;
		return "7.62";
	}
	else if (code == 303001)
	{

		Setting::colorcode = Colors::ammo5;
		return "5.56";
	}
	else if (code == 602004)
	{
		Setting::colorcode = Colors::Grandes;

		return "Grenade";
	}
	else if (code == 601006)
	{
		Setting::colorcode = Colors::madkit;

		return "Medkit";
	}
	else if (code == 101004)
	{
		Setting::colorcode = weapon::m16;
		return "M416";
	}

	else if (code == 101010)
	{
		Setting::colorcode = Colors::g36;
		return "G36";
	}

	else if (code == 101006)
	{
		Setting::colorcode = Colors::aug;
		return "AUG";
	}

	else if (code == 101101)
	{
		Setting::colorcode = Colors::assm;
		return "ASM"; //time
	}

	else if (code == 101001)
	{
		Setting::colorcode = weapon::AKM;
		return "AKM";
	}

	else if (code == 101005)
	{
		Setting::colorcode = weapon::GROZZA;
		return "Groza";
	}

	else if (code == 103003)
	{
		Setting::colorcode = weapon::AWM;
		return "AWM";
	}

	else if (code == 103002)
	{
		Setting::colorcode = weapon::M24;
		return "M24";
	}

	else if (code == 103001)
	{
		Setting::colorcode = weapon::kar98;
		return "Kar98k";
	}

	else if (code == 103011)
	{
		Setting::colorcode = Colors::mosin;
		return "Mosin";
	}

	else if (code == 502002)
	{
		Setting::colorcode = Colors::helmat;
		return "Helmet Lv.2";
	}

	else if (code == 502003)
	{
		Setting::colorcode = Colors::helmat;
		return "Helmet Lv.3";
	}

	else if (code == 503002)
	{
		Setting::colorcode = Colors::armer;
		return "Armour Lv.2";
	}

	else if (code == 503003)
	{
		Setting::colorcode = Colors::armer;
		return "Armour Lv.3";
	}

	else if (code == 501006)
	{
		Setting::colorcode = Colors::bag;
		return "Bag Lv.3";
	}

	else if (code == 501005)
	{
		Setting::colorcode = Colors::bag;
		return "Bag Lv.2";
	}

	else if (code == 203014)
	{
		Setting::colorcode = Colors::scope3x;
		return "3X";

	}

	else if (code == 203004)
	{
		Setting::colorcode = Colors::scope4x;
		return "4x";
	}

	else if (code == 203015)
	{
		Setting::colorcode = Colors::scope6x;
		return "6x";
	}

	else if (code == 203005)
	{
		Setting::colorcode = weapon::scope8x;
		return "8x";
	}

	else if (code == 106007)
	{
		Setting::colorcode = weapon::Flare;
		return "Flaregun";
	}

	else if (code == 105001)
	{
		Setting::colorcode = Colors::M249;
		return "M249";
	}

	else if (code == 105002)
	{
		Setting::colorcode = Colors::dp;
		return "DP28";
	}

	else if (code == 105010)
	{
		Setting::colorcode = Colors::ammo5;
		return "MG3";
	}
	else if (code == 403989)
	{
		return "Ghillie";
		Setting::colorcode = Colors::ammo5;
	}
	else if (code == 403045)
	{
		Setting::colorcode = Colors::ammo5;
		return "Ghillie";
	}
	else if (code == 403187)
	{
		Setting::colorcode = Colors::ammo5;
		return  "Ghillie";
	}
	else if (code == 403188)
	{
		Setting::colorcode = Colors::ammo5;
		return  "Ghillie";
	}
	return "Unknown";

}

string GetVehicleType(string Name)
{
	if (Name.find("BRDM") != std::string::npos) return "BRDM";
	if (Name.find("Scooter") != std::string::npos) return "Scooter";
	if (Name.find("Motorcycle") != std::string::npos) return "Motorcycle";
	if (Name.find("Snowmobile") != std::string::npos) return "Snowmobile";
	if (Name.find("Tuk") != std::string::npos) return "Tuk";
	if (Name.find("Buggy") != std::string::npos) return "Buggy";
	if (Name.find("open") != std::string::npos) return "Sports";
	if (Name.find("close") != std::string::npos) return "Sports";
	if (Name.find("Dacia") != std::string::npos) return "Dacia";
	if (Name.find("Rony") != std::string::npos) return "Rony";
	if (Name.find("UAZ") != std::string::npos) return "UAZ";
	if (Name.find("MiniBus") != std::string::npos) return "Minibus";
	if (Name.find("Bigfoot") != std::string::npos) return "Monster";
	if (Name.find("PG117") != std::string::npos) return "PG117";
	if (Name.find("AquaRail") != std::string::npos) return "Aquarail";
	if (Name.find("VH_UTV_C") != std::string::npos) return "UTV";
	if (Name.find("CoupeRB") != std::string::npos) return "CoupeRB";
	if (Name.find("ATV1_C") != std::string::npos || Name.find("ATV2_C") != std::string::npos) return "Quad";
	if (Name.find("BP_AirDropPlane_C") != std::string::npos) return "Plane";
	return "Unknown";
}

bool IsBox(std::string classname)
{
	/*if ( classname.find("BP_AirDropBox_C") != std::string::npos)
		return true;*/
	if (classname.find("PickUpListWrapperActor") != std::string::npos || classname.find("AirDropListWrapperActor") != std::string::npos)
		return true;

	return false;
}

string GetNationName(string str)
{

	if (str == "AF")
		return "Afghanistan";

	if (str == "AL")
		return "Albania";

	if (str == "DZ")
		return "Algeria";

	if (str == "AS")
		return "American Samoa";

	if (str == "AD")
		return "Andorra";

	if (str == "AO")
		return "Angola";

	if (str == "AI")
		return "Anguilla";

	if (str == "AQ")
		return "Antarctica";

	if (str == "AG")
		return "Antigua  Barbuda";

	if (str == "AR")
		return "Argentina";

	if (str == "AM")
		return "Armenia";

	if (str == "AW")
		return "Aruba";

	if (str == "AU")
		return "Australia";

	if (str == "AT")
		return "Austria";

	if (str == "AZ")
		return "Azerbaijan";

	if (str == "BS")
		return "Bahamas";

	if (str == "BH")
		return "Bahrain";

	if (str == "BD")
		return "Bangladesh";

	if (str == "BB")
		return "Barbados";

	if (str == "BY")
		return "Belarus";

	if (str == "BE")
		return "Belgium";

	if (str == "BZ")
		return "Belize";

	if (str == "BJ")
		return "Benin";

	if (str == "BM")
		return "Bermuda";

	if (str == "BT")
		return "Bhutan";

	if (str == "BO")
		return "Bolivia";

	if (str == "BQ")
		return "Bonaire";

	if (str == "BA")
		return "Bosnia";

	if (str == "BW")
		return "Botswana";

	if (str == "BV")
		return "Bouvet Island";

	if (str == "BR")
		return "Brazil";

	if (str == "IO")
		return "British Indian";

	if (str == "BN")
		return "Brunei Darussalam";

	if (str == "BG")
		return "Bulgaria";

	if (str == "BF")
		return "Burkina Faso";

	if (str == "BI")
		return "Burundi";

	if (str == "CV")
		return "Cabo Verde";

	if (str == "KH")
		return "Cambodia";

	if (str == "CM")
		return "Cameroon";

	if (str == "CA")
		return "Canada";

	if (str == "KY")
		return "Cayman Islands";

	if (str == "CF")
		return "Cent. African Rep.";

	if (str == "TD")
		return "Chad";

	if (str == "CL")
		return "Chile";

	if (str == "CN")
		return "China";

	if (str == "CX")
		return "Christmas Island";

	if (str == "CC")
		return "Cocos Islands";

	if (str == "CO")
		return "Colombia";

	if (str == "KM")
		return "Comoros";

	if (str == "CD")
		if (str == "CG")
			return "Congo";

	if (str == "CK")
		return "Cook Islands";

	if (str == "CR")
		return "Costa Rica";

	if (str == "HR")
		return "Croatia";

	if (str == "CU")
		return "Cuba";

	if (str == "CW")
		return "Curacao";

	if (str == "CY")
		return "Cyprus";

	if (str == "CZ")
		return "Czechia";

	if (str == "CI")
		return "Cote d Ivoire";

	if (str == "DK")
		return "Denmark";

	if (str == "DJ")
		return "Djibouti";

	if (str == "DM")
		return "Dominica";

	if (str == "DO")
		return "Dominican Republic";

	if (str == "EC")
		return "Ecuador";

	if (str == "EG")
		return "Egypt";

	if (str == "SV")
		return "El Salvador";

	if (str == "GQ")
		return "Equatorial Guinea";

	if (str == "ER")
		return "Eritrea";

	if (str == "EE")
		return "Estonia";

	if (str == "SZ")
		return "Eswatini";

	if (str == "ET")
		return "Ethiopia";

	if (str == "FK")
		return "Falkland Islands";

	if (str == "FO")
		return "Faroe Islands";

	if (str == "FJ")
		return "Fiji";

	if (str == "FI")
		return "Finland";

	if (str == "FR")
		return "France";

	if (str == "GF")
		return "French Guiana";

	if (str == "PF")
		return "French Polynesia";

	if (str == "TF")
		return "French Territories";

	if (str == "GA")
		return "Gabon";

	if (str == "GM")
		return "Gambia";

	if (str == "GE")
		return "Georgia";

	if (str == "DE")
		return "Germany";

	if (str == "GH")
		return "Ghana";

	if (str == "GI")
		return "Gibraltar";

	if (str == "GR")
		return "Greece";

	if (str == "GL")
		return "Greenland";

	if (str == "GD")
		return "Grenada";

	if (str == "GP")
		return "Guadeloupe";

	if (str == "GU")
		return "Guam";

	if (str == "GT")
		return "Guatemala";

	if (str == "GG")
		return "Guernsey";

	if (str == "GN")
		return "Guinea";

	if (str == "GW")
		return "Guinea-Bissau";

	if (str == "GY")
		return "Guyana";

	if (str == "HT")
		return "Haiti";

	if (str == "HM")
		return "McDonald Islands";

	if (str == "VA")
		return "Vatican";

	if (str == "HN")
		return "Honduras";

	if (str == "HK")
		return "Hong Kong";

	if (str == "HU")
		return "Hungary";

	if (str == "JM")
		return "Jamaica";

	if (str == "JP")
		return "Japan";

	if (str == "JE")
		return "Jersey";

	if (str == "JO")
		return "Jordan";

	if (str == "KZ")
		return "Kazakhstan";

	if (str == "KE")
		return "Kenya";

	if (str == "KI")
		return "Kiribati";

	if (str == "KP")
		return "South Korea";

	if (str == "KR")
		return "North Korea";

	if (str == "KW")
		return "Kuwait";

	if (str == "KG")
		return "Kyrgyzstan";

	if (str == "LA")
		return "LP Democratic Rep.";

	if (str == "LV")
		return "Latvia";

	if (str == "LB")
		return "Lebanon";

	if (str == "LS")
		return "Lesotho";

	if (str == "LR")
		return "Liberia";

	if (str == "LY")
		return "Libya";

	if (str == "LI")
		return "Liechtenstein";

	if (str == "LT")
		return "Lithuania";

	if (str == "LU")
		return "Luxembourg";

	if (str == "MO")
		return "Macao";

	if (str == "MG")
		return "Madagascar";

	if (str == "MW")
		return "Malawi";

	if (str == "MY")
		return "Malaysia";

	if (str == "MV")
		return "Maldives";

	if (str == "ML")
		return "Mali";

	if (str == "MT")
		return "Malta";

	if (str == "MH")
		return "Marshall Islands";

	if (str == "MQ")
		return "Martinique";

	if (str == "MR")
		return "Mauritania";

	if (str == "MU")
		return "Mauritius";

	if (str == "YT")
		return "Mayotte";

	if (str == "MX")
		return "Mexico";

	if (str == "FM")
		return "Micronesia";

	if (str == "MD")
		return "Moldova";

	if (str == "MC")
		return "Monaco";

	if (str == "MN")
		return "Mongolia";

	if (str == "ME")
		return "Montenegro";

	if (str == "MS")
		return "Montserrat";

	if (str == "MA")
		return "Morocco";

	if (str == "MZ")
		return "Mozambique";

	if (str == "MM")
		return "Myanmar";

	if (str == "NA")
		return "Namibia";

	if (str == "NR")
		return "Nauru";

	if (str == "NP")
		return "Nepal";

	if (str == "NL")
		return "Netherlands";

	if (str == "NC")
		return "New Caledonia";

	if (str == "NZ")
		return "New Zealand";

	if (str == "NI")
		return "Nicaragua";

	if (str == "NE")
		return "Niger";

	if (str == "NG")
		return "Nigeria";

	if (str == "NU")
		return "Niue";

	if (str == "NF")
		return "Norfolk Island";

	if (str == "MP")
		return "Mariana Islands";

	if (str == "NO")
		return "Norway";

	if (str == "OM")
		return "Oman";

	if (str == "PK")
		return "Pakistan";

	if (str == "PW")
		return "Palau";

	if (str == "PS")
		return "Palestine";

	if (str == "PA")
		return "Panama";

	if (str == "PG")
		return "Papua New Guinea";

	if (str == "PY")
		return "Paraguay";

	if (str == "PE")
		return "Peru";

	if (str == "PH")
		return "Philippines";

	if (str == "PN")
		return "Pitcairn";

	if (str == "PL")
		return "Poland";

	if (str == "PT")
		return "Portugal";

	if (str == "PR")
		return "Puerto Rico";

	if (str == "QA")
		return "Qatar";

	if (str == "MK")
		return "North Macedonia";

	if (str == "RO")
		return "Romania";

	if (str == "RU")
		return "Russia";

	if (str == "RW")
		return "Rwanda";

	if (str == "RE")
		return "Reunion";

	if (str == "BL")
		return "Saint Barthelemy";

	if (str == "SH")
		return "Saint Helena";

	if (str == "KN")
		return "Kitts and Nevis";

	if (str == "LC")
		return "Saint Lucia";

	if (str == "MF")
		return "Saint Martin";

	if (str == "PM")
		return "Saint Pierre";

	if (str == "VC")
		return "Saint Vincent";

	if (str == "WS")
		return "Samoa";

	if (str == "SM")
		return "San Marino";

	if (str == "ST")
		return "Sao Tome";

	if (str == "SA")
		return "Saudi Arabia";

	if (str == "SN")
		return "Senegal";

	if (str == "RS")
		return "Serbia";

	if (str == "SC")
		return "Seychelles";

	if (str == "SL")
		return "Sierra Leone";

	if (str == "SG")
		return "Singapore";

	if (str == "SX")
		return "Sint Maarten";

	if (str == "SK")
		return "Slovakia";

	if (str == "SI")
		return "Slovenia";

	if (str == "SB")
		return "Solomon Islands";

	if (str == "SO")
		return "Somalia";

	if (str == "ZA")
		return "South Africa";

	if (str == "GS")
		return "South Georgia";

	if (str == "SS")
		return "South Sudan";

	if (str == "ES")
		return "Spain";

	if (str == "LK")
		return "Sri Lanka";

	if (str == "SD")
		return "Sudan";

	if (str == "SR")
		return "Suriname";

	if (str == "SJ")
		return "Svalbard";

	if (str == "SE")
		return "Sweden";

	if (str == "CH")
		return "Switzerland";

	if (str == "SY")
		return "Syria";

	if (str == "TW")
		return "Taiwan";

	if (str == "TJ")
		return "Tajikistan";

	if (str == "TZ")
		return "Tanzania";

	if (str == "TH")
		return "Thailand";

	if (str == "TL")
		return "Timor-Leste";

	if (str == "TG")
		return "Togo";

	if (str == "TK")
		return "Tokelau";

	if (str == "TO")
		return "Tonga";

	if (str == "TT")
		return "Trinidad Tobago";

	if (str == "TN")
		return "Tunisia";

	if (str == "TR")
		return "Turkey";

	if (str == "TM")
		return "Turkmenistan";

	if (str == "TC")
		return "Turks  Caicos Islands";

	if (str == "TV")
		return "Tuvalu";

	if (str == "UG")
		return "Uganda";

	if (str == "UA")
		return "Ukraine";

	if (str == "AE")
		return "United Arab Emirates";

	if (str == "GB")
		return "United Kingdom";

	if (str == "US")
		return "America";

	if (str == "UY")
		return "Uruguay";

	if (str == "UZ")
		return "Uzbekistan";

	if (str == "VU")
		return "Vanuatu";

	if (str == "VE")
		return "Venezuela";

	if (str == "VN")
		return "Viet Nam";

	if (str == "VG")
		return "Virgin Islands";

	if (str == "VI")
		return "Virgin Islands";

	if (str == "WF")
		return "Wallis and Futuna";

	if (str == "EH")
		return "Western Sahara";

	if (str == "YE")
		return "Yemen";

	if (str == "ZM")
		return "Zambia";

	if (str == "ZW")
		return "Zimbabwe";

	if (str == "AX")
		return "Aland Islands";

	if (str == "IS")
		return "Iceland";

	if (str == "IN")
		return "India";

	if (str == "ID")
		return "Indonesia";

	if (str == "IR")
		return "Iran";

	if (str == "IQ")
		return "Iraq";

	if (str == "IE")
		return "Ireland";

	if (str == "IM")
		return "Isle of Man";

	if (str == "IL")
		return "Israel";

	if (str == "IT")
		return "Italy";

	return "";
}


std::string Data::playerstatus(int GetEnemyState)
{
	switch (GetEnemyState)
	{
	case 0:
		return "AFK";
		break;
	case 1:
		return "In Water";
		break;
	case 268435464:
		return "Play Emotion";
		break;
	case 8:
		return "Stand";
		break;
	case 520:
	case 544:
	case 656:
	case 521:
	case 528:
		return "Aiming";
		break;
	case 1680:
	case 1672:
	case 1673:
	case 1032:
	case 1544:
	case 1545:
	case 1033:
		return "Peek";
		break;
	case 9:
		return "Walking";
		break;
	case 11:
		return "Running";
		break;
	case 4194304:
		return "Swimming";
		break;
	case 32784:
		return "Reviving";
		break;
	case 16777224:
		return "Climbing";
		break;
	case 8200:
	case 8208:
		return "Punching";
		break;
	case 16:
	case 17:
	case 19:
		return "Crouch";
		break;
	case 32:
	case 33:
	case 35:
	case 5445:
	case 762:
		return "Snake";
		break;
	case 72:
	case 73:
	case 75:
		return "Jumping";
		break;
	case 264:
	case 272:
	case 273:
	case 288:
	case 265:
	case 329:
		return "Reloading";
		break;
	case 137:
	case 144:
	case 201:
	case 145:
	case 160:
	case 649:
	case 648:
	case 1160:
	case 1161:
	case 1169:
		return "Firing";
		break;
	case 131070:
	case 131071:
	case 131072:
	case 131073:
	case 131075:
	case 131074:
		return "Knocked";
		break;
	case 33554440:
	case 524296:
	case 1048584:
	case 524288:
		return "Driving";
		break;
	case 16392:
	case 16393:
	case 16401:
	case 16416:
	case 16417:
	case 16457:
	case 16400:
	case 17401:
	case 17417:
	case 17425:
	case 17424:
		return "Throwing Bomb";
		break;
	default:
		return "";
		break;
	}
}


std::string PlayerWeapon(std::string str)
{
	if (str == "BP_Sniper_AWM_C")
		return "AWM";
	else if (str == "BP_Sniper_QBU_C")
		return "QBU";
	else if (str == "BP_Sniper_SLR_C")
		return "SLR";
	else if (str == "BP_Sniper_SKS_C")
		return "SKS";
	else if (str == "BP_Sniper_Mini14_C")
		return "Mini14";
	else if (str == "BP_Sniper_M24_C")
		return "M24";
	else if (str == "BP_Sniper_Kar98k_C")
		return "Kar98k";
	else if (str == "BP_Sniper_VSS_C")
		return "VSS";
	else if (str == "BP_Sniper_Win94_C")
		return "Win94";
	else if (str == "BP_Sniper_Mosin_C")
		return "Mosin";
	else if (str == "BP_Sniper_MK12_C")
		return "MK12";
	else if (str == "BP_Rifle_AUG_C")
		return "AUG";
	else if (str == "BP_Rifle_M762_C")
		return "M762";
	else if (str == "BP_Rifle_SCAR_C")
		return "SCAR";
	else if (str == "BP_Rifle_M416_C")
		return "M416";
	else if (str == "BP_Rifle_M16A4_C")
		return "M16A4";
	else if (str == "BP_Rifle_Mk47_C")
		return "Mk47";
	else if (str == "BP_Rifle_G36_C")
		return "G36";
	else if (str == "BP_Rifle_QBZ_C")
		return "QBZ";
	else if (str == "BP_Rifle_AKM_C")
		return "AKM";
	else if (str == "BP_Rifle_Groza_C")
		return "Groza";
	else if (str == "BP_Other_DP28_C")
		return "DP28";
	else if (str == "BP_Other_M249_C")
		return "M249";
	else if (str == "BP_MachineGun_P90_C")
		return "P90";
	else if (str == "BP_ShotGun_S12K_C")
		return "S12K";
	else if (str == "BP_ShotGun_DP12_C")
		return "DP12";
	else if (str == "BP_ShotGun_S686_C")
		return "S686";
	else if (str == "BP_ShotGun_S1897_C")
		return "S1897";
	else if (str == "BP_ShotGun_SawedOff_C")
		return "SawedOff";
	else if (str == "BP_MachineGun_PP19_C")
		return "PP19";
	else if (str == "BP_MachineGun_TommyGun_C")
		return "TommyGu";
	else if (str == "BP_MachineGun_MP5K_C")
		return "MP5K";
	else if (str == "BP_MachineGun_UMP9_C")
		return "UMP9";
	else if (str == "BP_MachineGun_Vector_C")
		return "Vector";
	else if (str == "BP_MachineGun_Uzi_C")
		return "Uzi";
	else if (str == "BP_Pistol_Flaregun_C")
		return "Flaregun";
	else if (str == "BP_Pistol_R1895_C")
		return "R1895";
	else if (str == "BP_Pistol_Vz61_C")
		return "Vz61";
	else if (str == "BP_Pistol_P92_C")
		return "P92";
	else if (str == "BP_Pistol_P18C_C")
		return "P18C";
	else if (str == "BP_Pistol_R45_C")
		return "R45";
	else if (str == "BP_Pistol_P1911_C")
		return "P1911";
	else if (str == "BP_Pistol_DesertEagle_C")
		return "DesertEagle";
	else if (str == "BP_WEP_Mk14_C")
		return "Mk14";
	else if (str == "BP_Other_CrossBow_C")
		return "CrossBow";
	else if (str == "BP_Grenade_Shoulei_C")
		return "Shoulei Grenade";
	else if (str == "BP_Grenade_Smoke_C")
		return "Smoke Grenade";
	else if (str == "BP_Grenade_Burn_C")
		return "Burn Grenade";
	else
		return "";
	return "";
}

std::string scopes(int fov)
{
	if (fov == 70)
		return "Iron";
	else if (fov == 55)
		return "RedDot";
	else if (fov == 44)
		return "X2";
	else if (fov == 26)
		return "X3";
	else if (fov == 20)
		return "X4";
	else if (fov == 13)
		return "X6";
	else if (fov == 11)
		return "X8";
	else
		return "None";

	return "";
}

string GetPlayerFlag(DWORD BaseAddress)
{
	char* String = new char[34];
	for (int i = 0; i < 34; i++)
	{
		String[i] = Utility::ReadMemoryEx<char>(BaseAddress + i * 2);
	}

	string Name = String;

	delete[] String;
	return Name;
}

uint32_t DecryptActorsArray(uint32_t uLevel, int Actors_Offset, int EncryptedActors_Offset)
{
	if (uLevel < 0x10000000)
		return 0;

	if (Utility::ReadMemoryEx<uint32_t>(uLevel + Actors_Offset) > 0)
		return uLevel + Actors_Offset;

	if (Utility::ReadMemoryEx<uint32_t>(uLevel + EncryptedActors_Offset) > 0)
		return uLevel + EncryptedActors_Offset;

	auto Encryption = Utility::ReadMemoryEx<ActorsEncryption>(uLevel + EncryptedActors_Offset + 0x0C);

	if (Encryption.Enc_1 > 0)
	{
		uint32_t DecryptedActorsPointer = 0;
		int DecCount = 4;
		int index = 0;
		while (index < DecCount) {
			auto ival = Utility::ReadMemoryEx<uint32_t>(Encryption.Enc_1 + 0x80 + (0x4 * index));
			DecryptedActorsPointer += Utility::ReadMemoryEx<uint8_t>(Encryption.Enc_1 + ival) << (0x8 * index++);
		}
		return DecryptedActorsPointer;
	}
	else if (Encryption.Enc_2 > 0)
	{
		auto Encrypted_Actors = Utility::ReadMemoryEx<uint32_t>(Encryption.Enc_2);
		if (Encrypted_Actors > 0)
		{
			return ((unsigned short)Encrypted_Actors - 0x400) & 0xFF00
				| (unsigned char)(Encrypted_Actors - 0x04)
				| (Encrypted_Actors + 0xFC0000) & 0xFF0000
				| (Encrypted_Actors - 0x4000000) & 0xFF000000;
		}
	}
	else if (Encryption.Enc_3 > 0)
	{
		auto Encrypted_Actors = Utility::ReadMemoryEx<uint32_t>(Encryption.Enc_3);
		if (Encrypted_Actors > 0)
			return _rotr(Encrypted_Actors, 0x18);
	}
	else if (Encryption.Enc_4 > 0)
	{
		auto Encrypted_Actors = Utility::ReadMemoryEx<uint32_t>(Encryption.Enc_4);
		if (Encrypted_Actors > 0)
			return Encrypted_Actors ^ 0xCDCD00;
	}
	return 0;
}


DWORD Data::NetDriver;
DWORD Data::LocalPlayer;
CameraCacheEntry Data::CameraCache;

DWORD Data::LocalController;
DWORD Data::PlayerCameraManager;

string Data::LocalPawn = "";
string Data::PlayerPlayerName = "";
string Data::PlayerNation = "";
string Data::PlayerUID = "";

int Data::PlayerTotalKills;
int Data::PlayerTeamID;
int Data::PlayerLevel;
FLOAT Data::PlayerHealth;

FLOAT Data::PlayerTravelDistance;

DWORD Data::PlayerController;
DWORD Data::Ue4Base;
DWORD Data::EntityAddress = 0;
vector<AActor> Data::AActorList = {};
vector<BombAlert> Data::BombAlertList = {};
vector<Item> Data::ItemList = {};
vector<Vehicle> Data::VehicleList = {};


VOID Data::QueryThread()
{
	DWORD GName;
	DWORD GWorld;
	DWORD ViewMatrix;
	if (Setting::Vng == true)
	{
		GWorld = Utility::ReadMemoryEx<UINT>(Data::ViewMatrixBase + 101604) + 60;
		GName = Utility::ReadMemoryEx<UINT>(Data::ViewMatrixBase - 3614220) + 136;
	}
	else
	{
		GWorld = Utility::ReadMemoryEx<UINT>(Data::ViewMatrixBase + 101604) + 60;
		GName = Utility::ReadMemoryEx<UINT>(Data::ViewMatrixBase - 3614220) + 136;
	}

	DWORD PersistentLevel = 0;
	DWORD ServerConnection = 0;
	DWORD EntityList = 0;
	INT EntityCount = 0;

	DWORD GameStateBASE;
	DWORD PlayerStateBASE;

	DWORD EntityStruct = 0;
	string EntityType = "";

	DWORD RootComponent = 0;
	INT MyTeamId = 9999;


	DWORD MeshAddv;
	DWORD BodyAddv;
	DWORD BoneAddv;

	string GrenadeType = "";
	string ItemType = "";
	string VehicleType = "";
	string airdroptype = "";
	string wep = "";

	auto ActorsPointerAddress = 0;

	vector<AActor> AActorList = {};
	vector<BombAlert> BombAlertList = {};
	vector<Item> ItemList = {};
	vector<Vehicle> VehicleList = {};

	while (true)
	{
		Sleep(20);
		g_pEsp->lootbox.clear();
		UWorld = Utility::ReadMemoryEx<DWORD>(GWorld);
		PersistentLevel = Utility::ReadMemoryEx<DWORD>(UWorld + Offset::PersistentLevel);


		ActorsPointerAddress = DecryptActorsArray(PersistentLevel, 0x70, 0x334);//--Actors

		NetDriver = Utility::ReadMemoryEx<DWORD>(UWorld + Offset::NetDriver);
		ServerConnection = Utility::ReadMemoryEx<DWORD>(NetDriver + Offset::ServerConnection);
		PlayerController = Utility::ReadMemoryEx<DWORD>(ServerConnection + Offset::PlayerController);
		LocalPlayer = Utility::ReadMemoryEx<DWORD>(PlayerController + Offset::AcknowledgedPawn);

		LocalController = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::STExtraPlayerCharacter::STPlayerController);
		PlayerCameraManager = Utility::ReadMemoryEx<DWORD>(LocalController + Offset::PlayerController1::PlayerCameraManager);
		CameraCache = Utility::ReadMemoryEx<CameraCacheEntry>(PlayerCameraManager + Offset::PlayerCameraManager1::CameraCache);

		EntityList = Utility::ReadMemoryEx<uint32_t>(ActorsPointerAddress);
		EntityCount = Utility::ReadMemoryEx<int>(ActorsPointerAddress + 0x4);

		if (EntityCount > 1024)
			EntityCount = 1024;
		for (int i = 0; i < EntityCount; ++i)
		{
			EntityAddress = Utility::ReadMemoryEx<DWORD>(EntityList + i * 4);
			EntityStruct = Utility::ReadMemoryEx<DWORD>(EntityAddress + 0x10);



			//std::cout << Data::PlayerTravelDistance << std::endl;

			if (Emulator::IsGameLoop7 == TRUE)
			{
				EntityType = GetEntityType2(GName, EntityStruct);
			}

			if (EntityType == "BP_PlayerLobbyPawn_C" || EntityType == "Lobby_Main_int_C")
			{
				Data::LocalPawn = "InLobby";
			}
			else if (EntityType == "BRPlayerStateTeam_DeathMatch")
			{
				Data::LocalPawn = "InTDM";
			}
			else if (EntityType == "BuildingKanerjing_Trigger")
			{
				Data::LocalPawn = "InLivik";
			}
			else if (EntityType == "BP_PlayerState_SocialIsland_C")
			{
				Data::LocalPawn = "InCheerPark";
			}
			else if (EntityType == "PUBG_Desert_C")
			{
				Data::LocalPawn = "InMiramar";
			}
			else if (EntityType == "PUBG_Savage_Main_C")
			{
				Data::LocalPawn = "InSanhok";
			}
			else if (EntityType == "SummerLand_ObjectPoolMgr")
			{
				Data::LocalPawn = "InKarakin";
			}
			else if (EntityType == "BP_BRGameState_TeamHardPoint_C")
			{
				Data::LocalPawn = "InDomination";
			}

			else if (EntityType == "SingleTraining_Main_C")
			{
				Data::LocalPawn = "InTraining";
			}

			PlayerStateBASE = Utility::ReadMemoryEx<DWORD>(LocalPlayer + 0x300);


			Data::PlayerTotalKills = Utility::ReadMemoryEx<INT>(PlayerStateBASE + 0x4bc);
			if (Setting::ownInfo)
			{
				Data::PlayerPlayerName = GetPlayerName(Utility::ReadMemoryEx<DWORD>(PlayerStateBASE + 0x2f4));
				Data::PlayerNation = GetPlayerFlag(Utility::ReadMemoryEx<DWORD>(PlayerStateBASE + 0x49c));
				Data::PlayerTeamID = Utility::ReadMemoryEx<INT>(PlayerStateBASE + 0x4a8);
				Data::PlayerLevel = Utility::ReadMemoryEx<INT>(PlayerStateBASE + 0x460);
				Data::PlayerHealth = Utility::ReadMemoryEx<FLOAT>(PlayerStateBASE + 0xeb0);
				Data::PlayerUID = GetPlayerUID(Utility::ReadMemoryEx<DWORD>(PlayerStateBASE + 0x434));
				Data::PlayerTravelDistance = Utility::ReadMemoryEx<FLOAT>(PlayerStateBASE + 0x3f4);
			}

			RootComponent = Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::RootComponent);

			if (IsPlayer(EntityType))
			{
				AActor AActor;

				GameStateBASE = Utility::ReadMemoryEx<DWORD>(UWorld + Offset::GameStateBase);


				if (Setting::gameInfo)
				{
					Setting::AlivePlayers = Utility::ReadMemoryEx<INT>(GameStateBASE + Offset::AlivePlayerNum);
					Setting::TimeRemind = Utility::ReadMemoryEx<INT>(GameStateBASE + Offset::ElapsedTime);
					Setting::AliveTeams = Utility::ReadMemoryEx<INT>(GameStateBASE + Offset::AliveTeamNum);
					Setting::RealPls = Utility::ReadMemoryEx<INT>(GameStateBASE + Offset::PlayerNum);
					Setting::ZoneID = Utility::ReadMemoryEx<INT>(GameStateBASE + Offset::CurCircleWave);
					Setting::MyTeamID = Utility::ReadMemoryEx<INT>(LocalPlayer + Offset::TeamId);
					Setting::GameID = Utility::ReadMemoryEx<INT>(GameStateBASE + Offset::GameModeID);
				}



				AActor.TeamId = Utility::ReadMemoryEx<INT>(EntityAddress + Offset::TeamId);
				AActor.Address = EntityAddress;
				AActor.status = Utility::ReadMemoryEx<int>(EntityAddress + Offset::CurrentStates);


				if (AActor.Address == LocalPlayer)
				{
					MyTeamId = AActor.TeamId;
					continue;
				}


				if (AActor.TeamId == MyTeamId) continue;

				AActor.IsDead = Utility::ReadMemoryEx<INT>(EntityAddress + Offset::bDead) == 0 ? true : false;
				if (AActor.TeamId == MyTeamId) continue;

				AActor.Position = Utility::ReadMemoryEx<VECTOR3>(RootComponent + Offset::Position);
				AActor.IsBot = Utility::ReadMemoryEx<bool>(EntityAddress + Offset::IsBot);


				if (Setting::PlayerWeapon)
				{
					if (Offset::weaponOffset != 0)
					{
						wep = PlayerWeapon(GetEntityType2(GName, Utility::ReadMemoryEx<DWORD>(Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::weaponOffset) + 16)));
						if (wep == "") {
							wep = "Fist";
						}
						AActor.Weapon = wep;
					}
				}

				if (!AActor.IsBot)
				{
					AActor.Name = GetPlayerName(Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::Name));
					AActor.Nation = GetPlayerFlag(Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::Nation));
				}
				else
				{
					Setting::linescolors = { 1.00f, 1.00f, 1.00f , 1.00f };
					AActor.Name = " BOT ";
					AActor.Nation = "";
				}

				AActor.Health = Utility::ReadMemoryEx<FLOAT>(EntityAddress + Offset::Health);
				AActor.HealthMax = Utility::ReadMemoryEx<FLOAT>(EntityAddress + Offset::HealthMax);
				AActor.Velocity = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(AActor.Address + Offset::CharacterMovement) + Offset::LastUpdateVelocity);
				AActor.TeamId = Utility::ReadMemoryEx<INT>(EntityAddress + Offset::TeamId);


				if (Setting::Bone)
				{
					MeshAddv = Utility::ReadMemoryEx<DWORD>(AActor.Address + Offset::Mesh);
					BodyAddv = MeshAddv + Offset::BodyAddv;
					BoneAddv = Utility::ReadMemoryEx<DWORD>(MeshAddv + Offset::MinLOD) + 48;
					AActor.HeadPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 5 * 48);
				}

				if (Setting::Bone)
				{
					AActor.ChestPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 4 * 48);
					AActor.PelvisPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 1 * 48);
					AActor.lSholderPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 11 * 48);
					AActor.rSholderPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 32 * 48);
					AActor.lElbowPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 12 * 48);
					AActor.rElbowPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 33 * 48);
					AActor.lWristPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 63 * 48);
					AActor.rWristPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 62 * 48);
					AActor.lThighPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 52 * 48);
					AActor.rThighPos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 56 * 48);
					AActor.lKneePos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 53 * 48);
					AActor.rKneePos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 57 * 48);
					AActor.lAnklePos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 54 * 48);
					AActor.rAnklePos = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 58 * 48);
				}

				AActorList.push_back(AActor);
			}


			if (Setting::Item)
			{
				ItemType = GetItemType(EntityType);
				if (ItemType.find("Unknown") == std::string::npos)
				{
					Item Item;
					Item.Name = ItemType;
					Item.Position = Utility::ReadMemoryEx<VECTOR3>(RootComponent + Offset::Position);

					ItemList.push_back(Item);
				}
			}

			if (Setting::Vehicle)
			{
				VehicleType = GetVehicleType(EntityType);
				if (VehicleType.find("Unknown") == std::string::npos)
				{

					Vehicle Vehicle;
					Vehicle.Name = VehicleType;
					Vehicle.Position = Utility::ReadMemoryEx<VECTOR3>(RootComponent + Offset::Position);

					DWORD veh = Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::VehicleCommon);
					float HP = Utility::ReadMemoryEx<float>(veh + Offset::vHP);
					float HPMax = Utility::ReadMemoryEx<float>(veh + Offset::vHPMax);
					Vehicle.HP = (int)(HP * 100 / HPMax);

					Vehicle.isDriving = Utility::ReadMemoryEx<DWORD>(EntityAddress + 0x71d); //bool bIsEngineStarted;//(ByteOffset: 0, ByteMask: 1, FieldMask: 255)[Offset:


					float Fuel = Utility::ReadMemoryEx<float>(veh + Offset::vFuel);
					float FuelMax = Utility::ReadMemoryEx<float>(veh + Offset::vFuelMax);
					Vehicle.Fuel = (int)(Fuel * 100 / FuelMax);

					VehicleList.push_back(Vehicle);
				}
			}

			if (Setting::deadbox)
			{
				if (IsBox(EntityType))
				{

					g_pEsp->lootbox.push_back(g_pEsp->lbox);
					DWORD count = Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::boxItemCount);
					if (count > 30)
						count = 30;
					g_pEsp->lbox.boxitem.clear();
					if (count > 0)
					{
						long itemBase = Utility::ReadMemoryEx<DWORD>(EntityAddress + Offset::boxItemBase);
						long itemAddv;

						for (int t = 0; t < count; t++)
						{
							itemAddv = itemBase + t * 48;
							// std::string bitm = Dead(Utility::ReadMemoryEx<DWORD>(itemAddv + 0x4), "");
							std::string bitm = GetBoxItems(Utility::ReadMemoryEx<DWORD>(itemAddv + 0x4));
							if (bitm.find("Unknown") == std::string::npos)
							{
								Itemb temo;
								bitm.append("  :  ").append(std::to_string(Utility::ReadMemoryEx<DWORD>(itemAddv + 0x18)));
								g_pEsp->lbox.Position = Utility::ReadMemoryEx<VECTOR3>(RootComponent + Offset::Position);
								temo.colorcod = Setting::colorcode;
								temo.Displayname = bitm;
								g_pEsp->lbox.boxitem.push_back(temo);
								// bitm.clear();
							}
						}
					}
				}
			}

		}

		Data::AActorList.clear();

		Data::BombAlertList.clear();
		Data::ItemList.clear();
		Data::VehicleList.clear();
		Data::AActorList = AActorList;
		Data::BombAlertList = BombAlertList;
		Data::ItemList = ItemList;
		Data::VehicleList = VehicleList;
		g_pEsp->lootboxr = g_pEsp->lootbox;
		AActorList.clear();
		BombAlertList.clear();
		ItemList.clear();
		VehicleList.clear();

		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
}