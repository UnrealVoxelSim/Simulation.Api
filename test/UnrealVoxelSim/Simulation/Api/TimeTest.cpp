#include "UnrealVoxelSim/Simulation/Api/StepDuration.h"
#include "UnrealVoxelSim/Simulation/Api/TickIndex.h"

#include <gtest/gtest.h>

#include <chrono>
#include <limits>

namespace UnrealVoxelSim::Simulation::Api
{
namespace
{

TEST(TimeTest, PublishesTwentyMillisecondStandardStep)
{
    EXPECT_TRUE(StandardStepDuration.IsValid());
    EXPECT_EQ(StandardStepDuration.Value(), std::chrono::milliseconds{20});
}

TEST(TimeTest, ReportsWhetherTickCanAdvance)
{
    EXPECT_TRUE(TickIndex{41}.CanAdvance());
    EXPECT_FALSE(TickIndex{std::numeric_limits<std::uint64_t>::max()}.CanAdvance());
}

} // namespace
} // namespace UnrealVoxelSim::Simulation::Api
