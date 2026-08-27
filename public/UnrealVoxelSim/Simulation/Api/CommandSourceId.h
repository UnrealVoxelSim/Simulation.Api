#pragma once

#include <compare>
#include <cstdint>

namespace UnrealVoxelSim::Simulation::Api
{

class CommandSourceId final
{
  public:
    constexpr CommandSourceId() noexcept = default;
    explicit constexpr CommandSourceId(const std::uint32_t value) noexcept : m_Value(value) {}
    [[nodiscard]] constexpr bool IsValid() const noexcept { return m_Value != 0; }
    [[nodiscard]] constexpr std::uint32_t Value() const noexcept { return m_Value; }
    auto operator<=>(const CommandSourceId &) const = default;

  private:
    std::uint32_t m_Value{};
};

} // namespace UnrealVoxelSim::Simulation::Api
