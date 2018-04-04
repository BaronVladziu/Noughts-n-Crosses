#pragma once
#include "header.h"
#include "Algorithm.h"

class TestAlgorithm
	: public Algorithm
{
public:
	TestAlgorithm();
	int get_point_value(const int i, const int j, const Tab & tab, const Mark mark);
	const sf::Vector2i execute(const Tab & tab, const Mark mark);
	void save_data();
	~TestAlgorithm();
};