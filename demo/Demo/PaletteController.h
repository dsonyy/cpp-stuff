#pragma once

#include "BasicPalette.h"

class PaletteController
{
public:
	virtual void SetCurrentPallete(const BasicPalette & palette) const = 0;
	virtual BasicPalette * GetCurrentPallete()
};
