#pragma once

#include "Console.h"
#include "WinPalette.h"

namespace display
{
	namespace winapi
	{
		class WinConsole
			: public Console
		{
		public:
			WinConsole();
			WinConsole(int width, int height);

			// derived from Console
			virtual void Init(int width, int height);
			virtual void Write(int x, int y, const CharEx & char_to_write);

			virtual void SetCursorMode(cursor_mode new_mode);
			virtual void SetCursorPosition(int x, int y);

			virtual Palette GetCurrentPalette();
			virtual void SetCurrentPalette(const Palette & new_palette);

			virtual void Write(int x, int y, const CharEx & char_to_write);
			virtual void Write(int x, int y, const StringEx & text_to_write);


		private:

			SHORT width_;
			SHORT height_;
			SMALL_RECT window_size_;
			SMALL_RECT window_write_area;
			COORD buffer_size_;
			COORD buffer_position_;
			CHAR_INFO ** buffer_;
			WinPalette palette_;
		};
	}
}