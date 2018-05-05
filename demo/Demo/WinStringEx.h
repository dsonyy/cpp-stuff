#pragma once

#include "StringEx.h"

namespace display
{
	namespace winapi
	{
		class WinStringEx
			: public StringEx
		{
		public:
			// derived from StringEx
			virtual void Set(const std::vector<CharEx> & new_content);
			virtual void Set(const std::wstring & new_content, int backgroud_index, int foreground_index);
			virtual CharEx GetCharEx(int index);
			virtual const std::vector<CharEx> & GetCharExVector();
		
		private:
			std::vector<CharEx> content_;
		};
	}
}