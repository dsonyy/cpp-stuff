#pragma once

#include <string>
#include "CharEx.h"
#include "StringEx.h"

class SingleColorString
	: public StringEx
{
public:
	SingleColorString();
	SingleColorString(const std::string & text);
	SingleColorString(const std::string & text, const ColorAttributes & attributes);
	SingleColorString(const std::string & text, int background_color_index, int foreground_color_index);

	void SetText(const std::string & text);
	void SetColorAttributes(const ColorAttributes & attributes);
	void SetColorAttributes(int background_color_index, int foreground_color_index);

	const std::string & GetText();
	char GetChar(size_t index) const;
	CharEx GetCharEx(size_t index) const;
	ColorAttributes GetColorAttributes() const;
	int GetForegroundColorIndex() const;
	int GetBackgroundColorIndex() const;


	// ---- derived from StringEx
	virtual size_t GetSize() const;
	virtual explicit operator std::string();
	virtual CharEx operator[](size_t index);


private:
	ColorAttributes attributes_;
	std::string		string_;
};

