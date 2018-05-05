#pragma once

#include <vector>
#include "Color.h"

namespace display
{
	class Palette
	{
	public:
		Palette(size_t size);
		Palette(std::vector<Color> new_colors);

		void SetColor(const Color & new_color, int index);
		void Set(std::vector<Color> new_colors);

		const Color & GetColor(int index) const;
		const int GetIntColor(int index) const;
		const std::vector<Color> & Get() const;
		size_t GetSize() const;

	private:
		std::vector<Color> colors_;
	};
}