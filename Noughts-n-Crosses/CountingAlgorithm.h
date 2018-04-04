#pragma once
#include "header.h"
#include "Algorithm.h"

enum Action
{
	No_Action,
	My_Action,
	En_Action
};
enum Direction
{
	No,
	NE,
	Ea,
	SE
};
enum Line_State
{
	O____, //1
	_O___, //1
	__O__, //1
	O___O, //10
	O__O_, //10
	O_O__, //10
	_O_O_, //10
	OO___, //11
	_OO__, //11
	O_O_O, //100
	OO__O, //100
	OO_O_, //100
	O_OO_, //100
	OOO__, //101
	_OOO_, //101
	OO_OO, //1000
	OOO_O, //1000
	OOOO_ //1001
};

class CountingAlgorithm
	: public Algorithm
{
	int _wages[18];

	Mark get_tab_value(const int x, const int y, const int x_point, const int y_point, const Tab & tab, const Mark mark, const Action action) const;
	int get_line_value(const int x, const int y, const int x_point, const int y_point, const Direction dir, const Tab & tab, const Mark mark, const Action action);

public:
	CountingAlgorithm();
	int get_point_value(const int i, const int j, const Tab & tab, const Mark mark);
	const sf::Vector2i execute(const Tab & tab, const Mark mark);
	void save_data();
	~CountingAlgorithm();
};