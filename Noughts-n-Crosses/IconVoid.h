#pragma once
#include "header.h"
#include "Icon.h"

class IconVoid
	: public Icon
{
	sf::RectangleShape _shape;

public:
	IconVoid();
	void set_position(const sf::Vector2f & position);
	sf::Vector2f get_position() const;
	sf::Vector2f get_size() const;
	void draw(sf::RenderWindow & window) const;
	~IconVoid();
};