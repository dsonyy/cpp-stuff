#ifndef _H_CONSOLE_OUTPUT
#define _H_CONSOLE_OUTPUT

#include <iostream>
#include <curses.h>
#include <initializer_list>

class ConsoleOutput
{
public:
	enum MessageType
	{
		None, Info, Warning, Error
	};

	ConsoleOutput();
	~ConsoleOutput();

	void Write(MessageType type, const char * str, ...) const;

private:
	enum ColorPair : short
	{
		Red = 1, Green, Blue,
		Magenta, Yellow, Cyan,
		White, Gray
	};

	void WritePrefix(MessageType type) const;
	void SwitchColors(char char_color) const;
};




#endif // !_H_CONSOLE_OUTPUT
