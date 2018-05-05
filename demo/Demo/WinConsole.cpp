#include <Windows.h>
#include "WinConsole.h"
#include "Palette.h"
#include "StringEx.h"
#include "CharEx.h"
#include <wchar.h>

using display::winapi::WinConsole;
using display::Palette;

WinConsole::WinConsole()
{}


WinConsole::WinConsole(int width, int height)
{
	Init(width, height);
}

void WinConsole::Init(int width, int height)
{
	if (width < SM_CXMIN)
	{
		throw;
	}

	if (width > GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE)).X)
	{
		throw;
	}

	if (height < SM_CYMIN)
	{
		throw;
	}

	if (height > GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE)).Y)
	{
		throw;
	}

	width_ = static_cast<SHORT>(width);
	height_ = static_cast<SHORT>(height);
	window_size_ = { 0, 0, width_ - 1, height_ - 1 };
	window_write_area = { 0, 0, width_ - 1, height_ - 1 };
	buffer_size_ = { width_, height_ };
	buffer_position_ = { 0, 0 };

	buffer_ = new CHAR_INFO*[height_];
	for (int y = 0; y < height_; ++y)
	{
		buffer_[y] = new CHAR_INFO[width_];
		for (int x = 0; x < width_; ++x)
		{
			buffer_[y][x].Char.AsciiChar = '\0';
			buffer_[y][x].Attributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
		}
	}


	if (!SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &window_size_))
	{
		int x = GetLastError();
		throw;
	}

	if (!SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), buffer_size_))
	{
		int x = GetLastError();
		throw;
	}
}

void WinConsole::SetCursorMode(cursor_mode new_mode)
{

}

 void WinConsole::SetCursorPosition(int x, int y)
{

}

void WinConsole::Write(int x, int y, const CharEx & char_to_write)
{
	
}

void WinConsole::Write(int x, int y, const StringEx & text_to_write)
{

}

Palette WinConsole::GetCurrentPalette()
{
}

void WinConsole::SetCurrentPalette(const Palette & new_palette)
{

}
