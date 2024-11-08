#include "DiscordR.h"
#include <time.h>
#include <chrono>
#include <Setting.h>
#include <Data.h>
static int64_t eptime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();


void DiscordR::Initialize()
{
	DiscordEventHandlers Handle;
	memset(&Handle, 0, sizeof(Handle));

	if (Setting::isAntiban) {
		Discord_Initialize("1077633828765585548", &Handle, 1, NULL);
	}
	else
	{
		Discord_Initialize("1077633828765585548", &Handle, 1, NULL);
	}

}

void DiscordR::Update()
{
	DiscordRichPresence	discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	std::string statee = "";
	statee.append("Kills : " + std::to_string(Data::PlayerTotalKills));

	discordPresence.state = statee.c_str();

	if (Data::LocalPawn == "InLobby")
	{
		discordPresence.details = "Waiting In Lobby";
	}

	else if (Data::LocalPawn == "InTDM")
	{
		discordPresence.details = "Playing TDM";
	}

	else if (Data::LocalPawn == "InLivik")
	{
		discordPresence.details = "Playing Livik";
	}

	else if (Data::LocalPawn == "InCheerPark")
	{
		discordPresence.details = "Playing CheerPark";
	}

	else if (Data::LocalPawn == "InMiramar")
	{
		discordPresence.details = "Playing Miramar";
	}

	else if (Data::LocalPawn == "InSanhok")
	{
		discordPresence.details = "Playing Sanhok";
	}

	else if (Data::LocalPawn == "InKarakin")
	{
		discordPresence.details = "Playing Karakin";
	}

	else if (Data::LocalPawn == "InDomination")
	{
		discordPresence.details = "Playing Domination";
	}

	else if (Data::LocalPawn == "InTraining")
	{
		discordPresence.details = "In Training Ground";
	}

	discordPresence.startTimestamp = eptime;
	discordPresence.largeImageKey = "https://media.tenor.com/dJ0Wknn8mEMAAAAC/nexus.gif";
	discordPresence.largeImageText = "@Brady";
	discordPresence.smallImageKey = "https://c.tenor.com/WQ67K3ynhV0AAAAd/verified.gif";
	Discord_UpdatePresence(&discordPresence);
}