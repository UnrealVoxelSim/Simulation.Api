#pragma once

#include "StepContext.h"

namespace UnrealVoxelSim::Simulation::Api
{
	/* TODO The semantics and ownership of this interface are unclear.
	*
	* "Decision" is not a Simulation domain concept by itself. The interface does not define
	* what decisions are being made, which subsystem owns them, or what observable capability
	* UpdateDecisions provides to a consumer.
	*
	* It appears to exist primarily so the simulation pipeline can invoke some decision-making
	* implementation once per step. If so, this is another lifecycle hook rather than a meaningful
	* domain API.
	*
	* The subsystem that actually owns decision-making should expose its domain concepts separately.
	* If its implementation requires periodic simulation work, it should participate in the
	* simulation-owned step/phase mechanism instead of introducing a specialized updater interface.
	*
	* Also clarify execution-order requirements: if decisions must run before navigation, movement,
	* or other phases, that ordering belongs to the simulation execution model rather than being
	* implicit in this interface.
	*/
	class IDecisionUpdater
	{
	public:
		virtual ~IDecisionUpdater() = default;
		virtual void UpdateDecisions(StepContext context) = 0;
	};
} // namespace UnrealVoxelSim::Simulation::Api
