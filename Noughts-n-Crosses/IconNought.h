#pragma once
#include "header.h"
#include "Icon.h"

class IconNought
	: public Icon
{
	sf::RectangleShape _shape1;
	sf::CircleShape _shape2;

public:
	IconNought();
	void set_position(const sf::Vector2f & position);
	sf::Vector2f get_position() const;
	sf::Vector2f get_size() const;
	void draw(sf::RenderWindow & window) const;
	~IconNought();
};
