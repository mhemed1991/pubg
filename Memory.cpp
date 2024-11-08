#include "Memory.h"
#include "Aimbot.h"
#include<thread>


//0xC7, 0x45, 0x78, 0x00, 0x00, 0x00, 0x00,                        // mov[ebp + 78],00000000 
//0x83, 0x3D, 0x00, 0x00, 0x00, 0x00, 0x01,                        // cmp dword ptr[00000000],01 
//0x74, 0x0E,                                                      // je 0000001E
//0x60,                                                            // pushad
//0x8B, 0x5D, 0x50,                                                // mov ebx,[ebp + 00]
//0x8B, 0x53, 0x18,                                                // mov edx,[ebx + 18]
//0x8A, 0x02,                                                      // mov al,[edx]
//0x3C, 0xEC,   //26                                               // cmp al,30    // Need update
//0x74, 0x02,                                                      // je 0000001F
//0x61,                                                            // popad
//0xC3,                                                            // ret
//0x8A, 0x42, 0x01,                                                // mov al,[edx + 01]
//0x3C, 0x97,  //35                                                // cmp al,C2    // Need update
//0x75, 0x14,                                                      // jne 0000003A
//0xC7, 0x83, 0x20, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      // mov[ebx + 00000230],00000000 
//0xC7, 0x83, 0x24, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      // mov[ebx + 00000234],00000000 
//0xEB, 0xE1


BYTE MagicBulletShell[60]
{
 0xC7, 0x45, 0x78, 0x00, 0x00, 0x00, 0x00,
0x83, 0x3D, 0x00, 0x00, 0x00, 0x00, 0x01,
0x74, 0x0E,
0x60,
0x8B, 0x5D, 0x50,
0x8B, 0x53, 0x18,
0x8A, 0x02,
0x3C, 0x88,
0x74, 0x02,
0x61,
0xC3,
0x8A, 0x42, 0x01,
0x3C, 0x94,
0x75, 0x14,
0xC7, 0x83, 0x80, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xC7, 0x83, 0x84, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xEB, 0xE1
};

BYTE MagicBulletShellVng[60]
{
0xC7, 0x45, 0x78, 0x00, 0x00, 0x00, 0x00,
0x83, 0x3D, 0x00, 0x00, 0x00, 0x00, 0x01,
0x74, 0x0E,
0x60,
0x8B, 0x5D, 0x50,
0x8B, 0x53, 0x18,
0x8A, 0x02,
0x3C, 0x88,
0x74, 0x02,
0x61,
0xC3,
0x8A, 0x42, 0x01,
0x3C, 0x94,
0x75, 0x14,
0xC7, 0x83, 0x80, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xC7, 0x83, 0x84, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xEB, 0xE1
};



BYTE MagicBulletSearch1[] = { 0x66, 0x0F, 0x7E, '?', 0x80, 0x02, 0x00, 0x00, 0xC7, 0x45, 0x78, 0xC0 };
//BYTE MagicBulletSearch1[] = { 0x66, 0x0F, 0x7E, '?', 0x28, 0x02, 0x00, 0x00, 0xC7, 0x45, 0x78,0x18 /* 2.1 was D8 ,0x78 maybe for 2,2 0x6c 18 60*/ };
BYTE MagicBulletSearchVng[] = { 0x66, 0x0F, 0x7E, '?', 0x80, 0x02, 0x00, 0x00, 0xC7, 0x45, 0x78, 0xC0 };

DWORD MagicBulletAddress = 0;
vector<DWORD_PTR> MagicBulletList = {};
INT MagicBulletHook = 0;
BYTE RealByteCode[7];
DWORD FlyCarAddress = 0;
VOID GetMagicAddress()
{
	std::vector<DWORD_PTR> FoundedBase;
	if (Setting::Vng == true) {
		Utility::MemSearch(MagicBulletSearchVng, sizeof(MagicBulletSearchVng), 0x0D000000, 0x10000000, 0, 0, FoundedBase);
	}
	else {
		Utility::MemSearch(MagicBulletSearch1, sizeof(MagicBulletSearch1), 0x0D000000, 0x10000000, 0, 0, FoundedBase);
	}



	for (int i = 0; i < FoundedBase.size(); i++)
	{
		if (Setting::Vng == true)
		{
			if (Utility::ReadMemoryEx<BYTE>(FoundedBase[i] + 0xC) == 0x52)//0xBC 2.1   //0x47 2.0  //  0x79  1.9 // 0xE6 2.2 // 2.3 0xA4 // 2.4 0x9D
			{
				MagicBulletList.push_back(FoundedBase[i]);
				MagicBulletAddress = FoundedBase[i];
			}
		}
		else
		{
			if (Utility::ReadMemoryEx<BYTE>(FoundedBase[i] + 0xC) == 0x52)//0xBC 2.1   //0x47 2.0  //  0x79  1.9 // 0xEC 2.2 // 2.3 0xA4 // 2.4 0x9D
			{
				MagicBulletList.push_back(FoundedBase[i]);
				MagicBulletAddress = FoundedBase[i];
			}
		}

	}

	FoundedBase.clear();
}

VOID InitializeMagic()
{
	INT Addv = MagicBulletAddress;

	MagicBulletHook = (INT)VirtualAllocEx(Game::hProcess, 0, 500, MEM_COMMIT, PAGE_EXECUTE_READWRITE);

	if (Setting::Vng == true)
	{
		WriteProcessMemory(Game::hProcess, (LPVOID)MagicBulletHook, &MagicBulletShellVng, sizeof(MagicBulletShellVng), 0);
	}
	else
	{
		WriteProcessMemory(Game::hProcess, (LPVOID)MagicBulletHook, &MagicBulletShell, sizeof(MagicBulletShell), 0);

	}
	Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 0x13, 0x50);

	Utility::WriteMemoryEx<INT>(MagicBulletHook + 9, MagicBulletHook + 0x5E);
	ReadProcessMemory(Game::hProcess, (LPCVOID)(Addv + 8), &RealByteCode, sizeof(RealByteCode), 0);
	WriteProcessMemory(Game::hProcess, (LPVOID)(MagicBulletHook), &RealByteCode, sizeof(RealByteCode), 0);
}

VOID HookCall(INT Address, INT HookAdress)
{
	BYTE Shell[7] = { 0xE8, 0x00, 0x00, 0x00, 0x00, 0x90, 0x90 };
	*(INT*)(Shell + 1) = (INT)(HookAdress - Address - 5);
	WriteProcessMemory(Game::hProcess, (LPVOID)Address, &Shell, sizeof(Shell), 0);
}

bool IsEqual(BYTE Array1[], BYTE Array2[])
{
	for (int i = 0; i < 6; i++)
	{
		if (Array1[i] != Array2[i])
		{
			return false;
		}
	}

	return true;
}

bool Hooked(int Address)
{
	unsigned char Tmp[7];
	ReadProcessMemory(Game::hProcess, (LPCVOID)(Address + 0x8), &Tmp, sizeof(Tmp), 0);

	if ((Tmp[0] == 0xE8 && Tmp[5] == 0x90 && Tmp[6] == 0x90))
	{
		return true;
	}

	return false;
}

