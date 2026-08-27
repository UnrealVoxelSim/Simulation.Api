#pragma once

#include "UnrealVoxelSim/Simulation/Api/TickCount.h"

namespace UnrealVoxelSim::Simulation::Api
{
	struct AdvanceResult final
	{
		TickCount Executed;
		TickCount Pending;
	};
} // namespace UnrealVoxelSim::Simulation::Api
