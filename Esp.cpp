#include "Esp.h"
#include "Scanner.h"
#include "SimpleIni.h"
#include "Drawing.h"
#include "Menu.h"
#include "Setting.h"

#include <string.h>
#include <thread>
#include <D3DX11tex.h>
#include "auth.hpp"
#include <DiscordR.h>
#include "notification/imgui_notify.h"
#include <skStr.h>
using namespace KeyAuth;


#pragma region Define
MainMenu menu;
Drawing draw;

bool loader_active = true;
bool SaveUsers = true;
bool login = false;
bool ShowMenu2 = false;
char str1[100] = "";
#pragma endregion
DiscordR* g_Discord;


ImVec4 bonescolors1;
int currIndex;

#pragma region allert
ID3D11ShaderResourceView* Active = nullptr;
ID3D11ShaderResourceView* READ = nullptr;
ID3D11ShaderResourceView* YELLOW = nullptr;
#pragma endregion

#pragma region FLAGS

ID3D11ShaderResourceView* AFFLAG = nullptr;

ID3D11ShaderResourceView* ALFLAG = nullptr;

ID3D11ShaderResourceView* DZFLAG = nullptr;

ID3D11ShaderResourceView* ASFLAG = nullptr;

ID3D11ShaderResourceView* ADFLAG = nullptr;

ID3D11ShaderResourceView* AOFLAG = nullptr;

ID3D11ShaderResourceView* AIFLAG = nullptr;

ID3D11ShaderResourceView* AQFLAG = nullptr;

ID3D11ShaderResourceView* AGFLAG = nullptr;

ID3D11ShaderResourceView* ARFLAG = nullptr;

ID3D11ShaderResourceView* AMFLAG = nullptr;

ID3D11ShaderResourceView* AWFLAG = nullptr;

ID3D11ShaderResourceView* AUFLAG = nullptr;

ID3D11ShaderResourceView* ATFLAG = nullptr;

ID3D11ShaderResourceView* AZFLAG = nullptr;

ID3D11ShaderResourceView* BSFLAG = nullptr;

ID3D11ShaderResourceView* BHFLAG = nullptr;

ID3D11ShaderResourceView* BDFLAG = nullptr;

ID3D11ShaderResourceView* BBFLAG = nullptr;

ID3D11ShaderResourceView* BYFLAG = nullptr;

ID3D11ShaderResourceView* BEFLAG = nullptr;

ID3D11ShaderResourceView* BZFLAG = nullptr;

ID3D11ShaderResourceView* BJFLAG = nullptr;

ID3D11ShaderResourceView* BMFLAG = nullptr;

ID3D11ShaderResourceView* BTFLAG = nullptr;

ID3D11ShaderResourceView* BOFLAG = nullptr;

ID3D11ShaderResourceView* BQFLAG = nullptr;

ID3D11ShaderResourceView* BAFLAG = nullptr;

ID3D11ShaderResourceView* BWFLAG = nullptr;

ID3D11ShaderResourceView* BVFLAG = nullptr;

ID3D11ShaderResourceView* BRFLAG = nullptr;

ID3D11ShaderResourceView* IOFLAG = nullptr;

ID3D11ShaderResourceView* BNFLAG = nullptr;

ID3D11ShaderResourceView* BGFLAG = nullptr;

ID3D11ShaderResourceView* BFFLAG = nullptr;

ID3D11ShaderResourceView* BIFLAG = nullptr;

ID3D11ShaderResourceView* CVFLAG = nullptr;

ID3D11ShaderResourceView* KHFLAG = nullptr;

ID3D11ShaderResourceView* CMFLAG = nullptr;

ID3D11ShaderResourceView* CAFLAG = nullptr;

ID3D11ShaderResourceView* KYFLAG = nullptr;

ID3D11ShaderResourceView* CFFLAG = nullptr;

ID3D11ShaderResourceView* TDFLAG = nullptr;

ID3D11ShaderResourceView* CLFLAG = nullptr;

ID3D11ShaderResourceView* CNFLAG = nullptr;

ID3D11ShaderResourceView* CXFLAG = nullptr;

ID3D11ShaderResourceView* CCFLAG = nullptr;

ID3D11ShaderResourceView* COFLAG = nullptr;

ID3D11ShaderResourceView* KMFLAG = nullptr;

ID3D11ShaderResourceView* CDFLAG = nullptr;
ID3D11ShaderResourceView* CGFLAG = nullptr;

ID3D11ShaderResourceView* CKFLAG = nullptr;

ID3D11ShaderResourceView* CRFLAG = nullptr;

ID3D11ShaderResourceView* HRFLAG = nullptr;

ID3D11ShaderResourceView* CUFLAG = nullptr;

ID3D11ShaderResourceView* CWFLAG = nullptr;

ID3D11ShaderResourceView* CYFLAG = nullptr;

ID3D11ShaderResourceView* CZFLAG = nullptr;

ID3D11ShaderResourceView* CIFLAG = nullptr;

ID3D11ShaderResourceView* DKFLAG = nullptr;

ID3D11ShaderResourceView* DJFLAG = nullptr;

ID3D11ShaderResourceView* DMFLAG = nullptr;

ID3D11ShaderResourceView* DOFLAG = nullptr;

ID3D11ShaderResourceView* ECFLAG = nullptr;

ID3D11ShaderResourceView* EGFLAG = nullptr;

ID3D11ShaderResourceView* SVFLAG = nullptr;

ID3D11ShaderResourceView* GQFLAG = nullptr;

ID3D11ShaderResourceView* ERFLAG = nullptr;

ID3D11ShaderResourceView* EEFLAG = nullptr;

ID3D11ShaderResourceView* SZFLAG = nullptr;
ID3D11ShaderResourceView* ETFLAG = nullptr;
ID3D11ShaderResourceView* FKFLAG = nullptr;

ID3D11ShaderResourceView* FOFLAG = nullptr;
ID3D11ShaderResourceView* FJFLAG = nullptr;

ID3D11ShaderResourceView* FIFLAG = nullptr;

ID3D11ShaderResourceView* FRFLAG = nullptr;

ID3D11ShaderResourceView* GFFLAG = nullptr;

ID3D11ShaderResourceView* PFFLAG = nullptr;
ID3D11ShaderResourceView* TFFLAG = nullptr;
ID3D11ShaderResourceView* GAFLAG = nullptr;
ID3D11ShaderResourceView* GMFLAG = nullptr;
ID3D11ShaderResourceView* GEFLAG = nullptr;
ID3D11ShaderResourceView* DEFLAG = nullptr;
ID3D11ShaderResourceView* GHFLAG = nullptr;
ID3D11ShaderResourceView* GIFLAG = nullptr;
ID3D11ShaderResourceView* GRFLAG = nullptr;
ID3D11ShaderResourceView* GLFLAG = nullptr;
ID3D11ShaderResourceView* GDFLAG = nullptr;
ID3D11ShaderResourceView* GPFLAG = nullptr;
ID3D11ShaderResourceView* GUFLAG = nullptr;
ID3D11ShaderResourceView* GTFLAG = nullptr;
ID3D11ShaderResourceView* GGFLAG = nullptr;
ID3D11ShaderResourceView* GNFLAG = nullptr;
ID3D11ShaderResourceView* GWFLAG = nullptr;
ID3D11ShaderResourceView* GYFLAG = nullptr;
ID3D11ShaderResourceView* HTFLAG = nullptr;
ID3D11ShaderResourceView* HMFLAG = nullptr;
ID3D11ShaderResourceView* VAFLAG = nullptr;
ID3D11ShaderResourceView* HNFLAG = nullptr;
ID3D11ShaderResourceView* HKFLAG = nullptr;
ID3D11ShaderResourceView* HUFLAG = nullptr;
ID3D11ShaderResourceView* JMFLAG = nullptr;
ID3D11ShaderResourceView* G1FLAG = nullptr;
ID3D11ShaderResourceView* JPFLAG = nullptr;
ID3D11ShaderResourceView* JEFLAG = nullptr;
ID3D11ShaderResourceView* JOFLAG = nullptr;
ID3D11ShaderResourceView* KZFLAG = nullptr;
ID3D11ShaderResourceView* KEFLAG = nullptr;
ID3D11ShaderResourceView* KIFLAG = nullptr;
ID3D11ShaderResourceView* KPFLAG = nullptr;
ID3D11ShaderResourceView* KRFLAG = nullptr;
ID3D11ShaderResourceView* KWFLAG = nullptr;
ID3D11ShaderResourceView* KGFLAG = nullptr;
ID3D11ShaderResourceView* LAFLAG = nullptr;
ID3D11ShaderResourceView* LVFLAG = nullptr;
ID3D11ShaderResourceView* LBFLAG = nullptr;
ID3D11ShaderResourceView* LSFLAG = nullptr;
ID3D11ShaderResourceView* LRFLAG = nullptr;
ID3D11ShaderResourceView* LYFLAG = nullptr;

ID3D11ShaderResourceView* LIFLAG = nullptr;

ID3D11ShaderResourceView* LTFLAG = nullptr;

ID3D11ShaderResourceView* LUFLAG = nullptr;

ID3D11ShaderResourceView* MOFLAG = nullptr;

ID3D11ShaderResourceView* MGFLAG = nullptr;

ID3D11ShaderResourceView* MWFLAG = nullptr;

ID3D11ShaderResourceView* MYFLAG = nullptr;

ID3D11ShaderResourceView* MVFLAG = nullptr;

ID3D11ShaderResourceView* MLFLAG = nullptr;

ID3D11ShaderResourceView* MTFLAG = nullptr;

ID3D11ShaderResourceView* MHFLAG = nullptr;

ID3D11ShaderResourceView* MQFLAG = nullptr;

ID3D11ShaderResourceView* MRFLAG = nullptr;

ID3D11ShaderResourceView* MUFLAG = nullptr;

ID3D11ShaderResourceView* YTFLAG = nullptr;

ID3D11ShaderResourceView* MXFLAG = nullptr;

ID3D11ShaderResourceView* FMFLAG = nullptr;

ID3D11ShaderResourceView* MDFLAG = nullptr;

ID3D11ShaderResourceView* MCFLAG = nullptr;

ID3D11ShaderResourceView* MNFLAG = nullptr;

ID3D11ShaderResourceView* MEFLAG = nullptr;

ID3D11ShaderResourceView* MSFLAG = nullptr;

ID3D11ShaderResourceView* MAFLAG = nullptr;
ID3D11ShaderResourceView* MZFLAG = nullptr;
ID3D11ShaderResourceView* MMFLAG = nullptr;
ID3D11ShaderResourceView* NAFLAG = nullptr;
ID3D11ShaderResourceView* NRFLAG = nullptr;

ID3D11ShaderResourceView* NPFLAG = nullptr;

ID3D11ShaderResourceView* NLFLAG = nullptr;

ID3D11ShaderResourceView* NCFLAG = nullptr;

ID3D11ShaderResourceView* NZFLAG = nullptr;

ID3D11ShaderResourceView* NIFLAG = nullptr;

ID3D11ShaderResourceView* NEFLAG = nullptr;

ID3D11ShaderResourceView* NGFLAG = nullptr;

ID3D11ShaderResourceView* NUFLAG = nullptr;

ID3D11ShaderResourceView* NFFLAG = nullptr;

ID3D11ShaderResourceView* MPFLAG = nullptr;

ID3D11ShaderResourceView* NOFLAG = nullptr;

ID3D11ShaderResourceView* OMFLAG = nullptr;

ID3D11ShaderResourceView* PKFLAG = nullptr;

ID3D11ShaderResourceView* PWFLAG = nullptr;

ID3D11ShaderResourceView* PSFLAG = nullptr;

ID3D11ShaderResourceView* PAFLAG = nullptr;

ID3D11ShaderResourceView* PGFLAG = nullptr;

ID3D11ShaderResourceView* PYFLAG = nullptr;

ID3D11ShaderResourceView* PEFLAG = nullptr;

ID3D11ShaderResourceView* PHFLAG = nullptr;

ID3D11ShaderResourceView* PNFLAG = nullptr;

ID3D11ShaderResourceView* PLFLAG = nullptr;

ID3D11ShaderResourceView* PTFLAG = nullptr;

ID3D11ShaderResourceView* PRFLAG = nullptr;
ID3D11ShaderResourceView* QAFLAG = nullptr;

ID3D11ShaderResourceView* MKFLAG = nullptr;

ID3D11ShaderResourceView* ROFLAG = nullptr;

ID3D11ShaderResourceView* RUFLAG = nullptr;

ID3D11ShaderResourceView* RWFLAG = nullptr;

ID3D11ShaderResourceView* REFLAG = nullptr;

ID3D11ShaderResourceView* BLFLAG = nullptr;

ID3D11ShaderResourceView* SHFLAG = nullptr;

ID3D11ShaderResourceView* KNFLAG = nullptr;

ID3D11ShaderResourceView* LCFLAG = nullptr;

ID3D11ShaderResourceView* MFFLAG = nullptr;

ID3D11ShaderResourceView* PMFLAG = nullptr;

ID3D11ShaderResourceView* VCFLAG = nullptr;

ID3D11ShaderResourceView* WSFLAG = nullptr;

ID3D11ShaderResourceView* SMFLAG = nullptr;

ID3D11ShaderResourceView* STFLAG = nullptr;

ID3D11ShaderResourceView* SAFLAG = nullptr;

ID3D11ShaderResourceView* SNFLAG = nullptr;

ID3D11ShaderResourceView* RSFLAG = nullptr;

ID3D11ShaderResourceView* SCFLAG = nullptr;

ID3D11ShaderResourceView* SLFLAG = nullptr;

ID3D11ShaderResourceView* SGFLAG = nullptr;

ID3D11ShaderResourceView* SXFLAG = nullptr;

ID3D11ShaderResourceView* SKFLAG = nullptr;

ID3D11ShaderResourceView* SIFLAG = nullptr;

ID3D11ShaderResourceView* SBFLAG = nullptr;

ID3D11ShaderResourceView* SOFLAG = nullptr;

ID3D11ShaderResourceView* ZAFLAG = nullptr;

ID3D11ShaderResourceView* GSFLAG = nullptr;

ID3D11ShaderResourceView* SSFLAG = nullptr;

ID3D11ShaderResourceView* ESFLAG = nullptr;

ID3D11ShaderResourceView* LKFLAG = nullptr;

ID3D11ShaderResourceView* SDFLAG = nullptr;

ID3D11ShaderResourceView* SRFLAG = nullptr;

ID3D11ShaderResourceView* SJFLAG = nullptr;

ID3D11ShaderResourceView* SEFLAG = nullptr;

ID3D11ShaderResourceView* CHFLAG = nullptr;

ID3D11ShaderResourceView* SYFLAG = nullptr;

ID3D11ShaderResourceView* TWFLAG = nullptr;

ID3D11ShaderResourceView* TJFLAG = nullptr;

ID3D11ShaderResourceView* TZFLAG = nullptr;

ID3D11ShaderResourceView* THFLAG = nullptr;

ID3D11ShaderResourceView* TLFLAG = nullptr;

ID3D11ShaderResourceView* TGFLAG = nullptr;

ID3D11ShaderResourceView* TKFLAG = nullptr;

ID3D11ShaderResourceView* TOFLAG = nullptr;

ID3D11ShaderResourceView* TTFLAG = nullptr;

ID3D11ShaderResourceView* TNFLAG = nullptr;

ID3D11ShaderResourceView* TRFLAG = nullptr;

ID3D11ShaderResourceView* TMFLAG = nullptr;

ID3D11ShaderResourceView* TCFLAG = nullptr;

ID3D11ShaderResourceView* TVFLAG = nullptr;

ID3D11ShaderResourceView* UGFLAG = nullptr;

ID3D11ShaderResourceView* UAFLAG = nullptr;

ID3D11ShaderResourceView* AEFLAG = nullptr;

ID3D11ShaderResourceView* GBFLAG = nullptr;

ID3D11ShaderResourceView* USFLAG = nullptr;

ID3D11ShaderResourceView* UYFLAG = nullptr;

ID3D11ShaderResourceView* UZFLAG = nullptr;

ID3D11ShaderResourceView* VUFLAG = nullptr;

ID3D11ShaderResourceView* VEFLAG = nullptr;

ID3D11ShaderResourceView* VNFLAG = nullptr;

ID3D11ShaderResourceView* VGFLAG = nullptr;

ID3D11ShaderResourceView* VIFLAG = nullptr;

ID3D11ShaderResourceView* WFFLAG = nullptr;

ID3D11ShaderResourceView* EHFLAG = nullptr;

ID3D11ShaderResourceView* YEFLAG = nullptr;

ID3D11ShaderResourceView* ZMFLAG = nullptr;

ID3D11ShaderResourceView* ZWFLAG = nullptr;

ID3D11ShaderResourceView* AXFLAG = nullptr;

ID3D11ShaderResourceView* ISFLAG = nullptr;

ID3D11ShaderResourceView* INFLAG = nullptr;

ID3D11ShaderResourceView* IDFLAG = nullptr;

ID3D11ShaderResourceView* IRFLAG = nullptr;

ID3D11ShaderResourceView* IQFLAG = nullptr;

ID3D11ShaderResourceView* IEFLAG = nullptr;

ID3D11ShaderResourceView* IMFLAG = nullptr;

ID3D11ShaderResourceView* ILFLAG = nullptr;

ID3D11ShaderResourceView* ITFLAG = nullptr;


ID3D11ShaderResourceView* TotalA = nullptr;


#pragma endregion

void ToggleButton(const char* str_id, bool* v)
{
	ImVec2 p = ImGui::GetCursorScreenPos();
	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	float height = ImGui::GetFrameHeight();
	float width = height * 1.55f;
	float radius = height * 0.50f;
	if (ImGui::InvisibleButton(str_id, ImVec2(width, height)))
		*v = !*v;
	ImU32 col_bg;
	if (ImGui::IsItemHovered())
		col_bg = *v ? IM_COL32(145 + 20, 211, 68 + 20, 255) : IM_COL32(218 - 20, 218 - 20, 218 - 20, 255);
	else
		col_bg = *v ? IM_COL32(145, 211, 68, 255) : IM_COL32(218, 218, 218, 255);
	draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.5f);
	draw_list->AddCircleFilled(ImVec2(*v ? (p.x + width - radius) : (p.x + radius), p.y + radius), radius - 1.5f, IM_COL32(255, 255, 255, 255));
}



