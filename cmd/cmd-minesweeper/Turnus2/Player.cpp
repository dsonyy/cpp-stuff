#include "Player.h"


Player::Player()
{
	SetName("Unnamed Player");
	SetPosition({ 0,0 });
}

bool Player::Move(Coord rel_positioin)
{
	position_.x += rel_positioin.x;
	position_.y += rel_positioin.y;

	return true; //TODO: do konca to zxrobic
}

void Player::SetName(std::string new_name)
{
	name_ = new_name;
}

void Player::SetPosition(Coord new_position)
{
	position_ = new_position;
}
