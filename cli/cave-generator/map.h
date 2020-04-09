#ifndef _H_MAP
#define	_H_MAP

#include <vector>

typedef char Block;
typedef std::vector<std::vector<Block>> BlockMap;
enum BlockType : char
{
	None		 = 'X',
	RoomFloor	 = '.',
	PathFloor	 = ',',
	Wall		 = '#',
	Stone		 = 'S',
	StoneCracked = 'C',
	StoneMossy	 = 'M',
	Gravel		 = 'G',
};

struct Point
{
	int x;
	int y;
};
typedef Point MapPoint;
typedef Point LevelPoint;

enum CornerName 
{
	top_left,
	top_right,
	bottom_left,
	bottom_right,
	total_corners,
};

struct Coords
{
	Point corner[total_corners];
};
typedef Coords MapCoords;
typedef Coords LevelCoords;


class Map
{
public:
	void Write() const;

	inline bool		Empty();
	inline void		SetBlock(Block block, unsigned local_x, unsigned local_y);
	inline int		GetHeight() const;
	inline int		GetWidth() const;
	inline Block    GetBlock(unsigned local_x, unsigned local_y) const;
	inline int		GetSpecimen() const;
	inline const BlockMap & GetBlockArray() const;

protected:
	int specimen_;
	BlockMap block_array_;

};

inline bool Map::Empty()
{
	if (block_array_.empty())
	{
		return true;
	}

	return false;
}

inline int Map::GetWidth() const
{
	if (block_array_.size() > 0)
	{
		return block_array_[0].size();
	}
	
	return 0;
}

inline int Map::GetHeight() const
{
	return block_array_.size();
}

inline Block Map::GetBlock(unsigned x, unsigned y) const
{
	if (x > block_array_[0].size() - 1 && y > block_array_.size() - 1)
	{
		// TODO: throw exception
	}
	return block_array_[y][x];
}

inline int Map::GetSpecimen() const
{
	return specimen_;
}

inline void	Map::SetBlock(Block block, unsigned x, unsigned y)
{
	if (x > block_array_[0].size() - 1 && y > block_array_.size() - 1)
	{
		// TODO: throw exception
	}

	block_array_[y][x] = block;
}

inline const BlockMap & Map::GetBlockArray() const
{
	return block_array_;
}

#endif // !_H_MAP
