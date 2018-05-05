#pragma once

#include "StringEx.h"


class WriteController
{
public:
	virtual void Write(const StringEx & string_to_write) const = 0;
	virtual void Write(const StringEx & string_to_write, int x, int y) const = 0;
	virtual void Write(const CharEx & char_to_write) const = 0;
	virtual void Write(const CharEx & char_to_write, int x, int y) const = 0;

};