// int getue4header()
//{
//	int libue4header = 0;
//	BYTE ue4head[] = { 0x7F, 0x45, 0x4C, 0x46, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x28, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x24, 0x26, 0x8A, 0x07, 0x00, 0x02, 0x00, 0x05, 0x34, 0x00, 0x20, 0x00, 0x0A, 0x00, 0x28, 0x00, 0x1A, 0x00, 0x19, 0x00, 0x06, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x40, 0x01, 0x00, 0x00, 0x40, 0x01, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x74, 0x01, 0x00, 0x00, 0x74, 0x01, 0x00, 0x00, 0x74, 0x01, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
//	libue4header = Utility::SINGLEAOBSCAN(ue4head, sizeof(ue4head));
//	return libue4header;
// }


ImVec4 to_vec4(float r, float g, float b, float a)
{
	return ImVec4(r / 255.0, g / 255.0, b / 255.0, a / 255.0);
}

static auto RadarFlags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar;

void DrawRadarHUD(MinimalViewInfo Camera, AActor Player, int Distance, int xAxis, int yAxis, int width, int height, ImVec4 color)
{

	//ImGui::SetNextWindowSize(ImVec2(Setting::RadarLength, Setting::RadarWidth));
	ImGui::SetNextWindowSize(ImVec2(200, 200));
	ImGuiIO& Io = ImGui::GetIO();

	ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 108));
	ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 200));
	ImGui::SetNextWindowPos(ImVec2(50, (Io.DisplaySize.y / 2) + 100), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
	if (ImGui::Begin("     ", 0, RadarFlags))
	{
		{
			ImVec2 wind = ImGui::GetWindowSize();
			ImVec2 wind2 = ImGui::GetWindowPos();

			bool out = false;
			VECTOR3 siz;
			siz.X = wind.x;
			siz.Y = wind.y;
			VECTOR3 pos;
			pos.X = wind2.x;
			pos.Y = wind2.y;
			float RadarCenterX = pos.X + (siz.X / 2);
			float RadarCenterY = pos.Y + (siz.Y / 2);
			//DX11::ImGui_DX11::DrawOutlineBox(pos.X, pos.Y, siz.X, siz.Y, ImVec4(0, 0, 0, 1.f), 1.0f);
			//DX11::ImGui_DX11::DrawBox(pos.X, pos.Y, siz.X, siz.Y, .1, 0, 0, 0, .1, true);

			DX11::IMGUIDRAWLINE(RadarCenterX, RadarCenterY, pos.X, pos.Y, ImVec4(255, 0, 0, 255), 1.0f);
			DX11::IMGUIDRAWLINE(RadarCenterX, RadarCenterY, pos.X + siz.X, pos.Y, ImVec4(255, 0, 0, 255), 1.0f);
			DX11::IMGUIDRAWLINE(pos.X, RadarCenterY, pos.X + siz.X, RadarCenterY, ImVec4(color), 1.0f);
			DX11::IMGUIDRAWLINE(RadarCenterX, RadarCenterY, RadarCenterX, pos.Y + siz.Y, ImVec4(color), 1.0f);
			DX11::IMGUIDRAWCIRCLE(RadarCenterX, RadarCenterY, 2, ImVec4(color), 1.0f);
			VECTOR3 ddddd;
			ddddd.X = siz.X;
			ddddd.Y = siz.Y;
			ddddd.Z = 0;
			VECTOR3 single = Algorithm::WorldToRadar(Camera.Rotation.Yaw, Player.Position, Data::CameraCache.POV.Location, pos.X, pos.Y, ddddd, out);

			if (Distance < Setting::PlayerMaxDistance)
			{
				DX11::IMGUIDRAWCIRCLE(single.X, single.Y, 1.5, ImVec4(color), .1f);
			}
		}
		ImGui::End();
	}
	ImGui::PopStyleColor();
	ImGui::PopStyleColor();
}

void LoadIcons() {
	D3DX11_IMAGE_LOAD_INFO info;
	ID3DX11ThreadPump* pump{ nullptr };



	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CONQ, sizeof(CONQ), &info, pump, &draw.CONQ, 0);

	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AM556, sizeof(AM556), &info, pump, &draw.AM556, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AM762, sizeof(AM762), &info, pump, &draw.AM762, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AKM, sizeof(AKM), &info, pump, &draw.AKM, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, M416, sizeof(M416), &info, pump, &draw.M416, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, M762, sizeof(M762), &info, pump, &draw.M762, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AWM, sizeof(AWM), &info, pump, &draw.AWM, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KAR98K, sizeof(KAR98K), &info, pump, &draw.KAR98K, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, M24, sizeof(M24), &info, pump, &draw.M24, 0);

	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LOGOM, sizeof(LOGOM), &info, pump, &draw.LOGOM, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LOGO, sizeof(LOGO), &info, pump, &draw.Logo, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, RAINBG, sizeof(RAINBG), &info, pump, &draw.RAINBG, 0);


	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, Granade, sizeof(Granade), &info, pump, &draw.Granade_I, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, Smoke, sizeof(Smoke), &info, pump, &draw.Smoke_I, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, Molo, sizeof(Molo), &info, pump, &draw.Molo_I, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, FlareGun, sizeof(FlareGun), &info, pump, &draw.FlareGun_I, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, FlareAmmo, sizeof(FlareAmmo), &info, pump, &draw.FlareAmmo_I, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, Airdrop, sizeof(Airdrop), &info, pump, &draw.Airdrop_I, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GasCan, sizeof(GasCan), &info, pump, &draw.GasCan_I, 0);

	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, Warrior, sizeof(Warrior), &info, pump, &draw.Warrior_I, 0);

#pragma region country Flags
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AF, sizeof(AF), &info, pump, &AFFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AL, sizeof(AL), &info, pump, &ALFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, DZ, sizeof(DZ), &info, pump, &DZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AS, sizeof(AS), &info, pump, &ASFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AD, sizeof(AD), &info, pump, &ADFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AO, sizeof(AO), &info, pump, &AOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AI, sizeof(AI), &info, pump, &AIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AG, sizeof(AG), &info, pump, &AGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AR, sizeof(AR), &info, pump, &ARFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AM, sizeof(AM), &info, pump, &AMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AW, sizeof(AW), &info, pump, &AWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AU, sizeof(AU), &info, pump, &AUFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AT, sizeof(AT), &info, pump, &ATFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AZ, sizeof(AZ), &info, pump, &AZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BS, sizeof(BS), &info, pump, &BSFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BH, sizeof(BH), &info, pump, &BHFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BD, sizeof(BD), &info, pump, &BDFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BB, sizeof(BB), &info, pump, &BBFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BY, sizeof(BY), &info, pump, &BYFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BE, sizeof(BE), &info, pump, &BEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BZ, sizeof(BZ), &info, pump, &BZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BJ, sizeof(BJ), &info, pump, &BJFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BM, sizeof(BM), &info, pump, &BMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BT, sizeof(BT), &info, pump, &BTFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BO, sizeof(BO), &info, pump, &BOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BA, sizeof(BA), &info, pump, &BAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BW, sizeof(BW), &info, pump, &BWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BV, sizeof(BV), &info, pump, &BVFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IO, sizeof(IO), &info, pump, &BRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IO, sizeof(IO), &info, pump, &IOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BN, sizeof(BN), &info, pump, &BNFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BG, sizeof(BG), &info, pump, &BGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BF, sizeof(BF), &info, pump, &BFFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BI, sizeof(BI), &info, pump, &BIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CV, sizeof(CV), &info, pump, &CVFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KH, sizeof(KH), &info, pump, &KHFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CM, sizeof(CM), &info, pump, &CMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CA, sizeof(CA), &info, pump, &CAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KY, sizeof(KY), &info, pump, &KYFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CF, sizeof(CF), &info, pump, &CFFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TD, sizeof(TD), &info, pump, &TDFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CL, sizeof(CL), &info, pump, &CLFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CN, sizeof(CN), &info, pump, &CNFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CX, sizeof(CX), &info, pump, &CXFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CC, sizeof(CC), &info, pump, &CCFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CO, sizeof(CO), &info, pump, &COFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KM, sizeof(KM), &info, pump, &KMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CD, sizeof(CD), &info, pump, &CDFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CG, sizeof(CG), &info, pump, &CGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CK, sizeof(CK), &info, pump, &CKFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CR, sizeof(CR), &info, pump, &CRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, HR, sizeof(HR), &info, pump, &HRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CU, sizeof(CU), &info, pump, &CUFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CW, sizeof(CW), &info, pump, &CWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CZ, sizeof(CZ), &info, pump, &CZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CI, sizeof(CI), &info, pump, &CIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, DK, sizeof(DK), &info, pump, &DKFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, DJ, sizeof(DJ), &info, pump, &DJFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, DM, sizeof(DM), &info, pump, &DMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, DO, sizeof(DO), &info, pump, &DOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, EC, sizeof(EC), &info, pump, &ECFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, EG, sizeof(EG), &info, pump, &EGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SV, sizeof(SV), &info, pump, &SVFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GQ, sizeof(GQ), &info, pump, &GQFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ER, sizeof(ER), &info, pump, &ERFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, EE, sizeof(EE), &info, pump, &EEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SZ, sizeof(SZ), &info, pump, &SZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ET, sizeof(ET), &info, pump, &ETFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, FK, sizeof(FK), &info, pump, &FKFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, FO, sizeof(FO), &info, pump, &FOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, FJ, sizeof(FJ), &info, pump, &FJFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, FI, sizeof(FI), &info, pump, &FIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, FR, sizeof(FR), &info, pump, &FRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GF, sizeof(GF), &info, pump, &GFFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PF, sizeof(PF), &info, pump, &PFFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TF, sizeof(TF), &info, pump, &TFFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GA, sizeof(GA), &info, pump, &GAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GM, sizeof(GM), &info, pump, &GMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GE, sizeof(GE), &info, pump, &GEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, DE, sizeof(DE), &info, pump, &DEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GH, sizeof(GH), &info, pump, &GHFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LY, sizeof(LY), &info, pump, &LYFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LI, sizeof(LI), &info, pump, &LIFLAG, 0);

	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LU, sizeof(LU), &info, pump, &LUFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MO, sizeof(MO), &info, pump, &MOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MG, sizeof(MG), &info, pump, &MGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MW, sizeof(MW), &info, pump, &MWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MY, sizeof(MY), &info, pump, &MYFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MV, sizeof(MV), &info, pump, &MVFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ML, sizeof(ML), &info, pump, &MLFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MT, sizeof(MT), &info, pump, &MTFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MH, sizeof(MH), &info, pump, &MHFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MQ, sizeof(MQ), &info, pump, &MQFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MR, sizeof(MR), &info, pump, &MRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MU, sizeof(MU), &info, pump, &MUFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, YT, sizeof(YT), &info, pump, &YTFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MX, sizeof(MX), &info, pump, &MXFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, FM, sizeof(FM), &info, pump, &FMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MD, sizeof(MD), &info, pump, &MDFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MC, sizeof(MC), &info, pump, &MCFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MN, sizeof(MN), &info, pump, &MNFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ME, sizeof(ME), &info, pump, &MEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MS, sizeof(MS), &info, pump, &MSFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MA, sizeof(MA), &info, pump, &MAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MZ, sizeof(MZ), &info, pump, &MZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MM, sizeof(MM), &info, pump, &MMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NA, sizeof(NA), &info, pump, &NAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NR, sizeof(NR), &info, pump, &NRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GI, sizeof(GI), &info, pump, &GIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GR, sizeof(GR), &info, pump, &GRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GL, sizeof(GL), &info, pump, &GLFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GD, sizeof(GD), &info, pump, &GDFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GP, sizeof(GP), &info, pump, &GPFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GU, sizeof(GU), &info, pump, &GUFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GT, sizeof(GT), &info, pump, &GTFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GG, sizeof(GG), &info, pump, &GGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GN, sizeof(GN), &info, pump, &GNFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GW, sizeof(GW), &info, pump, &GWFLAG, 0);

	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, HT, sizeof(HT), &info, pump, &HTFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, HM, sizeof(HM), &info, pump, &HMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, VA, sizeof(VA), &info, pump, &VAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, HN, sizeof(HN), &info, pump, &HNFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, HK, sizeof(HK), &info, pump, &HKFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, HU, sizeof(HU), &info, pump, &HUFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, JM, sizeof(JM), &info, pump, &JMFLAG, 0);

	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, JP, sizeof(JP), &info, pump, &JPFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, JE, sizeof(JE), &info, pump, &JEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, JO, sizeof(JO), &info, pump, &JOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KZ, sizeof(KZ), &info, pump, &KZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KE, sizeof(KE), &info, pump, &KEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KI, sizeof(KI), &info, pump, &KIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KR, sizeof(KR), &info, pump, &KRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KW, sizeof(KW), &info, pump, &KWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KG, sizeof(KG), &info, pump, &KGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LA, sizeof(LA), &info, pump, &LAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LV, sizeof(LV), &info, pump, &LVFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LB, sizeof(LB), &info, pump, &LBFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LS, sizeof(LS), &info, pump, &LSFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LR, sizeof(LR), &info, pump, &LRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TR, sizeof(TR), &info, pump, &TRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TM, sizeof(TM), &info, pump, &TMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TC, sizeof(TC), &info, pump, &TCFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TV, sizeof(TV), &info, pump, &TVFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, UG, sizeof(UG), &info, pump, &UGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, UA, sizeof(UA), &info, pump, &UAFLAG, 0);

	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, US, sizeof(US), &info, pump, &GBFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, US, sizeof(US), &info, pump, &USFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, UY, sizeof(UY), &info, pump, &UYFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, UZ, sizeof(UZ), &info, pump, &UZFLAG, 0);

	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, VE, sizeof(VE), &info, pump, &VEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, VN, sizeof(VN), &info, pump, &VNFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, VG, sizeof(VG), &info, pump, &VGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, VI, sizeof(VI), &info, pump, &VIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, WF, sizeof(WF), &info, pump, &WFFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, YE, sizeof(YE), &info, pump, &YEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ZM, sizeof(ZM), &info, pump, &ZMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ZW, sizeof(ZW), &info, pump, &ZWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AX, sizeof(AX), &info, pump, &AXFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IS, sizeof(IS), &info, pump, &ISFLAG, 0);

	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ID, sizeof(ID), &info, pump, &IDFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IR, sizeof(IR), &info, pump, &IRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IQ, sizeof(IQ), &info, pump, &IQFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IE, sizeof(IE), &info, pump, &IEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IM, sizeof(IM), &info, pump, &IMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IL, sizeof(IL), &info, pump, &ILFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IT, sizeof(IT), &info, pump, &ITFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NP, sizeof(NP), &info, pump, &NPFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NL, sizeof(NL), &info, pump, &NLFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NC, sizeof(NC), &info, pump, &NCFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NZ, sizeof(NZ), &info, pump, &NZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NI, sizeof(NI), &info, pump, &NIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NE, sizeof(NE), &info, pump, &NEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NG, sizeof(NG), &info, pump, &NGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NU, sizeof(NU), &info, pump, &NUFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NF, sizeof(NF), &info, pump, &NFFLAG, 0);

	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NO, sizeof(NO), &info, pump, &NOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PK, sizeof(PK), &info, pump, &PKFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PW, sizeof(PW), &info, pump, &PWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PS, sizeof(PS), &info, pump, &PSFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PA, sizeof(PA), &info, pump, &PAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PG, sizeof(PG), &info, pump, &PGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PY, sizeof(PY), &info, pump, &PYFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PE, sizeof(PE), &info, pump, &PEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PH, sizeof(PH), &info, pump, &PHFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PN, sizeof(PN), &info, pump, &PNFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PL, sizeof(PL), &info, pump, &PLFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PT, sizeof(PT), &info, pump, &PTFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PR, sizeof(PR), &info, pump, &PRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, QA, sizeof(QA), &info, pump, &QAFLAG, 0);

	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, RO, sizeof(RO), &info, pump, &ROFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, RU, sizeof(RU), &info, pump, &RUFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, RW, sizeof(RW), &info, pump, &RWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, RE, sizeof(RE), &info, pump, &REFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BL, sizeof(BL), &info, pump, &BLFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SH, sizeof(SH), &info, pump, &SHFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KN, sizeof(KN), &info, pump, &KNFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LC, sizeof(LC), &info, pump, &LCFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MF, sizeof(MF), &info, pump, &MFFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PM, sizeof(PM), &info, pump, &PMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, VC, sizeof(VC), &info, pump, &VCFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, WS, sizeof(WS), &info, pump, &WSFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SM, sizeof(SM), &info, pump, &SMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ST, sizeof(ST), &info, pump, &STFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SA, sizeof(SA), &info, pump, &SAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SN, sizeof(SN), &info, pump, &SNFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, RS, sizeof(RS), &info, pump, &RSFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SC, sizeof(SC), &info, pump, &SCFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SL, sizeof(SL), &info, pump, &SLFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SG, sizeof(SG), &info, pump, &SGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SX, sizeof(SX), &info, pump, &SXFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SK, sizeof(SK), &info, pump, &SKFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SI, sizeof(SI), &info, pump, &SIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SB, sizeof(SB), &info, pump, &SBFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SO, sizeof(SO), &info, pump, &SOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ZA, sizeof(ZA), &info, pump, &ZAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GS, sizeof(GS), &info, pump, &GSFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SS, sizeof(SS), &info, pump, &SSFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LK, sizeof(LK), &info, pump, &LKFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SD, sizeof(SD), &info, pump, &SDFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SR, sizeof(SR), &info, pump, &SRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SJ, sizeof(SJ), &info, pump, &SJFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SE, sizeof(SE), &info, pump, &SEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CH, sizeof(CH), &info, pump, &CHFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SY, sizeof(SY), &info, pump, &SYFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TW, sizeof(TW), &info, pump, &TWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TJ, sizeof(TJ), &info, pump, &TJFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TZ, sizeof(TZ), &info, pump, &TZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TH, sizeof(TH), &info, pump, &THFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TL, sizeof(TL), &info, pump, &TLFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TG, sizeof(TG), &info, pump, &TGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TK, sizeof(TK), &info, pump, &TKFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TO, sizeof(TO), &info, pump, &TOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TT, sizeof(TT), &info, pump, &TTFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TN, sizeof(TN), &info, pump, &TNFLAG, 0);
