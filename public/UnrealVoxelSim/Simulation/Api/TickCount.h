#pragma once

#include <compare>
#include <cstdint>

namespace UnrealVoxelSim::Simulation::Api
{

class TickCount final
{
  public:
    constexpr TickCount() noexcept = default;
    explicit constexpr TickCount(const std::uint64_t value) noexcept : Value_(value)
    {
    }

    [[nodiscard]] constexpr std::uint64_t Value() const noexcept
    {
        return Value_;
    }

    auto operator<=>(const TickCount &) const = default;

  private:
    std::uint64_t Value_{};
};

} // namespace UnrealVoxelSim::Simulation::Api
