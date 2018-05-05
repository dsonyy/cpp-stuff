#pragma once

#include <array>
#include "CharEx.h"
#include "StringEx.h"

namespace display
{
	class Console
	{
	public:
		enum cursor_mode { HIDE, SMALL, MEDIUM, LARGE };

		virtual void Init(int width, int height) = 0;
		
		virtual void SetCursorMode(cursor_mode new_mode) = 0;
		virtual void SetCursorPosition(int x, int y) = 0;
	
		virtual Palette GetCurrentPalette() = 0;
		virtual void SetCurrentPalette(const Palette & new_palette) = 0;

		virtual void Write(int x, int y, const CharEx & char_to_write) = 0;
		virtual void Write(int x, int y, const StringEx & text_to_write) = 0;

	};
}
