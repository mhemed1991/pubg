#pragma once

#include "Includes.h"
#include "Algorithm.h"
#include "Utility.h"
#include "Data.h"
#include "Esp.h"

namespace Memory
{
	extern bool IsMagicInitialized;
	int AimFindBestTarget();
	VOID RestoreHook();
	VECTOR2 GetMagicCoordinatesFov();
	VECTOR2 GetMagicCoordinates();
	VOID MemoryThread();
	VOID Instant();
}