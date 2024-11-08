#pragma once

#include "Includes.h"

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGui/imgui_internal.h"

namespace Emulator
{
	extern bool IsGameLoop;
	extern bool IsGameLoop7;
}

namespace Game
{
	extern INT Id;
	extern HANDLE hProcess;
	extern HWND EmulatorWnd;
}

namespace Thread
{
	extern HANDLE hQueryThread;
	extern HANDLE hEspThread;
	extern HANDLE Target;
	extern HANDLE hMemoryThread;
	extern HANDLE hInstThread;
	extern HANDLE hAimbotThread;
	extern HANDLE InstantThread;
}