//
//#include "file-export.h"
//#include <filesystem>
//
//namespace file_system = std::experimental::filesystem;
//
//
//FileExport::FileExport(
//	const std::wstring & file_name)
//{
//	target_file_.open( "//elo//elo.txt", std::ios::out | std::ios::trunc);
//
//	if (!target_file_.good())
//	{
//		ERROR("Can not create level file.\n");
//		// throw an exception
//		return;
//	}
//
//	INFO("New level structure file created\n");
//}
//
//
//FileExport::~FileExport()
//{
//	if (!target_file_.is_open())
//	{
//		target_file_.close();
//	}
//}
//
//
//bool FileExport::ExportLevel(
//	Map2D const & map,
//	Point spawn,
//	Point exit,
//	int specimen,
//	int seed)
//{
//	if (!target_file_.is_open())
//	{
//		return false;
//	}
//
//	target_file_ << "filetype:\tlevel" << std::endl;
//	target_file_ << "spawn_x:\t" << spawn.x << std::endl;
//	target_file_ << "spawn_y:\t" << spawn.y << std::endl;
//	target_file_ << "exit_x:\t" << exit.x << std::endl;
//	target_file_ << "exit_y:\t" << exit.y << std::endl;
//	ExportExtraInfo(specimen, seed);
//	ExportContent(map);
//
//	INFO("Level data exported to file\n");
//	return true;
//
//}
//
//bool FileExport::ExportRoom(
//	const Map2D & map, 
//	const std::vector<Point> & doors, 
//	int specimen,
//	int seed)
//{
//	if (!target_file_.is_open())
//	{
//		return false;
//	}
//
//	target_file_ << "filetype:\troom" << std::endl;
//	ExportDoors(doors);
//	ExportExtraInfo(specimen, seed);
//	ExportContent(map);
//
//	INFO("Room data exported to file\n");
//	return true;
//}
//
//bool FileExport::ExportTunnel(
//	const Map2D & map,
//	const std::vector<Point> & doors,
//	int specimen,
//	int seed)
//{
//	if (!target_file_.is_open())
//	{
//		return false;
//	}
//
//	target_file_ << "filetype:\ttunnel" << std::endl;
//	ExportDoors(doors);
//	ExportExtraInfo(specimen, seed);
//	ExportContent(map);
//
//	INFO("Tunnel data exported to file\n");
//	return true;
//}
//
//
//
//void FileExport::ExportContent(
//	const Map2D & map)
//{
//	target_file_ << "height:\t" << map.size() << std::endl;
//	target_file_ << "width:\t" << map[0].size() << std::endl;
//
//	for (int y = 0; y < map.size(); ++y)
//	{
//		for (int x = 0; x < map[0].size(); ++x)
//		{
//			target_file_ << map[y][x];
//		}
//		target_file_ << std::endl;
//	}
//}
//
//void FileExport::ExportDoors(
//	const std::vector<Point> & doors)
//{
//	target_file_ << "doors:\t" << doors.size() << std::endl;
//	for (int i = 0; i < doors.size(); ++i)
//	{
//		target_file_ << "door" << i << "_width:\t" << doors[i].x << std::endl;
//		target_file_ << "door" << i << "_height:\t" << doors[i].y << std::endl;
//	}
//}
//
//void FileExport::ExportExtraInfo(
//	int specimen, 
//	int seed)
//{
//	if (seed >= 0)
//	{
//		target_file_ << "seed:\t" << seed << std::endl;
//	}
//
//	if (specimen >= 0)
//	{
//		target_file_ << "specimen:\t" << specimen << std::endl;
//	}
//}