#pragma endregion

}


//#define M_PI 3.14159265358979323846f
//#define RAD2DEG( x )  ( (float)(x) * (float)(180.f / IM_PI) )
//#define DEG2RAD( x ) ( (float)(x) * (float)(IM_PI / 180.f) )
//
//void VectorAnglesRadar(VECTOR3& forward, VECTOR3& angles)
//{
//	if (forward.X == 0.f && forward.Y == 0.f)
//	{
//		angles.X = forward.Z > 0.f ? -90.f : 90.f;
//		angles.Y = 0.f;
//	}
//	else
//	{
//		angles.X = RAD2DEG(atan2(-forward.Z, forward.Size()));
//		angles.Y = RAD2DEG(atan2(forward.Y, forward.X));
//	}
//	angles.Z = 0.f;
//}

inline bool FileExist(const std::string& name) {
	if (FILE* file = fopen(name.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}
void LoadConfig(std::string Path) {
	CSimpleIniA ini;
	ini.SetUnicode();
	SI_Error rc = ini.LoadFile(Path.c_str());
	if (FileExist(Path))
	{
		bool State = ini.GetBoolValue("Key", "UserKeyState");
		if (State == true)
		{
			std::string Key = ini.GetValue("Key", "UserKey");
			if (Key != "")
			{
				strcpy(str1, Key.c_str());
				SaveUsers = true;
			}

		}

	}

}
void WriteConfig(std::string Path, std::string Key, bool State) {
	CSimpleIniA ini;
	ini.SetUnicode();
	SI_Error rc = ini.LoadFile(Path.c_str());
	if (rc < 0) {

	};
	if (State == true)
	{
		ini.SetBoolValue("Key", "UserKeyState", true);
	}
	else
	{
		ini.SetBoolValue("Key", "UserKeyState", false);
	}
	ini.SetValue("Key", "UserKey", Key.c_str());

	ini.SaveFile(Path.c_str());
}


bool ProcessInlineHexColor(const char* start, const char* end, ImVec4& color)
{
	const int hexCount = (int)(end - start);
	if (hexCount == 6 || hexCount == 8)
	{
		char hex[9];
		strncpy(hex, start, hexCount);
		hex[hexCount] = 0;

		unsigned int hexColor = 0;
		if (sscanf(hex, "%x", &hexColor) > 0)
		{
			color.x = static_cast<float>((hexColor & 0x00FF0000) >> 16) / 255.0f;
			color.y = static_cast<float>((hexColor & 0x0000FF00) >> 8) / 255.0f;
			color.z = static_cast<float>((hexColor & 0x000000FF)) / 255.0f;
			color.w = 1.0f;

			if (hexCount == 8)
			{
				color.w = static_cast<float>((hexColor & 0xFF000000) >> 24) / 255.0f;
			}

			return true;
		}
	}

	return false;
}
const char ColorMarkerStart = '{';
const char ColorMarkerEnd = '}';
void TextWithColors(const char* fmt, ...)
{
	char tempStr[4096];

	va_list argPtr;
	va_start(argPtr, fmt);
	_vsnprintf(tempStr, sizeof(tempStr), fmt, argPtr);
	va_end(argPtr);
	tempStr[sizeof(tempStr) - 1] = '\0';

	bool pushedColorStyle = false;
	const char* textStart = tempStr;
	const char* textCur = tempStr;
	while (textCur < (tempStr + sizeof(tempStr)) && *textCur != '\0')
	{
		if (*textCur == ColorMarkerStart)
		{
			// Print accumulated text
			if (textCur != textStart)
			{
				ImGui::TextUnformatted(textStart, textCur);
				ImGui::SameLine(0.0f, 0.0f);
			}

			// Process color code
			const char* colorStart = textCur + 1;
			do
			{
				++textCur;
			} while (*textCur != '\0' && *textCur != ColorMarkerEnd);

			// Change color
			if (pushedColorStyle)
			{
				ImGui::PopStyleColor();
				pushedColorStyle = false;
			}

			ImVec4 textColor;
			if (ProcessInlineHexColor(colorStart, textCur, textColor))
			{
				ImGui::PushStyleColor(ImGuiCol_Text, textColor);
				pushedColorStyle = true;
			}

			textStart = textCur + 1;
		}
		else if (*textCur == '\n')
		{
			// Print accumulated text an go to next line
			ImGui::TextUnformatted(textStart, textCur);
			textStart = textCur + 1;
		}

		++textCur;
	}

	if (textCur != textStart)
	{
		ImGui::TextUnformatted(textStart, textCur);
	}
	else
	{
		ImGui::NewLine();
	}

	if (pushedColorStyle)
	{
		ImGui::PopStyleColor();
	}
}

VOID DrawMenu2()
{
	std::string AimAt[] = { "Head      ", "Body     ", "Pelvis     " };

	ImGui::SetNextWindowPos({ 8, (DX11::Height / 2.0f) - 80 });
	ImGuiIO& Io = ImGui::GetIO();
	ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 255));
	ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 108));

	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);

	ImGui::SetNextWindowSize(ImVec2(138.0f, 290.0f));


	static auto FlagsMenu = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

	ImGui::Begin("LUCIFER VIP", 0, FlagsMenu);
	{
		const float colPos = 220.0f;
		bool P = false;


		//ImGui::TextColored(to_vec4(255, 255, 0, 255), "LUCIFER VIP Hack");

		ImGui::Spacing();
		ImGui::Spacing();
		ImGui::Spacing();
		ImGui::Spacing();
		ImGui::Spacing();
		ImGui::Spacing();
		ImGui::Spacing();
		ImGui::Spacing();
		ImGui::Spacing();
		ImGui::Spacing();
		ImGui::Spacing(); // disable for redMix menu
		ImGui::Spacing(); // disable for redMix menu
		ImGui::Spacing(); // disable for redMix menu

		if (Setting::I_HackInjectType != 2)
		{
			Setting::MagicBullet ? TextWithColors(ICON_FA_MAGIC " F2 : " " {00FF0F}BULLET TRACKING{00FF0F}") : TextWithColors(ICON_FA_MAGIC " F2 : " " {FF1100}BULLET TRACKING{FF1100}");  //FFFFFF
			Setting::Aimbot ? TextWithColors(ICON_FA_CROSSHAIRS " F3 : " " {00FF0F}AIMBOT{00FF0F}") : TextWithColors(ICON_FA_CROSSHAIRS " F3 : " " {FF1100}AIMBOT{FF1100}");
		}
		if (Setting::I_HackInjectType == 1)
		{
			Setting::instanthit ? TextWithColors(ICON_FA_BOLT "  F4 : " " {00FF0F}  INSTANT HIT{00FF0F}") : TextWithColors(ICON_FA_BOLT "  F4 : " " {FF1100}  INSTANT HIT{FF1100}");
		}

		Setting::streamMode ? TextWithColors(ICON_FA_PODCAST " F5 : " " {00FF0F}ANTI STREAM{00FF0F}") : TextWithColors(ICON_FA_PODCAST " F5 : " " {FF1100}ANTI STREAM{FF1100}");
		Setting::FightMode ? TextWithColors(ICON_FA_COG " F6 : " " {00FF0F}FIGHT MODE{00FF0F}") : TextWithColors(ICON_FA_COG " F6 : " " {FF1100}FIGHT MODE{FF1100}");
		Setting::Item ? TextWithColors(ICON_FA_BOOK " F7 : " " {00FF0F}HIDE ITEMS{00FF0F}") : TextWithColors(ICON_FA_BOOK " F7 : " " {FF1100}SHOW ITEMS{FF1100}");
		Setting::Vehicle ? TextWithColors(ICON_FA_CAR " F8 :" " {00FF0F}HIDE VEHICLES{00FF0F}") : TextWithColors(ICON_FA_CAR " F8 :" " {FF1100}SHOW VEHICLES{FF1100}");
		if (Setting::I_HackInjectType != 2)
		{
			Setting::magicAutoLocation ? TextWithColors(ICON_FA_PAPER_PLANE " F9 :" " {00FF0F}MIX TRACKING{00FF0F}") : TextWithColors(ICON_FA_PAPER_PLANE " F9 :" " {FF1100}MIX TRACKING{FF1100}");
		}
		std::string AimDisplay = ICON_FA_SEARCH_PLUS " {FFFFFF}Aim At [T] : {42FF00}";
		AimDisplay.append(AimAt[Setting::curraim]);
		if (Setting::MagicBullet) {
			TextWithColors(AimDisplay.c_str());
		}
		ImGui::Separator();
		TextWithColors(("{D4AF37}       Hide | {D4AF37}  Show"));
		TextWithColors(("{FF0000}       END  | {FF0000}  Exit"));

		char fpsinfo[64];
		sprintf(fpsinfo, ICON_FA_EYE "  [FPS] : %0.f", ImGui::GetIO().Framerate);
		ImGui::TextColored(to_vec4(245, 233, 7, 255), fpsinfo);

		/*Setting::MagicBullet ? TextWithColors("{74ff03}F2   {74ff03}BULLET TRACK{74ff03}") : TextWithColors("{FF0000}F2   {FF0000}BULLET TRACK{FF0000}");
		ImGui::Spacing();
		Setting::Item ? TextWithColors("{74ff03}F6   {74ff03}ITEM ON{74ff03}") : TextWithColors("{FF0000}F6   {FF0000}ITEM OFF{FF0000}");
		ImGui::Spacing();
		Setting::Aimbot ? TextWithColors("{74ff03}F7   {74ff03}AIMBOT ON{74ff03}") : TextWithColors("{FF0000}F7   {FF0000}AIMBOT OFF{FF0000}");

		ImGui::Separator();

		if (Setting::curraim == 0)
		{
			TextWithColors(("{74ff03} Aim : Head "));
		}
		else if (Setting::curraim == 1)
		{
			TextWithColors(("{74ff03} Aim : Body "));
		}
		else if (Setting::curraim == 2)
		{
			TextWithColors(("{74ff03} Aim : Pelvis "));
		}

		ImGui::Separator();
		Setting::streamMode ? TextWithColors("{74ff03}Stream Mode{74ff03}") : TextWithColors("{FF0000}Stream Mode{FF0000}");*/


		ImGui::End();
	}

}


auto name = skCrypt("MARIO HACK 3.3"); // Application Name
auto ownerid = skCrypt("7WvrGuPk3t"); // Owner ID
auto secret = skCrypt("08169fb7846cf462b28c737e0814cd459285409e869f7a8886758480a0ca5685"); // Application Secret
auto version = skCrypt("1.0"); // Application Version
auto url = skCrypt("https://keyauth.win/api/1.2/"); // change if you're self-hosting
api KeyAuthApp(name.decrypt(), ownerid.decrypt(), secret.decrypt(), version.decrypt(), url.decrypt());

//KeyAuth::api KeyAuthApp(name, ownerid, secret, version, url);
std::string key;
std::string Ques = "";
bool hideKey = true;

