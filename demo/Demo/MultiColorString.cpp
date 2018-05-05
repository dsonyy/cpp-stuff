#include "CharEx.h"
#include "MultiColorString.h"

MultiColorString::MultiColorString()
{
}

MultiColorString::MultiColorString(const std::string & text)
{
	string_.resize(text.size());
	for (int i = 0; i < text.size(); ++i)
	{
		string_[i].symbol = text[i];
	}
}

MultiColorString::MultiColorString(const std::string & text, const ColorAttributes & attributes)
{
	string_.resize(text.size());
	for (int i = 0; i < text.size(); ++i)
	{
		string_[i].symbol = text[i];
		string_[i].background_index = attributes.background_index;
		string_[i].foreground_index = attributes.foreground_index;
	}
}

MultiColorString::MultiColorString(const std::string & text, int background_color_index, int foreground_color_index)
{
	string_.resize(text.size());
	for (int i = 0; i < text.size(); ++i)
	{
		string_[i].symbol = text[i];
		string_[i].background_index = background_color_index;
		string_[i].foreground_index = foreground_color_index;
	}
}

MultiColorString::MultiColorString(const std::vector<CharEx> & text_ext)
{
	string_ = text_ext;
}

void MultiColorString::SetText(const std::string & text)
{
	string_.resize(text.size());
	for (int i = 0; i < text.size(); ++i)
	{
		string_[i].symbol = text[i];
	}
}

void MultiColorString::SetTextEx(const std::vector<CharEx> & text_ext)
{
	string_ = text_ext;
}

void MultiColorString::SetColorAttributes(const ColorAttributes & attributes)
{
	for (int i = 0; i < string_.size(); ++i)
	{
		string_[i].background_index = attributes.background_index;
		string_[i].foreground_index = attributes.foreground_index;
	}
}

void MultiColorString::SetColorAttributes(int background_color_index, int foreground_color_index)
{
	for (int i = 0; i < string_.size(); ++i)
	{
		string_[i].background_index = background_color_index;
		string_[i].foreground_index = foreground_color_index;
	}
}

std::string MultiColorString::GetText()
{
	std::string temp;
	temp.resize(string_.size());

	for (int i = 0; i < string_.size(); ++i)
	{
		temp[i] = string_[i].symbol;
	}

	return temp;
}

const std::vector<CharEx> & MultiColorString::GetTextEx()
{
	return string_;
}

char MultiColorString::GetChar(size_t index) const
{
	if (index >= string_.size())
	{
		throw;
	}

	return string_[index].symbol;
}

CharEx MultiColorString::GetCharEx(size_t index) const
{
	if (index >= string_.size())
	{
		throw;
	}

	return string_[index];
}

ColorAttributes MultiColorString::GetColorAttributes(size_t index) const
{
	if (index >= string_.size())
	{
		throw;
	}

	return { string_[index].background_index, string_[index].foreground_index };
}

int MultiColorString::GetForegroundColorIndex(size_t index) const
{
	if (index >= string_.size())
	{
		throw;
	}

	return string_[index].foreground_index;
}

int MultiColorString::GetBackgroundColorIndex(size_t index) const
{
	if (index >= string_.size())
	{
		throw;
	}

	return string_[index].background_index;
}

size_t MultiColorString::GetSize() const
{
	return string_.size();
}

MultiColorString::operator std::string()
{
	std::string temp;
	temp.resize(string_.size());

	for (int i = 0; i < string_.size(); ++i)
	{
		temp[i] = string_[i].symbol;
	}

	return temp;
}

CharEx MultiColorString::operator[](size_t index)
{
	if (index >= string_.size())
	{
		throw;
	}

	return string_[index];
}
