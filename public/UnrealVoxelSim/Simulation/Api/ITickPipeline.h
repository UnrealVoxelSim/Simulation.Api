#pragma once

#include "UnrealVoxelSim/Simulation/Api/StepContext.h"

namespace UnrealVoxelSim::Simulation::Api
{

class ITickPipeline
{
  public:
    virtual ~ITickPipeline() = default;
    virtual void Step(StepContext context) = 0;
};

} // namespace UnrealVoxelSim::Simulation::Api
