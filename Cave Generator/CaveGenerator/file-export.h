#ifndef _H_FILE_EXPORT
#define _H_FILE_EXPORT

#include <string>
#include <fstream>
#include "level.h"

class FileExport
{
public:
	FileExport(std::string & file_name);
	~FileExport();

	void FileLevel(const Level & level_to_export) const;

private:
	std::ofstream file_;
};


#endif // !_H_FILE_EXPORT
