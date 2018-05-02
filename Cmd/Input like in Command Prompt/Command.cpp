#include <vector>
#include <cctype>
#include <string>
#include <iostream>
#include "headers/Command.h"

std::string Command::get(int arg)
{
	m_cmd.clear();

	std::cout << CMD_START;
	getline(std::cin, m_raw);
	
	while (!std::cin)
	{
		std::cout << ERR_INPUT;
		std::cin.clear();
		while (std::cin.get() != '\n');
		
		std::cout << CMD_START;
		getline(std::cin, m_raw);		
	}
	
	while ( !m_raw.empty() )
		m_cmd.push_back( filter() );

	return getBuffer(arg);
}

std::string Command::getBuffer(int arg)
{
	if (m_cmd.size() > arg)
		return m_cmd[arg];
	else return "";
}

std::string Command::filter()
{
	if ( ! m_raw.empty() )
	{
		for (int i = 0; i < m_raw.length(); ++i)
		{
			if (isblank(m_raw[i])) continue;
			else
			{
				int j;
				for (j = i; j < m_raw.length(); ++j)
					if (isblank(m_raw[j])) break;
				
				std::string temp = m_raw.substr(i,j-i);
				m_raw.erase(0,j);

				for (int k = 0; k < temp.size(); ++k)
					temp[k] = tolower( temp[k] );

				return temp;
			}
		}
	}
	else return "";
}