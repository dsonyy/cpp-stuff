#ifndef _H_MAP_STRUCTURE
#define	_H_MAP_STRUCTURE


#include <vector>
#include "functions.h"

typedef char Block;
typedef std::vector<std::vector<Block>> BlockMap;

enum BlockType : char
{
	None			= 'X',
	RoomFloor		= '.',
	PathFloor		= ',',
	Wall			= '#',
	Stone			= 'S',
	StoneCracked	= 'C',
	StoneMossy		= 'M',
	Gravel			= 'G',
};

struct ID
{
	int seed = -1;
	int specimen = -1;
};


class Map
{
public:
	void Write(ID id) const;

	inline void		SetBlock(Block block, unsigned local_x, unsigned local_y);
	inline int		GetHeight() const;
	inline int		GetWidth() const;
	inline Block    GetBlock(unsigned local_x, unsigned local_y) const;
	inline ID		GetID() const;

protected:
	ID id_;
	BlockMap map_;

};



inline int Map::GetWidth() const
{
	return map_[0].size();
}

inline int Map::GetHeight() const
{
	return map_.size();
}

inline Block Map::GetBlock(unsigned x, unsigned y) const
{
	if (x > map_[0].size() - 1 && y > map_.size() - 1)
	{
		// TODO: throw exception
	}
	return map_[y][x];
}

inline ID Map::GetID() const
{
	return id_;
}

inline void	Map::SetBlock(Block block, unsigned x, unsigned y)
{
	if (x > map_[0].size() - 1 && y > map_.size() - 1)
	{
		// TODO: throw exception
	}

	map_[y][x] = block;
}


#endif // !_H_MAP_STRUCTURE
