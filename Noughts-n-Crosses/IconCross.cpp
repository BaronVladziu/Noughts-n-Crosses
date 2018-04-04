#include "header.h"
#include "IconCross.h"

IconCross::IconCross()
	: _shape1(sf::Vector2f(20, 20)), _shape2(sf::Vector2f(16, 2)), _shape3(sf::Vector2f(16, 2))
{
	_shape1.setFillColor(sf::Color::Transparent);
	_shape1.setOutlineColor(sf::Color::Cyan);
	_shape1.setOutlineThickness(0.5);
	_shape2.setFillColor(sf::Color::Cyan);
	_shape2.setOrigin(8, 1);
	_shape2.setRotation(45);
	_shape3.setFillColor(sf::Color::Cyan);
	_shape2.setOrigin(8, 1);
	_shape3.setRotation(-45);
}
void IconCross::set_position(const sf::Vector2f & position)
{
	_shape1.setPosition(position);
	_shape2.setPosition(position + sf::Vector2f(10, 10.5));
	_shape3.setPosition(position + sf::Vector2f(4, 15.5));
}
sf::Vector2f IconCross::get_position() const
{
	return _shape1.getPosition();
}
sf::Vector2f IconCross::get_size() const
{
	return _shape1.getSize();
}
void IconCross::draw(sf::RenderWindow & window) const
{
	window.draw(_shape1);
	window.draw(_shape2);
	window.draw(_shape3);
}
IconCross::~IconCross()
{}