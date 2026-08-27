#pragma once

#include "StepContext.h"

namespace UnrealVoxelSim::Simulation::Api
{

class IDecisionUpdater
{
  public:
    virtual ~IDecisionUpdater() = default;
    virtual void UpdateDecisions(StepContext context) = 0;
};

} // namespace UnrealVoxelSim::Simulation::Api
