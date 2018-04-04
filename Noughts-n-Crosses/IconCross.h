#pragma once
#include "header.h"
#include "Icon.h"

class IconCross
	: public Icon
{
	sf::RectangleShape _shape1;
	sf::RectangleShape _shape2;
	sf::RectangleShape _shape3;

public:
	IconCross();
	void set_position(const sf::Vector2f & position);
	sf::Vector2f get_position() const;
	sf::Vector2f get_size() const;
	void draw(sf::RenderWindow & window) const;
	~IconCross();
};