static auto overlayFlag_1 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar;
D3DMATRIX Esp::ViewMatrix;
VOID Esp::EspThread()
{
	LoadIcons();

	//DWORD ue4Base = getue4header();
	VECTOR3 Screen;
	INT Distance;
	INT EnemyCount;

	VECTOR3 HeadPos;
	VECTOR2 Head;
	VECTOR2 Chest;
	VECTOR2 Pelvis;
	VECTOR2 lSholder;
	VECTOR2 rSholder;
	VECTOR2 lElbow;
	VECTOR2 rElbow;
	VECTOR2 lWrist;
	VECTOR2 rWrist;
	VECTOR2 lThigh;
	VECTOR2 rThigh;
	VECTOR2 lKnee;
	VECTOR2 rKnee;
	VECTOR2 lAnkle;
	VECTOR2 rAnkle;
	string Weapon = "";
	string Text = "";
	string distance = "";
	string distance1 = "";
	string Nation = "";
	int teamids;
	string BotName = "[ AI ]";
	string knockedstr = "[ Knocked ]";
	string TotalPlayerInMatch;

	KeyAuthApp.init();

	//Loading Saved Config While Hack is Loaded
	if (FileExist("C:\\Windows\\LUCIFERConfig.ini"))
	{
		_config.LoadConfiguratiton("C:\\Windows\\LUCIFERConfig.ini");

	}

	while (true)
	{
		DX11::ClearSurface();
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		//g_Discord->Update();

		if (Setting::ShowMenu)
		{
			LoadConfig("C:\\LUCIFER.lic");
			if (!login)
			{
				ImGuiIO& Io = ImGui::GetIO();
				ImGuiStyle& style = ImGui::GetStyle();


				style.WindowRounding = 9.3f;
				style.FrameRounding = 2.3f;
				style.ScrollbarRounding = 0;
				style.Colors[ImGuiCol_Text] = ImVec4(0.90f, 0.90f, 0.90f, 0.90f);
				style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
				style.Colors[ImGuiCol_WindowBg] = ImVec4(0.24f, 0.24f, 0.24f, 1.00f);
				style.Colors[ImGuiCol_PopupBg] = ImVec4(0.05f, 0.05f, 0.10f, 0.85f);
				style.Colors[ImGuiCol_Border] = ImVec4(0.70f, 0.70f, 0.70f, 0.65f);
				style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
				style.Colors[ImGuiCol_FrameBg] = ImVec4(0.24f, 0.24f, 0.24f, 1.00f);
				style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.90f, 0.80f, 0.80f, 0.40f);
				style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.90f, 0.65f, 0.65f, 0.45f);
				style.Colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.83f);
				style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.40f, 0.40f, 0.80f, 0.20f);
				style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 0.00f, 0.00f, 0.87f);
				style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.01f, 0.01f, 0.02f, 0.80f);
				style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.25f, 0.30f, 0.60f);
				style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.55f, 0.53f, 0.55f, 0.51f);
				style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.56f, 1.00f);
				style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.91f);
				style.Colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
				style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.70f, 0.70f, 0.70f, 0.62f);
				style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.30f, 0.30f, 0.30f, 0.84f);
				style.Colors[ImGuiCol_Button] = ImVec4(0.48f, 0.72f, 0.89f, 0.49f);
				style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.50f, 0.69f, 0.99f, 0.68f);
				style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.80f, 0.50f, 0.50f, 1.00f);
				style.Colors[ImGuiCol_Header] = ImVec4(0.30f, 0.69f, 1.00f, 0.53f);
				style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.44f, 0.61f, 0.86f, 1.00f);
				style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.38f, 0.62f, 0.83f, 1.00f);
				style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.85f);
				style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
				style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
				style.Colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
				style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
				style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
				style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
				style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);

				style.FramePadding = ImVec2(6, 6);
				ImGui::SetNextWindowSize(ImVec2(380.0f, 380.0f));

				ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.5f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));

				//ImGui::Image((PVOID)draw.Logo, ImVec2(140, 140));

				if (ImGui::Begin("LUCIFER", 0, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar))
				{

					ImGui::Image((PVOID)draw.RAINBG, ImVec2(380.0f, 270.0f));

					ImGui::SetCursorPos(ImVec2(30.0f, 30.0f));
					ImGui::InputText("###Key", str1, IM_ARRAYSIZE(str1), (hideKey) ? ImGuiInputTextFlags_Password : ImGuiInputTextFlags_None);
					ImGui::SameLine();
					if (ImGui::Button(ICON_FA_LOCK "", { 26.0f,26.0f }))
					{
						KeyAuthApp.license(str1);

						if (KeyAuthApp.data.success) {
							login = true;
							ShowMenu2 = true;
							Setting::fullLogin = true;
						}

						else if (!KeyAuthApp.data.success) {
							login = false;
							exit(0);
						}
						/*login = true;
						ShowMenu2 = true;
						Setting::fullLogin = true;*/
					}
					ImGui::SameLine();
					if (ImGui::Button(ICON_FA_EYE "", { 26.0f,26.0f }))
					{
						hideKey = !hideKey;
					}


					const char* C_label = Setting::HackInjectType[Setting::I_HackInjectType];
					ImGui::SetCursorPos(ImVec2(30.0f, 60.0f));
					if (ImGui::BeginCombo("Inject Type", C_label, ImGuiComboFlags_HeightSmall))
					{
						for (int n = 0; n < IM_ARRAYSIZE(Setting::HackInjectType); n++)
						{
							const bool is_selected = (Setting::I_HackInjectType == n);
							if (ImGui::Selectable(Setting::HackInjectType[n], is_selected))
								Setting::I_HackInjectType = n;
							if (is_selected)
								ImGui::SetItemDefaultFocus();
						}
						ImGui::EndCombo();
					}

					//ImGui::SetCursorPos(ImVec2(14.0f, 150.0f));
					//ImGui::Image((PVOID)draw.Logo, ImVec2(360, 200));

					WriteConfig("C:\\LUCIFER.lic", str1, true);

					ImGui::End();
				}

			}
			if (login)
			{
				menu.DrawMenu();
			}
		}
		if (ShowMenu2) {
			ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(233, 207, 0, 255));
			ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0.000f, 0.000f, 0.000f, 1.000f));
			//ImGui::SetNextWindowPos({ 10, (DX11Window::Height / 2.0f) - 80 });

			ImGui::SetNextWindowSize(ImVec2(150.0f, 245.0f));
			const float colPos = 220.0f;
			bool P = false;
			ImGui::Text;
			ImGuiStyle* style = &ImGui::GetStyle();
			style->Colors[ImGuiCol_TitleBg] = ImColor(18, 18, 23, 255);
			style->Colors[ImGuiCol_TitleBgCollapsed] = ImColor(18, 18, 23, 255);
			style->Colors[ImGuiCol_TitleBgActive] = ImColor(18, 18, 23, 255);
			style->FrameRounding = 0.0f;

			if (Setting::sideMenu) {
				ImGui::Begin("LUCIFER VIP", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar);
				{
					Setting::Item ? TextWithColors(ICON_FA_EYE"{74ff03}F7 : {74ff03}ITEM ESP{74ff03}") : TextWithColors(ICON_FA_COG"{FF0000}F7 : {FF0000}ITEM ESP{FF0000}");  //FFFFFF
					ImGui::Text("------------------------------");
					ImGui::Spacing();
					//Setting::fightmode ? TextWithColors(ICON_FA_COG"{74ff03}F4 : {74ff03}FIGHT MODE{74ff03}") : TextWithColors(ICON_FA_COG"{FF0000}F3 : {FF0000}FIGHT MODE{FF0000}");  //FFFFFF
					ImGui::Spacing();
					/*ImGui::Text("------------------------------");*/
					Setting::MagicBullet ? TextWithColors(ICON_FA_MAGIC"{74ff03}F5 : {74ff03}BULLET TRACK{74ff03}") : TextWithColors(ICON_FA_MAGIC"{FF0000}F5 : {FF0000}BULLET TRACK{FF0000}");  //FFFFFF
					ImGui::Spacing();
					ImGui::Text("------------------------------");
					Setting::magicAutoLocation ? TextWithColors(ICON_FA_SEARCH"{74ff03}F9 : {AB7007}LIGET TRACKING{AB7007}") : TextWithColors(ICON_FA_SEARCH"{FF0000}F9 : {AB7007}LIGET TRACKING{AB7007}");  //FFFFFF
					ImGui::Spacing();
					ImGui::Text("------------------------------");
					Setting::Vehicle ? TextWithColors(ICON_FA_CAR"{74ff03}F8 : {74ff03}VEHICLES ESP{74ff03}") : TextWithColors(ICON_FA_CAR"{FF0000}F8 : {FF0000}VEHICLES ESP{FF0000}");  //FFFFFF
					ImGui::Spacing();
					ImGui::Separator();
					ImGui::Spacing();
					TextWithColors(("{FF0000}Home - Hide           "));
					TextWithColors(("{FF0000}END - EXIT           "));
					ImGui::End();
				}
				ImGui::PopStyleColor();
				ImGui::PopStyleColor();
				if (GetAsyncKeyState(VK_F7) & 1)
				{
					Setting::Item = !Setting::Item;
				}
				if (GetAsyncKeyState(VK_F9) & 1)
				{
					Setting::magicAutoLocation = !Setting::magicAutoLocation;
				}
				if (GetAsyncKeyState(VK_F8) & 1)
				{
					Setting::Vehicle = !Setting::Vehicle;
				}
				/*if (GetAsyncKeyState(VK_F4) & 1)
				{
					Setting::fightmode = !Setting::fightmode;
				}*/
				if (GetAsyncKeyState(VK_F5) & 1)
				{
					Setting::MagicBullet = !Setting::MagicBullet;
					//Setting::fovcircle = !Setting::fovcircle;
				}


			}

		}


		if (Setting::TotalEnemy)
		{
			int botcount;
			int playercount;
			if (Setting::fullLogin)
			{
				botcount = 0;
				playercount = 0;
				for (int i = 0; i < Data::AActorList.size(); i++)
				{
					if (Data::AActorList[i].IsBot)
					{
						botcount = botcount + 1;
					}
					else
					{
						playercount = playercount + 1;
					}
				}

				if (Data::AActorList.size() != 0)
				{
					ImGui::SetNextWindowSize(ImVec2(165.0f, 35.0f));
					ImGuiIO& Io = ImGui::GetIO();
					ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 108));
					ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 255));
					ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
					if (ImGui::Begin("LUCIFER", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar))
					{
						std::string player = ICON_FA_MALE " PLAYER : ";
						player.append(std::to_string(playercount));
						std::string bot = ICON_FA_USER " BOT : ";
						std::string text = "||";
						bot.append(std::to_string(botcount));
						ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
						ImGui::Text(player.c_str());
						ImGui::PopStyleColor();
						ImGui::SameLine();
						ImGui::Text(text.c_str());
						ImGui::SameLine();
						ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 230, 255));
						ImGui::Text(bot.c_str());
						ImGui::PopStyleColor();

					}
					ImGui::End();
				}
				else
				{
					ImGui::SetNextWindowSize(ImVec2(110.0f, 35.0f));
					ImGuiIO& Io = ImGui::GetIO();
					ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 108));
					ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 255));
					ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
					if (ImGui::Begin("LUCIFER", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar))
					{

						std::string text = ICON_FA_HOME " Area Is Clear ";
						ImGui::TextColored(ImVec4(0.01, 0.99, 0.48, 1.00), text.c_str());
						ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 230, 255));
						ImGui::PopStyleColor();

					}
					ImGui::End();
				}

				/*if (Data::AActorList.size() != 0)
				{
					Text = "[ PLAYER :" + to_string(playercount) + " | " + "BOT :" + to_string(botcount) + " ]";
				}
				else {
					Text = ICON_FA_HOME"[ Area Is Clear ]";
				}
				DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::TotalEnemySize, Text, DX11::Width / 2, DX11::Height / 100 * 11.0f, ImColor(Setting::TotalEnemyColor[0], Setting::TotalEnemyColor[1], Setting::TotalEnemyColor[2], Setting::TotalEnemyColor[3]), true);*/
			}
		}

		ViewMatrix = Utility::ReadMemoryEx<D3DMATRIX>(Utility::ReadMemoryEx<DWORD>(Utility::ReadMemoryEx<DWORD>(Data::ViewMatrixBase) + 0x20) + 0x200);
		currIndex = Memory::AimFindBestTarget();
		if (Setting::fullLogin)
		{
			for (AActor& AActor : Data::AActorList)
			{
				if (!Algorithm::WorldToScreenPlayer(AActor.Position, Screen, &Distance, ViewMatrix)) continue;



				if (Distance < 500)
				{
					if (Distance > 500 || Screen.Z < 0.001f || !AActor.IsDead) continue;

					//if (Setting::PlayerWeapon)
					//{
					//	Weapon = AActor.Weapon.c_str();
					//	DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::playernamesize, Weapon, Screen.X, Screen.Y - 46, ImColor(Setting::PlayerNameColor[0], Setting::PlayerNameColor[1], Setting::PlayerNameColor[2], Setting::PlayerNameColor[3]), true);
					//}


					if (Setting::Name)
					{
						// Nation = AActor.Nation;
						Text = "[" + AActor.Name + "]";

						if (Setting::TeamId)
						{
							Text = "[" + to_string(AActor.TeamId) + "]" + " | " + AActor.Name.c_str();
						}

						if (Setting::PlayerWeapon) {
							Weapon = AActor.Weapon.c_str();
							Text = "[" + Weapon + "]" + " | " + AActor.Name.c_str();
						}

						if (Setting::PlayerWeapon && Setting::TeamId) {
							Weapon = AActor.Weapon.c_str();
							Text = "[" + to_string(AActor.TeamId) + "]" + " | " + AActor.Name.c_str() + " | " + "[" + Weapon + "]";
						}

						if (AActor.Health <= 0)
						{
							if (AActor.IsBot)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pNameFont, Setting::playernamesize, knockedstr, Screen.X, Screen.Y - 26, DX11::ImGui_DX11::Color::Red, true);
							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pNameFont, Setting::playernamesize, knockedstr, Screen.X, Screen.Y - 26, DX11::ImGui_DX11::Color::Red, true);
							}
						}
						else
						{
							if (!AActor.IsBot)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pNameFont, Setting::playernamesize, Text, Screen.X, Screen.Y - 26, ImColor(Setting::PlayerNameColor[0], Setting::PlayerNameColor[1], Setting::PlayerNameColor[2], Setting::PlayerNameColor[3]), true);
							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pNameFont, Setting::playernamesize, Text, Screen.X, Screen.Y - 26, DX11::ImGui_DX11::Color::Blue, true);
							}
						}
					}

					if (Setting::enemyIndicator)
					{
						//float S_height = DX11::Height;
						//float S_width = DX11::Width;
						//bool shit = false;
						//VECTOR3 EntityPos = Algorithm::WorldToRadar(Data::CameraCache.POV.Rotation.Yaw, AActor.Position, Data::CameraCache.POV.Location, NULL, NULL, ToVECTOR3(S_width, S_height, 0), shit);

						//int x, y;
						//x = EntityPos.X;
						//y = EntityPos.Y;

						//auto angle = VECTOR3();
						//VECTOR3 temmp = ToVECTOR3((float)(S_width / 2) - x, (float)(S_height / 2) - y, 0.f);

						//VectorAnglesRadar(temmp, angle);

						//const auto angle_yaw_rad = DEG2RAD(angle.Y + 180.f);

						//const auto new_point_x = (S_width / 2) + (Setting::dots_range) / 2 * 8 * cosf(angle_yaw_rad);
						//const auto new_point_y = (S_height / 2) + (Setting::dots_range) / 2 * 8 * sinf(angle_yaw_rad);

						//std::array<VECTOR3, 3> points
						//{
						//	ToVECTOR3(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y - ((Setting::dots_range) / 4 + 3.5f) / 2, 0.f),
						//	ToVECTOR3(new_point_x + ((90) / 4 + 3.5f) / 4, new_point_y, 0.f),
						//	ToVECTOR3(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y + ((Setting::dots_range) / 4 + 3.5f) / 2, 0.f)
						//};
						//if (AActor.IsBot) {
						//	DX11::ImGui_DX11::DrawCircle(points.at(1).X, points.at(1).Y, 5, DX11::ImGui_DX11::Color::White, 2.3f);
						//}
						//else {
						//	DX11::ImGui_DX11::DrawCircle(points.at(1).X, points.at(1).Y, 6, Setting::BoneColorSameAsLine, 3.3f);
						//}

						if (AActor.Name == " BOT ")
						{
							if (Screen.X > DX11::Width && Screen.Y > 0 && Screen.Y < DX11::Height)//Right
							{
								DX11::ImGui_DX11::DrawCircle(DX11::Width - 20, Screen.Y + Screen.Z, 7, DX11::ImGui_DX11::Color::White, 4.0f);
							}
							if (Screen.X < 0 && Screen.Y  >0 && Screen.Y < DX11::Height)//Left
							{
								DX11::ImGui_DX11::DrawCircle(20, Screen.Y + Screen.Z, 7, DX11::ImGui_DX11::Color::White, 4.0f);
							}
							if (Screen.Y < 0 && Screen.X>0 && Screen.X < DX11::Width)//Top
							{
								DX11::ImGui_DX11::DrawCircle(Screen.X, 20, 7, DX11::ImGui_DX11::Color::White, 4.0f);

							}
							if (Screen.Y > DX11::Height && Screen.X > 0 && Screen.X < DX11::Width)//Bottom
							{
								DX11::ImGui_DX11::DrawCircle(Screen.X, DX11::Height - 20, 7, DX11::ImGui_DX11::Color::White, 4.0f);

							}
							if (Screen.X < 0 && Screen.Y < 0)//top left
							{
								DX11::ImGui_DX11::DrawCircle(20, 20, 7, DX11::ImGui_DX11::Color::White, 4.0f);

							}
							if (Screen.X > DX11::Width && Screen.Y > DX11::Height)//bottom right
							{
								DX11::ImGui_DX11::DrawCircle(DX11::Width - 20, DX11::Height - 20, 7, DX11::ImGui_DX11::Color::White, 4.0f);

							}
							if (Screen.X > DX11::Width && Screen.Y < 0)//top right
							{
								DX11::ImGui_DX11::DrawCircle(DX11::Width - 20, 20, 7, DX11::ImGui_DX11::Color::White, 4.0f);

							}
							if (Screen.X<0 && Screen.Y >DX11::Width)//bottom left
							{
								DX11::ImGui_DX11::DrawCircle(20, DX11::Height - 20, 7, DX11::ImGui_DX11::Color::White, 4.0f);

							}
						}
						else
						{
							if (Screen.X > DX11::Width && Screen.Y > 0 && Screen.Y < DX11::Height)//Right
							{
								DX11::ImGui_DX11::DrawCircle(DX11::Width - 20, Screen.Y + Screen.Z, 7, Setting::BoneColorSameAsLine, 4.0f);

							}
							if (Screen.X < 0 && Screen.Y  >0 && Screen.Y < DX11::Height)//Left
							{

								DX11::ImGui_DX11::DrawCircle(20, Screen.Y + Screen.Z, 7, Setting::BoneColorSameAsLine, 4.0f);

							}
							if (Screen.Y < 0 && Screen.X>0 && Screen.X < DX11::Width)//Top
							{
								DX11::ImGui_DX11::DrawCircle(Screen.X, 20, 7, Setting::BoneColorSameAsLine, 4.0f);

							}
							if (Screen.Y > DX11::Height && Screen.X > 0 && Screen.X < DX11::Width)//Bottom
							{
								DX11::ImGui_DX11::DrawCircle(Screen.X, DX11::Height - 20, 7, Setting::BoneColorSameAsLine, 4.0f);

							}
							if (Screen.X < 0 && Screen.Y < 0)//top left
							{
								DX11::ImGui_DX11::DrawCircle(20, 20, 7, Setting::BoneColorSameAsLine, 4.0f);

							}
							if (Screen.X > DX11::Width && Screen.Y > DX11::Height)//bottom right
							{
								DX11::ImGui_DX11::DrawCircle(DX11::Width - 20, DX11::Height - 20, 7, Setting::BoneColorSameAsLine, 4.0f);

							}
							if (Screen.X > DX11::Width && Screen.Y < 0)//top right
							{
								DX11::ImGui_DX11::DrawCircle(DX11::Width - 20, 20, 7, Setting::BoneColorSameAsLine, 4.0f);

							}
							if (Screen.X<0 && Screen.Y >DX11::Width)//bottom left
							{
								DX11::ImGui_DX11::DrawCircle(20, DX11::Height - 20, 7, Setting::BoneColorSameAsLine, 4.0f);

							}
						}
					}

					if (Setting::EnemyStatus) {

						if (!Setting::FightMode)
						{

							int enemystate = AActor.status;
							std::string stateB = "";
							stateB = std::to_string(enemystate);
							if (stateB == "0") { stateB == "AFK"; }
							else if (stateB == "1") { stateB = "InWater"; }
							else if (stateB == "262144") { stateB = "Killed Now"; }
							else if (stateB == "262152") { stateB = "Killed Now"; }
							else if (stateB == "268435464") { stateB = "Emote"; }
							else if (stateB == "8") { stateB = "Stand"; }
							else if (stateB == "520" || stateB == "544" || stateB == "656" || stateB == "521" || stateB == "528") { stateB = "Aiming"; }
							else if (stateB == "1680" || stateB == "1672" || stateB == "1673" || stateB == "1032" || stateB == "1544" || stateB == "1545" || stateB == "1033") { stateB = "Peek"; }
							else if (stateB == "9") { stateB = "Walking"; }
							else if (stateB == "11") { stateB = "Running"; }
							else if (stateB == "4194304") { stateB = "Swimming"; }
							else if (stateB == "32784") { stateB = "Reviving"; }
							else if (stateB == "16777224") { stateB = "Climbing"; }
							else if (stateB == "8200" || stateB == "8208") { stateB = "Punching"; }
							else if (stateB == "16" || stateB == "17" || stateB == "19") { stateB = "Crouch"; }
							else if (stateB == "32" || stateB == "33" || stateB == "35") { stateB = "Snake"; }
							else if (stateB == "5445" || stateB == "762" || stateB == "35") { stateB = "Snake"; }
							else if (stateB == "72" || stateB == "73" || stateB == "75") { stateB = "Jumping"; }
							else if (stateB == "264" || stateB == "272" || stateB == "273" || stateB == "288" || stateB == "265" || stateB == "329") { stateB = "Reloading"; }
							else if (stateB == "137" || stateB == "144" || stateB == "201" || stateB == "145" || stateB == "160" || stateB == "649" || stateB == "648" || stateB == "1160" || stateB == "1161" || stateB == "1169") { stateB = "Firing"; }
							else if (stateB == "131070" || stateB == "131071" || stateB == "131072" || stateB == "131073" || stateB == "131074" || stateB == "131075") { stateB = "Got Knocked Now"; }
							else if (stateB == "33554440" || stateB == "524296" || stateB == "1048584" || stateB == "524288") { stateB = "Driving"; }
							else if (stateB == "16392" || stateB == "16393" || stateB == "16401" || stateB == "16416" || stateB == "16417" || stateB == "16457") { stateB = "Throwing Bomb"; }
							else if (stateB == "16400" || stateB == "17401" || stateB == "17417" || stateB == "17424" || stateB == "17425") { stateB = "Throwing Bomb"; }
							else
							{
								stateB = std::to_string(enemystate);
							}
							if (Setting::EnemyStatus)
							{
								//TotalPlayerInMatch = "Total Player : " + AActor.TotalPlayer;
								//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 16, TotalPlayerInMatch, DX11::Width / 2, DX11::Height / 2 + 385, DX11::ImGui_DX11::Color::Green, true);

								//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::playernamesize, stateB, Screen.X - 5 , Screen.Y - 45, DX11::ImGui_DX11::Color::Yellow, true);
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::playernamesize, stateB, Screen.X, (Screen.Y + Screen.Z + 15), DX11::ImGui_DX11::Color::Yellow, true);
							}
						}

					}

					DWORD SkeletalMeshComponent = Utility::ReadMemoryEx<DWORD>(Data::EntityAddress + Offset::Mesh);
					DWORD localSkeletalMeshComponent = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::Mesh);
					float LocalRenderTime = Utility::ReadMemoryEx<float>(localSkeletalMeshComponent + 0x304);
					float ActorRenderTime = Utility::ReadMemoryEx<float>(SkeletalMeshComponent + 0x308);

					if (Setting::PlayerAiming)
					{
						if (!Setting::FightMode)
						{
							if (ActorRenderTime == LocalRenderTime)
							{
								ImColor warncolor;
								int randomNum = (rand() % 2) + 1;

								if (Data::playerstatus(AActor.status) == "Aiming")
								{

									if (randomNum == 1)
									{
										warncolor = DX11::ImGui_DX11::Color::Red;
									}
									if (randomNum == 2)
									{
										warncolor = DX11::ImGui_DX11::Color::Yellow;
									}

									string bombnot = "! Enemy Aiming at you !";
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 35, bombnot, DX11::Width / 2 - 10, DX11::Height / 100 * 22.5f, warncolor, true);
								}

							}
						}
					}


					if (Setting::Distance)
					{
						if (!Setting::FightMode)
						{
							distance = to_string(Distance) + "[M]";
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::DistanceSize, distance, Screen.X, (Screen.Y + Screen.Z) + 1, DX11::ImGui_DX11::Color::PdisColor, true);
						}
					}



					if (Setting::country)
					{
						if (!Setting::FightMode)
						{

							if (AActor.Nation == "JM")
							{
								//DX11::ImGui_DX11::DrawImage(JMFLAG, Screen.X - 5 , Screen.Y - 45, 20, 14);
								DX11::ImGui_DX11::DrawImage(JMFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "G1")
							{
								DX11::ImGui_DX11::DrawImage(G1FLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}

							if (AActor.Nation == "AF")
							{
								DX11::ImGui_DX11::DrawImage(AFFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "AL")
							{
								DX11::ImGui_DX11::DrawImage(ALFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "DZ")
							{
								DX11::ImGui_DX11::DrawImage(DZFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "AS")
							{
								DX11::ImGui_DX11::DrawImage(ASFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "AD")
							{
								DX11::ImGui_DX11::DrawImage(ADFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "AO")
							{
								DX11::ImGui_DX11::DrawImage(AOFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "AI")
							{
								DX11::ImGui_DX11::DrawImage(AIFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "AQ")
							{
								DX11::ImGui_DX11::DrawImage(AQFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "AG")
							{
								DX11::ImGui_DX11::DrawImage(AGFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "AR")
							{
								DX11::ImGui_DX11::DrawImage(ARFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "AM")
							{
								DX11::ImGui_DX11::DrawImage(AMFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "AW")
							{
								DX11::ImGui_DX11::DrawImage(AWFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "AU")
							{
								DX11::ImGui_DX11::DrawImage(AUFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "AT")
							{
								DX11::ImGui_DX11::DrawImage(ATFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "AZ")
							{
								DX11::ImGui_DX11::DrawImage(AZFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BS")
							{
								DX11::ImGui_DX11::DrawImage(BSFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BH")
							{
								DX11::ImGui_DX11::DrawImage(BHFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BD")
							{
								DX11::ImGui_DX11::DrawImage(BDFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BB")
							{
								DX11::ImGui_DX11::DrawImage(BBFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BY")
							{
								DX11::ImGui_DX11::DrawImage(BYFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BE")
							{
								DX11::ImGui_DX11::DrawImage(BEFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BZ")
							{
								DX11::ImGui_DX11::DrawImage(BZFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BJ")
							{
								DX11::ImGui_DX11::DrawImage(BJFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BM")
							{
								DX11::ImGui_DX11::DrawImage(BMFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BT")
							{
								DX11::ImGui_DX11::DrawImage(BTFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BO")
							{
								DX11::ImGui_DX11::DrawImage(BOFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BQ")
							{
								DX11::ImGui_DX11::DrawImage(BQFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BA")
							{
								DX11::ImGui_DX11::DrawImage(BAFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BW")
							{
								DX11::ImGui_DX11::DrawImage(BWFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BV")
							{
								DX11::ImGui_DX11::DrawImage(BVFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BR")
							{
								DX11::ImGui_DX11::DrawImage(BRFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "IO")
							{
								DX11::ImGui_DX11::DrawImage(IOFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BN")
							{
								DX11::ImGui_DX11::DrawImage(BNFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BG")
							{
								DX11::ImGui_DX11::DrawImage(BGFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BF")
							{
								DX11::ImGui_DX11::DrawImage(BFFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BI")
							{
								DX11::ImGui_DX11::DrawImage(BIFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CV")
							{
								DX11::ImGui_DX11::DrawImage(CVFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "KH")
							{
								DX11::ImGui_DX11::DrawImage(KHFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CM")
							{
								DX11::ImGui_DX11::DrawImage(CMFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CA")
							{
								DX11::ImGui_DX11::DrawImage(CAFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "KY")
							{
								DX11::ImGui_DX11::DrawImage(KYFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CF")
							{
								DX11::ImGui_DX11::DrawImage(CFFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "TD")
							{
								DX11::ImGui_DX11::DrawImage(TDFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CL")
							{
								DX11::ImGui_DX11::DrawImage(CLFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CN")
							{
								DX11::ImGui_DX11::DrawImage(CNFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CX")
							{
								DX11::ImGui_DX11::DrawImage(CXFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CC")
							{
								DX11::ImGui_DX11::DrawImage(CCFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CO")
							{
								DX11::ImGui_DX11::DrawImage(COFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "KM")
							{
								DX11::ImGui_DX11::DrawImage(KMFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CD")
							{
								DX11::ImGui_DX11::DrawImage(CDFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CG")
							{
								DX11::ImGui_DX11::DrawImage(CGFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CK")
							{
								DX11::ImGui_DX11::DrawImage(CKFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CR")
							{
								DX11::ImGui_DX11::DrawImage(CRFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "HR")
							{
								DX11::ImGui_DX11::DrawImage(HRFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CU")
							{
								DX11::ImGui_DX11::DrawImage(CUFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CW")
							{
								DX11::ImGui_DX11::DrawImage(CWFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CY")
							{
								DX11::ImGui_DX11::DrawImage(CYFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CZ")
							{
								DX11::ImGui_DX11::DrawImage(CZFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CI")
							{
								DX11::ImGui_DX11::DrawImage(CIFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "DK")
							{
								DX11::ImGui_DX11::DrawImage(DKFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "DJ")
							{
								DX11::ImGui_DX11::DrawImage(DJFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "DM")
							{
								DX11::ImGui_DX11::DrawImage(DMFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "DO")
							{
								DX11::ImGui_DX11::DrawImage(DOFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "EC")
							{
								DX11::ImGui_DX11::DrawImage(ECFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "EG")
							{
								DX11::ImGui_DX11::DrawImage(EGFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SV")
							{
								DX11::ImGui_DX11::DrawImage(SVFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GQ")
							{
								DX11::ImGui_DX11::DrawImage(GQFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "ER")
							{
								DX11::ImGui_DX11::DrawImage(ERFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "EE")
							{
								DX11::ImGui_DX11::DrawImage(EEFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SZ")
							{
								DX11::ImGui_DX11::DrawImage(SZFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "ET")
							{
								DX11::ImGui_DX11::DrawImage(ETFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "FK")
							{
								DX11::ImGui_DX11::DrawImage(FKFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "FO")
							{
								DX11::ImGui_DX11::DrawImage(FOFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "FJ")
							{
								DX11::ImGui_DX11::DrawImage(FJFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "FI")
							{
								DX11::ImGui_DX11::DrawImage(FIFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "FR")
							{
								DX11::ImGui_DX11::DrawImage(FRFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GF")
							{
								DX11::ImGui_DX11::DrawImage(GFFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "PF")
							{
								DX11::ImGui_DX11::DrawImage(PFFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "TF")
							{
								DX11::ImGui_DX11::DrawImage(TFFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GA")
							{
								DX11::ImGui_DX11::DrawImage(GAFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GM")
							{
								DX11::ImGui_DX11::DrawImage(GMFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GE")
							{
								DX11::ImGui_DX11::DrawImage(GEFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "DE")
							{
								DX11::ImGui_DX11::DrawImage(DEFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GH")
							{
								DX11::ImGui_DX11::DrawImage(GHFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GI")
							{
								DX11::ImGui_DX11::DrawImage(GIFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GR")
							{
								DX11::ImGui_DX11::DrawImage(GRFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GL")
							{
								DX11::ImGui_DX11::DrawImage(GLFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GD")
							{
								DX11::ImGui_DX11::DrawImage(GDFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GP")
							{
								DX11::ImGui_DX11::DrawImage(GPFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GU")
							{
								DX11::ImGui_DX11::DrawImage(GUFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GT")
							{
								DX11::ImGui_DX11::DrawImage(GTFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GG")
							{
								DX11::ImGui_DX11::DrawImage(GGFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GN")
							{
								DX11::ImGui_DX11::DrawImage(GNFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GW")
							{
								DX11::ImGui_DX11::DrawImage(GWFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GY")
							{
								DX11::ImGui_DX11::DrawImage(GYFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "HT")
							{
								DX11::ImGui_DX11::DrawImage(HTFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "HM")
							{
								DX11::ImGui_DX11::DrawImage(HMFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "VA")
							{
								DX11::ImGui_DX11::DrawImage(VAFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "HN")
							{
								DX11::ImGui_DX11::DrawImage(HNFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "HK")
							{
								DX11::ImGui_DX11::DrawImage(HKFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "HU")
							{
								DX11::ImGui_DX11::DrawImage(HUFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "JP")
							{
								DX11::ImGui_DX11::DrawImage(JPFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "JE")
							{
								DX11::ImGui_DX11::DrawImage(JEFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "JO")
							{
								DX11::ImGui_DX11::DrawImage(JOFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "KZ")
							{
								DX11::ImGui_DX11::DrawImage(KZFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "KE")
							{
								DX11::ImGui_DX11::DrawImage(KEFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "KI")
							{
								DX11::ImGui_DX11::DrawImage(KIFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "KP")
							{
								DX11::ImGui_DX11::DrawImage(KPFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "KR")
							{
								DX11::ImGui_DX11::DrawImage(KRFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "KW")
							{
								DX11::ImGui_DX11::DrawImage(KWFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "KG")
							{
								DX11::ImGui_DX11::DrawImage(KGFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "LA")
							{
								DX11::ImGui_DX11::DrawImage(LAFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "LV")
							{
								DX11::ImGui_DX11::DrawImage(LVFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "LB")
							{
								DX11::ImGui_DX11::DrawImage(LBFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "LS")
							{
								DX11::ImGui_DX11::DrawImage(LSFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "LR")
							{
								DX11::ImGui_DX11::DrawImage(LRFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "LY")
							{
								DX11::ImGui_DX11::DrawImage(LYFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "LI")
							{
								DX11::ImGui_DX11::DrawImage(LIFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "LT")
							{
								DX11::ImGui_DX11::DrawImage(LTFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "LU")
							{
								DX11::ImGui_DX11::DrawImage(LUFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MO")
							{
								DX11::ImGui_DX11::DrawImage(MOFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MG")
							{
								DX11::ImGui_DX11::DrawImage(MGFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MW")
							{
								DX11::ImGui_DX11::DrawImage(MWFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MY")
							{
								DX11::ImGui_DX11::DrawImage(MYFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MV")
							{
								DX11::ImGui_DX11::DrawImage(MVFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "ML")
							{
								DX11::ImGui_DX11::DrawImage(MLFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MT")
							{
								DX11::ImGui_DX11::DrawImage(MTFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MH")
							{
								DX11::ImGui_DX11::DrawImage(MHFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MQ")
							{
								DX11::ImGui_DX11::DrawImage(MQFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MR")
							{
								DX11::ImGui_DX11::DrawImage(MRFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MU")
							{
								DX11::ImGui_DX11::DrawImage(MUFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "YT")
							{
								DX11::ImGui_DX11::DrawImage(YTFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MX")
							{
								DX11::ImGui_DX11::DrawImage(MXFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "FM")
							{
								DX11::ImGui_DX11::DrawImage(FMFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MD")
							{
								DX11::ImGui_DX11::DrawImage(MDFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MC")
							{
								DX11::ImGui_DX11::DrawImage(MCFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MN")
							{
								DX11::ImGui_DX11::DrawImage(MNFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "ME")
							{
								DX11::ImGui_DX11::DrawImage(MEFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MS")
							{
								DX11::ImGui_DX11::DrawImage(MSFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MA")
							{
								DX11::ImGui_DX11::DrawImage(MAFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MZ")
							{
								DX11::ImGui_DX11::DrawImage(MZFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MM")
							{
								DX11::ImGui_DX11::DrawImage(MMFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "NA")
							{
								DX11::ImGui_DX11::DrawImage(NAFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "NR")
							{
								DX11::ImGui_DX11::DrawImage(NRFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "NP")
							{
								DX11::ImGui_DX11::DrawImage(NPFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "NL")
							{
								DX11::ImGui_DX11::DrawImage(NLFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "NC")
							{
								DX11::ImGui_DX11::DrawImage(NCFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "NZ")
							{
								DX11::ImGui_DX11::DrawImage(NZFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "NI")
							{
								DX11::ImGui_DX11::DrawImage(NIFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "NE")
							{
								DX11::ImGui_DX11::DrawImage(NEFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "NG")
							{
								DX11::ImGui_DX11::DrawImage(NGFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "NU")
							{
								DX11::ImGui_DX11::DrawImage(MUFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "NF")
							{
								DX11::ImGui_DX11::DrawImage(NFFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MP")
							{
								DX11::ImGui_DX11::DrawImage(NPFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "NO")
							{
								DX11::ImGui_DX11::DrawImage(NOFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "OM")
							{
								DX11::ImGui_DX11::DrawImage(OMFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "PK")
							{
								DX11::ImGui_DX11::DrawImage(PKFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "PW")
							{
								DX11::ImGui_DX11::DrawImage(PWFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "PS")
							{
								DX11::ImGui_DX11::DrawImage(PSFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "PA")
							{
								DX11::ImGui_DX11::DrawImage(PAFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "PG")
							{
								DX11::ImGui_DX11::DrawImage(PGFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "PY")
							{
								DX11::ImGui_DX11::DrawImage(PYFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "PE")
							{
								DX11::ImGui_DX11::DrawImage(PEFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "PH")
							{
								DX11::ImGui_DX11::DrawImage(PHFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "PN")
							{
								DX11::ImGui_DX11::DrawImage(PNFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "PL")
							{
								DX11::ImGui_DX11::DrawImage(PLFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "PT")
							{
								DX11::ImGui_DX11::DrawImage(PTFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "PR")
							{
								DX11::ImGui_DX11::DrawImage(PRFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "QA")
							{
								DX11::ImGui_DX11::DrawImage(QAFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MK")
							{
								DX11::ImGui_DX11::DrawImage(MKFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "RO")
							{
								DX11::ImGui_DX11::DrawImage(ROFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "RU")
							{
								DX11::ImGui_DX11::DrawImage(RUFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "RW")
							{
								DX11::ImGui_DX11::DrawImage(RWFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "RE")
							{
								DX11::ImGui_DX11::DrawImage(REFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "BL")
							{
								DX11::ImGui_DX11::DrawImage(BLFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SH")
							{
								DX11::ImGui_DX11::DrawImage(SHFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "KN")
							{
								DX11::ImGui_DX11::DrawImage(KNFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "LC")
							{
								DX11::ImGui_DX11::DrawImage(LCFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "MF")
							{
								DX11::ImGui_DX11::DrawImage(MFFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "PM")
							{
								DX11::ImGui_DX11::DrawImage(PMFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "VC")
							{
								DX11::ImGui_DX11::DrawImage(VCFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "WS")
							{
								DX11::ImGui_DX11::DrawImage(WSFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SM")
							{
								DX11::ImGui_DX11::DrawImage(SMFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "ST")
							{
								DX11::ImGui_DX11::DrawImage(STFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SA")
							{
								DX11::ImGui_DX11::DrawImage(SAFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SN")
							{
								DX11::ImGui_DX11::DrawImage(SNFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "RS")
							{
								DX11::ImGui_DX11::DrawImage(RSFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SC")
							{
								DX11::ImGui_DX11::DrawImage(SCFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SL")
							{
								DX11::ImGui_DX11::DrawImage(SLFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SG")
							{
								DX11::ImGui_DX11::DrawImage(SGFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SX")
							{
								DX11::ImGui_DX11::DrawImage(SXFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SK")
							{
								DX11::ImGui_DX11::DrawImage(SKFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SI")
							{
								DX11::ImGui_DX11::DrawImage(SIFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SB")
							{
								DX11::ImGui_DX11::DrawImage(SBFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SO")
							{
								DX11::ImGui_DX11::DrawImage(SOFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "ZA")
							{
								DX11::ImGui_DX11::DrawImage(ZAFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GS")
							{
								DX11::ImGui_DX11::DrawImage(GSFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SS")
							{
								DX11::ImGui_DX11::DrawImage(SSFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "ES")
							{
								DX11::ImGui_DX11::DrawImage(ESFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "LK")
							{
								DX11::ImGui_DX11::DrawImage(LKFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SD")
							{
								DX11::ImGui_DX11::DrawImage(SDFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SR")
							{
								DX11::ImGui_DX11::DrawImage(SRFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SJ")
							{
								DX11::ImGui_DX11::DrawImage(SJFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SE")
							{
								DX11::ImGui_DX11::DrawImage(SEFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "CH")
							{
								DX11::ImGui_DX11::DrawImage(CHFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "SY")
							{
								DX11::ImGui_DX11::DrawImage(SYFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "TW")
							{
								DX11::ImGui_DX11::DrawImage(TWFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "TJ")
							{
								DX11::ImGui_DX11::DrawImage(TJFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "TZ")
							{
								DX11::ImGui_DX11::DrawImage(TZFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "TH")
							{
								DX11::ImGui_DX11::DrawImage(THFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "TL")
							{
								DX11::ImGui_DX11::DrawImage(TLFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "TG")
							{
								DX11::ImGui_DX11::DrawImage(TGFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "TK")
							{
								DX11::ImGui_DX11::DrawImage(TKFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "TO")
							{
								DX11::ImGui_DX11::DrawImage(TOFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "TT")
							{
								DX11::ImGui_DX11::DrawImage(TTFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "TN")
							{
								DX11::ImGui_DX11::DrawImage(TNFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "TR")
							{
								DX11::ImGui_DX11::DrawImage(TRFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "TM")
							{
								DX11::ImGui_DX11::DrawImage(TMFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "TC")
							{
								DX11::ImGui_DX11::DrawImage(TCFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "TV")
							{
								DX11::ImGui_DX11::DrawImage(TVFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "UG")
							{
								DX11::ImGui_DX11::DrawImage(UGFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "UA")
							{
								DX11::ImGui_DX11::DrawImage(UAFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "AE")
							{
								DX11::ImGui_DX11::DrawImage(AEFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "GB")
							{
								DX11::ImGui_DX11::DrawImage(GBFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "US")
							{
								DX11::ImGui_DX11::DrawImage(USFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "UY")
							{
								DX11::ImGui_DX11::DrawImage(UYFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "UZ")
							{
								DX11::ImGui_DX11::DrawImage(UZFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "VU")
							{
								DX11::ImGui_DX11::DrawImage(VUFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "VE")
							{
								DX11::ImGui_DX11::DrawImage(VEFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "VN")
							{
								DX11::ImGui_DX11::DrawImage(VNFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "VG")
							{
								DX11::ImGui_DX11::DrawImage(VGFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "VI")
							{
								DX11::ImGui_DX11::DrawImage(VIFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "WF")
							{
								DX11::ImGui_DX11::DrawImage(WFFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "EH")
							{
								DX11::ImGui_DX11::DrawImage(EHFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "YE")
							{
								DX11::ImGui_DX11::DrawImage(YEFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "ZM")
							{
								DX11::ImGui_DX11::DrawImage(ZMFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "ZW")
							{
								DX11::ImGui_DX11::DrawImage(ZWFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "AX")
							{
								DX11::ImGui_DX11::DrawImage(AXFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "IS")
							{
								DX11::ImGui_DX11::DrawImage(ISFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "IN")
							{
								DX11::ImGui_DX11::DrawImage(INFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "ID")
							{
								DX11::ImGui_DX11::DrawImage(IDFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "IR")
							{
								DX11::ImGui_DX11::DrawImage(IRFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "IQ")
							{
								DX11::ImGui_DX11::DrawImage(IQFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "IE")
							{
								DX11::ImGui_DX11::DrawImage(IEFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "IM")
							{
								DX11::ImGui_DX11::DrawImage(IMFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "IL")
							{
								DX11::ImGui_DX11::DrawImage(ILFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
							if (AActor.Nation == "IT")
							{
								DX11::ImGui_DX11::DrawImage(ITFLAG, Screen.X - 5, Screen.Y - 45, 20, 14);
							}
						}

					}




					if (Setting::Line)
					{
						teamids = AActor.TeamId;

						switch (teamids)
						{

						case 1:
							Setting::linescolors = { 1.000f, 0.033f, 0.129f, 1.000f };
							break;
						case 2:
							Setting::linescolors = { 1.000f, 1.000f, 0.000f, 1.000f };
							break;
						case 3:
							Setting::linescolors = { 0.866f, 0.128f, 0.081f, 1.000f };
							break;
						case 4:
							Setting::linescolors = { 0.844f, 0.066f, 1.000f, 1.000f };
							break;
						case 5:
							Setting::linescolors = { 0.737f, 1.000f, 0.000f, 1.000f };
							break;
						case 6:
							Setting::linescolors = { 0.000f, 1.000f, 0.964f, 1.000f };
							break;
						case 7:
							Setting::linescolors = { 0.610f, 0.190f, 1.000f, 1.000f };
							break;
						case 8:
							Setting::linescolors = { 1.000f, 0.100f, 0.401f, 1.000f };
							break;
						case 9:
							Setting::linescolors = { 0.610f, 0.190f, 1.000f, 1.000f };
							break;
						case  10:
							Setting::linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };
							break;
						case 11:
							Setting::linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };
							break;
						case 12:
							Setting::linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };
							break;
						case 13:
							Setting::linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };
							break;
						case 14:
							Setting::linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };
							break;
						case 15:
							Setting::linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };
							break;
						case 16:
							Setting::linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };
							break;
						case 17:
							Setting::linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };
							break;
						case 18:
							Setting::linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };
							break;
						case 19:
							Setting::linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };
							break;
						case  20:
							Setting::linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };
							break;
						case 21:
							Setting::linescolors = { 0.126f, 0.430f, 1.000f, 1.000f };
							break;
						case 22:
							Setting::linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
							break;
						case 23:
							Setting::linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
							break;
						case 24:
							Setting::linescolors = { 1.000f, 0.859f, 0.251f, 1.000f };
							break;
						case 25:
							Setting::linescolors = { 0.053f, 0.355f, 1.000f, 1.000f };
							break;
						case 26:
							Setting::linescolors = { 1.000f, 0.70f, 0.000f, 1.000f };
							break;
						case 27:
							Setting::linescolors = { 1.000f, 1.000f, 0.000f, 1.000f };
							break;
						case 28:
							Setting::linescolors = { 0.866f, 0.128f, 0.081f, 1.000f };
							break;
						case 29:
							Setting::linescolors = { 0.844f, 0.066f, 1.000f, 1.000f };
							break;
						case 30:
							Setting::linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };
							break;
						case 31:
							Setting::linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };
							break;
						case 32:
							Setting::linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };
							break;
						case 33:
							Setting::linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };
							break;
						case 34:
							Setting::linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };
							break;
						case 35:
							Setting::linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };
							break;
						case 36:
							Setting::linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };
							break;
						case 37:
							Setting::linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };
							break;
						case 38:
							Setting::linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };
							break;
						case 39:
							Setting::linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };
							break;
						case  40:
							Setting::linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };
							break;
						case 41:
							Setting::linescolors = { 0.126f, 0.430f, 1.000f, 1.000f };
							break;
						case 42:
							Setting::linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
							break;
						case 43:
							Setting::linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
							break;
						case 44:
							Setting::linescolors = { 1.000f, 0.859f, 0.251f, 1.000f };
							break;
						case 45:
							Setting::linescolors = { 0.053f, 0.355f, 1.000f, 1.000f };
							break;
						case 46:
							Setting::linescolors = { 0.126f, 0.430f, 1.000f, 1.000f };
							break;
						case 47:
							Setting::linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
							break;
						case 48:
							Setting::linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
							break;
						case 49:
							Setting::linescolors = { 1.000f, 0.859f, 0.251f, 1.000f };
							break;
						case 50:
							Setting::linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };
							break;
						case 51:
							Setting::linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };
							break;
						case 52:
							Setting::linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };
							break;
						case 53:
							Setting::linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };
							break;
						case 54:
							Setting::linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };
							break;
						case 55:
							Setting::linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };

							break;
						case 56:
							Setting::linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };

							break;
						case 57:
							Setting::linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };

							break;
						case 58:
							Setting::linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };

							break;
						case 59:
							Setting::linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };
							break;
						case  60:
							Setting::linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };

							break;
						case 61:
							Setting::linescolors = { 0.399f, 0.720f, 0.122f, 1.000f };

							break;
						case 62:
							Setting::linescolors = { 1.000f, 0.960f, 0.560f, 1.000f };

							break;
						case 63:
							Setting::linescolors = { 0.874f, 0.301f, 0.068f, 1.000f };

							break;
						case 64:
							Setting::linescolors = { 0.110f, 0.845f, 0.174f, 1.000f };

							break;
						case 65:
							Setting::linescolors = { 0.802f, 0.267f, 0.077f, 1.000f };

							break;

						case 66:
							Setting::linescolors = { 0.129f, 0.774f, 0.986f, 1.000f };

							break;
						case 67:
							Setting::linescolors = { 0.168f, 0.792f, 0.792f, 1.000f };

							break;
						case 68:
							Setting::linescolors = { 1.000f, 0.237f, 0.945f, 1.000f };

							break;
						case 69:
							Setting::linescolors = { 1.000f, 0.126f, 0.430f, 1.000f };

							break;
						case  70:
							Setting::linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };

							break;
						case 71:
							Setting::linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };

							break;
						case 72:
							Setting::linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };

							break;
						case 73:
							Setting::linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };

							break;
						case 74:
							Setting::linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };

							break;
						case 75:
							Setting::linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };

							break;
						case 76:
							Setting::linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };

							break;
						case 77:
							Setting::linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };

							break;
						case 78:
							Setting::linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };

							break;
						case 79:
							Setting::linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };

							break;
						case 80:
							Setting::linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };

							break;
						case 81:
							Setting::linescolors = { 1.000f, 0.033f, 0.129f, 1.000f };

							break;
						case 82:
							Setting::linescolors = { 1.000f, 0.033f, 0.290f, 1.000f };

							break;
						case 83:
							Setting::linescolors = { 1.000f, 0.033f, 0.450f, 1.000f };

							break;
						case 84:
							Setting::linescolors = { 1.000f, 0.033f, 0.578f, 1.000f };

							break;
						case 85:
							Setting::linescolors = { 1.000f, 0.033f, 0.802f, 1.000f };

							break;

						case 86:
							Setting::linescolors = { 0.973f, 0.033f, 1.000f, 1.000f };

							break;
						case 87:
							Setting::linescolors = { 0.781f, 0.033f, 1.000f, 1.000f };

							break;
						case 88:
							Setting::linescolors = { 0.557f, 0.033f, 1.000f, 1.000f };

							break;
						case 89:
							Setting::linescolors = { 0.033f, 0.375f, 1.000f, 1.000f };

							break;
						case  90:
							Setting::linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };

							break;
						case 91:
							Setting::linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };

							break;
						case 92:
							Setting::linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };

							break;
						case 93:
							Setting::linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };

							break;
						case 94:
							Setting::linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };

							break;
						case 95:
							Setting::linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };

							break;

						case 96:
							Setting::linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };

							break;
						case 97:
							Setting::linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };

							break;
						case 98:
							Setting::linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };

							break;
						case 99:
							Setting::linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };

							break;
						case  100:
							Setting::linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };
							break;
						}


						Setting::BoneColorSameAsLine = Setting::linescolors;
						if (AActor.IsBot)
						{
							Setting::linescolors = { 1.000f, 1.000f, 1.000f, 1.000f };
						}
						//ImColor(BoneColor[0], BoneColor[1], BoneColor[2], BoneColor[3]) =  Setting::Setting::linescolors;
						if (!Setting::FightMode)
						{
							if (Setting::lineTop)
							{
								DX11::ImGui_DX11::DrawLine(DX11::Width / 2, 0, Screen.X, Screen.Y - 23, Setting::linescolors, Setting::bonesize);
							}
							else
							{
								//DX11::ImGui_DX11::DrawLine(DX11::Width / 2, 0, Screen.X, Screen.Z, Setting::linescolors, Setting::bonesize);
								DX11::ImGui_DX11::DrawLine(DX11::Width / 2, DX11::Height, Screen.X, (Screen.Y + Screen.Z) + 26, Setting::linescolors, Setting::bonesize);
							}
						}
					}




					if (Setting::Box)
					{
						if (!Setting::FightMode)
						{
							DX11::DrawCorneredBox(Screen.X - (Screen.Z / 4) - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, ImColor(Setting::BoxColor[0], Setting::BoxColor[1], Setting::BoxColor[2], Setting::BoxColor[3]), 1.5f);
						}
					}

					if (Setting::Health)
					{


						DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5), DX11::ImGui_DX11::Color::Black);

						if (AActor.Health > 70.0)
						{
							DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5) * AActor.Health / 100, DX11::ImGui_DX11::Color::Green);
						}
						if (AActor.Health > 30.0 && AActor.Health <= 70.0)
						{
							DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5) * AActor.Health / 100, DX11::ImGui_DX11::Color::Yellow);
						}
						if (AActor.Health > 0.0 && AActor.Health <= 30.0)
						{
							DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5) * AActor.Health / 100, DX11::ImGui_DX11::Color::Red);
						}
					}

					if (Setting::Bone)
					{

						HeadPos = AActor.HeadPos;
						HeadPos.Z += 7;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, HeadPos, Head, &Distance))
							continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.ChestPos, Chest, &Distance))
							continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.PelvisPos, Pelvis, &Distance))
							continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lSholderPos, lSholder, &Distance))
							continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rSholderPos, rSholder, &Distance))
							continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lElbowPos, lElbow, &Distance))
							continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rElbowPos, rElbow, &Distance))
							continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lWristPos, lWrist, &Distance))
							continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rWristPos, rWrist, &Distance))
							continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lThighPos, lThigh, &Distance))
							continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rThighPos, rThigh, &Distance))
							continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lKneePos, lKnee, &Distance))
							continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rKneePos, rKnee, &Distance))
							continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lAnklePos, lAnkle, &Distance))
							continue;
						if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rAnklePos, rAnkle, &Distance))
							continue;

						if (Setting::BoneColorSameAsLineBool)
						{
							if (AActor.Address == Setting::CurrentTargetAddress) {
								bonescolors1 = DX11::ImGui_DX11::Color::Red;
							}
							else {
								bonescolors1 = Setting::BoneColorSameAsLine;
							}
							DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, DX11::ImGui_DX11::Color::Red, 3.0f);
							DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, bonescolors1, 1.0f);
							DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, bonescolors1, 1.0f);
							DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, bonescolors1, 1.0f);
							DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, bonescolors1, 1.0f);
							DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, bonescolors1, 1.0f);
							DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, bonescolors1, 1.0f);
							DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, bonescolors1, 1.0f);
							DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, bonescolors1, 1.0f);
							DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, bonescolors1, 1.0f);
							DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, bonescolors1, 1.0f);
							DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, bonescolors1, 1.0f);
							DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, bonescolors1, 1.0f);
							DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, bonescolors1, 1.0f);
						}
						else
						{
							if (AActor.Address == Setting::CurrentTargetAddress) {
								DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, DX11::ImGui_DX11::Color::Red, 3.0f);
								DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, DX11::ImGui_DX11::Color::Red, 1.0f);
								DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, DX11::ImGui_DX11::Color::Red, 1.0f);
								DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, DX11::ImGui_DX11::Color::Red, 1.0f);
								DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, DX11::ImGui_DX11::Color::Red, 1.0f);
								DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, DX11::ImGui_DX11::Color::Red, 1.0f);
								DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, DX11::ImGui_DX11::Color::Red, 1.0f);
								DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, DX11::ImGui_DX11::Color::Red, 1.0f);
								DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, DX11::ImGui_DX11::Color::Red, 1.0f);
								DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, DX11::ImGui_DX11::Color::Red, 1.0f);
								DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, DX11::ImGui_DX11::Color::Red, 1.0f);
								DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, DX11::ImGui_DX11::Color::Red, 1.0f);
								DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, DX11::ImGui_DX11::Color::Red, 1.0f);
								DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, DX11::ImGui_DX11::Color::Red, 1.0f);
							}
							else {

								DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, DX11::ImGui_DX11::Color::Red, 3.0f);
								DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, ImColor(Setting::BoneColor[0], Setting::BoneColor[1], Setting::BoneColor[2], Setting::BoneColor[3]), 1.0f);
								DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, ImColor(Setting::BoneColor[0], Setting::BoneColor[1], Setting::BoneColor[2], Setting::BoneColor[3]), 1.0f);
								DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, ImColor(Setting::BoneColor[0], Setting::BoneColor[1], Setting::BoneColor[2], Setting::BoneColor[3]), 1.0f);
								DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, ImColor(Setting::BoneColor[0], Setting::BoneColor[1], Setting::BoneColor[2], Setting::BoneColor[3]), 1.0f);
								DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, ImColor(Setting::BoneColor[0], Setting::BoneColor[1], Setting::BoneColor[2], Setting::BoneColor[3]), 1.0f);
								DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, ImColor(Setting::BoneColor[0], Setting::BoneColor[1], Setting::BoneColor[2], Setting::BoneColor[3]), 1.0f);
								DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, ImColor(Setting::BoneColor[0], Setting::BoneColor[1], Setting::BoneColor[2], Setting::BoneColor[3]), 1.0f);
								DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, ImColor(Setting::BoneColor[0], Setting::BoneColor[1], Setting::BoneColor[2], Setting::BoneColor[3]), 1.0f);
								DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, ImColor(Setting::BoneColor[0], Setting::BoneColor[1], Setting::BoneColor[2], Setting::BoneColor[3]), 1.0f);
								DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, ImColor(Setting::BoneColor[0], Setting::BoneColor[1], Setting::BoneColor[2], Setting::BoneColor[3]), 1.0f);
								DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, ImColor(Setting::BoneColor[0], Setting::BoneColor[1], Setting::BoneColor[2], Setting::BoneColor[3]), 1.0f);
								DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, ImColor(Setting::BoneColor[0], Setting::BoneColor[1], Setting::BoneColor[2], Setting::BoneColor[3]), 1.0f);
								DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, ImColor(Setting::BoneColor[0], Setting::BoneColor[1], Setting::BoneColor[2], Setting::BoneColor[3]), 1.0f);
							}

						}
					}


					if (Setting::radar)
					{
						if (!Setting::FightMode)
						{

							float S_height = DX11::Height;
							float S_width = DX11::Width;
							if (AActor.IsBot) {
								DrawRadarHUD(Data::CameraCache.POV, AActor, Distance, 30, 60, 200, 200, DX11::ImGui_DX11::Color::Blue);

							}
							else {
								DrawRadarHUD(Data::CameraCache.POV, AActor, Distance, 30, 60, 200, 200, DX11::ImGui_DX11::Color::Green);

							}
						}

					}

					if (Setting::fovcircle)
					{
						if (Data::AActorList.size() != 0)
						{
							DX11::ImGui_DX11::DrawCircle(DX11::Width / 2, DX11::Height / 2, Setting::fovcircleredus, ImColor(Setting::fovcirclecolor[0], Setting::fovcirclecolor[1], Setting::fovcirclecolor[2], Setting::fovcirclecolor[3]));
						}
					}

				}
			}

			if (Setting::ownInfo)
			{
				ImGui::SetNextWindowSize(ImVec2(215.0f, 200.0f));
				ImGuiStyle& sstyle = ImGui::GetStyle();
				ImVec4* colors = sstyle.Colors;
				ImGuiIO& Io = ImGui::GetIO();
				sstyle.Colors[ImGuiCol_Border] = DX11::ImGui_DX11::Color::Green;
				ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.25f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.15f, 0.1f));
				if (ImGui::Begin("Your Information", 0, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar))
				{
					std::string currentLocation;

					if (Data::LocalPawn == "InLobby")
					{
						currentLocation.append("You Are in Lobby");
					}

					else if (Data::LocalPawn == "InTDM")
					{
						currentLocation.append("Playing TDM");
					}

					else if (Data::LocalPawn == "InLivik")
					{
						currentLocation.append("Playing Livik");
					}

					else if (Data::LocalPawn == "InCheerPark")
					{
						currentLocation.append("Playing CheerPark");
					}

					else if (Data::LocalPawn == "InMiramar")
					{
						currentLocation.append("Playing Miramar");
					}

					else if (Data::LocalPawn == "InSanhok")
					{
						currentLocation.append("Playing Sanhok");
					}

					else if (Data::LocalPawn == "InKarakin")
					{
						currentLocation.append("Playing Karakin");
					}

					else if (Data::LocalPawn == "InDomination")
					{
						currentLocation.append("Playing Domination");
					}

					else if (Data::LocalPawn == "InTraining")
					{
						currentLocation.append("In Training Ground");
					}

					std::string totalKills;
					totalKills.append("Your Kills : " + std::to_string(Data::PlayerTotalKills));

					std::string yourTeamId;
					yourTeamId.append("Your TeamId : " + std::to_string(Data::PlayerTeamID));

					std::string yourUId;
					yourUId.append("Your UID : " + Data::PlayerUID);

					std::string yourLevel;
					yourLevel.append("Your Level : " + Data::PlayerLevel);

					std::string yourNation;
					yourNation.append("Your Country : " + Data::PlayerNation);

					std::string yourHealth;
					yourHealth.append("Your Health : " + std::to_string(Data::PlayerHealth));

					std::string yourName;
					yourName.append("Your Name : " + Data::PlayerPlayerName);

					ImGui::TextColored(ImVec4(1.00, 1.00, 1.00, 1.00), currentLocation.c_str());
					ImGui::Spacing();
					ImGui::TextColored(ImVec4(1.00, 1.00, 1.00, 1.00), yourNation.c_str());
					ImGui::Spacing();
					ImGui::TextColored(ImVec4(1.00, 1.00, 1.00, 1.00), totalKills.c_str());
					ImGui::Spacing();
					ImGui::TextColored(ImVec4(1.00, 1.00, 1.00, 1.00), yourUId.c_str());
					ImGui::Spacing();
					ImGui::TextColored(ImVec4(1.00, 1.00, 1.00, 1.00), yourLevel.c_str());
					ImGui::Spacing();
					ImGui::TextColored(ImVec4(1.00, 1.00, 1.00, 1.00), yourHealth.c_str());
					ImGui::Spacing();
					ImGui::TextColored(ImVec4(1.00, 1.00, 1.00, 1.00), yourName.c_str());
					ImGui::Spacing();

					ImGui::End();
				}
			}

			if (Setting::gameInfo)
			{
				ImGui::SetNextWindowSize(ImVec2(250.0f, 80.0f));
				ImGuiStyle& sstyle = ImGui::GetStyle();
				ImVec4* colors = sstyle.Colors;
				sstyle.Colors[ImGuiCol_Border] = DX11::ImGui_DX11::Color::Yellow;
				ImGuiIO& Io = ImGui::GetIO();
				ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.25f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.15f, 0.1f));
				if (ImGui::Begin("gameInfo", 0, overlayFlag_1))
				{
					TextWithColors(("{ffffff} Alive Players : {05d5ff} " + std::to_string(Setting::AlivePlayers)).c_str());
					ImGui::SameLine();
					TextWithColors(("{ffffff} Has Real Players : {05d5ff} " + std::to_string(Setting::RealPls)).c_str());
					TextWithColors(("{ffffff} With Alive Teams : {05d5ff} " + std::to_string(Setting::AliveTeams)).c_str());
					TextWithColors(("{ffffff} Distance Traveled : {05d5ff} " + std::to_string(Data::PlayerTravelDistance)).c_str());

					/*	std::string Alive;
						Alive.append();

						std::string Alive1 = "ElapsedTime : ";
						Alive1.append(std::to_string(Setting::TimeRemind));

						std::string Alive2 = "Alive Team : ";
						Alive2.append(std::to_string(Setting::AliveTeams));

						std::string Alive3 = "Real Player : ";
						Alive3.append(std::to_string(Setting::RealPls));

						std::string Alive6 = "Bot : ";
						Alive6.append(std::to_string((Setting::AlivePlayers - Setting::RealPls)));

						std::string Alive4 = "ZoneID : ";
						Alive4.append(std::to_string(Setting::ZoneID));

						std::string Alive5 = "My TeamID : ";
						Alive5.append(std::to_string(Setting::MyTeamID));

						ImGui::TextColored(ImVec4(0.02, 0.84, 1.00, 1.00), "Alive Player : " + std::to_string(Setting::AlivePlayers));
						ImGui::Spacing();
						ImGui::Text(Alive1.c_str());
						ImGui::Spacing();
						ImGui::Text(Alive2.c_str());
						ImGui::Spacing();
						ImGui::Text(Alive3.c_str());
						ImGui::Spacing();
						ImGui::Text(Alive6.c_str());
						ImGui::Spacing();
						ImGui::Text(Alive4.c_str());
						ImGui::Spacing();
						ImGui::Text(Alive5.c_str());*/

					ImGui::End();
				}
			}

			if (Setting::aimbotposition)
			{
				/*std::string infoText;
				std::string MagicinfoText;
				std::string AimbotinfoText;
				std::string FightMode;



				if (Setting::Aimbot)
				{
					AimbotinfoText = "Aimbot Is ON";
					DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 16, AimbotinfoText, DX11::Width / 2, DX11::Height / 2 + 315, DX11::ImGui_DX11::Color::Green, true);
				}
				else
				{
					AimbotinfoText = "Aimbot Is Off";
					DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 16, AimbotinfoText, DX11::Width / 2, DX11::Height / 2 + 315, DX11::ImGui_DX11::Color::Red, true);
				}

				if (Setting::FightMode == true)
				{
					FightMode = "Fight Mode";
					DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 16, FightMode, DX11::Width / 2, DX11::Height / 2 + 375, DX11::ImGui_DX11::Color::Green, true);
				}

				if (Setting::MagicBullet)
				{
					MagicinfoText = "Bullet Tracking ON";
					if (Setting::Magic360deg) {
						MagicinfoText = "Bullet Tracking + Mid ON";
					}
					DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 16, MagicinfoText, DX11::Width / 2, DX11::Height / 2 + 360, DX11::ImGui_DX11::Color::Green, true);

					if (Setting::curraim == 0)
					{
						infoText = "Aim Pos: Head";
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 16, infoText, DX11::Width / 2, DX11::Height / 2 + 335, DX11::ImGui_DX11::Color::Yellow, true);

					}
					if (Setting::curraim == 1)
					{
						infoText = "Aim Pos : Body";
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 16, infoText, DX11::Width / 2, DX11::Height / 2 + 335, DX11::ImGui_DX11::Color::Yellow, true);

					}
					if (Setting::curraim == 2)
					{
						infoText = "Aim Pos : Pelvis";
						DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 16, infoText, DX11::Width / 2, DX11::Height / 2 + 335, DX11::ImGui_DX11::Color::Yellow, true);

					}
				}
				else
				{
					MagicinfoText = "Bullet Tracking OFF";
					DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 16, MagicinfoText, DX11::Width / 2, DX11::Height / 2 + 360, DX11::ImGui_DX11::Color::Red, true);
				}*/

			}


			if (Setting::MagicBullet)
			{
				if (Setting::magicAutoLocation) {
					int random = rand() % 3;
					Setting::curraim = random;
				}
			}
			if (Setting::BombAlert)
			{
				// for (BombAlert& BombAlert : Data::BombAlertList)
				//{
				//	if (!Algorithm::WorldToScreen(BombAlert.Position, Screen, &Distance, ViewMatrix)) continue;
				//	DX11::ImGui_DX11::DrawCircle(Screen.X, Screen.Y, Screen.X / 12, DX11::ImGui_DX11::Color::Red);
				//	DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 20, BombAlert.Name, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);
				// }
				if (!Setting::FightMode)
				{
					for (Item& Item : Data::ItemList)
					{
						if (!Algorithm::WorldToScreen(Item.Position, Screen, &Distance, ViewMatrix))
							continue;
						if (Distance < 90)
						{
							std::string air = Item.Name + " " + to_string(Distance) + " M";
							std::string Textt = Item.Name;

							if (Setting::G_Warning_Frag && Item.Name == "Frag Granade!")
							{
								//DX11::ImGui_DX11::DrawCircle(Screen.X, Screen.Y,  Setting::GranadeWarningSize, DX11::ImGui_DX11::Color::Red, 1.0f);
								if (Setting::G_warningType == 0) {
									DX11::ImGui_DX11::DrawImage(draw.Granade_I, Screen.X - 10, Screen.Y - 30, 30, 30);
									//DX11::ImGui_DX11::DrawBlood(Screen.X - 65, Screen.Y - 15, 120, 4.0, AActor.Health);
								}
								else {
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 18, air, Screen.X, Screen.Y, ImColor(Setting::G_warningColor[0], Setting::G_warningColor[1], Setting::G_warningColor[2], Setting::G_warningColor[3]), true);
								}
							}

							if (Setting::G_Warning_Molotof && Item.Name == "Molotof Granade!")
							{
								//DX11::ImGui_DX11::DrawCircle(Screen.X, Screen.Y,  Setting::GranadeWarningSize, DX11::ImGui_DX11::Color::Red, 1.0f);
								//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 18, air, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);
								if (Setting::G_warningType == 0) {
									DX11::ImGui_DX11::DrawImage(draw.Molo_I, Screen.X - 10, Screen.Y - 30, Setting::GranadeWarningSize, Setting::GranadeWarningSize);
								}
								else {
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 18, air, Screen.X, Screen.Y, ImColor(Setting::G_warningColor[0], Setting::G_warningColor[1], Setting::G_warningColor[2], Setting::G_warningColor[3]), true);
								}
							}

							if (Setting::G_Warning_Smoke && Item.Name == "Smoke Granade!")
							{
								//DX11::ImGui_DX11::DrawCircle(Screen.X, Screen.Y,  Setting::GranadeWarningSize, DX11::ImGui_DX11::Color::Red, 1.0f);
								//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 18, air, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);
								if (Setting::G_warningType == 0) {
									DX11::ImGui_DX11::DrawImage(draw.Smoke_I, Screen.X - 10, Screen.Y - 30, Setting::GranadeWarningSize, Setting::GranadeWarningSize);
								}
								else {
									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 18, air, Screen.X, Screen.Y, ImColor(Setting::G_warningColor[0], Setting::G_warningColor[1], Setting::G_warningColor[2], Setting::G_warningColor[3]), true);
								}
							}
						}
					}
				}
			}

			if (Setting::Redzone)
			{
				if (!Setting::FightMode)
				{
					for (Item& Item : Data::ItemList)
					{
						if (!Algorithm::WorldToScreen(Item.Position, Screen, &Distance, ViewMatrix))
							continue;

						Text = Item.Name; // +" " + "(" + to_string(Distance) + "m)";
						std::string air = Item.Name + " " + to_string(Distance) + " M";

						if (Setting::Redzone && Item.Name == "RedZone")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, air, Screen.X, Screen.Y, ImColor(Setting::RedZoneColor[0], Setting::RedZoneColor[1], Setting::RedZoneColor[2], Setting::RedZoneColor[3]), true);
							DX11::ImGui_DX11::DrawCircle(Screen.X, Screen.Y, Setting::redzoneSize, ImColor(Setting::RedZoneColor[0], Setting::RedZoneColor[1], Setting::RedZoneColor[2], Setting::RedZoneColor[3]));
						}
					}
				}
			}

			if (Setting::Item)
			{
				if (!Setting::FightMode)
				{
					for (Item& Item : Data::ItemList)
					{
						if (!Algorithm::WorldToScreen(Item.Position, Screen, &Distance, ViewMatrix))
							continue;

						Text = Item.Name + " " + "(" + to_string(Distance) + "m)";

						if (Setting::Esp_Item_AKM && Item.Name == "AKM")
						{
							DX11::ImGui_DX11::DrawImage(draw.AKM, Screen.X - 10, Screen.Y - 20, 40, 35);
							//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_AKM_Color[0], Setting::Esp_Item_AKM_Color[1], Setting::Esp_Item_AKM_Color[2], Setting::Esp_Item_AKM_Color[3]), true);
						}

						if (Setting::Esp_Item_M762 && Item.Name == "M762")
						{
							DX11::ImGui_DX11::DrawImage(draw.M762, Screen.X - 10, Screen.Y - 20, 40, 35);
							//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_M762_Color[0], Setting::Esp_Item_M762_Color[1], Setting::Esp_Item_M762_Color[2], Setting::Esp_Item_M762_Color[3]), true);
						}

						if (Setting::Esp_Item_Mk47Mutant && Item.Name == "Mk47 Mutant")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Mk47Mutant_Color[0], Setting::Esp_Item_Mk47Mutant_Color[1], Setting::Esp_Item_Mk47Mutant_Color[2], Setting::Esp_Item_Mk47Mutant_Color[3]), true);
						}

						if (Setting::Esp_Item_DP28 && Item.Name == "DP28")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_DP28_Color[0], Setting::Esp_Item_DP28_Color[1], Setting::Esp_Item_DP28_Color[2], Setting::Esp_Item_DP28_Color[3]), true);
						}

						if (Setting::Esp_Item_SCARL && Item.Name == "SCAR-L")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_SCARL_Color[0], Setting::Esp_Item_SCARL_Color[1], Setting::Esp_Item_SCARL_Color[2], Setting::Esp_Item_SCARL_Color[3]), true);
						}

						if (Setting::Esp_Item_M416 && Item.Name == "M416")
						{
							DX11::ImGui_DX11::DrawImage(draw.M416, Screen.X - 10, Screen.Y - 20, 40, 35);
							//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_M416_Color[0], Setting::Esp_Item_M416_Color[1], Setting::Esp_Item_M416_Color[2], Setting::Esp_Item_M416_Color[3]), true);
						}

						if (Setting::Esp_Item_M16A4 && Item.Name == "M16A4")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_M16A4_Color[0], Setting::Esp_Item_M16A4_Color[1], Setting::Esp_Item_M16A4_Color[2], Setting::Esp_Item_M16A4_Color[3]), true);
						}

						if (Setting::Esp_Item_G36C && Item.Name == "G36C")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_G36C_Color[0], Setting::Esp_Item_G36C_Color[1], Setting::Esp_Item_G36C_Color[2], Setting::Esp_Item_G36C_Color[3]), true);
						}

						if (Setting::Esp_Item_QBZ && Item.Name == "QBZ")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_QBZ_Color[0], Setting::Esp_Item_QBZ_Color[1], Setting::Esp_Item_QBZ_Color[2], Setting::Esp_Item_QBZ_Color[3]), true);
						}

						if (Setting::Esp_Item_QBU && Item.Name == "QBU")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_QBU_Color[0], Setting::Esp_Item_QBU_Color[1], Setting::Esp_Item_QBU_Color[2], Setting::Esp_Item_QBU_Color[3]), true);
						}

						if (Setting::Esp_Item_SLR && Item.Name == "SLR")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_SLR_Color[0], Setting::Esp_Item_SLR_Color[1], Setting::Esp_Item_SLR_Color[2], Setting::Esp_Item_SLR_Color[3]), true);
						}

						if (Setting::Esp_Item_Mini14 && Item.Name == "Mini-14")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Mini14_Color[0], Setting::Esp_Item_Mini14_Color[1], Setting::Esp_Item_Mini14_Color[2], Setting::Esp_Item_Mini14_Color[3]), true);
						}

						if (Setting::Esp_Item_M24 && Item.Name == "M24")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_M24_Color[0], Setting::Esp_Item_M24_Color[1], Setting::Esp_Item_M24_Color[2], Setting::Esp_Item_M24_Color[3]), true);
						}

						if (Setting::Esp_Item_AWM && Item.Name == "AWM")
						{
							DX11::ImGui_DX11::DrawImage(draw.AWM, Screen.X - 10, Screen.Y - 20, 40, 35);
							//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_AWM_Color[0], Setting::Esp_Item_AWM_Color[1], Setting::Esp_Item_AWM_Color[2], Setting::Esp_Item_AWM_Color[3]), true);
						}

						if (Setting::Esp_Item_Kar98k && Item.Name == "Kar98k")
						{
							DX11::ImGui_DX11::DrawImage(draw.KAR98K, Screen.X - 10, Screen.Y - 20, 40, 35);
							//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Kar98k_Color[0], Setting::Esp_Item_Kar98k_Color[1], Setting::Esp_Item_Kar98k_Color[2], Setting::Esp_Item_Kar98k_Color[3]), true);
						}

						if (Setting::Esp_Item_PP19 && Item.Name == "PP19")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_PP19_Color[0], Setting::Esp_Item_PP19_Color[1], Setting::Esp_Item_PP19_Color[2], Setting::Esp_Item_PP19_Color[3]), true);
						}

						if (Setting::Esp_Item_TommyGun && Item.Name == "Tommy Gun")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_TommyGun_Color[0], Setting::Esp_Item_TommyGun_Color[1], Setting::Esp_Item_TommyGun_Color[2], Setting::Esp_Item_TommyGun_Color[3]), true);
						}

						if (Setting::Esp_Item_MP5K && Item.Name == "MP5K")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_MP5K_Color[0], Setting::Esp_Item_MP5K_Color[1], Setting::Esp_Item_MP5K_Color[2], Setting::Esp_Item_MP5K_Color[3]), true);
						}

						if (Setting::Esp_Item_UMP9 && Item.Name == "UMP9")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_UMP9_Color[0], Setting::Esp_Item_UMP9_Color[1], Setting::Esp_Item_UMP9_Color[2], Setting::Esp_Item_UMP9_Color[3]), true);
						}

						if (Setting::Esp_Item_Vector && Item.Name == "Vector")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Vector_Color[0], Setting::Esp_Item_Vector_Color[1], Setting::Esp_Item_Vector_Color[2], Setting::Esp_Item_Vector_Color[3]), true);
						}

						if (Setting::Esp_Item_Uzi && Item.Name == "Uzi")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Uzi_Color[0], Setting::Esp_Item_Uzi_Color[1], Setting::Esp_Item_Uzi_Color[2], Setting::Esp_Item_Uzi_Color[3]), true);
						}

						if (Setting::Esp_Item_762mm && Item.Name == "7.62mm")
						{
							DX11::ImGui_DX11::DrawImage(draw.AM762, Screen.X - 10, Screen.Y - 20, 40, 35);
							//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_762mm_Color[0], Setting::Esp_Item_762mm_Color[1], Setting::Esp_Item_762mm_Color[2], Setting::Esp_Item_762mm_Color[3]), true);
						}

						if (Setting::Esp_Item_556mm && Item.Name == "5.56mm")
						{
							DX11::ImGui_DX11::DrawImage(draw.AM556, Screen.X - 10, Screen.Y - 20, 40, 35);
							//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_556mm_Color[0], Setting::Esp_Item_556mm_Color[1], Setting::Esp_Item_556mm_Color[2], Setting::Esp_Item_556mm_Color[3]), true);
						}

						if (Setting::Esp_Item_9mm && Item.Name == "9mm")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_9mm_Color[0], Setting::Esp_Item_9mm_Color[1], Setting::Esp_Item_9mm_Color[2], Setting::Esp_Item_9mm_Color[3]), true);
						}

						if (Setting::Esp_Item_45ACP && Item.Name == "45ACP")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_45ACP_Color[0], Setting::Esp_Item_45ACP_Color[1], Setting::Esp_Item_45ACP_Color[2], Setting::Esp_Item_45ACP_Color[3]), true);
						}

						if (Setting::Esp_Item_RedDot && Item.Name == "Red Dot")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Holo_Color[0], Setting::Esp_Item_Holo_Color[1], Setting::Esp_Item_Holo_Color[2], Setting::Esp_Item_Holo_Color[3]), true);
						}

						if (Setting::Esp_Item_Holo && Item.Name == "Holo")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Holo_Color[0], Setting::Esp_Item_Holo_Color[1], Setting::Esp_Item_Holo_Color[2], Setting::Esp_Item_Holo_Color[3]), true);
						}

						if (Setting::Esp_Item_x2 && Item.Name == "2x")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x2_Color[0], Setting::Esp_Item_x2_Color[1], Setting::Esp_Item_x2_Color[2], Setting::Esp_Item_x2_Color[3]), true);
						}

						if (Setting::Esp_Item_x3 && Item.Name == "3x")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x3_Color[0], Setting::Esp_Item_x3_Color[1], Setting::Esp_Item_x3_Color[2], Setting::Esp_Item_x3_Color[3]), true);
						}

						if (Setting::Esp_Item_x4 && Item.Name == "4x")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x4_Color[0], Setting::Esp_Item_x4_Color[1], Setting::Esp_Item_x4_Color[2], Setting::Esp_Item_x4_Color[3]), true);
						}

						if (Setting::Esp_Item_x6 && Item.Name == "6x")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x6_Color[0], Setting::Esp_Item_x6_Color[1], Setting::Esp_Item_x6_Color[2], Setting::Esp_Item_x6_Color[3]), true);
						}

						if (Setting::Esp_Item_x8 && Item.Name == "8x")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_x8_Color[0], Setting::Esp_Item_x8_Color[1], Setting::Esp_Item_x8_Color[2], Setting::Esp_Item_x8_Color[3]), true);
						}

						if (Setting::Esp_Item_Bag1 && Item.Name == "Bag Lv1")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Bag1_Color[0], Setting::Esp_Item_Bag1_Color[1], Setting::Esp_Item_Bag1_Color[2], Setting::Esp_Item_Bag1_Color[3]), true);
						}

						if (Setting::Esp_Item_Bag2 && Item.Name == "Bag Lv2")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Bag2_Color[0], Setting::Esp_Item_Bag2_Color[1], Setting::Esp_Item_Bag2_Color[2], Setting::Esp_Item_Bag2_Color[3]), true);
						}

						if (Setting::Esp_Item_Bag3 && Item.Name == "Bag Lv3")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Bag3_Color[0], Setting::Esp_Item_Bag3_Color[1], Setting::Esp_Item_Bag3_Color[2], Setting::Esp_Item_Bag3_Color[3]), true);
						}

						if (Setting::Esp_Item_Armor1 && Item.Name == "Armor Lv1")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Armor1_Color[0], Setting::Esp_Item_Armor1_Color[1], Setting::Esp_Item_Armor1_Color[2], Setting::Esp_Item_Armor1_Color[3]), true);
						}

						if (Setting::Esp_Item_Armor2 && Item.Name == "Armor Lv2")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Armor2_Color[0], Setting::Esp_Item_Armor2_Color[1], Setting::Esp_Item_Armor2_Color[2], Setting::Esp_Item_Armor2_Color[3]), true);
						}

						if (Setting::Esp_Item_Armor3 && Item.Name == "Armor Lv3")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Armor3_Color[0], Setting::Esp_Item_Armor3_Color[1], Setting::Esp_Item_Armor3_Color[2], Setting::Esp_Item_Armor3_Color[3]), true);
						}

						if (Setting::Esp_Item_Helmet1 && Item.Name == "Helmet Lv1")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Helmet1_Color[0], Setting::Esp_Item_Helmet1_Color[1], Setting::Esp_Item_Helmet1_Color[2], Setting::Esp_Item_Helmet1_Color[3]), true);
						}

						if (Setting::Esp_Item_Helmet2 && Item.Name == "Helmet Lv2")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Helmet2_Color[0], Setting::Esp_Item_Helmet2_Color[1], Setting::Esp_Item_Helmet2_Color[2], Setting::Esp_Item_Helmet2_Color[3]), true);
						}

						if (Setting::Esp_Item_Helmet3 && Item.Name == "Helmet Lv3")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Helmet3_Color[0], Setting::Esp_Item_Helmet3_Color[1], Setting::Esp_Item_Helmet3_Color[2], Setting::Esp_Item_Helmet3_Color[3]), true);
						}

						if (Setting::Esp_Item_Frag && Item.Name == "Frag")
						{

							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Frag_Color[0], Setting::Esp_Item_Frag_Color[1], Setting::Esp_Item_Frag_Color[2], Setting::Esp_Item_Frag_Color[3]), true);
						}

						if (Setting::Esp_Item_Smoke && Item.Name == "Smoke")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Smoke_Color[0], Setting::Esp_Item_Smoke_Color[1], Setting::Esp_Item_Smoke_Color[2], Setting::Esp_Item_Smoke_Color[3]), true);
						}

						if (Setting::Esp_Item_Molotof && Item.Name == "Molotof")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Molotof_Color[0], Setting::Esp_Item_Molotof_Color[1], Setting::Esp_Item_Molotof_Color[2], Setting::Esp_Item_Molotof_Color[3]), true);
						}

						if (Setting::Esp_Item_MedKit && Item.Name == "Med Kit")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_MedKit_Color[0], Setting::Esp_Item_MedKit_Color[1], Setting::Esp_Item_MedKit_Color[2], Setting::Esp_Item_MedKit_Color[3]), true);
						}

						if (Setting::Esp_Item_FirstAidKit && Item.Name == "First Aid Kit")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_FirstAidKit_Color[0], Setting::Esp_Item_FirstAidKit_Color[1], Setting::Esp_Item_FirstAidKit_Color[2], Setting::Esp_Item_FirstAidKit_Color[3]), true);
						}

						if (Setting::Esp_Item_Painkiller && Item.Name == "Painkiller")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Painkiller_Color[0], Setting::Esp_Item_Painkiller_Color[1], Setting::Esp_Item_Painkiller_Color[2], Setting::Esp_Item_Painkiller_Color[3]), true);
						}

						if (Setting::Esp_Item_EnergyDrink && Item.Name == "Energy Drink")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_EnergyDrink_Color[0], Setting::Esp_Item_EnergyDrink_Color[1], Setting::Esp_Item_EnergyDrink_Color[2], Setting::Esp_Item_EnergyDrink_Color[3]), true);
						}

						if (Setting::Esp_Item_AdrenalineSyringe && Item.Name == "Adrenaline Syringe")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_AdrenalineSyringe_Color[0], Setting::Esp_Item_AdrenalineSyringe_Color[1], Setting::Esp_Item_AdrenalineSyringe_Color[2], Setting::Esp_Item_AdrenalineSyringe_Color[3]), true);
						}

						if (Setting::Esp_Item_PlayerDeadBox && Item.Name == "Dead-Box")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_PlayerDeadBox_Color[0], Setting::Esp_Item_PlayerDeadBox_Color[1], Setting::Esp_Item_PlayerDeadBox_Color[2], Setting::Esp_Item_PlayerDeadBox_Color[3]), true);
						}

						if (Setting::Esp_Item_FlareGun && Item.Name == "Flare Gun")
						{
							//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont,  Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_FlareGun_Color[0], Setting::Esp_Item_FlareGun_Color[1], Setting::Esp_Item_FlareGun_Color[2], Setting::Esp_Item_FlareGun_Color[3]), true);
							DX11::ImGui_DX11::DrawImage(draw.FlareGun_I, Screen.X - 10, Screen.Y - 30, 30, 30);
						}

						if (Setting::Esp_Item_Flare && Item.Name == "Flare")
						{
							DX11::ImGui_DX11::DrawImage(draw.FlareAmmo_I, Screen.X - 10, Screen.Y - 30, 30, 30);
							//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont,  Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_Flare_Color[0], Setting::Esp_Item_Flare_Color[1], Setting::Esp_Item_Flare_Color[2], Setting::Esp_Item_Flare_Color[3]), true);
						}

						if (Setting::Esp_Item_GasCan && Item.Name == "GasCan")
						{
							//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont,  Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_FlareGun_Color[0], Setting::Esp_Item_FlareGun_Color[1], Setting::Esp_Item_FlareGun_Color[2], Setting::Esp_Item_FlareGun_Color[3]), true);
							DX11::ImGui_DX11::DrawImage(draw.GasCan_I, Screen.X - 10, Screen.Y - 30, 30, 30);
						}

						if (Setting::Esp_Item_AirDrop && Item.Name == "Air Drop")
						{
							//DX11::ImGui_DX11::DrawImage(draw.Airdrop_I, Screen.X - 10, Screen.Y - 30, 30, 30);
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::ItemSize, Text, Screen.X, Screen.Y, ImColor(Setting::Esp_Item_AirDrop_Color[0], Setting::Esp_Item_AirDrop_Color[1], Setting::Esp_Item_AirDrop_Color[2], Setting::Esp_Item_AirDrop_Color[3]), true);
						}
					}
				}
			}

			if (Setting::deadbox)
			{
				if (!Setting::FightMode)
				{
					ImColor color;
					for (int i = 0; i < g_pEsp->lootboxr.size(); i++)
					{

						if (!Algorithm::WorldToScreen(g_pEsp->lootboxr[i].Position, Screen, &Distance, Esp::ViewMatrix)) continue;
						if (Distance >= 200 || Distance <= 5) continue;
						for (int k = 0; k < g_pEsp->lootboxr[i].boxitem.size(); k++)
						{
							color = g_pEsp->lootboxr[i].boxitem[k].colorcod;
							std::string text = g_pEsp->lootboxr[i].boxitem[k].Displayname;
							float popcorn2 = 0.450f;
							if (Setting::deadboxBG)
							{
								DX11::ImGui_DX11::DrawFilledRect(Screen.X - 10, Screen.Y - 15 * (k), 100, 15, ImColor(0.000f, 0.00f, 0.00f, 0.200f));
							}
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, 14, text, Screen.X, Screen.Y - 15 * (k), g_pEsp->lootboxr[i].boxitem[k].colorcod, false);
							//DX11::ImGui_DX11::DrawFilledRect(Screen.X - 10, Screen.Y - 15 * (k), 100, 15, ImColor(0.000f, 0.00f, 0.00f, 0.200f));
							//DX11::ImGui_DX11::CornerBox(Screen.X - 10, Screen.Y - 15 * (k), 110, 15, 0.6f, popcorn2, Colors::bgcorner);
						}
					}
				}
			}

			//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);
			//DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, details, Screen.X, Screen.Y + 15, ImColor(Setting::hpFuel[0], Setting::hpFuel[1], Setting::hpFuel[2], Setting::hpFuel[3]), true);

			if (Setting::Vehicle)
			{
				if (!Setting::FightMode)
				{
					for (Vehicle& Vehicle : Data::VehicleList)
					{
						if (!Algorithm::WorldToScreen(Vehicle.Position, Screen, &Distance, ViewMatrix)) continue;

						Text = Vehicle.Name + " | " + to_string(Distance) + "M";

						if (Distance < 10 || Distance > 750) {
							if (Vehicle.HP > 10 || Vehicle.HP < 750)
								continue;
						}


						if (Setting::vehicleHpFuel)
						{
							std::string fuel;
							fuel.append(ICON_FA_HEARTBEAT " ").append(std::to_string((int)(Vehicle.HP)).append(" | " ICON_FA_BATTERY_FULL).append(" " + std::to_string((int)(Vehicle.Fuel)).append("")));
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pIconFont, Setting::carsize, fuel, Screen.X, Screen.Y + 17, ImColor(Setting::hpFuel[0], Setting::hpFuel[1], Setting::hpFuel[2], Setting::hpFuel[3]), true);

						}
						if (Vehicle.Name == "BRDM")
						{
							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);
							}
						}
						if (Vehicle.Name == "Scooter")
						{
							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}
						if (Vehicle.Name == "Motorcycle")
						{
							std::string motorCycle = ICON_FA_MOTORCYCLE " | " + Vehicle.Name + " | " + to_string(Distance) + "M";

							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pIconFont, Setting::carsize, motorCycle, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}
						if (Vehicle.Name == "Snowmobile")
						{
							//std::string Snowmobile = ICON_FA_SNOWPLOW " | " + Vehicle.Name + " | " + to_string(Distance) + "M";
							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pIconFont, Setting::carsize, Text, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}
						if (Vehicle.Name == "Tuk")
						{
							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}
						if (Vehicle.Name == "Buggy")
						{
							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}
						if (Vehicle.Name == "Sportsa")
						{
							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}
						if (Vehicle.Name == "Sports")
						{
							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}
						if (Vehicle.Name == "Dacia")
						{
							std::string Dacia = ICON_FA_CAR " | " + Vehicle.Name + " | " + to_string(Distance) + "M";
							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pIconFont, Setting::carsize, Dacia, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}
						if (Vehicle.Name == "Rony")
						{
							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}
						if (Vehicle.Name == "Tesla")
						{
							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}
						if (Vehicle.Name == "Gravity")
						{
							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}
						if (Vehicle.Name == "Glider")
						{
							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}
						if (Vehicle.Name == "UAZ")
						{
							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}
						if (Vehicle.Name == "Minibus")
						{
							std::string Minibus = ICON_FA_CAR " | " + Vehicle.Name + " | " + to_string(Distance) + "M";


							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pIconFont, Setting::carsize, Minibus, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}
						if (Vehicle.Name == "PG117")
						{
							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}
						if (Vehicle.Name == "Coupe")
						{
							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}
						if (Vehicle.Name == "Aquarail")
						{
							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}
						if (Vehicle.Name == "UTV")
						{
							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}
						if (Vehicle.Name == "Monster")
						{
							std::string Monster = ICON_FA_CAR " | " + Vehicle.Name + " | " + to_string(Distance) + "M";
							if (Vehicle.isDriving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pRegularFont, Setting::carsize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pIconFont, Setting::carsize, Monster, Screen.X, Screen.Y, ImColor(Setting::VehhilceColor[0], Setting::VehhilceColor[1], Setting::VehhilceColor[2], Setting::VehhilceColor[3]), true);

							}
						}

					}
				}
			}

			//if (Setting::MAgicline && GetAsyncKeyState(Setting::AimbotKey))
			if (Setting::I_HackInjectType != 2)
			{

				if (Setting::MAgicline && GetAsyncKeyState(VK_LBUTTON))
				{
					for (int i = 0; i < Data::AActorList.size(); i++)
					{
						if (!Algorithm::WorldToScreen(Data::AActorList[i].Position, Screen, &Distance, ViewMatrix)) continue;
						if (currIndex == i)
						{
							DX11::ImGui_DX11::DrawLine(DX11::Width / 2, DX11::Height / 2, Screen.X, Screen.Y - 10, DX11::ImGui_DX11::Color::Red, 1.8f);
						}
					}
				}
			}
			if (Setting::I_HackInjectType != 2)
			{
				if (Setting::IpadView)
				{
					DWORD dd = Utility::ReadMemoryEx<INT>(Data::LocalPlayer + 0x1324) + 0x260;
					Utility::WriteMemoryEx<float>(dd, Setting::Ipad);
				}
			}

			if (Setting::I_HackInjectType != 2)
			{

				if (GetAsyncKeyState(Setting::MagicPositionKey) & 1)
				{
					if (Setting::curraim == 2)
						if (Setting::curraim == 2)
							Setting::curraim = 0;

						else if (Setting::curraim == 0)
							Setting::curraim = 1;

						else if (Setting::curraim == 1)
							Setting::curraim = 2;
				}

			}

			if (Setting::I_HackInjectType != 2)
			{

				if (GetAsyncKeyState(Setting::EnableMagicKey) & 1)
				{
					Setting::MagicBullet = !Setting::MagicBullet;
				}

				if (GetAsyncKeyState(Setting::OnOffAimbotKey) & 1)
				{
					Setting::Aimbot = !Setting::Aimbot;
				}

			}
			if (Setting::I_HackInjectType != 2)
			{

				if (Setting::I_HackInjectType == 1)
				{
					if (GetAsyncKeyState(VK_F4) & 1)
					{
						Setting::instanthit = !Setting::instanthit;
					}
				}
			}


			if (GetAsyncKeyState(VK_F5) & 1)
			{

				Setting::streamMode = !Setting::streamMode;
			}

			if (GetAsyncKeyState(VK_F6) & 1)
			{
				Setting::FightMode = !Setting::FightMode;
			}

			if (GetAsyncKeyState(VK_F7) & 1)
			{
				Setting::Item = !Setting::Item;
			}

			if (GetAsyncKeyState(VK_F8) & 1)
			{
				Setting::Vehicle = !Setting::Vehicle;
			}

			if (Setting::I_HackInjectType != 2)
			{

				if (GetAsyncKeyState(VK_F9) & 1)
				{
					Setting::magicAutoLocation = !Setting::magicAutoLocation;
				}
			}


			if (Setting::streamMode)
			{
				SetWindowDisplayAffinity(DX11::hWindow, WDA_EXCLUDEFROMCAPTURE);
			}
			else
			{
				SetWindowDisplayAffinity(DX11::hWindow, WDA_NONE);
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(20));

		ImGui::Render();
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
		DX11::EndDraw();
	}
}