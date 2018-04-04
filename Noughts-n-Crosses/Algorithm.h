#pragma once
#include "header.h"

class Algorithm
{
public:
	virtual int get_point_value(const int i, const int j, const Tab & tab, const Mark mark) = 0;
	virtual const sf::Vector2i execute(const Tab & tab, const Mark mark) = 0;
	virtual void save_data() = 0;
};