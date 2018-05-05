#pragma once

#include <array>
#include "BasicPalette.h"

class Palette16
	: public BasicPalette
{
public:
	// derived from BasicPalette
	virtual const Color &	GetColor(size_t index) const;
	virtual void			SetColor(size_t index, const Color & new_color);

	static const size_t Colors_Number = 0;

private:
	std::array<Color, Colors_Number> colors_;
};
