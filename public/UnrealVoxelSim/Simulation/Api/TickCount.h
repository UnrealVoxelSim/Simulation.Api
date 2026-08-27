#pragma once

#include <compare>
#include <cstdint>

namespace UnrealVoxelSim::Simulation::Api
{
	class TickCount final
	{
	public:
		constexpr TickCount() noexcept = default;

		explicit constexpr TickCount(const std::uint64_t value) noexcept : m_Value(value)
		{
		}

		[[nodiscard]] constexpr std::uint64_t Value() const noexcept
		{
			return m_Value;
		}

		auto operator<=>(const TickCount&) const = default;

	private:
		std::uint64_t m_Value{};
	};
}