VOID HookMagic()
{
	for (DWORD_PTR& Addv : MagicBulletList)
	{
		BYTE Tmp[7];
		ReadProcessMemory(Game::hProcess, (LPCVOID)((int)Addv + 0x8), &Tmp, sizeof(Tmp), 0);

		if (IsEqual(Tmp, RealByteCode))
		{
			HookCall((INT)(Addv + 0x8), (INT)MagicBulletHook);
		}
	}
}

VOID Memory::RestoreHook()
{
	for (DWORD_PTR& Addv : MagicBulletList)
	{
		if (Hooked(Addv))
		{
			WriteProcessMemory(Game::hProcess, (LPVOID)(Addv + 0x8), &RealByteCode, sizeof(RealByteCode), 0);
		}
	}
}

VECTOR3 Subtract(VECTOR3 Src, VECTOR3 Dst)
{
	VECTOR3 Result;
	Result.X = Src.X - Dst.X;
	Result.Y = Src.Y - Dst.Y;
	Result.Z = Src.Z - Dst.Z;

	return Result;
}

float Magnitude(VECTOR3 Vec)
{
	return sqrtf(Vec.X * Vec.X + Vec.Y * Vec.Y + Vec.Z * Vec.Z);
}

float GetDistance(VECTOR3 Src, VECTOR3 Dst)
{
	VECTOR3 Result = Subtract(Src, Dst);
	return Magnitude(Result);
}

VECTOR3 NormalizeVec(VECTOR3 Vector)
{
	float Length = Magnitude(Vector);

	Vector.X /= Length;
	Vector.Y /= Length;
	Vector.Z /= Length;

	return Vector;
}
float Distance(VECTOR3 myPos, VECTOR3 enPos)
{
	return sqrt((myPos.X - enPos.X) * (myPos.X - enPos.X) + (myPos.Y - enPos.Y) * (myPos.Y - enPos.Y) + (myPos.Z - enPos.Z) * (myPos.Z - enPos.Z));
}
float BulletDrop(float TravelTime)
{
	return (TravelTime * TravelTime * 980 / 2);
}


bool Memory::IsMagicInitialized = false;

VECTOR2 Memory::GetMagicCoordinatesFov()
{
	if (Data::AActorList.size() > 0)
	{
		VECTOR2 Coordinate;
		Coordinate.X = 0;
		Coordinate.Y = 0;
		VECTOR3 HeadPos;
		HeadPos.X = 0;
		HeadPos.Y = 0;
		HeadPos.Z = 0;
		VECTOR2 Screen;
		Screen.X = 0;
		Screen.Y = 0;
		VECTOR3 Velocity;
		Velocity.X = 0;
		Velocity.Y = 0;
		Velocity.Z = 0;
		FLOAT TargetDistance = 9999.0f;
		FLOAT CrossDist = 0;
		INT Distance4 = 0;
		VECTOR3 posi;

		for (int i = 0; i < Data::AActorList.size(); i++)
		{
			VECTOR3 chestPos = Data::AActorList[i].HeadPos;
			if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, chestPos, Screen, &Distance4))
			{
				if (Aimbot::InsideFov(DX11::Width, DX11::Height, Screen, Setting::fovcircleredus))
				{
					HookMagic();
					CrossDist = sqrt(pow(Screen.X - DX11::Width / 2, 2) + pow(Screen.Y - DX11::Height / 2, 2));
					if (CrossDist < TargetDistance)
					{
						if (Setting::curraim == 0)
						{
							HeadPos = Data::AActorList[i].HeadPos;
							HeadPos.Z += 7;
						}
						if (Setting::curraim == 1)
						{
							HeadPos = Data::AActorList[i].ChestPos;
						}
						if (Setting::curraim == 2)
						{
							HeadPos = Data::AActorList[i].PelvisPos;
						}

						TargetDistance = CrossDist;
						Velocity = Data::AActorList[i].Velocity;
						Setting::CurrentTargetAddress = Data::AActorList[i].Address;
					}
				}
				else
				{
					RestoreHook();
				}
			}
		}

		DWORD MeshAddv = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::Mesh);
		DWORD BodyAddv = MeshAddv + Offset::BodyAddv;
		DWORD BoneAddv = Utility::ReadMemoryEx<DWORD>(MeshAddv + Offset::MinLOD) + 48;
		VECTOR3 MyPosition = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 5 * 48);

		float AddTime = 30 / 10.0f + 1.0f;
		float Gravity = 5.72f;
		float distance = GetDistance(MyPosition, HeadPos) / 100.0f;
		float zAssist;
		if (distance < 5000.f)
			zAssist = 1.8f;
		else if (distance < 10000.f)
			zAssist = 1.72f;
		else if (distance < 15000.f)
			zAssist = 1.23f;
		else if (distance < 20000.f)
			zAssist = 1.24f;
		else if (distance < 25000.f)
			zAssist = 1.25f;
		else if (distance < 30000.f)
			zAssist = 1.26f;
		else if (distance < 35000.f)
			zAssist = 1.27f;
		else if (distance < 40000.f)
			zAssist = 1.28f;
		else if (distance < 45000.f)
			zAssist = 1.29f;
		else if (distance < 50000.f)
			zAssist = 1.30f;

		DWORD CurrentReloadWeapon = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::CurrentReloadWeapon);
		DWORD ShootWeaponEntity = Utility::ReadMemoryEx<DWORD>(CurrentReloadWeapon + Offset::ShootWeaponEntity);
		float BulletSpeed = Utility::ReadMemoryEx<FLOAT>(ShootWeaponEntity + Offset::BulletFireSpeed);
		float BulletTravelTime = distance / Offset::BulletFireSpeed;

		HeadPos.X += Velocity.X * BulletTravelTime;
		HeadPos.Y += Velocity.Y * BulletTravelTime;
		HeadPos.Z += Velocity.Z * BulletTravelTime * zAssist + 50.5f * 5.72f * BulletTravelTime * BulletTravelTime;


		FLOAT xDif = HeadPos.X - MyPosition.X;
		FLOAT yDif = HeadPos.Y - MyPosition.Y;
		FLOAT zDif = HeadPos.Z - MyPosition.Z;

		float Hyp = sqrt(xDif * xDif + yDif * yDif);
		Coordinate.X = atan2(zDif, Hyp) * 180.0f / 3.1415926535897f;
		Coordinate.Y = atan2(yDif, xDif) * 180.0f / 3.1415926535897f;

		return Coordinate;
	}
	else
	{
		Memory::RestoreHook();
		MagicBulletList.clear();
		VirtualFreeEx(Game::hProcess, (LPVOID)MagicBulletHook, 0, MEM_RELEASE);
		MagicBulletAddress = 0;
		MagicBulletHook = 0;
		ZeroMemory(RealByteCode, sizeof(RealByteCode));
		Memory::IsMagicInitialized = false;
	}
}

