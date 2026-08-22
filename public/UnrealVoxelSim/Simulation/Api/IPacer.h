#pragma once

#include "UnrealVoxelSim/Simulation/Api/AdvanceError.h"
#include "UnrealVoxelSim/Simulation/Api/AdvanceResult.h"
#include "UnrealVoxelSim/Simulation/Api/Rate.h"
#include "UnrealVoxelSim/Simulation/Api/TickCount.h"

#include <chrono>
#include <expected>

namespace UnrealVoxelSim::Simulation::Api
{

class IPacer
{
  public:
    virtual ~IPacer() = default;

    [[nodiscard]] virtual Rate CurrentRate() const noexcept = 0;
    virtual void SetRate(Rate rate) noexcept = 0;
    [[nodiscard]] virtual std::expected<AdvanceResult, AdvanceError> Advance(std::chrono::nanoseconds elapsed,
                                                                            TickCount maximumTicks) = 0;
};

} // namespace UnrealVoxelSim::Simulation::Api
