#include "Setting.h"

bool Setting::ShowMenu = true;
int Setting::ItemSize = 20;
int Setting::PlayerTotalKills;
int Setting::redzoneSize = 20;
int Setting::carsize = 15;
int Setting::carDist = 150;
int Setting::playernamesize = 17;
int Setting::PlayerWeaponSize = 10;
int Setting::GranadeWarningSize = 30;
const char* Setting::GranadeWarningType[] = { "Image","Text" };
int Setting::G_warningType = 0;
float Setting::G_warningColor[4] = { 1.00f, 0.00f, 0.00f , 1.00f };

const char* Setting::HackInjectType[] = { "Safe Mode","Brutal Mode" ,"Only ESP" };
int Setting::I_HackInjectType = 0;

int Setting::AlivePlayers;
int Setting::TimeRemind;
int Setting::AliveTeams;
int Setting::RealPls;
int Setting::ZoneID;
int Setting::MyTeamID;
int Setting::GameID;

int	Setting::instantv = 500000;
int	Setting::lineChose = 0;
bool Setting::lineTop = true;

bool Setting::G_Warning_Frag = false;
bool Setting::G_Warning_Molotof = false;
bool Setting::G_Warning_Smoke = false;


bool Setting::isAntiban = false;
bool Setting::sideMenu = false;
bool Setting::PlayerAiming = true;


bool Setting::gameInfo = true;


string Setting::versionString;
string Setting::expiresString;

string Setting::userKey = "";

bool Setting::Name = true;
bool Setting::PlayerWeapon = false;
bool Setting::Nation = false;
bool Setting::TeamId = false;
bool Setting::Distance = false;
int Setting::DistanceSize = 16;
bool Setting::TotalEnemy = true;
bool Setting::Line = true;
bool Setting::Box = false;
bool Setting::Bone = true;
bool Setting::Health = true;
bool Setting::BombAlert = false;
bool Setting::Item = false;
bool Setting::Vehicle = false;
bool Setting::country = false;
bool Setting::Redzone = false;
bool Setting::isOldUI = false;

bool Setting::DeadsBox = false;

bool Setting::radar = false;
bool Setting::cameratracking = false;


bool Setting::memoryEnabled = true;

bool Setting::Vng = false;






//Aimbot - Magic
bool Setting::Aimbot = false;
bool Setting::MagicInsideFOV = true;

float Setting::fovcircleredus = 65.0f;
float Setting::Ipad = 360.0f;
float Setting::bonesize = 0.5f;
float Setting::fovcirclecolor[4] = { 0.986f, 0.952f, 0.209f, 1.000f };
bool Setting::fovcircle = false;
int	Setting::curraim = 0;
int	Setting::magicv = 7;
bool Setting::knocked = false;
DWORD Setting::CurrentTargetAddress = 0;




bool Setting::Magic360deg = false;
bool Setting::instanthit = false;
bool Setting::NoRecoil = false;
bool Setting::IpadView = false;
bool Setting::ownInfo = true;


bool Setting::magicAutoLocation = false;


bool Setting::MagicBullet = false;
int Setting::AimbotKey = 0x01;
int Setting::OnOffAimbotKey = VK_F3;
int Setting::ItemOnOffKey = VK_F7;
int Setting::MidMagicButton = 0x72;
int Setting::MagicPositionKey = 0x54;
bool Setting::MAgicline = false;
bool Setting::SkipBots = false;
bool Setting::aimbotposition = true;
float Setting::Aimspeed = 2.0f;

int Setting::EnableMagicKey = VK_F2;


int	Setting::GameVersionL = 0;


int Setting::matchInfo_TotalPlayer;


float Setting::magicDistance = 300.0f;


bool Setting::EnemyStatus = false;
bool Setting::FightMode = false;

bool Setting::fastrun = false;

bool Setting::enemyIndicator = false;
bool Setting::streamMode = false;

bool Setting::fullLogin = false;

bool Setting::vehicleHpFuel = true;


