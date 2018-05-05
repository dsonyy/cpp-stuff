#pragma once

#include <vector>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


class Buffer
	: public sf::Drawable,
	public sf::Transformable
{
public:
	Buffer(size_t width, size_t height,
		   sf::Vector2f pos = sf::Vector2f(0, 0));
	~Buffer();

	// derived from sf::Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	const sf::Color & GetColor(size_t x, size_t y) const;
	bool SetColor(size_t x, size_t y, sf::Color color);
	void Clear(const sf::Color & color);


	
	size_t GetWidth() const		{ return width_; }
	size_t GetHeight() const	{ return height_; }
	size_t GetSize() const		{ return width_ * height_; }

	float GetX() const { return pos_.x; }
	float GetY() const { return pos_.y; }

	void UpdateTexture();
private:
	

	size_t width_;
	size_t height_;
	sf::Vector2f pos_;

	std::vector<sf::Color> color_map_;
	sf::Texture texture_;
	sf::Sprite sprite_;

};

