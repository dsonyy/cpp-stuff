#include <string>
#include <vector>
#include "WinStringEx.h"

using display::winapi::WinStringEx;
using display::CharEx;

void WinStringEx::Set(const std::vector<CharEx> & new_content)
{
	content_ = new_content;
}

void WinStringEx::Set(const std::wstring & new_content, int backgroud_index, int foreground_index)
{
	content_.clear();
	for (int i = 0; i < content_.size(); ++i)
	{
		content_.push_back({ new_content[i], backgroud_index, foreground_index });
	}
}

CharEx WinStringEx::GetCharEx(int index)
{
	if (index < 0 || index > content_.size() - 1)
	{
		throw;
	}

	return content_[index];
}

const std::vector<CharEx> & WinStringEx::GetCharExVector()
{
	return content_;
}
