#include "Global.h"

bool Emulator::IsGameLoop = false;
bool Emulator::IsGameLoop7 = false;


INT Game::Id = 0;
HANDLE Game::hProcess;
HWND Game::EmulatorWnd = 0;

HANDLE Thread::hQueryThread = 0;
HANDLE Thread::hEspThread = 0;
HANDLE Thread::Target = 0;
HANDLE Thread::hMemoryThread = 0;
HANDLE Thread::hInstThread = 0;
HANDLE Thread::hAimbotThread = 0;
HANDLE Thread::InstantThread = 0;
