#pragma once

#include "UnrealVoxelSim/Simulation/Api/CommandSourceId.h"
#include "UnrealVoxelSim/Simulation/Api/TickIndex.h"

#include <compare>
#include <cstdint>

namespace UnrealVoxelSim::Simulation::Api
{
	// TODO Potential cross-domain semantics leak. Simulation API has nothing to do with the concept of Commands. Usage pattern of this struct supports it: it is used by other modules, but not in Simulation domain itself.
	struct CommandStamp final
	{
		TickIndex TargetTick;
		CommandSourceId Source;
		std::uint64_t SourceSequence{};

		[[nodiscard]] constexpr bool IsValid() const noexcept { return Source.IsValid() && SourceSequence != 0; }
		auto operator<=>(const CommandStamp&) const = default;
	};
} // namespace UnrealVoxelSim::Simulation::Api
