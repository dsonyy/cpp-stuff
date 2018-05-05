#pragma once

struct ColorAttributes
{
	int foreground_index = 0;
	int background_index = 0;
};

struct CharEx 
	: public ColorAttributes
{
	wchar_t symbol = 0;
};
