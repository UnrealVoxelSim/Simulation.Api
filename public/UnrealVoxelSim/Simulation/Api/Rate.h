#pragma once

#include "UnrealVoxelSim/Simulation/Api/RateError.h"

#include <compare>
#include <cstdint>
#include <expected>
#include <numeric>

namespace UnrealVoxelSim::Simulation::Api
{

class Rate final
{
  public:
    [[nodiscard]] static constexpr std::expected<Rate, RateError> Create(const std::uint32_t numerator,
                                                                         const std::uint32_t denominator) noexcept
    {
        if (denominator == 0)
        {
            return std::unexpected{RateError::ZeroDenominator};
        }
        const auto divisor = std::gcd(numerator, denominator);
        return Rate{numerator / divisor, denominator / divisor};
    }

    [[nodiscard]] constexpr std::uint32_t Numerator() const noexcept
    {
        return Numerator_;
    }

    [[nodiscard]] constexpr std::uint32_t Denominator() const noexcept
    {
        return Denominator_;
    }

    [[nodiscard]] constexpr bool IsPaused() const noexcept
    {
        return Numerator_ == 0;
    }

    auto operator<=>(const Rate &) const = default;

  private:
    constexpr Rate(const std::uint32_t numerator, const std::uint32_t denominator) noexcept
        : Numerator_(numerator), Denominator_(denominator)
    {
    }

    std::uint32_t Numerator_{};
    std::uint32_t Denominator_{1};
};

inline constexpr Rate PausedRate = *Rate::Create(0, 1);
inline constexpr Rate NormalRate = *Rate::Create(1, 1);

} // namespace UnrealVoxelSim::Simulation::Api
