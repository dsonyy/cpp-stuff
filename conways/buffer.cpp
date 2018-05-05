#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "buffer.h"

Buffer::Buffer(size_t width, size_t height, sf::Vector2f pos)
	: width_(width), height_(height), pos_(pos), color_map_(width * height)
{
	setPosition(pos);

	texture_.create(width, height);

	sprite_.setTexture(texture_);
	sprite_.setPosition(pos);
}

Buffer::~Buffer()
{
}

void Buffer::UpdateTexture()
{
	texture_.update((sf::Uint8*)&color_map_[0]);
}

void Buffer::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	
	states.texture = &texture_;

	target.draw(sprite_, states);
}

const sf::Color & Buffer::GetColor(size_t x, size_t y) const
{
	if (x >= width_ || y >= height_)
	{
		return sf::Color::Transparent;
	}

	return color_map_[y * width_ + x];
}

bool Buffer::SetColor(size_t x, size_t y, sf::Color color)
{
	if (x >= width_ || y >= height_)
	{
		return false;
	}

	color_map_[y * width_ + x] = color;

}

void Buffer::Clear(const sf::Color & color)
{

}