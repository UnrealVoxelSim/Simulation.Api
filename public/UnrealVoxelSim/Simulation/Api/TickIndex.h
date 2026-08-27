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
    explicit constexpr TickIndex(const std::uint64_t value) noexcept : m_Value(value)
    {
    }

    [[nodiscard]] constexpr std::uint64_t Value() const noexcept
    {
        return m_Value;
    }

    [[nodiscard]] constexpr bool CanAdvance() const noexcept
    {
        return m_Value != std::numeric_limits<std::uint64_t>::max();
    }

    constexpr void Advance() noexcept
    {
        ++m_Value;
    }

    auto operator<=>(const TickIndex &) const = default;

  private:
    std::uint64_t m_Value{};
};

} // namespace UnrealVoxelSim::Simulation::Api
