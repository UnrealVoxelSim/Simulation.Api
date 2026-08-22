#include "UnrealVoxelSim/Simulation/Api/CommandStamp.h"
#include <gtest/gtest.h>

namespace UnrealVoxelSim::Simulation::Api
{
TEST(CommandStampTest, OrdersByTickThenSourceThenSequence)
{
    constexpr CommandStamp earlier{TickIndex{4}, CommandSourceId{9}, 20};
    constexpr CommandStamp laterTick{TickIndex{5}, CommandSourceId{1}, 1};
    constexpr CommandStamp laterSource{TickIndex{4}, CommandSourceId{10}, 1};
    constexpr CommandStamp laterSequence{TickIndex{4}, CommandSourceId{9}, 21};
    static_assert(earlier < laterTick);
    static_assert(earlier < laterSource);
    static_assert(earlier < laterSequence);
    EXPECT_TRUE(earlier.IsValid());
}
} // namespace UnrealVoxelSim::Simulation::Api
