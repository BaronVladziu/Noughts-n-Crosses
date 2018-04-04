#include "header.h"
#include "IconNought.h"

IconNought::IconNought()
	: _shape1(sf::Vector2f(20, 20)), _shape2(5, 7)
{
	_shape1.setFillColor(sf::Color::Transparent);
	_shape1.setOutlineColor(sf::Color::Cyan);
	_shape1.setOutlineThickness(0.5);
	_shape2.setFillColor(sf::Color::Black);
	_shape2.setOutlineColor(sf::Color::Cyan);
	_shape2.setOutlineThickness(2);
	_shape2.setOrigin(-5, -5);
}
void IconNought::set_position(const sf::Vector2f & position)
{
	_shape1.setPosition(position);
	_shape2.setPosition(position);
}
sf::Vector2f IconNought::get_position() const
{
	return _shape1.getPosition();
}
sf::Vector2f IconNought::get_size() const
{
	return _shape1.getSize();
}
void IconNought::draw(sf::RenderWindow & window) const
{
	window.draw(_shape1);
	window.draw(_shape2);
}
IconNought::~IconNought()
{}