#ifndef _H_COMMAND
#define _H_COMMAND

#include <string>
#include <vector>
#include "statements.h"

class Command
{
	std::string m_raw;				/* temporary raw-buffer */
	std::vector<std::string> m_cmd;	/* buffer
									   [0] - command name
									   [1,2..] - arguments */
public:
	std::string get(int = 0);		// get a cmd from user
	std::string getBuffer(int = 0);	// get a cmd/args from buffer
private:
	std::string filter();			/* cuts and adjust the first
									   word from raw-buffer */
};


#endif