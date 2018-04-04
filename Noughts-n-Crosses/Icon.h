#pragma once
#include "header.h"

class Icon
{
public:
	virtual void set_position(const sf::Vector2f & position) = 0;
	virtual sf::Vector2f get_position() const = 0;
	virtual sf::Vector2f get_size() const = 0;
	virtual void draw(sf::RenderWindow & window) const = 0;
};