VECTOR2 Memory::GetMagicCoordinates()
{
	if (Data::AActorList.size() > 0)
	{
		VECTOR2 Coordinate;
		Coordinate.X = 0;
		Coordinate.Y = 0;
		VECTOR3 HeadPos;
		HeadPos.X = 0;
		HeadPos.Y = 0;
		HeadPos.Z = 0;
		VECTOR2 Screen;
		Screen.X = 0;
		Screen.Y = 0;
		VECTOR3 Velocity;
		Velocity.X = 0;
		Velocity.Y = 0;
		Velocity.Z = 0;
		FLOAT TargetDistance = 9999.0f;
		FLOAT CrossDist = 0;
		INT Distance4 = 0;
		VECTOR3 posi;

		for (AActor& AActor : Data::AActorList)
		{
			if (Setting::knocked == true && AActor.Health < 0)
			{
				continue;
			}
			if (Setting::SkipBots == true && AActor.IsBot == true)
			{
				continue;
			}

			if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.HeadPos, Screen, &Distance4))
			{
				HookMagic();
				CrossDist = sqrt(pow(Screen.X - DX11::Width / 2, 2) + pow(Screen.Y - DX11::Height / 2, 2));
				if (CrossDist < TargetDistance)
				{
					if (Setting::curraim == 0)
					{
						HeadPos = AActor.HeadPos;
						HeadPos.Z += 5 && Setting::magicv;
						HeadPos.X += 4;
					}
					if (Setting::curraim == 1)
					{
						HeadPos = AActor.ChestPos;
					}

					if (Setting::curraim == 2)
					{
						HeadPos = AActor.PelvisPos;
					}

					if (Setting::knocked)
					{
						if (AActor.Health <= 0)
						{
							Memory::RestoreHook();
							continue;
						}
					}
					if (Setting::SkipBots)
					{
						if (AActor.IsBot)
						{
							Memory::RestoreHook();
							continue;
						}
					}

					TargetDistance = CrossDist;
					Velocity = AActor.Velocity;
					Setting::CurrentTargetAddress = AActor.Address;
				}
			}
		}


		//////////////////////////////////////////////////////////////////////////////
		DWORD MeshAddv = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::Mesh);
		DWORD BodyAddv = MeshAddv + Offset::BodyAddv;
		DWORD BoneAddv = Utility::ReadMemoryEx<DWORD>(MeshAddv + Offset::MinLOD) + 48;
		VECTOR3 MyPosition = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 5 * 48);
		float Gravity = 7.72f;
		float AddTime = 30 / 10.0f + 1.0f;
		float Distance = GetDistance(MyPosition, HeadPos) / 100.0f;
		float temp = 1.0f;
		DWORD CurrentReloadWeapon = Utility::ReadMemoryEx<DWORD>(Offset::CurrentReloadWeapon);
		DWORD ShootWeaponEntity = Utility::ReadMemoryEx<DWORD>(CurrentReloadWeapon + Offset::ShootWeaponEntity);
		float BulletSpeed = Utility::ReadMemoryEx<FLOAT>(ShootWeaponEntity + Offset::BulletFireSpeed) / 750.f;

		FLOAT BaseFlyTime = Distance / BulletSpeed;
		FLOAT SecFlyTime = BaseFlyTime * temp;
		float BulletTravelTime = Distance / 750.0f;
		float zAssist;

		if (Distance < 5000.f)
			zAssist = 1.8f;
		else if (Distance < 10000.f)
			zAssist = 1.72f;
		else if (Distance < 15000.f)
			zAssist = 1.23f;
		else if (Distance < 20000.f)
			zAssist = 1.24f;
		else if (Distance < 25000.f)
			zAssist = 1.25f;
		else if (Distance < 30000.f)
			zAssist = 1.26f;
		else if (Distance < 35000.f)
			zAssist = 1.27f;
		else if (Distance < 40000.f)
			zAssist = 1.28f;
		else if (Distance < 45000.f)
			zAssist = 1.29f;
		else if (Distance < 50000.f)
			zAssist = 1.30f;
		float secFlyTime = BulletTravelTime * AddTime * temp;

		HeadPos.X += Velocity.X * BulletTravelTime;
		HeadPos.Y += Velocity.Y * BulletTravelTime;
		HeadPos.Z += Velocity.Z * BulletTravelTime * zAssist + 50.5f * 5.72f * BulletTravelTime * BulletTravelTime;
		VECTOR3 PredictedShift = { Velocity.X * secFlyTime, Velocity.Y * secFlyTime, Velocity.Z * secFlyTime };

		PredictedShift.Z += 0.5 * Gravity * BulletTravelTime * BaseFlyTime * 5.0f;
		PredictedShift.Y += 0.5 * Gravity * BulletTravelTime * BaseFlyTime * 500.0f;

		FLOAT xDif = HeadPos.X - MyPosition.X;
		FLOAT yDif = HeadPos.Y - MyPosition.Y;
		FLOAT zDif = HeadPos.Z - MyPosition.Z;
		float Hyp = sqrt(xDif * xDif + yDif * yDif);
		if (Distance > 100.f) HeadPos.Z += 1;
		Coordinate.X = atan2(zDif, Hyp) * 180.0f / 3.1415926535897f;
		Coordinate.Y = atan2(yDif, xDif) * 180.0f / 3.1415926535897f;
		return Coordinate;
	}
	else
	{
		Memory::RestoreHook();
		MagicBulletList.clear();
		VirtualFreeEx(Game::hProcess, (LPVOID)MagicBulletHook, 0, MEM_RELEASE);
		MagicBulletAddress = 0;
		MagicBulletHook = 0;
		ZeroMemory(RealByteCode, sizeof(RealByteCode));
		Memory::IsMagicInitialized = false;
	}

	//	DWORD MeshAddv = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::Mesh);
	//	DWORD BodyAddv = MeshAddv + Offset::BodyAddv;
	//	DWORD BoneAddv = Utility::ReadMemoryEx<DWORD>(MeshAddv + Offset::MinLOD) + 48;
	//	VECTOR3 MyPosition = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 5 * 48);

	//	float AddTime = 30 / 10.0f + 1.0f;
	//	float Gravity = 5.72f;
	//	float distance = GetDistance(MyPosition, HeadPos) / 100.0f;
	//	float zAssist;
	//	if (distance < 5000.f)
	//		zAssist = 1.8f;
	//	else if (distance < 10000.f)
	//		zAssist = 1.72f;
	//	else if (distance < 15000.f)
	//		zAssist = 1.23f;
	//	else if (distance < 20000.f)
	//		zAssist = 1.24f;
	//	else if (distance < 25000.f)
	//		zAssist = 1.25f;
	//	else if (distance < 30000.f)
	//		zAssist = 1.26f;
	//	else if (distance < 35000.f)
	//		zAssist = 1.27f;
	//	else if (distance < 40000.f)
	//		zAssist = 1.28f;
	//	else if (distance < 45000.f)
	//		zAssist = 1.29f;
	//	else if (distance < 50000.f)
	//		zAssist = 1.30f;

	//	DWORD CurrentReloadWeapon = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::CurrentReloadWeapon);
	//	DWORD ShootWeaponEntity = Utility::ReadMemoryEx<DWORD>(CurrentReloadWeapon + Offset::ShootWeaponEntity);
	//	float BulletSpeed = Utility::ReadMemoryEx<FLOAT>(ShootWeaponEntity + Offset::BulletFireSpeed);
	//	float BulletTravelTime = distance / Offset::BulletFireSpeed;

	//	HeadPos.X += Velocity.X * BulletTravelTime;
	//	HeadPos.Y += Velocity.Y * BulletTravelTime;
	//	HeadPos.Z += Velocity.Z * BulletTravelTime * zAssist + 50.5f * 5.72f * BulletTravelTime * BulletTravelTime;


	//	FLOAT xDif = HeadPos.X - MyPosition.X;
	//	FLOAT yDif = HeadPos.Y - MyPosition.Y;
	//	FLOAT zDif = HeadPos.Z - MyPosition.Z;

	//	float Hyp = sqrt(xDif * xDif + yDif * yDif);
	//	Coordinate.X = atan2(zDif, Hyp) * 180.0f / 3.1415926535897f;
	//	Coordinate.Y = atan2(yDif, xDif) * 180.0f / 3.1415926535897f;

	//	return Coordinate;
	//}
	//else
	//{
	//	Memory::RestoreHook();
	//	MagicBulletList.clear();
	//	VirtualFreeEx(Game::hProcess, (LPVOID)MagicBulletHook, 0, MEM_RELEASE);
	//	MagicBulletAddress = 0;
	//	MagicBulletHook = 0;
	//	ZeroMemory(RealByteCode, sizeof(RealByteCode));
	//	Memory::IsMagicInitialized = false;
	//}






	//if (Data::AActorList.size() > 0)
	//{
	//	VECTOR2 Coordinate;
	//	Coordinate.X = 0;
	//	Coordinate.Y = 0;
	//	VECTOR3 HeadPos;
	//	HeadPos.X = 0;
	//	HeadPos.Y = 0;
	//	HeadPos.Z = 0;
	//	VECTOR2 Screen;
	//	Screen.X = 0;
	//	Screen.Y = 0;
	//	VECTOR3 Velocity;
	//	Velocity.X = 0;
	//	Velocity.Y = 0;
	//	Velocity.Z = 0;
	//	FLOAT TargetDistance = 9999.0f;
	//	FLOAT CrossDist = 0;
	//	INT Distance4 = 0;
	//	VECTOR3 posi;


	//	for (AActor& AActor : Data::AActorList)
	//	{
	//		if (Setting::SkipBots)
	//		{
	//			if (AActor.Health > 0 && !AActor.IsDead && !AActor.IsBot) //Alive
	//			{
	//				if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
	//				{
	//					if (Setting::fovcircle)
	//					{
	//						if (Aimbot::InsideFov(DX11::Width, DX11::Height, Screen, Setting::fovcircleredus/*FovRadius*/))
	//						{
	//							HookMagic();
	//							CrossDist = sqrt(pow(Screen.X - DX11::Width / 2, 2) + pow(Screen.Y - DX11::Height / 2, 2));
	//							if (CrossDist < TargetDistance)
	//							{
	//								if (Setting::curraim == 0)
	//								{
	//									HeadPos = AActor.HeadPos;
	//									HeadPos.Z += 5 && Setting::magicv;
	//									HeadPos.X += 4;
	//								}
	//								if (Setting::curraim == 1)
	//								{
	//									HeadPos = AActor.ChestPos;
	//									HeadPos.Z -= 50;
	//									HeadPos.X += 3;
	//								}
	//								if (Setting::curraim == 2)
	//								{
	//									HeadPos = AActor.PelvisPos;
	//									HeadPos.Z -= 65;
	//									HeadPos.X += 3;
	//								}
	//								TargetDistance = CrossDist;
	//								Velocity = AActor.Velocity;
	//							}

	//						}
	//					}
	//					else
	//					{
	//						HookMagic();
	//						if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
	//						{
	//							CrossDist = sqrt(pow(Screen.X - DX11::Width / 2, 2) + pow(Screen.Y - DX11::Height / 2, 2));
	//							if (CrossDist < TargetDistance)
	//							{
	//								if (Setting::curraim == 0)
	//								{
	//									HeadPos = AActor.HeadPos;
	//									HeadPos.Z += 5 && Setting::magicv;
	//									HeadPos.X += 4;
	//								}
	//								if (Setting::curraim == 1)
	//								{
	//									HeadPos = AActor.ChestPos;
	//									HeadPos.Z -= 50;
	//									HeadPos.X += 3;
	//								}
	//								if (Setting::curraim == 2)
	//								{
	//									HeadPos = AActor.PelvisPos;
	//									HeadPos.Z -= 65;
	//									HeadPos.X += 3;
	//								}
	//								TargetDistance = CrossDist;
	//								Velocity = AActor.Velocity;
	//							}
	//						}
	//					}


	//				}
	//			}
	//			if (AActor.Health <= 0 && !AActor.IsDead && !AActor.IsBot)
	//			{
	//				if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
	//				{
	//					if (Setting::fovcircle)
	//					{
	//						if (Aimbot::InsideFov(DX11::Width, DX11::Height, Screen, Setting::fovcircleredus/*FovRadius*/))
	//						{
	//							HookMagic();

	//							CrossDist = sqrt(pow(Screen.X - DX11::Width / 2, 2) + pow(Screen.Y - DX11::Height / 2, 2));
	//							if (CrossDist < TargetDistance)
	//							{
	//								if (Setting::curraim == 0)
	//								{
	//									HeadPos = AActor.HeadPos;
	//									HeadPos.Z += 5 && Setting::magicv;
	//									HeadPos.X += 4;
	//								}
	//								if (Setting::curraim == 1)
	//								{
	//									HeadPos = AActor.ChestPos;
	//									HeadPos.Z -= 50;
	//									HeadPos.X += 3;
	//								}
	//								if (Setting::curraim == 2)
	//								{
	//									HeadPos = AActor.PelvisPos;
	//									HeadPos.Z -= 65;
	//									HeadPos.X += 3;
	//								}
	//								TargetDistance = CrossDist;
	//								Velocity = AActor.Velocity;
	//							}

	//						}

	//					}
	//					else
	//					{
	//						HookMagic();
	//						if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
	//						{

	//							CrossDist = sqrt(pow(Screen.X - DX11::Width / 2, 2) + pow(Screen.Y - DX11::Height / 2, 2));

	//							if (CrossDist < TargetDistance)
	//							{
	//								if (Setting::curraim == 0)
	//								{
	//									HeadPos = AActor.HeadPos;
	//									HeadPos.Z += 5 && Setting::magicv;
	//									HeadPos.X += 4;
	//								}
	//								if (Setting::curraim == 1)
	//								{
	//									HeadPos = AActor.ChestPos;
	//									HeadPos.Z -= 50;
	//									HeadPos.X += 3;
	//								}
	//								if (Setting::curraim == 2)
	//								{
	//									HeadPos = AActor.PelvisPos;
	//									HeadPos.Z -= 65;
	//									HeadPos.X += 3;
	//								}
	//								TargetDistance = CrossDist;
	//								Velocity = AActor.Velocity;
	//							}
	//						}
	//					}
	//				}
	//			}
	//		}
	//		else
	//		{
	//			if (AActor.Health > 0 && !AActor.IsDead) //Alive
	//			{
	//				if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
	//				{
	//					if (Setting::fovcircle)
	//					{
	//						if (Aimbot::InsideFov(DX11::Width, DX11::Height, Screen, Setting::fovcircleredus/*FovRadius*/))
	//						{
	//							HookMagic();
	//							CrossDist = sqrt(pow(Screen.X - DX11::Width / 2, 2) + pow(Screen.Y - DX11::Height / 2, 2));
	//							if (CrossDist < TargetDistance)
	//							{
	//								if (Setting::curraim == 0)
	//								{
	//									HeadPos = AActor.HeadPos;
	//									HeadPos.Z += 5 && Setting::magicv;
	//									HeadPos.X += 4;
	//								}
	//								if (Setting::curraim == 1)
	//								{
	//									HeadPos = AActor.ChestPos;
	//									HeadPos.Z -= 50;
	//									HeadPos.X += 3;
	//								}
	//								if (Setting::curraim == 2)
	//								{
	//									HeadPos = AActor.PelvisPos;
	//									HeadPos.Z -= 65;
	//									HeadPos.X += 3;
	//								}
	//								TargetDistance = CrossDist;
	//								Velocity = AActor.Velocity;
	//							}

	//						}
	//					}
	//					else
	//					{
	//						HookMagic();
	//						if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
	//						{
	//							CrossDist = sqrt(pow(Screen.X - DX11::Width / 2, 2) + pow(Screen.Y - DX11::Height / 2, 2));
	//							if (CrossDist < TargetDistance)
	//							{
	//								if (Setting::curraim == 0)
	//								{
	//									HeadPos = AActor.HeadPos;
	//									HeadPos.Z += 5 && Setting::magicv;
	//									HeadPos.X += 4;
	//								}
	//								if (Setting::curraim == 1)
	//								{
	//									HeadPos = AActor.ChestPos;
	//									HeadPos.Z -= 50;
	//									HeadPos.X += 3;
	//								}
	//								if (Setting::curraim == 2)
	//								{
	//									HeadPos = AActor.PelvisPos;
	//									HeadPos.Z -= 65;
	//									HeadPos.X += 3;
	//								}
	//								TargetDistance = CrossDist;
	//								Velocity = AActor.Velocity;
	//							}
	//						}
	//					}
	//				}
	//			}
	//			if (AActor.Health <= 0 && !AActor.IsDead)
	//			{
	//				if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
	//				{

	//					if (Setting::fovcircle)
	//					{
	//						if (Aimbot::InsideFov(DX11::Width, DX11::Height, Screen, Setting::fovcircleredus/*FovRadius*/))
	//						{
	//							HookMagic();

	//							CrossDist = sqrt(pow(Screen.X - DX11::Width / 2, 2) + pow(Screen.Y - DX11::Height / 2, 2));
	//							if (CrossDist < TargetDistance)
	//							{
	//								if (Setting::curraim == 0)
	//								{
	//									HeadPos = AActor.HeadPos;
	//									HeadPos.Z += 5 && Setting::magicv;
	//									HeadPos.X += 4;
	//								}
	//								if (Setting::curraim == 1)
	//								{
	//									HeadPos = AActor.ChestPos;
	//									HeadPos.Z -= 50;
	//									HeadPos.X += 3;
	//								}
	//								if (Setting::curraim == 2)
	//								{
	//									HeadPos = AActor.PelvisPos;
	//									HeadPos.Z -= 65;
	//									HeadPos.X += 3;
	//								}
	//								TargetDistance = CrossDist;
	//								Velocity = AActor.Velocity;
	//							}

	//						}

	//					}
	//					else
	//					{
	//						HookMagic();
	//						if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
	//						{

	//							CrossDist = sqrt(pow(Screen.X - DX11::Width / 2, 2) + pow(Screen.Y - DX11::Height / 2, 2));

	//							if (CrossDist < TargetDistance)
	//							{
	//								if (Setting::curraim == 0)
	//								{
	//									HeadPos = AActor.HeadPos;
	//									HeadPos.Z += 5 && Setting::magicv;
	//									HeadPos.X += 4;
	//								}
	//								if (Setting::curraim == 1)
	//								{
	//									HeadPos = AActor.ChestPos;
	//									HeadPos.Z -= 50;
	//									HeadPos.X += 3;
	//								}
	//								if (Setting::curraim == 2)
	//								{
	//									HeadPos = AActor.PelvisPos;
	//									HeadPos.Z -= 65;
	//									HeadPos.X += 3;
	//								}
	//								TargetDistance = CrossDist;
	//								Velocity = AActor.Velocity;
	//							}
	//						}
	//					}

	//				}
	//			}
	//		}

	//		if (Setting::knocked)
	//		{
	//			if (AActor.Health > 0 && !AActor.IsDead) //Alive
	//			{
	//				if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
	//				{
	//					if (Setting::fovcircle)
	//					{
	//						if (Aimbot::InsideFov(DX11::Width, DX11::Height, Screen, Setting::fovcircleredus/*FovRadius*/))
	//						{
	//							HookMagic();
	//							CrossDist = sqrt(pow(Screen.X - DX11::Width / 2, 2) + pow(Screen.Y - DX11::Height / 2, 2));
	//							if (CrossDist < TargetDistance)
	//							{
	//								if (Setting::curraim == 0)
	//								{
	//									HeadPos = AActor.HeadPos;
	//									HeadPos.Z += 5 && Setting::magicv;
	//									HeadPos.X += 4;
	//								}
	//								if (Setting::curraim == 1)
	//								{
	//									HeadPos = AActor.ChestPos;
	//									HeadPos.Z -= 50;
	//									HeadPos.X += 3;
	//								}
	//								if (Setting::curraim == 2)
	//								{
	//									HeadPos = AActor.PelvisPos;
	//									HeadPos.Z -= 65;
	//									HeadPos.X += 3;
	//								}
	//								TargetDistance = CrossDist;
	//								Velocity = AActor.Velocity;
	//							}

	//						}
	//					}
	//					else
	//					{
	//						HookMagic();
	//						if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
	//						{
	//							CrossDist = sqrt(pow(Screen.X - DX11::Width / 2, 2) + pow(Screen.Y - DX11::Height / 2, 2));
	//							if (CrossDist < TargetDistance)
	//							{
	//								if (Setting::curraim == 0)
	//								{
	//									HeadPos = AActor.HeadPos;
	//									HeadPos.Z += 5 && Setting::magicv;
	//									HeadPos.X += 4;
	//								}
	//								if (Setting::curraim == 1)
	//								{
	//									HeadPos = AActor.ChestPos;
	//									HeadPos.Z -= 50;
	//									HeadPos.X += 3;
	//								}
	//								if (Setting::curraim == 2)
	//								{
	//									HeadPos = AActor.PelvisPos;
	//									HeadPos.Z -= 65;
	//									HeadPos.X += 3;
	//								}
	//								TargetDistance = CrossDist;
	//								Velocity = AActor.Velocity;
	//							}
	//						}
	//					}


	//				}
	//			}
	//			if (AActor.Health <= 0 && !AActor.IsDead && !AActor.IsBot)
	//			{
	//				if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
	//				{
	//					if (Setting::fovcircle)
	//					{
	//						if (Aimbot::InsideFov(DX11::Width, DX11::Height, Screen, Setting::fovcircleredus/*FovRadius*/))
	//						{
	//							HookMagic();

	//							CrossDist = sqrt(pow(Screen.X - DX11::Width / 2, 2) + pow(Screen.Y - DX11::Height / 2, 2));
	//							if (CrossDist < TargetDistance)
	//							{
	//								if (Setting::curraim == 0)
	//								{
	//									HeadPos = AActor.HeadPos;
	//									HeadPos.Z += 5 && Setting::magicv;
	//									HeadPos.X += 4;
	//								}
	//								if (Setting::curraim == 1)
	//								{
	//									HeadPos = AActor.ChestPos;
	//									HeadPos.Z -= 50;
	//									HeadPos.X += 3;
	//								}
	//								if (Setting::curraim == 2)
	//								{
	//									HeadPos = AActor.PelvisPos;
	//									HeadPos.Z -= 65;
	//									HeadPos.X += 3;
	//								}
	//								TargetDistance = CrossDist;
	//								Velocity = AActor.Velocity;
	//							}

	//						}

	//					}
	//					else
	//					{
	//						HookMagic();
	//						if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
	//						{

	//							CrossDist = sqrt(pow(Screen.X - DX11::Width / 2, 2) + pow(Screen.Y - DX11::Height / 2, 2));

	//							if (CrossDist < TargetDistance)
	//							{
	//								if (Setting::curraim == 0)
	//								{
	//									HeadPos = AActor.HeadPos;
	//									HeadPos.Z += 5 && Setting::magicv;
	//									HeadPos.X += 4;
	//								}
	//								if (Setting::curraim == 1)
	//								{
	//									HeadPos = AActor.ChestPos;
	//									HeadPos.Z -= 50;
	//									HeadPos.X += 3;
	//								}
	//								if (Setting::curraim == 2)
	//								{
	//									HeadPos = AActor.PelvisPos;
	//									HeadPos.Z -= 65;
	//									HeadPos.X += 3;
	//								}
	//								TargetDistance = CrossDist;
	//								Velocity = AActor.Velocity;
	//							}
	//						}
	//					}
	//				}
	//			}
	//		}
	//		else
	//		{
	//			if (AActor.Health > 0 && !AActor.IsDead) //Alive
	//			{
	//				if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
	//				{
	//					if (Setting::fovcircle)
	//					{
	//						if (Aimbot::InsideFov(DX11::Width, DX11::Height, Screen, Setting::fovcircleredus/*FovRadius*/))
	//						{
	//							HookMagic();
	//							CrossDist = sqrt(pow(Screen.X - DX11::Width / 2, 2) + pow(Screen.Y - DX11::Height / 2, 2));
	//							if (CrossDist < TargetDistance)
	//							{
	//								if (Setting::curraim == 0)
	//								{
	//									HeadPos = AActor.HeadPos;
	//									HeadPos.Z += 5 && Setting::magicv;
	//									HeadPos.X += 4;
	//								}
	//								if (Setting::curraim == 1)
	//								{
	//									HeadPos = AActor.ChestPos;
	//									HeadPos.Z -= 50;
	//									HeadPos.X += 3;
	//								}
	//								if (Setting::curraim == 2)
	//								{
	//									HeadPos = AActor.PelvisPos;
	//									HeadPos.Z -= 65;
	//									HeadPos.X += 3;
	//								}
	//								TargetDistance = CrossDist;
	//								Velocity = AActor.Velocity;
	//							}

	//						}
	//					}
	//					else
	//					{
	//						HookMagic();
	//						if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
	//						{
	//							CrossDist = sqrt(pow(Screen.X - DX11::Width / 2, 2) + pow(Screen.Y - DX11::Height / 2, 2));
	//							if (CrossDist < TargetDistance)
	//							{
	//								if (Setting::curraim == 0)
	//								{
	//									HeadPos = AActor.HeadPos;
	//									HeadPos.Z += 5 && Setting::magicv;
	//									HeadPos.X += 4;
	//								}
	//								if (Setting::curraim == 1)
	//								{
	//									HeadPos = AActor.ChestPos;
	//									HeadPos.Z -= 50;
	//									HeadPos.X += 3;
	//								}
	//								if (Setting::curraim == 2)
	//								{
	//									HeadPos = AActor.PelvisPos;
	//									HeadPos.Z -= 65;
	//									HeadPos.X += 3;
	//								}
	//								TargetDistance = CrossDist;
	//								Velocity = AActor.Velocity;
	//							}
	//						}
	//					}


	//				}
	//			}
	//			if (AActor.Health <= 0 && !AActor.IsDead)
	//			{
	//				if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
	//				{

	//					if (Setting::fovcircle)
	//					{
	//						if (Aimbot::InsideFov(DX11::Width, DX11::Height, Screen, Setting::fovcircleredus/*FovRadius*/))
	//						{
	//							HookMagic();

	//							CrossDist = sqrt(pow(Screen.X - DX11::Width / 2, 2) + pow(Screen.Y - DX11::Height / 2, 2));
	//							if (CrossDist < TargetDistance)
	//							{
	//								if (Setting::curraim == 0)
	//								{
	//									HeadPos = AActor.HeadPos;
	//									HeadPos.Z += 5 && Setting::magicv;
	//									HeadPos.X += 4;
	//								}
	//								if (Setting::curraim == 1)
	//								{
	//									HeadPos = AActor.ChestPos;
	//									HeadPos.Z -= 50;
	//									HeadPos.X += 3;
	//								}
	//								if (Setting::curraim == 2)
	//								{
	//									HeadPos = AActor.PelvisPos;
	//									HeadPos.Z -= 65;
	//									HeadPos.X += 3;
	//								}
	//								TargetDistance = CrossDist;
	//								Velocity = AActor.Velocity;
	//							}

	//						}

	//					}
	//					else
	//					{
	//						HookMagic();
	//						if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
	//						{

	//							CrossDist = sqrt(pow(Screen.X - DX11::Width / 2, 2) + pow(Screen.Y - DX11::Height / 2, 2));

	//							if (CrossDist < TargetDistance)
	//							{
	//								if (Setting::curraim == 0)
	//								{
	//									HeadPos = AActor.HeadPos;
	//									HeadPos.Z += 5 && Setting::magicv;
	//									HeadPos.X += 4;
	//								}
	//								if (Setting::curraim == 1)
	//								{
	//									HeadPos = AActor.ChestPos;
	//									HeadPos.Z -= 50;
	//									HeadPos.X += 3;
	//								}
	//								if (Setting::curraim == 2)
	//								{
	//									HeadPos = AActor.PelvisPos;
	//									HeadPos.Z -= 65;
	//									HeadPos.X += 3;
	//								}
	//								TargetDistance = CrossDist;
	//								Velocity = AActor.Velocity;
	//							}
	//						}
	//					}

	//				}
	//			}
	//		}
	//	}


	//	//////////////////////////////////////////////////////////////////////////////
	//	DWORD MeshAddv = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::Mesh);
	//	DWORD BodyAddv = MeshAddv + Offset::BodyAddv;
	//	DWORD BoneAddv = Utility::ReadMemoryEx<DWORD>(MeshAddv + Offset::MinLOD) + 48;
	//	VECTOR3 MyPosition = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 5 * 48);
	//	float Gravity = 7.72f;
	//	float AddTime = 30 / 10.0f + 1.0f;
	//	float Distance = GetDistance(MyPosition, HeadPos) / 100.0f;
	//	float temp = 1.0f;
	//	DWORD CurrentReloadWeapon = Utility::ReadMemoryEx<DWORD>(Offset::CurrentReloadWeapon);
	//	DWORD ShootWeaponEntity = Utility::ReadMemoryEx<DWORD>(CurrentReloadWeapon + Offset::ShootWeaponEntity);
	//	float BulletSpeed = Utility::ReadMemoryEx<FLOAT>(ShootWeaponEntity + Offset::BulletFireSpeed) / 750.f;

	//	FLOAT BaseFlyTime = Distance / BulletSpeed;
	//	FLOAT SecFlyTime = BaseFlyTime * temp;
	//	float BulletTravelTime = Distance / 750.0f;
	//	float zAssist;

	//	if (Distance < 5000.f)
	//		zAssist = 1.8f;
	//	else if (Distance < 10000.f)
	//		zAssist = 1.72f;
	//	else if (Distance < 15000.f)
	//		zAssist = 1.23f;
	//	else if (Distance < 20000.f)
	//		zAssist = 1.24f;
	//	else if (Distance < 25000.f)
	//		zAssist = 1.25f;
	//	else if (Distance < 30000.f)
	//		zAssist = 1.26f;
	//	else if (Distance < 35000.f)
	//		zAssist = 1.27f;
	//	else if (Distance < 40000.f)
	//		zAssist = 1.28f;
	//	else if (Distance < 45000.f)
	//		zAssist = 1.29f;
	//	else if (Distance < 50000.f)
	//		zAssist = 1.30f;
	//	//float secFlyTime = BulletTravelTime * AddTime * temp;

	//	HeadPos.X += Velocity.X * BulletTravelTime;
	//	HeadPos.Y += Velocity.Y * BulletTravelTime;
	//	HeadPos.Z += Velocity.Z * BulletTravelTime * zAssist + 50.5f * 5.72f * BulletTravelTime * BulletTravelTime;
	//	//VECTOR3 PredictedShift = { Velocity.X * secFlyTime, Velocity.Y * secFlyTime, Velocity.Z * secFlyTime };

	//	//PredictedShift.Z += 0.5 * Gravity * BulletTravelTime * BaseFlyTime * 5.0f;
	//	//PredictedShift.Y += 0.5 * Gravity * BulletTravelTime * BaseFlyTime * 500.0f;

	//	FLOAT xDif = HeadPos.X - MyPosition.X;
	//	FLOAT yDif = HeadPos.Y - MyPosition.Y;
	//	FLOAT zDif = HeadPos.Z - MyPosition.Z;
	//	float Hyp = sqrt(xDif * xDif + yDif * yDif);
	//	//if (Distance > 100.f) HeadPos.Z += 1;
	//	Coordinate.X = atan2(zDif, Hyp) * 180.0f / 3.1415926535897f;
	//	Coordinate.Y = atan2(yDif, xDif) * 180.0f / 3.1415926535897f;
	//	return Coordinate;
	//}
	//else
	//{
	//	Memory::RestoreHook();
	//	MagicBulletList.clear();
	//	VirtualFreeEx(Game::hProcess, (LPVOID)MagicBulletHook, 0, MEM_RELEASE);
	//	MagicBulletAddress = 0;
	//	MagicBulletHook = 0;
	//	ZeroMemory(RealByteCode, sizeof(RealByteCode));
	//	Memory::IsMagicInitialized = false;
	//}
}


