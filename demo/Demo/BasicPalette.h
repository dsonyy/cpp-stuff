#pragma once

#include "Color.h"

class BasicPalette
{
public:
	virtual const Color &	GetColor(size_t index) const = 0;
	virtual void			SetColor(size_t index, const Color & new_color) = 0;
};
