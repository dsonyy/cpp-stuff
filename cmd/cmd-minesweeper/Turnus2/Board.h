#pragma once

#include <vector>
#include "Coord.h"

struct Block
{
	enum { BOMB = -1, EMPTY = 0 };

	int number = EMPTY;
	bool clicked = false;
	bool flag = false;
};

class Board
{
public:
	Board(const Coord & size, unsigned bombs);

	bool Click(const Coord & position, bool ignore_bombs = false);
	bool SpecialClick(const Coord & position);
	void EmptyClick(const Coord & position);

	void Board::Flag(const Coord & pos);
	void Board::Unflag(const Coord & pos);

	void Set(const Coord & position, int type);

	int GetSizeX() const { return size_.x; };
	int GetSizeY() const { return size_.y; };
	Coord GetSize() const { return size_; };

	bool ValidCoord(const Coord & pos) const;

	Block GetBlock(const Coord & position) const;

private:
	bool Generate(const Coord & size, unsigned bombs);
	int	 GenerateNumber(const Coord & position) const;
	void SetSize(const Coord & size);
	bool CheckCoord(const Coord & pos, bool ignore_bombs);
	void CheckEmptyCoord(const Coord & pos);
	bool CheckSpecialCoord(const Coord & pos);
	

	int seed_;
	Coord size_;
	Block ** body_;

};