DWORD CurrWeapon = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::CurrentWeapon);
DWORD ShootWeaponEntity = Utility::ReadMemoryEx<DWORD>(CurrWeapon + Offset::ShootWeaponEntity);

VOID Memory::MemoryThread()
{
	static bool BulletKeyState = false;
	VECTOR2 MagicCoordinate;
	VECTOR3 AimRotation;

	while (true)
	{
		if (Data::NetDriver > 0)
		{
			if (Setting::MagicBullet)
			{
				if (Setting::I_HackInjectType != 2)
				{

					if (IsMagicInitialized == false)
					{
						GetMagicAddress();
						InitializeMagic();
						IsMagicInitialized = true;
					}

					if (Setting::fovcircle) {
						MagicCoordinate = GetMagicCoordinatesFov();
					}
					else {
						MagicCoordinate = GetMagicCoordinates();
					}

					if (GetAsyncKeyState(Setting::AimbotKey) & 0x8000)
					{
						if (IsMagicInitialized == false)
						{
							GetMagicAddress();
							InitializeMagic();
							IsMagicInitialized = true;
						}
						BulletKeyState = true;
						Utility::WriteMemoryEx<FLOAT>(MagicBulletHook + 44, MagicCoordinate.X);
						Utility::WriteMemoryEx<FLOAT>(MagicBulletHook + 54, MagicCoordinate.Y);
						if (IsMagicInitialized == false)
						{
							GetMagicAddress();
							InitializeMagic();
							IsMagicInitialized = true;
						}
					}
					if (GetAsyncKeyState(Setting::AimbotKey) == 0 && BulletKeyState == true && IsMagicInitialized == true)
					{
						BulletKeyState = false;
						RestoreHook();
						MagicBulletList.clear();
						Setting::CurrentTargetAddress = 0;
						VirtualFreeEx(Game::hProcess, (LPVOID)MagicBulletHook, 0, MEM_RELEASE);
						MagicBulletAddress = 0;
						MagicBulletHook = 0;
						ZeroMemory(RealByteCode, sizeof(RealByteCode));
						IsMagicInitialized = false;
					}
					else if (IsMagicInitialized == false)
					{
						RestoreHook();
						MagicBulletList.clear();
						Setting::CurrentTargetAddress = 0;
						VirtualFreeEx(Game::hProcess, (LPVOID)MagicBulletHook, 0, MEM_RELEASE);
						MagicBulletAddress = 0;
						MagicBulletHook = 0;
						ZeroMemory(RealByteCode, sizeof(RealByteCode));
						GetMagicAddress();
						InitializeMagic();
						IsMagicInitialized = true;
					}
					if (GetAsyncKeyState('R'))
					{
						RestoreHook();
						Setting::CurrentTargetAddress = 0;
						MagicBulletList.clear();
						VirtualFreeEx(Game::hProcess, (LPVOID)MagicBulletHook, 0, MEM_RELEASE);
						MagicBulletAddress = 0;
						MagicBulletHook = 0;
						ZeroMemory(RealByteCode, sizeof(RealByteCode));
						IsMagicInitialized = false;
					}
				}

				else if (Setting::MagicBullet == false /*&& IsMagicInitialized == true*/)
				{
					RestoreHook();
					MagicBulletList.clear();
					Setting::CurrentTargetAddress = 0;
					if (MagicBulletHook != 0)
						VirtualFreeEx(Game::hProcess, (LPVOID)MagicBulletHook, 0, MEM_RELEASE);
					MagicBulletAddress = 0;
					MagicBulletHook = 0;
					ZeroMemory(RealByteCode, sizeof(RealByteCode));
					//    MagicRested = false;
					IsMagicInitialized = false;
				}
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

FRotator ToRotator(VECTOR3 local, VECTOR3 target) {
	VECTOR3 rotation;
	rotation.X = local.X - target.X;
	rotation.Y = local.Y - target.Y;
	rotation.Z = local.Z - target.Z;

	FRotator newViewAngle = { 0 };

	float hyp = sqrt(rotation.X * rotation.X + rotation.Y * rotation.Y);

	newViewAngle.Pitch = -atan(rotation.Z / hyp) * (180.f / (float)3.14159265358979323846);
	newViewAngle.Yaw = atan(rotation.Y / rotation.X) * (180.f / (float)3.14159265358979323846);
	newViewAngle.Roll = (float)0.f;

	if (rotation.X >= 0.f)
		newViewAngle.Yaw += 180.0f;

	return newViewAngle;
}

VECTOR3 ClosestToCrosshair()
{
	float targetDistance = 500.0f;
	VECTOR2 retval;
	int dist, headdist;
	VECTOR3 ret;
	for (int i = 0; i < Data::AActorList.size(); i++) {
		DWORD tmpAddv = Utility::ReadMemoryEx<INT>(Data::AActorList[i].Address + Offset::Mesh);
		DWORD bodyAddv = tmpAddv + Offset::BodyAddv;
		DWORD boneAddv = Utility::ReadMemoryEx<INT>(tmpAddv + Offset::MinLOD) + 48;
		VECTOR2 chest;
		VECTOR2 head;
		//VECTOR3 chestPos = Algorithm::GetBoneWorldPosition(bodyAddv, boneAddv + 3 * 48); 
		VECTOR3 CurrPos = { 0 };
		if (Setting::curraim == 0) {
			CurrPos = Algorithm::GetBoneWorldPosition(bodyAddv, boneAddv + 5 * 48);
			//CurrPos.z += 15; 
		}
		if (Setting::curraim == 1)
		{
			CurrPos = Algorithm::GetBoneWorldPosition(bodyAddv, boneAddv + 4 * 48);
		}
		if (Setting::curraim == 2)
		{
			CurrPos = Algorithm::GetBoneWorldPosition(bodyAddv, boneAddv + 1 * 48);
		}
		if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, CurrPos, chest, &dist))
		{
			if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, CurrPos, chest, &dist))
			{
				float cross_dist = sqrt(pow(chest.X - DX11::Width / 2, 2) + pow(chest.Y - DX11::Height / 2, 2));

				if (cross_dist < targetDistance)
				{
					ret = CurrPos;
					targetDistance = cross_dist;

				}
			}

		}
	}
	return ret;
}


