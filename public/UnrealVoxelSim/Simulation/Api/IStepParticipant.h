#pragma once

#include "UnrealVoxelSim/Simulation/Api/StepContext.h"

namespace UnrealVoxelSim::Simulation::Api
{
	class IStepParticipant
	{
	public:
		virtual ~IStepParticipant() = default;
		virtual void Step(StepContext context) = 0;
	};
}
