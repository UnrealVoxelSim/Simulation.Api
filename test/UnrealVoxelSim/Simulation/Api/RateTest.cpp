#include "UnrealVoxelSim/Simulation/Api/Rate.h"

#include <gtest/gtest.h>

namespace UnrealVoxelSim::Simulation::Api
{
namespace
{

TEST(RateTest, RejectsZeroDenominator)
{
    const auto result = Rate::Create(1, 0);

    ASSERT_FALSE(result);
    EXPECT_EQ(result.error(), RateError::ZeroDenominator);
}

TEST(RateTest, ReducesToCanonicalForm)
{
    const auto result = Rate::Create(50, 100);

    ASSERT_TRUE(result);
    EXPECT_EQ(result->Numerator(), 1U);
    EXPECT_EQ(result->Denominator(), 2U);
}

TEST(RateTest, RepresentsPauseCanonically)
{
    const auto result = Rate::Create(0, 100);

    ASSERT_TRUE(result);
    EXPECT_EQ(*result, PausedRate);
    EXPECT_TRUE(result->IsPaused());
}

}
}