int Memory::AimFindBestTarget()
{
	float targetDistance = 9999.0;
	VECTOR2 retval{};
	int dist, headdist = 0;
	int ret{};
	for (int i = 0; i < Data::AActorList.size(); i++)
	{
		DWORD tmpAddv = Utility::ReadMemoryEx<INT>(Data::AActorList[i].Address + Offset::Mesh);
		DWORD bodyAddv = tmpAddv + Offset::BodyAddv;
		DWORD boneAddv = Utility::ReadMemoryEx<INT>(tmpAddv + Offset::MinLOD) + 48;

		VECTOR2 chest;
		VECTOR2 head;
		VECTOR3 chestPos = Algorithm::GetBoneWorldPosition(bodyAddv, boneAddv + 4 * 48);

		if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, Data::AActorList[i].ChestPos, chest, &dist))
		{
			if (Setting::fovcircle)
			{
				if (Aimbot::InsideFov(DX11::Width, DX11::Height, chest, Setting::fovcircleredus))
				{
					float cross_dist = sqrt(pow(chest.X - DX11::Width / 2, 2) + pow(chest.Y - DX11::Height / 2, 2));
					if (cross_dist < targetDistance)
					{
						ret = i;
						targetDistance = cross_dist;

					}
				}
			}
			else
			{
				float cross_dist = sqrt(pow(chest.X - DX11::Width / 2, 2) + pow(chest.Y - DX11::Height / 2, 2));

				if (cross_dist < targetDistance)
				{
					ret = i;
					targetDistance = cross_dist;

				}
			}
		}
	}
	return ret;
}


