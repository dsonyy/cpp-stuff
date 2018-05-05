#pragma once

#include <vector>
#include <string>
#include "CharEx.h"
#include "StringEx.h"

class MultiColorString
	: public StringEx
{
public:
	MultiColorString();
	MultiColorString(const std::string & text);
	MultiColorString(const std::string & text, const ColorAttributes & attributes);
	MultiColorString(const std::string & text, int background_color_index, int foreground_color_index);
	MultiColorString(const std::vector<CharEx> & text_ext);

	void SetText(const std::string & text);
	void SetTextEx(const std::vector<CharEx> & text_ext);
	void SetColorAttributes(const ColorAttributes & attributes);
	void SetColorAttributes(int background_color_index, int foreground_color_index);

	std::string GetText();
	const std::vector<CharEx> & GetTextEx();
	char GetChar(size_t index) const;
	CharEx GetCharEx(size_t index) const;
	ColorAttributes GetColorAttributes(size_t index) const;
	int GetForegroundColorIndex(size_t index) const;
	int GetBackgroundColorIndex(size_t index) const;

	// ---- derived from StringEx
	virtual size_t GetSize() const;
	virtual explicit operator std::string();
	virtual CharEx operator[](size_t index);

private:
	std::vector<CharEx> string_;
};
