#pragma once

#include "Includes.h"

namespace Offset
{
	const DWORD bDead = 0xa54;  // bool bDead;//(ByteOffset: 0, ByteMask: 1, FieldMask: 1)[Offset: 0x9c0, Size: 1]
	const DWORD PersistentLevel = 0x20;
	const DWORD NetDriver = 0x24;
	const DWORD ServerConnection = 0x60;
	const DWORD PlayerController = 0x20;
	const DWORD AcknowledgedPawn = 0x400; // PlayerController.Controller.Actor.Object -> Pawn* AcknowledgedPawn;//[Offset:
	const DWORD EntityList = 0x70;
	const DWORD EntityCount = 0x74;


	namespace PlayerCameraManager1 {
		constexpr auto CameraCache = 0x3a0; // Class: PlayerCameraManager.Actor.Object -> CameraCacheEntry CameraCache;//[Offset: 0x360,
	}
	namespace STExtraPlayerCharacter {
		//Class: STExtraPlayerCharacter.STExtraBaseCharacter.STExtraCharacter.UAECharacter.Character.Pawn.Actor.Object
		constexpr auto STPlayerController = 0x30c4;//STExtraPlayerController* STPlayerController;//[Offset
	}
	namespace PlayerController1 {
		constexpr auto PlayerCameraManager = 0x30ec; // Class: PlayerController.Controller.Actor.Object -> PlayerCameraManager* PlayerCameraManager;//[Offset: 0x350,
	}

	const DWORD RootComponent = 0x158; // SceneComponent* RootComponent;//[Offset:0x154

	//Class: STExtraCharacter.UAECharacter.Character.Pawn.Actor.Object
	//uint64 CurrentStates;//[Offset: 0xb00, Size: 8]
	const DWORD CurrentStates = 0xb78; //STExtraCharacter.UAECharacter.Character.Pawn.Actor.Object -> uint64 CurrentStates;//[Offset: 0xb00


	//STExtraGameStateBase.UAEGameState.LuaGameState.GameState.GameStateBase.Info.Actor.Object
	const DWORD TotalPlayerCountOffset = 0x404; // int AlivePlayerNum;//[Offset: 0x794, Size: 4]


	// AActor
	const DWORD Nation = 0x6ac; //FString Nation;//[Offset:
	const DWORD TeamId = 0x6b4; //Class: UAECharacter.Character.Pawn.Actor.Object int TeamID;//[Offset:

	//Class: STExtraBaseCharacter.STExtraCharacter.UAECharacter.Character.Pawn.Actor.Object
	//byte PoseState;//[Offset: 0xfd8, Size: 1]
	const DWORD PoseState = 0x1084; //Class: UAECharacter.Character.Pawn.Actor.Object byte PoseState;//[Offset: 0xfc0
	const DWORD IsBot = 0x76d; // bool bIsAI;//(ByteOffset:
	const DWORD Name = 0x6a0; // FString PlayerName;//[Offset:
	const DWORD Health = 0xa3c; // float Health;//[Offset:
	const DWORD HealthMax = 0xa40; // float HealthMax;//[Offset:


	// Class: STExtraPlayerController.UAEPlayerController.LuaPlayerController.PlayerController.Controller.Actor.Object -> float CanSprintCDTime;//[Offset: 0x1ad8, Size: 4]
	const DWORD weaponOffset = 0x1c14; //Class: PlayerCameraManager.Actor.Object -> //PostProcessSettings[] PostProcessBlendCache;//[Offset:
	//float JoystickSprintBtnHeight;//[Offset: 0x1c24, Size: 0x4]

	const DWORD CharacterMovement = 0x380; // Class: Character.Pawn.Actor.Object -> CharacterMovementComponent* CharacterMovement;//[Offset:
	const DWORD LastUpdateVelocity = 0x260; // Class: CharacterMovementComponent.PawnMovementComponent.NavMovementComponent.MovementComponent.ActorComponent.Object -> Vector LastUpdateVelocity;//[Offset:
	const DWORD Velocity = 0xd0; // Class: MovementComponent.ActorComponent.Object -> Vector Velocity;//[Offset:

	const DWORD RelativeLocation = 0x120; // Class: SceneComponent.ActorComponent.Object -> Vector RelativeLocation;//[Offset:
	const DWORD RelativeRotation = 0x12c; // Class: SceneComponent.ActorComponent.Object -> Rotator RelativeRotation;//[Offset:


	// Bone
	const DWORD Mesh = 0x37c; //Character.Pawn.Actor.Object-> SkeletalMeshComponent* Mesh;//[Offset:
	const DWORD BodyAddv = 0x150; //Class: WeaponMeshCfg -> enum meshType;//[Offset
	const DWORD MinLOD = 0x6e4; //StaticMeshComponent.MeshComponent.PrimitiveComponent.SceneComponent.ActorComponent.Object-> int MinLOD;//[Offset:

