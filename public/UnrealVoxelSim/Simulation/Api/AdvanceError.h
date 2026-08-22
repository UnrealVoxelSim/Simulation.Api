#pragma once

namespace UnrealVoxelSim::Simulation::Api
{

enum class AdvanceError
{
    NegativeElapsedTime,
    AccumulatorOverflow,
    TickOverflow,
};

} // namespace UnrealVoxelSim::Simulation::Api