bool Setting::fastCar = false;
int	Setting::carsv = 300.0f;






bool Setting::deadbox = true;
bool Setting::deadboxBG = true;

ImVec4 Setting::colorcode;



float Setting::BoneColor[4] = { 1.00f, 1.00f, 1.00f , 1.00f };
bool Setting::BoneColorSameAsLineBool = true;
ImVec4 Setting::BoneColorSameAsLine;




ImVec4	weapon::MG3{ 1.000f, 0.695f, 0.323f, 1.000f };
ImVec4	weapon::FAMAS{ 0.118f, 0.76f, 0.788f, 1.000f };
ImVec4	weapon::Mk14{ 0.844f, 0.066f, 1.000f, 1.000f };
ImVec4	weapon::G36{ 0.61f, 0.19f, 1.00f, 1.0f };
ImVec4	weapon::AN94{ 0.61f, 0.19f, 1.00f, 1.0f };

ImVec4 weapon::m16 = { 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4  weapon::AKM = { 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4  weapon::AWM = { 1.000f, 0.089f, 0.089f, 1.000f };
ImVec4  weapon::AWMimmo = { 0.942f, 0.300f, 0.073f, 1.000f };

ImVec4  weapon::scarl = { 1.000f, 0.695f, 0.323f, 1.000f };
ImVec4  weapon::m762 = { 0.118f, 0.76f, 0.788f, 1.000f };
ImVec4  weapon::M24 = { 0.844f, 0.066f, 1.000f, 1.000f };
ImVec4  weapon::GROZZA = { 0.279f, 0.990f, 0.812f, 1.000f };
ImVec4  weapon::scope8x = { 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4  weapon::kar98 = { 1.0f, 0.60f,0.05f, 1.0f };
ImVec4  weapon::Airdrop = { 0.279f, 0.990f, 0.812f, 1.000f };
ImVec4  weapon::Flare = { 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4  weapon::Flaregun = { 1.0f, 0.60f,0.05f, 1.0f };

/////////////////////////drop//////////////////////////
ImVec4 Colors::bgcorner = { 0.000f, 1.000f, 0.964f, 1.000f };
ImVec4  Colors::dp = { 1.000f, 0.760f, 0.150f, 1.000f };
ImVec4  Colors::scope4x = { 0.937f, 0.063f, 0.937f, 1.000f };
ImVec4  Colors::scope3x = { 0.874f, 0.484f, 0.106f, 1.000f };
ImVec4  Colors::bag = { 0.529f, 0.127f, 0.903f, 1.000f };
ImVec4  Colors::armer = { 0.591f, 1.000f, 0.237f, 1.000f };
ImVec4  Colors::helmat = { 0.726f, 0.070f, 0.908f, 1.000f };
ImVec4  Colors::mosin = { 0.258f, 0.971f, 0.775f, 1.000f };
ImVec4  Colors::aug = { 0.442f, 0.971f, 0.122f, 1.000f };
ImVec4  Colors::g36 = { 0.671f, 0.217f, 1.000f, 1.000f };
ImVec4  Colors::assm = { 1.000f, 0.217f, 0.762f, 1.000f };

ImVec4 Colors::Grandes = { 1.000f, 0.396f, 0.357f, 1.000f };
ImVec4 Colors::ammo7 = { 0.957f, 0.353f, 0.226f, 1.000f };
ImVec4 Colors::ammo5 = { 0.000f, 1.000f, 0.000f, 1.000f };
ImVec4 Colors::madkit = { 0.952f, 0.558f, 0.129f, 1.000f };


int	Setting::RadarLength = 200;
int	Setting::instanthitsize = 3000;
int	Setting::RadarWidth = 200;
float Setting::PlayerMaxDistance = 350.0f;

ImVec4 Setting::linescolors;

int CurrentAim = 0;

float Setting::RedZoneColor[4] = { 0.00f, 1.00f, 0.32f , 1.00f };
float Setting::PlayerNameColor[4] = { 1.000f, 0.620f, 0.150f , 1.000f };

//float PlayerWeaponColor[4] = { 0.69f, 0.71f, 0.60f, 1.00f };
float Setting::BoxColor[4] = { 1.00f, 1.00f, 1.00f , 1.00f };
float Setting::LineColor[4] = { 1.00f, 0.76f, 0.15f, 1.0f };
float Setting::VehhilceColor[4] = { 0.90f, 1.00f, 0.00f , 1.00f };
float Setting::VehhilceUsedColor[4] = { 1.000f, 0.620f, 0.150f, 1.000f };
float Setting::hpFuel[4] = { 0.00f, 1.00f, 0.32f , 1.00f };


float Setting::TotalEnemyColor[4] = { 0.00f, 1.00f, 0.32f , 1.00f };
int Setting::TotalEnemySize = 18;

bool Setting::Esp_Item_AKM = false;
float Setting::Esp_Item_AKM_Color[4] = { 1.00f, 0.00f, 0.00f, 1.00f };
float Setting::Esp_Item_AKM_TextSize = 20.0f;

bool Setting::Esp_Item_Groza = false;
float Setting::Esp_Item_Groza_Color[4] = { 1.00f, 0.00f, 0.00f, 1.00f };
float Setting::Esp_Item_Groza_TextSize = 20.0f;

bool Setting::Esp_Item_PlayerDeadBox = false;
float Setting::Esp_Item_PlayerDeadBox_Color[4] = { 0.69f, 0.71f, 0.60f, 1.00f };
float Setting::Esp_Item_PlayerDeadBox_TextSize = 20.0f;


bool Setting::Esp_Item_M762 = false;
float Setting::Esp_Item_M762_Color[4] = { 1.00f, 0.00f, 0.00f, 1.00f };
float Setting::Esp_Item_M762_TextSize = 20.0f;

bool Setting::Esp_Item_Mk47Mutant = false;
float Setting::Esp_Item_Mk47Mutant_Color[4] = { 0.69f, 0.71f, 0.60f, 1.00f };
float Setting::Esp_Item_Mk47Mutant_TextSize = 20.0f;

bool Setting::Esp_Item_DP28 = false;
float Setting::Esp_Item_DP28_Color[4] = { 0.69f, 0.71f, 0.60f, 1.00f };
float Setting::Esp_Item_DP28_TextSize = 20.0f;

bool Setting::Esp_Item_SCARL = false;
float Setting::Esp_Item_SCARL_Color[4] = { 1.00f, 0.00f, 0.00f, 1.00f };
float Setting::Esp_Item_SCARL_TextSize = 20.0f;

bool Setting::Esp_Item_M416 = false;
float Setting::Esp_Item_M416_Color[4] = { 1.00f, 0.00f, 0.00f, 1.00f };
float Setting::Esp_Item_M416_TextSize = 20.0f;

bool Setting::Esp_Item_M249 = false;
float Setting::Esp_Item_M249_Color[4] = { 1.00f, 0.00f, 0.00f, 1.00f };
float Setting::Esp_Item_M249_TextSize = 20.0f;

bool Setting::Esp_Item_AUG = false;
float Setting::Esp_Item_AUG_Color[4] = { 0.98f, 0.64f, 0.17f, 1.00f };
float Setting::Esp_Item_AUG_TextSize = 20.0f;


bool Setting::Esp_Item_M16A4 = false;
float Setting::Esp_Item_M16A4_Color[4] = { 0.98f, 0.64f, 0.17f, 1.00f };
float Setting::Esp_Item_M16A4_TextSize = 20.0f;


bool Setting::Esp_Item_G36C = false;
float Setting::Esp_Item_G36C_Color[4] = { 0.98f, 0.64f, 0.17f, 1.00f };
float Setting::Esp_Item_G36C_TextSize = 20.0f;

bool Setting::Esp_Item_QBZ = false;
float Setting::Esp_Item_QBZ_Color[4] = { 0.98f, 0.64f, 0.17f, 1.00f };
float Setting::Esp_Item_QBZ_TextSize = 20.0f;

bool Setting::Esp_Item_QBU = false;
float Setting::Esp_Item_QBU_Color[4] = { 0.00f, 0.00f, 0.31f,1.00f };
float Setting::Esp_Item_QBU_TextSize = 20.0f;

bool Setting::Esp_Item_SLR = false;
float Setting::Esp_Item_SLR_Color[4] = { 0.00f, 0.00f, 0.31f,1.00f };
float Setting::Esp_Item_SLR_TextSize = 20.0f;

bool Setting::Esp_Item_SKS = false;
float Setting::Esp_Item_SKS_Color[4] = { 0.80f, 0.00f, 1.00f,1.00f };
float Setting::Esp_Item_SKS_TextSize = 20.0f;

bool Setting::Esp_Item_Mini14 = false;
float Setting::Esp_Item_Mini14_Color[4] = { 0.80f, 0.00f, 1.00f,1.00f };
float Setting::Esp_Item_Mini14_TextSize = 20.0f;

bool Setting::Esp_Item_M24 = false;
float Setting::Esp_Item_M24_Color[4] = { 1.00f, 0.00f, 0.00f, 1.00f };
float Setting::Esp_Item_M24_TextSize = 20.0f;

bool Setting::Esp_Item_Kar98k = false;
float Setting::Esp_Item_Kar98k_Color[4] = { 0.80f, 0.00f, 1.00f,1.00f };
float Setting::Esp_Item_Kar98k_TextSize = 20.0f;

bool Setting::Esp_Item_AWM = false;
float Setting::Esp_Item_AWM_Color[4] = { 1.00f, 0.00f, 0.00f, 1.00f };
float Setting::Esp_Item_AWM_TextSize = 20.0f;

bool Setting::Esp_Item_Crossbow = false;
float Setting::Esp_Item_Crossbow_Color[4] = { 0.80f, 0.00f, 1.00f,1.00f };
float Setting::Esp_Item_Crossbow_TextSize = 20.0f;



bool Setting::Esp_Item_PP19 = false;
float Setting::Esp_Item_PP19_Color[4] = { 0.00f, 1.00f, 0.31f, 1.00f };
float Setting::Esp_Item_PP19_TextSize = 20.0f;

bool Setting::Esp_Item_TommyGun = false;
float Setting::Esp_Item_TommyGun_Color[4] = { 0.00f, 1.00f, 0.31f, 1.00f };
float Setting::Esp_Item_TommyGun_TextSize = 20.0f;

bool Setting::Esp_Item_MP5K = false;
float Setting::Esp_Item_MP5K_Color[4] = { 0.00f, 1.00f, 0.31f, 1.00f };
float Setting::Esp_Item_MP5K_TextSize = 20.0f;

bool Setting::Esp_Item_UMP9 = false;
float Setting::Esp_Item_UMP9_Color[4] = { 0.00f, 1.00f, 0.31f, 1.00f };
float Setting::Esp_Item_UMP9_TextSize = 20.0f;

bool Setting::Esp_Item_Vector = false;
float Setting::Esp_Item_Vector_Color[4] = { 0.00f, 1.00f, 0.31f, 1.00f };
float Setting::Esp_Item_Vector_TextSize = 20.0f;

bool Setting::Esp_Item_Uzi = false;
float Setting::Esp_Item_Uzi_Color[4] = { 0.00f, 1.00f, 0.31f, 1.00f };
float Setting::Esp_Item_Uzi_TextSize = 20.0f;

bool Setting::Esp_Item_762mm = false;
float Setting::Esp_Item_762mm_Color[4] = { 0.75f, 1.00f, 0.24f, 1.0f };
float Setting::Esp_Item_762mm_TextSize = 20.0f;

bool Setting::Esp_Item_556mm = false;
float Setting::Esp_Item_556mm_Color[4] = { 0.00f, 1.0f, 0.0f, 1.0f };
float Setting::Esp_Item_556mm_TextSize = 20.0f;

bool Setting::Esp_Item_9mm = false;
float Setting::Esp_Item_9mm_Color[4] = { 0.75f, 1.00f, 0.24f, 1.0f };
float Setting::Esp_Item_9mm_TextSize = 20.0f;

bool Setting::Esp_Item_300Magnum = false;
float Setting::Esp_Item_300Magnum_Color[4] = { 1.00f, 0.00f, 0.00f, 1.00f };
float Setting::Esp_Item_300Magnum_TextSize = 20.0f;



bool Setting::Esp_Item_45ACP = false;
float Setting::Esp_Item_45ACP_Color[4] = { 0.76f, 0.98f, 0.85f, 1.00f };
float Setting::Esp_Item_45ACP_TextSize = 20.0f;



bool Setting::Esp_Item_RedDot = false;
float Setting::Esp_Item_RedDot_Color[4] = { 1.00f, 0.0f, 1.0f, 1.0f };
float Setting::Esp_Item_RedDot_TextSize = 20.0f;

bool Setting::Esp_Item_Holo = false;
float Setting::Esp_Item_Holo_Color[4] = { 1.00f, 0.0f, 1.0f, 1.0f };
float Setting::Esp_Item_Holo_TextSize = 20.0f;

bool Setting::Esp_Item_x2 = false;
float Setting::Esp_Item_x2_Color[4] = { 0.12f, 0.52f, 0.79f, 1.00f };
float Setting::Esp_Item_x2_TextSize = 20.0f;

bool Setting::Esp_Item_x3 = false;
float Setting::Esp_Item_x3_Color[4] = { 0.12f, 0.52f, 0.79f, 1.00f };
float Setting::Esp_Item_x3_TextSize = 20.0f;

bool Setting::Esp_Item_x4 = false;
float Setting::Esp_Item_x4_Color[4] = { 0.12f, 0.52f, 0.79f, 1.00f };
float Setting::Esp_Item_x4_TextSize = 20.0f;

bool Setting::Esp_Item_x6 = false;
float Setting::Esp_Item_x6_Color[4] = { 1.00f, 0.00f, 0.00f, 1.00f };
float Setting::Esp_Item_x6_TextSize = 20.0f;

bool Setting::Esp_Item_x8 = false;
float Setting::Esp_Item_x8_Color[4] = { 1.00f, 0.00f, 0.00f, 1.00f };
float Setting::Esp_Item_x8_TextSize = 20.0f;

bool Setting::Esp_Item_Bag1 = false;
float Setting::Esp_Item_Bag1_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting::Esp_Item_Bag1_TextSize = 20.0f;

bool Setting::Esp_Item_Bag2 = false;
float Setting::Esp_Item_Bag2_Color[4] = { 0.62f, 0.10f, 0.94f, 1.00f };
float Setting::Esp_Item_Bag2_TextSize = 20.0f;

bool Setting::Esp_Item_Bag3 = false;
float Setting::Esp_Item_Bag3_Color[4] = { 1.00f, 0.00f, 0.00f, 1.00f };
float Setting::Esp_Item_Bag3_TextSize = 20.0f;

bool Setting::Esp_Item_Armor1 = false;
float Setting::Esp_Item_Armor1_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting::Esp_Item_Armor1_TextSize = 20.0f;

bool Setting::Esp_Item_Armor2 = false;
float Setting::Esp_Item_Armor2_Color[4] = { 0.62f, 0.10f, 0.94f, 1.00f };
float Setting::Esp_Item_Armor2_TextSize = 20.0f;

bool Setting::Esp_Item_Armor3 = false;
float Setting::Esp_Item_Armor3_Color[4] = { 1.00f, 0.00f, 0.00f, 1.00f };
float Setting::Esp_Item_Armor3_TextSize = 20.0f;

bool Setting::Esp_Item_Helmet1 = false;
float Setting::Esp_Item_Helmet1_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting::Esp_Item_Helmet1_TextSize = 20.0f;

bool Setting::Esp_Item_Helmet2 = false;
float Setting::Esp_Item_Helmet2_Color[4] = { 0.62f, 0.10f, 0.94f, 1.00f };
float Setting::Esp_Item_Helmet2_TextSize = 20.0f;

bool Setting::Esp_Item_Helmet3 = false;
float Setting::Esp_Item_Helmet3_Color[4] = { 1.00f, 0.00f, 0.00f, 1.00f };
float Setting::Esp_Item_Helmet3_TextSize = 20.0f;

bool Setting::Esp_Item_Frag = false;
float Setting::Esp_Item_Frag_Color[4] = { 0.62f, 0.64f, 0.00f, 1.00f };
float Setting::Esp_Item_Frag_TextSize = 20.0f;

bool Setting::Esp_Item_Smoke = false;
float Setting::Esp_Item_Smoke_Color[4] = { 0.62f, 0.64f, 0.00f, 1.00f };
float Setting::Esp_Item_Smoke_TextSize = 20.0f;

bool Setting::Esp_Item_Molotof = false;
float Setting::Esp_Item_Molotof_Color[4] = { 0.62f, 0.64f, 0.00f, 1.00f };
float Setting::Esp_Item_Molotof_TextSize = 20.0f;

bool Setting::Esp_Item_MedKit = false;
float Setting::Esp_Item_MedKit_Color[4] = { 0.96f, 0.76f, 0.89f, 1.00f };
float Setting::Esp_Item_MedKit_TextSize = 20.0f;

bool Setting::Esp_Item_FirstAidKit = false;
float Setting::Esp_Item_FirstAidKit_Color[4] = { 0.96f, 0.76f, 0.89f, 1.00f };
float Setting::Esp_Item_FirstAidKit_TextSize = 20.0f;

bool Setting::Esp_Item_Painkiller = false;
float Setting::Esp_Item_Painkiller_Color[4] = { 0.96f, 0.76f, 0.89f, 1.00f };
float Setting::Esp_Item_Painkiller_TextSize = 20.0f;

bool Setting::Esp_Item_EnergyDrink = false;
float Setting::Esp_Item_EnergyDrink_Color[4] = { 0.30f, 0.67f, 1.00f, 1.00f };
float Setting::Esp_Item_EnergyDrink_TextSize = 20.0f;

bool Setting::Esp_Item_AdrenalineSyringe = false;
float Setting::Esp_Item_AdrenalineSyringe_Color[4] = { 0.96f, 0.76f, 0.89f, 1.00f };
float Setting::Esp_Item_AdrenalineSyringe_TextSize = 20.0f;

bool Setting::Esp_Item_FlareGun = false;
float Setting::Esp_Item_FlareGun_Color[4] = { 1.00f, 0.00f, 0.00f, 1.0f };
float Setting::Esp_Item_FlareGun_TextSize = 20.0f;

bool Setting::Esp_Item_GasCan = false;
float Setting::Esp_Item_GasCan_Color[4] = { 0.69f, 0.71f, 0.60f, 1.00f };
float Setting::Esp_Item_GasCan_TextSize = 20.0f;

bool Setting::Esp_Item_Flare = false;
float Setting::Esp_Item_Flare_Color[4] = { 1.00f, 0.00f, 0.00f, 1.0f };
float Setting::Esp_Item_Flare_TextSize = 20.0f;

bool Setting::Esp_Item_AirDrop = false;
float Setting::Esp_Item_AirDrop_Color[4] = { 1.00f, 0.00f, 0.00f, 1.0f };
float Setting::Esp_Item_AirDrop_TextSize = 20.0f;

bool Setting::Esp_Item_PlayerBox = false;
float Setting::Esp_Item_PlayerBox_Color[4] = { 1.00f, 1.00f, 1.00f, 1.00f };
float Setting::Esp_Item_PlayerBox_TextSize = 20.0f;
