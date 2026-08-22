#pragma once

#include <chrono>
#include <compare>
#include <cstdint>

namespace UnrealVoxelSim::Simulation::Api
{

class StepDuration final
{
  public:
    constexpr StepDuration() noexcept = default;
    explicit constexpr StepDuration(const std::chrono::nanoseconds value) noexcept : Value_(value)
    {
    }

    [[nodiscard]] constexpr bool IsValid() const noexcept
    {
        return Value_.count() > 0;
    }

    [[nodiscard]] constexpr std::chrono::nanoseconds Value() const noexcept
    {
        return Value_;
    }

    auto operator<=>(const StepDuration &) const = default;

  private:
    std::chrono::nanoseconds Value_{};
};

inline constexpr StepDuration StandardStepDuration{std::chrono::milliseconds{20}};

static_assert(StandardStepDuration.Value() == std::chrono::nanoseconds{20'000'000});

} // namespace UnrealVoxelSim::Simulation::Api
