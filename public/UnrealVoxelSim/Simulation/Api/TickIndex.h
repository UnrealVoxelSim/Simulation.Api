#pragma once

#include <compare>
#include <cstdint>
#include <limits>

namespace UnrealVoxelSim::Simulation::Api
{

class TickIndex final
{
  public:
    constexpr TickIndex() noexcept = default;
    explicit constexpr TickIndex(const std::uint64_t value) noexcept : Value_(value)
    {
    }

    [[nodiscard]] constexpr std::uint64_t Value() const noexcept
    {
        return Value_;
    }

    [[nodiscard]] constexpr bool CanAdvance() const noexcept
    {
        return Value_ != std::numeric_limits<std::uint64_t>::max();
    }

    constexpr void Advance() noexcept
    {
        ++Value_;
    }

    auto operator<=>(const TickIndex &) const = default;

  private:
    std::uint64_t Value_{};
};

} // namespace UnrealVoxelSim::Simulation::Api
