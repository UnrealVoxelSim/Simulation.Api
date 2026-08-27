#pragma once

#include "UnrealVoxelSim/Simulation/Api/StepError.h"
#include "UnrealVoxelSim/Simulation/Api/TickCount.h"
#include "UnrealVoxelSim/Simulation/Api/TickIndex.h"

#include <expected>

namespace UnrealVoxelSim::Simulation::Api
{
	class IStepper
	{
	public:
		virtual ~IStepper() = default;

		[[nodiscard]] virtual TickIndex CurrentTick() const noexcept = 0;
		[[nodiscard]] virtual std::expected<void, StepError> Step(TickCount count) = 0;
	};
} // namespace UnrealVoxelSim::Simulation::Api
