#pragma once
#include "header.h"

class Tab
{
	std::unique_ptr<std::unique_ptr<Mark[]>[]> _table_ptr;
	int _width;
	int _height;

public:
	Tab();
	Mark get(const int x, const int y) const;
	void change(const int x, const int y, const Mark mark);
	void clear();
	int get_width() const;
	int get_height() const;
	~Tab();
};