#include "header.h"
#include "IconVoid.h"

IconVoid::IconVoid()
	: _shape(sf::Vector2f(20, 20))
{
	_shape.setFillColor(sf::Color::Transparent);
	_shape.setOutlineColor(sf::Color::Cyan);
	_shape.setOutlineThickness(0.5);
}
void IconVoid::set_position(const sf::Vector2f & position)
{
	_shape.setPosition(position);
}
sf::Vector2f IconVoid::get_position() const
{
	return _shape.getPosition();
}
sf::Vector2f IconVoid::get_size() const
{
	return _shape.getSize();
}
void IconVoid::draw(sf::RenderWindow & window) const
{
	window.draw(_shape);
}
IconVoid::~IconVoid()
{}