#include "header.h"
#include "Tab.h"

Tab::Tab()
{
	_height = 28;
	_width = 38;
	_table_ptr.reset(new std::unique_ptr<Mark[]>[_width]);
	for (int i = 0; i < _width; i++)
	{
		_table_ptr[i].reset(new Mark[_height]);
	}
	this->clear();
}
Mark Tab::get(const int x, const int y) const
{
	if (x < 0 || x >= _width || y < 0 || y >= _height)
	{
		return Mark::N;
	}
	return _table_ptr[x][y];
}
void Tab::change(const int x, const int y, const Mark mark)
{
	if (x >= 0 && x < _width && y >= 0 && y < _height)
	{
		_table_ptr[x][y] = mark;
	}
}
void Tab::clear()
{
	for (int i = 0; i < _width; i++)
	{
		for (int j = 0; j < _height; j++)
		{
			_table_ptr[i][j] = Mark::V;
		}
	}
}
int Tab::get_width() const
{
	return _width;
}
int Tab::get_height() const
{
	return _height;
}
Tab::~Tab()
{}