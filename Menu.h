#pragma once

#include "Esp.h"
#include <string.h>
#include <thread>
#include <D3DX11tex.h>
#include "ConfigMain.h"
#include "StreamMode.h"
#include <iconcpp.h>
//#include "notification\imgui_notify.h"

#pragma region Define

ConfigMain _config;
StreamMode _stream;

#pragma endregion

namespace Settingss
{
	static int Tab = 5;
}

struct MainMenu
{


	ImVec4 to_vec4(float r, float g, float b, float a)
	{
		return ImVec4(r / 255.0, g / 255.0, b / 255.0, a / 255.0);
	}

	void DrawMenu()
	{
		ImGuiStyle* style = &ImGui::GetStyle();
		style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
		style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
		style->Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
		style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
		style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.10f, 0.09f, 0.13f, 1.00f);
		style->Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
		style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
		style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.10f, 0.09f, 0.13f, 1.00f);
		style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.10f, 0.09f, 0.13f, 1.00f);
		style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.10f, 0.09f, 0.13f, 1.00f);
		style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.10f, 0.09f, 0.13f, 1.00f);
		style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
		style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
		style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
		style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
		style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);


		style->WindowPadding = ImVec2(10, 10);
		style->WindowRounding = 11.0f;
		style->FramePadding = ImVec2(4, 4);
		style->FrameRounding = 11.0f;
		style->ItemSpacing = ImVec2(7, 4);
		style->ItemInnerSpacing = ImVec2(3, 3);
		style->TouchExtraPadding = ImVec2(0, 0);
		style->IndentSpacing = 10.0f;
		style->ScrollbarSize = 12.0f;
		style->ScrollbarRounding = 16.0f;
		style->GrabMinSize = 20.0f;
		style->GrabRounding = 15.0f;

		style->WindowTitleAlign.x = 0.50f;

		style->Colors[ImGuiCol_Border] = ImVec4(0.539f, 0.479f, 0.255f, 0.162f);
		style->FrameBorderSize = 0.0f;
		style->WindowBorderSize = 1.0f;




		ImGui::SetNextWindowPos(ImVec2(DX11::Width * 0.5f, DX11::Height * 0.5f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));
		ImGuiStyle& styleMenu = ImGui::GetStyle();

		ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 108));
		ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 255, 255));
		ImGui::PushStyleColor(ImGuiCol_CheckMark, ImVec4(1.00f, 1.00f, 1.00f, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.24f, 0.23f, 0.29f, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.10f, 0.09f, 0.12f, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_TitleBgCollapsed, ImVec4(1.00f, 0.98f, 0.95f, 0.75f));
		ImGui::PushStyleColor(ImGuiCol_TitleBgActive, ImVec4(0.07f, 0.07f, 0.09f, 1.00f));
		ImGui::PushStyleColor(ImGuiCol_MenuBarBg, ImVec4(0.10f, 0.09f, 0.12f, 1.00f));

		styleMenu.FrameRounding = 2.3f;

		static auto colorPickerFlags = ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs;

		if (ImGui::Begin("", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize))
		{
			ImGui::TextColored(ImVec4(0.02, 0.84, 1.00, 1.00), "NEXUS PREMIUM");

			if (ImGui::CollapsingHeader(ICON_FA_PUZZLE_PIECE" ESP"))
			{
				if (ImGui::TreeNode("MAIN SETTINGS"))
				{
					ImGui::ColorEdit4("Name Color###PlayerNameColor", (float*)&Setting::PlayerNameColor, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("ESP Name", &Setting::Name);
					ImGui::SameLine();
					ImGui::Checkbox("Player Flags", &Setting::country);
					ImGui::Checkbox("ESP Item", &Setting::Item);
					ImGui::Checkbox("ESP Health", &Setting::Health);
					ImGui::Checkbox("Player Lines", &Setting::Line);
					ImGui::SameLine();
					ImGui::Checkbox("Offscreen Lines", &Setting::enemyIndicator);
					ImGui::Checkbox("Player Weapon", &Setting::PlayerWeapon);

					ImGui::ColorEdit4("Bone Color### Setting::BoneColor", Setting::BoneColor, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("ESP Skeleton", &Setting::Bone);
					ImGui::SameLine();
					ImGui::Checkbox("Auto", &Setting::BoneColorSameAsLineBool);
					ImGui::SliderFloat("Skeleton Size##SkeletonSize", &Setting::bonesize, 0.0f, 5.0f);

					ImGui::ColorEdit4("Box Color### Setting::BoxColor", Setting::BoxColor, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("ESP BOX", &Setting::Box);

					/*if (ImGui::Button("dd")) {
						ImGuiNoti::InsertNotification({ ImGuiToastType_Success, 3000, "Hello World! This is a success! %s", "We can also format here:)" });
					}*/
					ImGui::TreePop();
				}

				if (ImGui::TreeNode("MISC SETTINGS"))
				{
					if (Setting::I_HackInjectType != 2) {
						ImGui::Checkbox("Aim Line CrossHair", &Setting::MAgicline);
					}
					ImGui::Checkbox("Show Total Enemies", &Setting::TotalEnemy);
					ImGui::Checkbox("Show Enemy ID", &Setting::TeamId);
					ImGui::Checkbox("Show Enemy Distance", &Setting::Distance);
					ImGui::Checkbox("Show Enemy Status", &Setting::EnemyStatus);
					ImGui::Checkbox("Show Enemy Aiming Alert", &Setting::PlayerAiming);
					ImGui::Checkbox("Show Game Info", &Setting::gameInfo);
					ImGui::Checkbox("Show Own Info", &Setting::ownInfo);
					ImGui::Checkbox("Side Menu", &Setting::sideMenu);
					ImGui::Checkbox("Anti Stream", &Setting::streamMode);
					ImGui::Checkbox("Draw Radar", &Setting::radar);

					if (ImGui::RadioButton("Line Top", (Setting::lineTop) ? 1 : 0))
					{
						Setting::lineTop = true;
					}
					ImGui::SameLine();
					if (ImGui::RadioButton("Line Bottom", (Setting::lineTop) ? 0 : 1))
					{
						Setting::lineTop = false;
					}

					ImGui::ColorEdit4("Warning Color##Gwarning", Setting::G_warningColor, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Show Bomb Warning", &Setting::BombAlert);
					if (Setting::BombAlert)
					{
						if (ImGui::TreeNode("WARNING SETTINGS"))
						{
							ImGui::Indent();

							ImGui::Checkbox("Fraw", &Setting::G_Warning_Frag);
							ImGui::SameLine();
							ImGui::Checkbox("Molotof", &Setting::G_Warning_Molotof);
							ImGui::SameLine();
							ImGui::Checkbox("Smoke", &Setting::G_Warning_Smoke);

							Setting::Item = true;
							const char* C_label = Setting::GranadeWarningType[Setting::G_warningType];
							if (ImGui::BeginCombo("Warning Type", C_label, ImGuiComboFlags_HeightSmall))
							{
								for (int n = 0; n < IM_ARRAYSIZE(Setting::GranadeWarningType); n++)
								{
									const bool is_selected = (Setting::G_warningType == n);
									if (ImGui::Selectable(Setting::GranadeWarningType[n], is_selected))
										Setting::G_warningType = n;
									if (is_selected)
										ImGui::SetItemDefaultFocus();
								}
								ImGui::EndCombo();
							}
							ImGui::SliderInt("Warning Size##Warning Size", &Setting::GranadeWarningSize, 1, 100);
						}

						ImGui::TreePop();
					}


					ImGui::TreePop();
				}

				if (ImGui::TreeNode("ITEMS SETTINGS"))
				{
					ImGui::ColorEdit4("Vehicles Color###CarColor", Setting::VehhilceColor, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Vehicles", &Setting::Vehicle);

					ImGui::ColorEdit4("Vehicles HpFuel###HpFuelColor", Setting::hpFuel, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Vehicles HP-FUEL", &Setting::vehicleHpFuel);

					ImGui::TreePop();
				}
			}

			if (ImGui::CollapsingHeader(ICON_FA_EYE" VISUALS"))
			{
				if (ImGui::TreeNode("ASSAULT"))
				{
					ImGui::Indent();
					ImGui::ColorEdit4("###AKM_Color", Setting::Esp_Item_AKM_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("AKM##1", &Setting::Esp_Item_AKM);

					ImGui::ColorEdit4("###Esp_Item_M762_Color", Setting::Esp_Item_M762_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("M762##2  ", &Setting::Esp_Item_M762);

					ImGui::ColorEdit4("###Esp_Item_Groza_Color", Setting::Esp_Item_Groza_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Groza##3  ", &Setting::Esp_Item_Groza);

					ImGui::ColorEdit4("###Esp_Item_Mk47Mutant_Color", Setting::Esp_Item_Mk47Mutant_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Mk47-Mutan##4  ", &Setting::Esp_Item_Mk47Mutant);

					ImGui::ColorEdit4("###Esp_Item_DP28_Color", Setting::Esp_Item_DP28_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("DP28##5  ", &Setting::Esp_Item_DP28);

					ImGui::ColorEdit4("###Esp_Item_SCARL_Color", Setting::Esp_Item_SCARL_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("SCAR-L##6  ", &Setting::Esp_Item_SCARL);

					ImGui::ColorEdit4("###Esp_Item_M416_Color", Setting::Esp_Item_M416_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("M416##7  ", &Setting::Esp_Item_M416);

					ImGui::ColorEdit4("###Esp_Item_AUG_Color", Setting::Esp_Item_AUG_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("AUG##8  ", &Setting::Esp_Item_AUG);

					ImGui::ColorEdit4("###Esp_Item_M249_Color", Setting::Esp_Item_M249_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("M249##9  ", &Setting::Esp_Item_M249);

					ImGui::ColorEdit4("###Esp_Item_G36C_Color", Setting::Esp_Item_G36C_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("G36C##10", &Setting::Esp_Item_G36C);

					ImGui::ColorEdit4("###Esp_Item_QBZ_Color", Setting::Esp_Item_QBZ_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("QBZ##11", &Setting::Esp_Item_QBZ);

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("SMG"))
				{
					ImGui::Indent();

					ImGui::ColorEdit4("###Esp_Item_TommyGun_Color", Setting::Esp_Item_TommyGun_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Tommy Gun##20", &Setting::Esp_Item_TommyGun);

					ImGui::ColorEdit4("###Esp_Item_MP5K_Color", Setting::Esp_Item_MP5K_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("MP5K##21", &Setting::Esp_Item_MP5K);

					ImGui::ColorEdit4("###Esp_Item_UMP9_Color", Setting::Esp_Item_UMP9_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("UMP9##22", &Setting::Esp_Item_UMP9);

					ImGui::ColorEdit4("###Esp_Item_Vector_Color", Setting::Esp_Item_Vector_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Vector##23", &Setting::Esp_Item_Vector);

					ImGui::ColorEdit4("###Esp_Item_Uzi_Color", Setting::Esp_Item_Uzi_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Uzi##24", &Setting::Esp_Item_Uzi);

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("SNIPER"))
				{
					ImGui::Indent();
					ImGui::ColorEdit4("###Esp_Item_QBU_Color", Setting::Esp_Item_QBU_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("QBU##12", &Setting::Esp_Item_QBU);

					ImGui::ColorEdit4("###Esp_Item_SLR_Color", Setting::Esp_Item_SLR_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("SLR##13", &Setting::Esp_Item_SLR);

					ImGui::ColorEdit4("###Esp_Item_SKS_Color", Setting::Esp_Item_SKS_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("SKS##14", &Setting::Esp_Item_SKS);

					ImGui::ColorEdit4("###Esp_Item_Mini14_Color", Setting::Esp_Item_Mini14_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Mini14##15", &Setting::Esp_Item_Mini14);

					ImGui::ColorEdit4("###Esp_Item_M24_Color", Setting::Esp_Item_M24_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("M24##16", &Setting::Esp_Item_M24);

					ImGui::ColorEdit4("###Esp_Item_Kar98k_Color", Setting::Esp_Item_Kar98k_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Kar98k##17", &Setting::Esp_Item_Kar98k);

					ImGui::ColorEdit4("###Esp_Item_AWM_Color", Setting::Esp_Item_AWM_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("AWM##18", &Setting::Esp_Item_AWM);
					ImGui::TreePop();
				}

				if (ImGui::TreeNode("AMMO"))
				{
					ImGui::Indent();
					ImGui::ColorEdit4("###Esp_Item_762mm_Color", Setting::Esp_Item_762mm_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("7.62MM##25", &Setting::Esp_Item_762mm);

					ImGui::ColorEdit4("###Esp_Item_556mm_Color", Setting::Esp_Item_556mm_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("5.56MM##26", &Setting::Esp_Item_556mm);

					ImGui::ColorEdit4("###Esp_Item_9mm_Color", Setting::Esp_Item_9mm_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("9mm##27", &Setting::Esp_Item_9mm);

					ImGui::ColorEdit4("###Esp_Item_45ACP_Color", Setting::Esp_Item_45ACP_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("45ACP##28", &Setting::Esp_Item_45ACP);

					ImGui::ColorEdit4("###Esp_Item_300Magnum_Color", Setting::Esp_Item_300Magnum_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("300Magnum##29", &Setting::Esp_Item_300Magnum);
					ImGui::TreePop();
				}

				if (ImGui::TreeNode("SCOPE"))
				{
					ImGui::Indent();
					ImGui::ColorEdit4("###Esp_Item_RedDot_Color", Setting::Esp_Item_RedDot_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("RedDot##56", &Setting::Esp_Item_RedDot);

					ImGui::ColorEdit4("###Esp_Item_Holo_Color", Setting::Esp_Item_Holo_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Holo##30", &Setting::Esp_Item_Holo);

					ImGui::ColorEdit4("###Esp_Item_x2_Color", Setting::Esp_Item_x2_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("2x##31", &Setting::Esp_Item_x2);

					ImGui::ColorEdit4("###Esp_Item_x3_Color", Setting::Esp_Item_x3_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("3x##32", &Setting::Esp_Item_x3);

					ImGui::ColorEdit4("###Esp_Item_x4_Color", Setting::Esp_Item_x4_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("4x##33", &Setting::Esp_Item_x4);

					ImGui::ColorEdit4("###Esp_Item_x6_Color", Setting::Esp_Item_x6_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("6x##34", &Setting::Esp_Item_x6);

					ImGui::ColorEdit4("###Esp_Item_x8_Color", Setting::Esp_Item_x8_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("8x##35", &Setting::Esp_Item_x8);
					ImGui::TreePop();
				}

				if (ImGui::TreeNode("ATTACHMENT"))
				{
					ImGui::Indent();
					ImGui::ColorEdit4("###Esp_Item_Bag1_Color", Setting::Esp_Item_Bag1_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Bag 1##36", &Setting::Esp_Item_Bag1);

					ImGui::ColorEdit4("###Esp_Item_Bag2_Color", Setting::Esp_Item_Bag2_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Bag 2##37", &Setting::Esp_Item_Bag2);

					ImGui::ColorEdit4("###Esp_Item_Bag3_Color", Setting::Esp_Item_Bag3_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Bag 3##38", &Setting::Esp_Item_Bag3);

					ImGui::ColorEdit4("###Esp_Item_Armor1_Color", Setting::Esp_Item_Armor1_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Armor 1##39", &Setting::Esp_Item_Armor1);

					ImGui::ColorEdit4("###Esp_Item_Armor2_Color", Setting::Esp_Item_Armor2_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Armor 2##40", &Setting::Esp_Item_Armor2);

					ImGui::ColorEdit4("###Esp_Item_Armor3_Color", Setting::Esp_Item_Armor3_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Armor 3##41", &Setting::Esp_Item_Armor3);

					ImGui::ColorEdit4("###Esp_Item_Helmet1_Color", Setting::Esp_Item_Helmet1_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Helmet 1##42", &Setting::Esp_Item_Helmet1);

					ImGui::ColorEdit4("###Esp_Item_Helmet2_Color", Setting::Esp_Item_Helmet2_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Helmet 2##43", &Setting::Esp_Item_Helmet2);

					ImGui::ColorEdit4("###Esp_Item_Helmet3_Color", Setting::Esp_Item_Helmet3_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Helmet 3##44", &Setting::Esp_Item_Helmet3);
					ImGui::TreePop();
				}

				if (ImGui::TreeNode("GRANADE"))
				{
					ImGui::Indent();
					ImGui::ColorEdit4("###Esp_Item_Frag_Color", Setting::Esp_Item_Frag_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Frag##45", &Setting::Esp_Item_Frag);

					ImGui::ColorEdit4("###Esp_Item_Smoke_Color", Setting::Esp_Item_Smoke_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Smoke##46", &Setting::Esp_Item_Smoke);

					ImGui::ColorEdit4("###Esp_Item_Molotof_Color", Setting::Esp_Item_Molotof_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Molotof##47", &Setting::Esp_Item_Molotof);
					ImGui::TreePop();
				}

				if (ImGui::TreeNode("HEALING"))
				{
					ImGui::Indent();
					ImGui::ColorEdit4("###Esp_Item_MedKit_Color", Setting::Esp_Item_MedKit_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Med Kit##48", &Setting::Esp_Item_MedKit);

					ImGui::ColorEdit4("###Esp_Item_FirstAidKit_Color", Setting::Esp_Item_FirstAidKit_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("First Aid##49", &Setting::Esp_Item_FirstAidKit);

					ImGui::ColorEdit4("###Esp_Item_Painkiller_Color", Setting::Esp_Item_Painkiller_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Painkiller##50", &Setting::Esp_Item_Painkiller);

					ImGui::ColorEdit4("###Esp_Item_EnergyDrink_Color", Setting::Esp_Item_EnergyDrink_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Energy Drink##51", &Setting::Esp_Item_EnergyDrink);

					ImGui::ColorEdit4("###Esp_Item_AdrenalineSyringe_Color", Setting::Esp_Item_AdrenalineSyringe_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Adrenaline##52", &Setting::Esp_Item_AdrenalineSyringe);

					ImGui::ColorEdit4("###Esp_Item_GasCan_Color", Setting::Esp_Item_GasCan_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("GasCan##57", &Setting::Esp_Item_GasCan);

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("AIRDROP"))
				{
					ImGui::Indent();
					ImGui::ColorEdit4("###Esp_Item_FlareGun_Color", Setting::Esp_Item_FlareGun_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("FlareGun##53", &Setting::Esp_Item_FlareGun);

					ImGui::ColorEdit4("###Esp_Item_Flare_Color", Setting::Esp_Item_Flare_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("Flare##54", &Setting::Esp_Item_Flare);

					ImGui::ColorEdit4("###Esp_Item_AirDrop_Color", Setting::Esp_Item_AirDrop_Color, colorPickerFlags);
					ImGui::SameLine();
					ImGui::Checkbox("AirDrop##55", &Setting::Esp_Item_AirDrop);
					ImGui::TreePop();
				}
			}

			if (Setting::I_HackInjectType != 2)
			{
				if (ImGui::CollapsingHeader(ICON_FA_CROSSHAIRS" AIMBOT"))
				{
					ImGui::Checkbox("Aimbot", &Setting::Aimbot);
					if (Setting::Aimbot)
					{
						ImGui::TextColored(ImVec4(1.00f, 0.00f, 0.00f, 1.00f), "High Value -> Smooth Aimbot");
						ImGui::TextColored(ImVec4(0.15f, 0.57f, 0.07f, 1.00f), "Fov Recomended Always!");
						ImGui::SliderFloat("##AimbotSpeede", &Setting::Aimspeed, 1.0f, 15.0f);
						ImGui::Text("Aimbot Key :->");
						ImGui::SameLine();
						ImGui::Hotkey("##Aimbot1Key ", &Setting::AimbotKey, ImVec2(180.0f, 24));
					}
				}
			}
			if (Setting::I_HackInjectType != 2)
			{
				if (ImGui::CollapsingHeader(ICON_FA_MAGIC" MEMORY"))
				{
					if (ImGui::TreeNode("Normal Features"))
					{
						ImGui::Indent();

						ImGui::Checkbox("Magic Bullet", &Setting::MagicBullet);
						if (Setting::MagicBullet)
						{
							if (ImGui::TreeNode("Magic Settings"))
							{
								ImGui::Indent();
								ImGui::TextColored(ImVec4(0.15f, 0.57f, 0.07f, 1.00f), "Fov Recomended Always!");
								const char* aimb[] = { "Head", "Body", "Pelvis" };
								const char* combo_label = aimb[Setting::curraim];

								if (ImGui::BeginCombo("AimcPositon", combo_label, ImGuiComboFlags_HeightSmall))
								{
									for (int n = 0; n < IM_ARRAYSIZE(aimb); n++)
									{
										const bool is_selected = (Setting::curraim == n);
										if (ImGui::Selectable(aimb[n], is_selected))
											Setting::curraim = n;
										if (is_selected)
											ImGui::SetItemDefaultFocus();
									}


									ImGui::EndCombo();
								}
								ImGui::SameLine();
								ImGui::Hotkey("##Change Magic Bullet  Position", &Setting::MagicPositionKey, ImVec2(100, 25));

								ImGui::Checkbox("Skip Knock", &Setting::knocked);
								ImGui::Checkbox("Skip Bot", &Setting::SkipBots);

								ImGui::Spacing();
								ImGui::TextColored(ImVec4(0.15f, 0.57f, 0.07f, 1.00f), "T - Change Position");
								ImGui::Checkbox("Mix Tracking", &Setting::magicAutoLocation);
								ImGui::Spacing();
								ImGui::Text("Magic Fire Key :->");
								ImGui::Hotkey("##Magic Bullet", &Setting::AimbotKey, ImVec2(100, 25));
								ImGui::TreePop();
							}
						}
						ImGui::Checkbox("IpadView", &Setting::IpadView);

						if (Setting::IpadView)
						{
							ImGui::SliderFloat("Ipad", &Setting::Ipad, 200.0f, 660.0f);
						}
						ImGui::TreePop();
					}

					if (Setting::I_HackInjectType == 1)
					{
						if (ImGui::TreeNode("Brutal Features"))
						{
							ImGui::Indent();
							ImGui::Checkbox("Instant Hit", &Setting::instanthit);
							ImGui::Checkbox("Brutal Magic", &Setting::Magic360deg);
							ImGui::TreePop();
						}
					}

				}
			}

			if (ImGui::CollapsingHeader(ICON_FA_COGS" SETTINGS"))
			{
				if (ImGui::Button("Save Config", { 185.f, 25.f }))
				{
					_config.WriteConfiguratiton("C:\\Windows\\NexusConfig.ini");
				}
				ImGui::SameLine();
				if (ImGui::Button("Load Config", { 185.f, 25.f }))
				{
					_config.LoadConfiguratiton("C:\\Windows\\NexusConfig.ini");
				}
				if (ImGui::Button("Unload"))
				{
					Setting::MagicBullet = false;
					system("netsh advfirewall reset");
					system("sc stop Nexus");
					system("sc delete Nexus");
					exit(0);
				}
			}

			//ImGuiNoti::RenderNotifications();
		}
	}

};