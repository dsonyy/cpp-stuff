#include <cstdlib>
#include <iostream>
#include "Board.h"
#include "Player.h"


Board::Board(const Coord & size, unsigned bombs)
{
	seed_ = 100;
	SetSize(size);
	Generate(size, bombs);
}


bool Board::Click(const Coord & position, bool ignore_bombs)
{
	if (CheckCoord({ position.x, position.y }, ignore_bombs))
		return true;
	
	return false;
}

void Board::Flag(const Coord & pos)
{
	body_[pos.y][pos.x].flag = true;
}

void Board::Unflag(const Coord & pos)
{
	body_[pos.y][pos.x].flag = false;
}

void Board::EmptyClick(const Coord & position)
{
	CheckEmptyCoord({ position.x, position.y - 1 });
	CheckEmptyCoord({ position.x, position.y + 1 });
	CheckEmptyCoord({ position.x - 1, position.y });
	CheckEmptyCoord({ position.x + 1, position.y });
	CheckEmptyCoord({ position.x - 1, position.y - 1 });
	CheckEmptyCoord({ position.x + 1, position.y + 1 });
	CheckEmptyCoord({ position.x - 1, position.y + 1 });
	CheckEmptyCoord({ position.x + 1, position.y - 1 });
}

bool Board::ValidCoord(const Coord & pos) const
{
	if (pos.x >= 0 && pos.y >= 0 && pos.x < size_.x && pos.y < size_.y)
	{
		return true;
	}

	return false;
}

bool Board::SpecialClick(const Coord & pos)
{
	bool alive = true;

	if (body_[pos.y][pos.x].clicked)
	{
		int bombs_around = body_[pos.y][pos.x].number;

		if (ValidCoord({pos.x ,pos.y - 1}) && body_[pos.y - 1][pos.x].flag == true) bombs_around--;
		if (ValidCoord({pos.x,pos.y + 1}) && body_[pos.y + 1][pos.x].flag == true) bombs_around--;
		if (ValidCoord({pos.x - 1,pos.y - 1}) && body_[pos.y - 1][pos.x - 1].flag == true) bombs_around--;
		if (ValidCoord({pos.x - 1,pos.y + 1}) && body_[pos.y + 1][pos.x - 1].flag == true) bombs_around--;
		if (ValidCoord({pos.x + 1,pos.y - 1}) && body_[pos.y - 1][pos.x + 1].flag == true) bombs_around--;
		if (ValidCoord({pos.x + 1,pos.y + 1}) && body_[pos.y + 1][pos.x + 1].flag == true) bombs_around--;
		if (ValidCoord({pos.x - 1 ,pos.y}) && body_[pos.y][pos.x - 1].flag == true) bombs_around--;
		if (ValidCoord({pos.x + 1,pos.y}) && body_[pos.y][pos.x + 1].flag == true) bombs_around--;


		if (bombs_around <= 0)
		{
			if (!CheckSpecialCoord({ pos.x, pos.y - 1 })) alive = false;
			if (!CheckSpecialCoord({ pos.x, pos.y + 1 })) alive = false;
			if (!CheckSpecialCoord({ pos.x - 1, pos.y }))  alive = false;
			if (!CheckSpecialCoord({ pos.x + 1, pos.y })) alive = false;
			if (!CheckSpecialCoord({ pos.x - 1, pos.y - 1 })) alive = false;
			if (!CheckSpecialCoord({ pos.x + 1, pos.y + 1 })) alive = false;
			if (!CheckSpecialCoord({ pos.x - 1, pos.y + 1 })) alive = false;
			if (!CheckSpecialCoord({ pos.x + 1, pos.y - 1 })) alive = false;
		}
	}

	return alive;
}

bool Board::Generate(const Coord & size,  unsigned bombs)
{
	if (size.x * size.y < bombs) return false;

	srand(seed_);

	//for (int y = 0; y < size.y; y++)
	//{
	//	for (int x = 0; x < size.x; x++)
	//		body_[y][x].number = Block::EMPTY;
	//}

	Coord temp;
	for (int i = 0; i < bombs; i++)
	{
		do 
		{
			temp.x = rand() % size.x;
			temp.y = rand() % size.y;
		} while (body_[temp.y][temp.x].number == Block::BOMB);

		body_[temp.y][temp.x].number = Block::BOMB;
	}

	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			if (body_[y][x].number != Block::BOMB)
				body_[y][x].number = GenerateNumber({ y, x });
		}
	}

	return true;
}

