#include "Game.h"
#include "Player.h"
#include "Board.h"


Game::Game(Player * player, Board * board)
{
	player_ = player;
	board_ = board;
}

void Game::GoUp()
{
	if (player_->GetPosY() > 0) player_->Move({ 0, -1 });
}

void Game::GoDown()
{
	if (player_->GetPosY() < board_->GetSizeY() - 1) player_->Move({ 0, +1 });
}

void Game::GoLeft()
{
	if (player_->GetPosX() > 0) player_->Move({ -1, 0 });
}

void Game::GoRight()
{
	if (player_->GetPosX() < board_->GetSizeX() - 1) player_->Move({ +1, 0 });
}

bool Game::Click()
{
	if (board_->Click({ player_->GetPosX(), player_->GetPosY() }))
	{
		return true;
	}

	player_->Kill();
	return false;
}

bool Game::SpecialClick()
{
	if (board_->SpecialClick({ player_->GetPosX(), player_->GetPosY() }))
	{
		return true;
	}

	player_->Kill();
	return false;
}

void Game::Flag()
{
	Coord pos = { player_->GetPosX(), player_->GetPosY() };

	if (board_->GetBlock(pos).flag)
	{
		board_->Unflag(pos);
	}
	else
	{
		board_->Flag(pos);
	}
}

void Game::SetPlayer(Player * player)
{
	player_ = player;
	player_->SetPosition({0, 0});
}

void Game::SetBoard(Board * board)
{
	board_ = board;
	player_->SetPosition({ 0, 0 });
}
