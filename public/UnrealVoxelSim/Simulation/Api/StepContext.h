#pragma once

#include "UnrealVoxelSim/Simulation/Api/StepDuration.h"
#include "UnrealVoxelSim/Simulation/Api/TickIndex.h"

namespace UnrealVoxelSim::Simulation::Api
{
	struct StepContext final
	{
		TickIndex Tick;
		StepDuration Duration;
	};
}