void Board::SetSize(const Coord & size)
{
	body_ = new Block * [size.y];
	for (int x = 0; x < size.x; x++)
	{
		body_[x] = new Block [size.x];
	}

	size_ = { size.x, size.y };

	//body_.resize(size.y);
	//for (int y = 0; y < size.y; ++y)
	//{
	//	body_[y].resize(size.x);
	//}

	//size_ = { int(body_.size()), int(body_[0].size()) };
}

Block Board::GetBlock(const Coord & pos) const
{
	if (pos.x < 0 || pos.y < 0 || pos.x >= size_.x || pos.y >= size_.y)
	{
		throw;
	}

	return body_[pos.y][pos.x];
}

int Board::GenerateNumber(const Coord & pos) const 
{
	int number = 0;

	Coord size = { size_.x - 1, size_.y - 1 };

	// top left
	if (pos.x > 0 && pos.y > 0 && body_[pos.x - 1][pos.y - 1].number == Block::BOMB) ++number;
	// bottom right
	if (pos.x < size.x && pos.y < size.y && body_[pos.x + 1][pos.y + 1].number == Block::BOMB) ++number;

	// top
	if (pos.y > 0 && body_[pos.x][pos.y - 1].number == Block::BOMB) ++number;
	// bottom
	if (pos.y < size.y && body_[pos.x][pos.y + 1].number == Block::BOMB) ++number;
	
	// left
	if (pos.x > 0 && body_[pos.x - 1][pos.y].number == Block::BOMB) ++number;
	// right
	if (pos.x < size.x && body_[pos.x + 1][pos.y].number == Block::BOMB) ++number;

	// top right 
	if (pos.x < size.x && pos.y > 0 && body_[pos.x + 1][pos.y - 1].number == Block::BOMB) ++number;
	// bottom left
	if (pos.x > 0 && pos.y < size.y && body_[pos.x - 1][pos.y + 1].number == Block::BOMB) ++number;
	

	return number;
}

void Board::Set(const Coord & position, int type)
{
	body_[position.y][position.y].number = type;
}

void Board::CheckEmptyCoord(const Coord & pos)
{
	if (pos.x >= 0 &&
		pos.y >= 0 && 
		pos.x < size_.x &&
		pos.y < size_.y &&
		!body_[pos.y][pos.x].clicked)
	{
		if (body_[pos.y][pos.x].number == Block::EMPTY )
		{
			body_[pos.y][pos.x].clicked = true;
			EmptyClick(pos);
		}
		else if (body_[pos.y][pos.x].number != Block::BOMB)
		{
			body_[pos.y][pos.x].clicked = true;
		}
	}

}

bool Board::CheckCoord(const Coord & pos, bool ignore_bombs)
{
	bool alive = true;

	if (ValidCoord(pos) && !body_[pos.y][pos.x].clicked && !body_[pos.y][pos.x].flag)
	{
 		switch ( body_[pos.y][pos.x].number)
		{
		case Block::BOMB:
			if (!ignore_bombs) alive = false;
			body_[pos.y][pos.x].clicked = true;
			break;
		case Block::EMPTY:
			EmptyClick(pos);
			body_[pos.y][pos.x].clicked = true;
			break;
		default:
			body_[pos.y][pos.x].clicked = true;
			break;
		}
	}

	return alive;
}

bool Board::CheckSpecialCoord(const Coord & pos)
{
	bool alive = true;

	if (ValidCoord(pos) && !body_[pos.y][pos.x].clicked && !body_[pos.y][pos.x].flag)
	{
		body_[pos.y][pos.x].clicked = true;
		if (body_[pos.y][pos.x].number == Block::EMPTY)
		{
			EmptyClick(pos);
		}
		else if (body_[pos.y][pos.x].number == Block::BOMB)
		{
			alive = false;
		}
	}

	return alive;
}
