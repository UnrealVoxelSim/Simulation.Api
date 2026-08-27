#pragma once

#include "UnrealVoxelSim/Simulation/Api/StepContext.h"

namespace UnrealVoxelSim::Simulation::Api
{
	/* TODO The role of this interface as public Simulation API is unclear.
	*
	* IStepper already exposes the consumer-facing capability of advancing the simulation.
	* ITickPipeline instead appears to represent the internal mechanism used to execute a single
	* tick after StepContext has been constructed.
	*
	* If this abstraction exists to let Stepper delegate execution to an ordered set of simulation
	* phases/systems, it is a legitimate implementation seam, but probably should not be part of
	* Simulation.Api. Other domains should not need to know about or invoke the simulation pipeline
	* directly.
	*
	* Also reconsider whether an interface is needed at all: "TickPipeline" may simply be the
	* concrete internal orchestrator, while individual systems participate through the common
	* simulation step/phase contract.
	*/
	class ITickPipeline
	{
	public:
		virtual ~ITickPipeline() = default;
		virtual void Step(StepContext context) = 0;
	};
} // namespace UnrealVoxelSim::Simulation::Api
