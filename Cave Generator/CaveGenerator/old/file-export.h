//#ifndef _H_EXPORT
//#define _H_EXPORT
//
//
//#include "headers.h"
//#include "level-structure.h"
//
//
//class FileExport
//{
//public:
//	FileExport(const std::wstring & file_name);
//	~FileExport();
//
//	bool ExportLevel(const Map2D & map, 
//		Point spawn, 
//		Point exit, 
//		int specimen = -1, 
//		int seed = -1
//	);
//	bool ExportRoom(
//		const Map2D & map, 
//		const std::vector<Point> & doors,
//		int specimen = -1, 
//		int seed = -1
//	);
//	bool ExportTunnel(
//		const Map2D & map, 
//		const std::vector<Point> & doors, 
//		int specimen = -1, 
//		int seed = -1
//	);
//
//private:
//	void ExportContent(const Map2D & map);
//	void ExportDoors(const std::vector<Point> & doors);
//	void ExportExtraInfo(int specimen, int seed);
//
//	std::ofstream * target_file_;
//};
//
//
//#endif // !_H_EXPORT
