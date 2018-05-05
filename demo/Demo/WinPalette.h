#pragma once

#include <Windows.h>
#include <array>
#include "Palette.h"
#include "Color.h"

namespace display
{
	namespace winapi
	{
		class WinPalette
			: public Palette
		{
		public:
			static const unsigned int Palette_size = 16;

			WinPalette();
			WinPalette(const std::array<Color, Palette_size> & colors);

			// derived from Palette
			virtual void SetColor(const Color & new_color, int index);
			virtual const Color & GetColor(int index) const;
			virtual void Apply();

			void SetColors(std::array<Color, Palette_size> colors);
			const std::array<Color, Palette_size> & GetColors();

		private:
			std::array<Color, Palette_size> colors_;
		};
	}
}