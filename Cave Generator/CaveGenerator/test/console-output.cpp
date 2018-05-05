
#include <iostream>
#include <curses.h>
#include <initializer_list>
#include <cstdarg>
#include "console-output.h"

#define COLOR_INTENSITY 8

ConsoleOutput::ConsoleOutput()
{

	initscr();
	if (has_colors())
	{
		start_color();

		init_pair(Gray, COLOR_WHITE, COLOR_BLACK);
		init_pair(White, COLOR_WHITE | COLOR_INTENSITY, COLOR_BLACK);

		init_pair(Red, COLOR_RED | COLOR_INTENSITY, COLOR_BLACK);
		init_pair(Green, COLOR_GREEN | COLOR_INTENSITY, COLOR_BLACK);
		init_pair(Blue, COLOR_BLUE | COLOR_INTENSITY, COLOR_BLACK);

		init_pair(Magenta, COLOR_BLUE | COLOR_RED | COLOR_INTENSITY, COLOR_BLACK);
		init_pair(Yellow, COLOR_GREEN | COLOR_RED | COLOR_INTENSITY, COLOR_BLACK);
		init_pair(Cyan, COLOR_BLUE | COLOR_GREEN |COLOR_INTENSITY, COLOR_BLACK);
	}
	scroll(stdscr);
	scrollok(stdscr, TRUE);

}


ConsoleOutput::~ConsoleOutput()
{
	endwin();
}


void ConsoleOutput::WritePrefix(
	MessageType type) const
{
	switch (type)
	{
	case None:
		break;
	case Info:
		printw("[  i  ] ");
		break;

	case Warning:
		printw("[");
		attron(COLOR_PAIR(chtype(Yellow)));
		printw(" WAR ");
		attroff(COLOR_PAIR(chtype(Yellow)));
		printw("] ");
		break;

	case Error:
		printw("[");
		attron(COLOR_PAIR(chtype(Red)));
		printw("ERROR");
		attroff(COLOR_PAIR(chtype(Red)));
		printw("] ");
		break;
	}
}

void ConsoleOutput::SwitchColors(
	char char_color) const
{
	if (has_colors())
	{
		switch (char_color)
		{
		case 'D': attron(COLOR_PAIR(chtype(Gray)));		break;
		case 'W': attron(COLOR_PAIR(chtype(White)));	break;

		case 'R': attron(COLOR_PAIR(chtype(Red)));		break;
		case 'G': attron(COLOR_PAIR(chtype(Green)));	break;
		case 'B': attron(COLOR_PAIR(chtype(Blue)));		break;

		case 'M': attron(COLOR_PAIR(chtype(Magenta)));	break;
		case 'Y': attron(COLOR_PAIR(chtype(Yellow)));	break;
		case 'C': attron(COLOR_PAIR(chtype(Cyan)));		break;
		}
	}
}

void ConsoleOutput::Write(
	MessageType type,
	const char * str,
	...) const
{
	va_list parameters;
	va_start(parameters, str);
	int argc = 0;
	int i = 0;

	WritePrefix(type);

	while (str[i] != '\0')
	{
		if (str[i] != '#')
		{
			addch(str[i]);
			++i;
			continue;
		}
		
		switch (str[i + 1])
		{
		case 's':  printw("%s", va_arg(parameters, char*)); break;
		case 'i':  printw("%i", va_arg(parameters, int));	break;
		case '#':  addch('#'); break;
		}

		SwitchColors(str[i + 1]);
		i += 2;
	}

	refresh();
	va_end(parameters);
}


#undef COLOR_INTENSITY
