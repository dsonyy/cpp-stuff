#include "Palette16.h"

const Color & Palette16::GetColor(size_t index) const
{
	if (index >= colors_.size())
	{
		throw;
	}
	return colors_[index];
}

void Palette16::SetColor(size_t index, const Color & new_color)
{
	if (index >= colors_.size())
	{
		throw;
	}

	colors_[index] = new_color;
}
