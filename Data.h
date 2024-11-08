#pragma once

#include "Includes.h"
#include "Utility.h"
#include "Setting.h"
#include "Algorithm.h"
#include "Offset.h"
#include "Global.h"

struct AActor
{
	bool IsBot;
	bool IsDead;
	int status;
	int TotalPlayer;
	VECTOR3 Position;
	FLOAT Health;
	FLOAT HealthMax;
	string Name;
	string Nation;
	string Weapon;
	INT TeamId;
	DWORD Address;
	VECTOR3 Velocity;

	//INT AlivePlayers;
	//INT TimeRemind;
	//INT AliveTeams;
	//INT RealPls;
	//INT ZoneID;
	//INT MyTeamID;
	//INT GameID;


	VECTOR3 HeadPos;
	VECTOR3 ChestPos;
	VECTOR3 PelvisPos;
	VECTOR3 lSholderPos;
	VECTOR3 rSholderPos;
	VECTOR3 lElbowPos;
	VECTOR3 rElbowPos;
	VECTOR3 lWristPos;
	VECTOR3 rWristPos;
	VECTOR3 lThighPos;
	VECTOR3 rThighPos;
	VECTOR3 lKneePos;
	VECTOR3 rKneePos;
	VECTOR3 lAnklePos;
	VECTOR3 rAnklePos;
};

struct BombAlert
{
	string Name;
	VECTOR3 Position;
};

struct Item
{
	string Name;
	VECTOR3 Position;
};

struct Vehicle
{
	string Name;
	VECTOR3 Position;
	int HP;
	bool isDriving;
	int Fuel;
};

struct Itemb {
	std::string Displayname;
	ImVec4 colorcod;

};

struct Deadbox
{
	int picid;
	std::vector<Itemb> boxitem;
	string Name;
	VECTOR3 Position;
};

struct ActorsEncryption {
	uint32_t Enc_1; //0x0340 
	uint32_t Enc_2; //0x0344 
	uint32_t Enc_3; //0x0348 
	uint32_t Enc_4; //0x034C ;

};

struct Encryption_Chunk {
	uint32_t val_1, val_2, val_3, val_4;
};

class Espp {
public:
	std::string airdropstring;
	std::vector<Deadbox> lootbox, lootboxr;
	VECTOR3 mypos;
	DWORD myadd;
	Deadbox lbox;
};
extern Espp* g_pEsp;

namespace Data
{
	extern DWORD ViewMatrixBase;
	extern DWORD UWorld;
	extern DWORD NetDriver;
	extern DWORD LocalPlayer;
	extern CameraCacheEntry CameraCache;
	extern DWORD PlayerCameraManager;
	extern string LocalPawn;
	extern int PlayerTeamID;
	extern int PlayerLevel;
	extern int PlayerTotalKills;
	extern string PlayerUID;
	extern FLOAT PlayerTravelDistance;
	extern FLOAT PlayerHealth;
	extern string PlayerNation;
	extern string PlayerPlayerName;
	extern DWORD LocalController;
	extern DWORD ue4Headerr;
	extern DWORD PlayerController;
	extern DWORD EntityAddress;
	extern vector<AActor> AActorList;
	extern vector<BombAlert> BombAlertList;
	extern vector<Item> ItemList;
	extern vector<Vehicle> VehicleList;
	extern DWORD Ue4Base;

	DWORD GetViewMatrixBase(DWORD StartAddress, DWORD EndAddress);
	std::string playerstatus(int GetEnemyState);
	VOID QueryThread();
};