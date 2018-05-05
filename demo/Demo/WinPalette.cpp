#include "WinPalette.h"
#include "Color.h"

using display::winapi::WinPalette;
using display::Color;

WinPalette::WinPalette()
{
	CONSOLE_SCREEN_BUFFER_INFOEX buffer_infoex;
	buffer_infoex.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
	if (!GetConsoleScreenBufferInfoEx(GetStdHandle(STD_OUTPUT_HANDLE), &buffer_infoex))
	{
		int x = GetLastError();
		throw;
	}

	for (int i = 0; i < Palette_size; ++i)
	{
		colors_[i].R = GetRValue(buffer_infoex.ColorTable[i]);
		colors_[i].G = GetGValue(buffer_infoex.ColorTable[i]);
		colors_[i].B = GetBValue(buffer_infoex.ColorTable[i]);
	}
}

WinPalette::WinPalette(const std::array<Color, Palette_size> & colors)
{
	SetColors(colors);
}

void WinPalette::SetColor(const Color & new_color, int index)
{
	if (!(index < Palette_size))
	{
		throw;
	}

	colors_[index] = new_color;
}

const Color & WinPalette::GetColor(int index) const
{
	if (!(index < Palette_size))
	{
		throw;
	}

	return colors_[index];
}

void WinPalette::SetColors(std::array<Color, Palette_size> colors)
{
	colors_ = colors;
}

const std::array<Color, WinPalette::Palette_size> & WinPalette::GetColors()
{
	return colors_;
}

void WinPalette::Apply()
{
	CONSOLE_SCREEN_BUFFER_INFOEX buffer_infoex;
	buffer_infoex.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
	if (!GetConsoleScreenBufferInfoEx(GetStdHandle(STD_OUTPUT_HANDLE), &buffer_infoex))
	{
		throw;
	}

	// required to fix conhost bug with changing a window size
	buffer_infoex.srWindow.Right += 1;
	buffer_infoex.srWindow.Bottom += 1;

	for (int i = 0; i < Palette_size; ++i)
	{
		buffer_infoex.ColorTable[i] = (colors_[i].R) | (colors_[i].G << 8) | (colors_[i].B << 16);
	}

	if (!SetConsoleScreenBufferInfoEx(GetStdHandle(STD_OUTPUT_HANDLE), &buffer_infoex))
	{
		throw;
	}
}