int	instantv = 700000.0f;

void Memory::Instant()
{
	while (true)
	{
		if (Setting::I_HackInjectType != 2)
		{
			if (Setting::I_HackInjectType == 1)
			{

				if (Setting::instanthit)
				{
					/*	float BulletFireSpeed = Utility::ReadMemoryEx<float>(ShootWeaponEntity + Offset::BulletFireSpeed);
						if (BulletFireSpeed != 17000)
						{
							std::cout << BulletFireSpeed << std::endl;
							Utility::WriteMemoryEx<float>(ShootWeaponEntity + Offset::BulletFireSpeed, Setting::instantv);
						}*/

					DWORD gameInstance = Utility::ReadMemoryEx<INT>(Data::UWorld + 0x24);
					DWORD playerController = Utility::ReadMemoryEx<INT>(gameInstance + 0x60);
					DWORD playerCarry = Utility::ReadMemoryEx<INT>(playerController + 0x20);
					DWORD uMyObject = Utility::ReadMemoryEx<INT>(playerCarry + 0x340);

					DWORD weaponOffSet = Utility::ReadMemoryEx<DWORD>(uMyObject + Offset::CurrentReloadWeapon);
					std::cout << "weaponOffSet : " << weaponOffSet << std::endl;
					if (weaponOffSet != NULL)
					{
						DWORD shootOffset = Utility::ReadMemoryEx<DWORD>(weaponOffSet + Offset::ShootWeaponEntity);
						std::cout << "shootOffset : " << shootOffset << std::endl;
						if (shootOffset != NULL)
						{
							Utility::WriteMemoryEx<float>(shootOffset + Offset::BulletFireSpeed, Setting::instantv);
						}
					}
				}
				//if (Setting::Magic360deg)
				//{
				//	DWORD LocalController = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::STPlayerController);
				//	if (LocalController)
				//	{
				//		DWORD Controller1 = 0x31c;
				//		DWORD ControlRotation = 0x318;

				//		DWORD PlayerCameraManager = Utility::ReadMemoryEx<DWORD>(LocalController + Offset::PlayerCameraManager);
				//		if (PlayerCameraManager)
				//		{
				//			CameraCacheEntry CameraCache = Utility::ReadMemoryEx<CameraCacheEntry>(PlayerCameraManager + Offset::CameraCache);

				//			VECTOR3 HeadPosition = ClosestToCrosshair();
				//			VECTOR3 currentViewAngle = CameraCache.POV.Location;

				//			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
				//			{
				//				FRotator aimRotation = ToRotator(currentViewAngle, HeadPosition);
				//				CameraCache.POV.Rotation = aimRotation;
				//				Utility::WriteMemoryEx<CameraCacheEntry>(PlayerCameraManager + Offset::CameraCache, CameraCache);

				//			}
				//		}
				//	}
				//}
				if (Setting::fastrun)
				{
					if (GetAsyncKeyState(VK_RSHIFT))
					{
						Utility::WriteMemoryEx<float>(Data::LocalPlayer + Offset::CharacterOverrideAttrs, 20.0f);
					}
				}
				if (!Setting::fastrun)
				{
					float write = 1.0f;
					Utility::WriteMemoryEx<float>(Data::LocalPlayer + Offset::CharacterOverrideAttrs, write);
				}
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(30));
		}
	}
}