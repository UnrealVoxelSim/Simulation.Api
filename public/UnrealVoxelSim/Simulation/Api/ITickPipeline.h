#pragma once

#include "UnrealVoxelSim/Simulation/Api/StepContext.h"

namespace UnrealVoxelSim::Simulation::Api
{
	// Internal implementation seam between the fixed-step controller and an ordered participant pipeline.
	// Application and domain callers receive IStepper/IPacer or domain capabilities, not this interface.
	class ITickPipeline
	{
	public:
		virtual ~ITickPipeline() = default;
		virtual void Step(StepContext context) = 0;
	};
}
