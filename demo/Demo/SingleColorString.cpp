#include <string>
#include "CharEx.h"
#include "SingleColorString.h"

SingleColorString::SingleColorString()
{
}

SingleColorString::SingleColorString(const std::string & text)
{
	string_ = text;
}

SingleColorString::SingleColorString(const std::string & text, const ColorAttributes & attributes)
{
	string_ = text;
	attributes_ = attributes;
}

SingleColorString::SingleColorString(const std::string & text, int background_color_index, int foreground_color_index)
{
	string_ = text;
	attributes_.background_index = background_color_index;
	attributes_.foreground_index = foreground_color_index;
}

void SingleColorString::SetText(const std::string & text)
{
	string_ = text;
}

void SingleColorString::SetColorAttributes(const ColorAttributes & attributes)
{
	attributes_ = attributes;
}

void SingleColorString::SetColorAttributes(int background_color_index, int foreground_color_index)
{
	attributes_.background_index = background_color_index;
	attributes_.foreground_index = foreground_color_index;
}

const std::string & SingleColorString::GetText()
{
	return string_;
}

char SingleColorString::GetChar(size_t index) const
{
	if (index >= string_.size())
	{
		throw;
	}
	return string_[index];
}

CharEx SingleColorString::GetCharEx(size_t index) const
{
	if (index >= string_.size())
	{
		throw;
	}

	CharEx temp;
	temp.background_index = attributes_.background_index;
	temp.foreground_index = attributes_.foreground_index;
	temp.symbol = string_[index];

	return temp;
}

ColorAttributes SingleColorString::GetColorAttributes() const
{
	return attributes_;
}

int SingleColorString::GetForegroundColorIndex() const
{
	return attributes_.foreground_index;
}

int SingleColorString::GetBackgroundColorIndex() const
{
	return attributes_.background_index;
}

size_t SingleColorString::GetSize() const
{
	return string_.size();
}

SingleColorString::operator std::string()
{
	return string_;
}

CharEx SingleColorString::operator[](size_t index)
{
	if (index >= string_.size())
	{
		throw;
	}

	CharEx temp;
	temp.background_index = attributes_.background_index;
	temp.foreground_index = attributes_.foreground_index;
	temp.symbol = string_[index];

	return temp;
}
