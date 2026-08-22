#pragma once

#include <compare>
#include <cstdint>

namespace UnrealVoxelSim::Simulation::Api
{

class CommandSourceId final
{
  public:
    constexpr CommandSourceId() noexcept = default;
    explicit constexpr CommandSourceId(const std::uint32_t value) noexcept : Value_(value) {}
    [[nodiscard]] constexpr bool IsValid() const noexcept { return Value_ != 0; }
    [[nodiscard]] constexpr std::uint32_t Value() const noexcept { return Value_; }
    auto operator<=>(const CommandSourceId &) const = default;

  private:
    std::uint32_t Value_{};
};

} // namespace UnrealVoxelSim::Simulation::Api
