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

		explicit constexpr StepDuration(const std::chrono::nanoseconds value) noexcept : m_Value(value)
		{
		}

		[[nodiscard]] constexpr bool IsValid() const noexcept
		{
			return m_Value.count() > 0;
		}

		[[nodiscard]] constexpr std::chrono::nanoseconds Value() const noexcept
		{
			return m_Value;
		}

		auto operator<=>(const StepDuration&) const = default;

	private:
		std::chrono::nanoseconds m_Value{};
	};

	inline constexpr StepDuration StandardStepDuration{std::chrono::milliseconds{20}};

	static_assert(StandardStepDuration.Value() == std::chrono::nanoseconds{20'000'000});
} // namespace UnrealVoxelSim::Simulation::Api
