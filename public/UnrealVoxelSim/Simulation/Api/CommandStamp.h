#pragma once

#include "UnrealVoxelSim/Simulation/Api/CommandSourceId.h"
#include "UnrealVoxelSim/Simulation/Api/TickIndex.h"

#include <compare>
#include <cstdint>

namespace UnrealVoxelSim::Simulation::Api
{

struct CommandStamp final
{
    TickIndex TargetTick;
    CommandSourceId Source;
    std::uint64_t SourceSequence{};

    [[nodiscard]] constexpr bool IsValid() const noexcept { return Source.IsValid() && SourceSequence != 0; }
    auto operator<=>(const CommandStamp &) const = default;
};

} // namespace UnrealVoxelSim::Simulation::Api
