#include "Color.h"
#include "Palette.h"

using display::Palette;
using display::Color;

Palette::Palette(size_t size)
{
	if (size < 0)
	{
		throw;
	}

	colors_.resize(size);
}

Palette::Palette(std::vector<Color> new_colors)
{
	Set(new_colors);
}

void Palette::SetColor(const Color & new_color, int index)
{
	if (index < 0 || index > colors_.size() - 1)
	{
		throw;
	}
	colors_[index] = new_color;
}

void Palette::Set(std::vector<Color> new_colors)
{
	colors_ = new_colors;
}

const Color & Palette::GetColor(int index) const
{
	if (index < 0 || index > colors_.size() - 1)
	{
		throw;
	}
	return colors_[index];
}

const std::vector<Color> & Palette::Get() const
{
	return colors_;
}

size_t Palette::GetSize() const
{
	return colors_.size();
}

const int  Palette::GetIntColor(int index) const
{
	if (index < 0 || index > colors_.size() - 1)
	{
		throw;
	}
	return (colors_[index].R) | (colors_[index].G << 8) | (colors_[index].B << 16);
}
