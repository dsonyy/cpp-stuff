#pragma once

#include <string>
#include "CharEx.h"

class StringEx
{
public:
	virtual explicit operator std::string() = 0;
	virtual CharEx operator[](size_t index) = 0;
	virtual size_t GetSize() const = 0;

};