	// Camera
	const DWORD PlayerCameraManager = 0x3a0; // Class: PlayerController.Controller.Actor.Object -> PlayerCameraManager* PlayerCameraManager;//[Offset:
	const DWORD CameraCache = 0x3a0; // Class: PlayerCameraManager.Actor.Object -> CameraCacheEntry CameraCache;//[Offset:
	const DWORD POV = 0x10; // Class: CameraCacheEntry -> MinimalViewInfo POV;//
	const DWORD Location = 0x0; // Class: MinimalViewInfo -> Vector Location;//
	const DWORD Rotation = 0x18; // Class: MinimalViewInfo -> Rotator Rotation;//[Offset:
	const DWORD FOV = 0x24; // Class: MinimalViewInfo -> float FOV;//[Offset:

	//////SPEED OFFSETS/////
	//CharacterOverrideAttrData[] CharacterOverrideAttrs;//[Offset: 0xd58, Size: 0xc] -> UAEGameMode.LuaGameMode.GameMode.GameModeBase.Info.Actor.Object
	const DWORD CharacterOverrideAttrs = 0x2220; // CharacterOverrideAttrs CharacterOverrideAttrs;//[Offset:

	//Instant hit
	const DWORD CurrentWeapon = 0x1E2C; // STExtraWeapon* CurrentReloadWeapon;//[Offset:

	const DWORD CurrentReloadWeapon = 0x2278; // STExtraWeapon* CurrentReloadWeapon;//[Offset:
	const DWORD ShootWeaponEntity = 0xc88; // ShootWeaponEntity* ShootWeaponEntityComp;
	const DWORD BulletFireSpeed = 0x418; // Class: ShootWeaponEntity.WeaponEntity.WeaponLogicBaseComponent.ActorComponent.Object -> float BulletFireSpeed;//[Offset: 0x408, Size: 4]

	// NoRecoil
	const DWORD AccessoriesVRecoilFactor = 0x928;
	const DWORD AccessoriesHRecoilFactor = 0x92c;
	const DWORD AccessoriesRecoveryFactor = 0x930;

	//Vehicle
	//VehicleCommonComponent.VehicleComponent.LuaActorComponent.ActorComponent.Object
	const DWORD vHP = 0x200; // Class: VehicleCommonComponent.VehicleComponent.ActorComponent.Object -> float HP;//[Offset: 0x11c, Size: 4]
	const DWORD vHPMax = 0x1fc; // Class: VehicleCommonComponent.VehicleComponent.ActorComponent.Object -> float HPMax;//[Offset: 0x118
	const DWORD vFuel = 0x25c; // Class: VehicleCommonComponent.VehicleComponent.ActorComponent.Object -> float FuelMax;//[Offset: 0x130
	const DWORD vFuelMax = 0x258;  // Class: VehicleCommonComponent.VehicleComponent.ActorComponent.Object -> float Fuel;//[Offset: 0x134
	const DWORD VehicleCommon = 0x7d0; // VehicleCommonComponent* VehicleCommon;//[Offset: 0x698,

	const DWORD Position = 0x160;

	const DWORD boxItemCount = 1664;  //count = itemBase + 4 : 1680 + 4 Class: ItemDefineID --> int TypeSpecificID;//[Offset: 0x4, Size: 4]  -- need convirt to decimal from hex
	const DWORD boxItemBase = 0x6f8;  //PickUpItemData[] PickUpDataList;//[Offset:


	//Game Status
	const DWORD GameStateBase = 0x13c; //Class: World.Object   GameStateBase* GameState;//[Offset:
	const DWORD AlivePlayerNum = 0x814; //Class: STExtraGameStateBase.UAEGameState.LuaGameState.GameState.GameStateBase.Info.Actor.Object  int AlivePlayerNum;//[Offset:
	const DWORD ElapsedTime = 0x378; //Class: GameState.GameStateBase.Info.Actor.Object -> int ElapsedTime;//[Offset:
	const DWORD AliveTeamNum = 0x818; //int AliveTeamNum;//[Offset:
	const DWORD PlayerNum = 0x580; // int PlayerNum;//[Offset:
	const DWORD CurCircleWave = 0x7a0; //int CurCircleWave;//[Offset:
	const DWORD GameModeID = 0xc18; //Class: STExtraGameStateBase.UAEGameState.LuaGameState.GameState.GameStateBase.Info.Actor.Object  ->  FString GameModeID;//[Offset:
	const DWORD IsFPPGameMode = 0x678; //bool IsFPPGameMode;//(ByteOffset: 0, ByteMask: 1, FieldMask: 255)[Offset:

}
