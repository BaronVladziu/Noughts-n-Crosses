#include "header.h"
#include "Algorithm.h"
#include "CountingAlgorithm.h"
#include "Tab.h"

Mark CountingAlgorithm::get_tab_value(const int x, const int y, const int x_point, const int y_point, const Tab & tab, const Mark mark, const Action action) const
{
	if (x == x_point && y == y_point)
	{
		switch (action)
		{
		case Action::My_Action:
			return mark;
			break;
		case Action::En_Action:
			if (mark == Mark::X)
			{
				return Mark::O;
			}
			else
			{
				return Mark::X;
			}
			break;
		}
	}
	return tab.get(x, y);
}
int CountingAlgorithm::get_line_value(const int x, const int y, const int x_point, const int y_point,
	const Direction dir, const Tab & tab, const Mark mark, const Action action)
{
	//wyznaczanie symbolu wroga
	Mark _enemy;
	if (mark == Mark::O)
	{
		_enemy = Mark::X;
	}
	else
	{
		_enemy = Mark::O;
	}
	//tworzenie wektora z danej linii + dodawanie potencjalnej akcji
	Mark _vector[5];
	switch (dir)
	{
	case No:
		_vector[0] = get_tab_value(x, y, x_point, y_point, tab, mark, action);
		_vector[1] = get_tab_value(x, y + 1, x_point, y_point, tab, mark, action);
		_vector[2] = get_tab_value(x, y + 2, x_point, y_point, tab, mark, action);
		_vector[3] = get_tab_value(x, y + 3, x_point, y_point, tab, mark, action);
		_vector[4] = get_tab_value(x, y + 4, x_point, y_point, tab, mark, action);
		break;
	case NE:
		_vector[0] = get_tab_value(x, y, x_point, y_point, tab, mark, action);
		_vector[1] = get_tab_value(x + 1, y + 1, x_point, y_point, tab, mark, action);
		_vector[2] = get_tab_value(x + 2, y + 2, x_point, y_point, tab, mark, action);
		_vector[3] = get_tab_value(x + 3, y + 3, x_point, y_point, tab, mark, action);
		_vector[4] = get_tab_value(x + 4, y + 4, x_point, y_point, tab, mark, action);
		break;
	case Ea:
		_vector[0] = get_tab_value(x, y, x_point, y_point, tab, mark, action);
		_vector[1] = get_tab_value(x + 1, y, x_point, y_point, tab, mark, action);
		_vector[2] = get_tab_value(x + 2, y, x_point, y_point, tab, mark, action);
		_vector[3] = get_tab_value(x + 3, y, x_point, y_point, tab, mark, action);
		_vector[4] = get_tab_value(x + 4, y, x_point, y_point, tab, mark, action);
		break;
	case SE:
		_vector[0] = get_tab_value(x, y, x_point, y_point, tab, mark, action);
		_vector[1] = get_tab_value(x - 1, y + 1, x_point, y_point, tab, mark, action);
		_vector[2] = get_tab_value(x - 2, y + 2, x_point, y_point, tab, mark, action);
		_vector[3] = get_tab_value(x - 3, y + 3, x_point, y_point, tab, mark, action);
		_vector[4] = get_tab_value(x - 4, y + 4, x_point, y_point, tab, mark, action);
		break;
	}
	//sprawdzanie, czy w granicach planszy
	if (_vector[0] == Mark::N || _vector[1] == Mark::N || _vector[2] == Mark::N || _vector[3] == Mark::N || _vector[4] == Mark::N)
	{
		return 0;
	}
	//sprawdzanie, czy gracze zagrali w tej linii
	bool if_my = false;
	bool if_en = false;
	if (_vector[0] == mark || _vector[1] == mark || _vector[2] == mark || _vector[3] == mark || _vector[4] == mark)
	{
		if_my = true;
	}
	if (_vector[0] == _enemy || _vector[1] == _enemy || _vector[2] == _enemy || _vector[3] == _enemy || _vector[4] == _enemy)
	{
		if_en = true;
	}
	//bezwartoœciowe linie
	if (if_my == if_en)
	{
		return 0;
	}
	//okreœlenie typu linii
	Mark _only;
	int value;
	if (if_my == true)
	{
		_only = mark;
	}
	else
	{
		_only = _enemy;
	}
	if (_vector[0] == _only)
	{
		if (_vector[1] == _only)
		{
			if (_vector[2] == _only)
			{
				if (_vector[3] == _only)
				{
					if (_vector[4] == _only)
					{
						value = 100000;
					}
					else
					{
						value = _wages[OOOO_];
					}
				}
				else
				{
					if (_vector[4] == _only)
					{
						value = _wages[OOO_O];
					}
					else
					{
						value = _wages[OOO__];
					}
				}
			}
			else
			{
				if (_vector[3] == _only)
				{
					if (_vector[4] == _only)
					{
						value = _wages[OO_OO];
					}
					else
					{
						value = _wages[OO_O_];
					}
				}
				else
				{
					if (_vector[4] == _only)
					{
						value = _wages[OO__O];
					}
					else
					{
						value = _wages[OO___];
					}
				}
			}
		}
		else
		{
			if (_vector[2] == _only)
			{
				if (_vector[3] == _only)
				{
					if (_vector[4] == _only)
					{
						value = _wages[OOO_O];
					}
					else
					{
						value = _wages[O_OO_];
					}
				}
				else
				{
					if (_vector[4] == _only)
					{
						value = _wages[O_O_O];
					}
					else
					{
						value = _wages[O_O__];
					}
				}
			}
			else
			{
				if (_vector[3] == _only)
				{
					if (_vector[4] == _only)
					{
						value = _wages[OO__O];
					}
					else
					{
						value = _wages[O__O_];
					}
				}
				else
				{
					if (_vector[4] == _only)
					{
						value = _wages[O___O];
					}
					else
					{
						value = _wages[O____];
					}
				}
			}
		}
	}
	else
	{
		if (_vector[1] == _only)
		{
			if (_vector[2] == _only)
			{
				if (_vector[3] == _only)
				{
					if (_vector[4] == _only)
					{
						value = _wages[OOOO_];
					}
					else
					{
						value = _wages[_OOO_];
					}
				}
				else
				{
					if (_vector[4] == _only)
					{
						value = _wages[O_OO_];
					}
					else
					{
						value = _wages[_OO__];
					}
				}
			}
			else
			{
				if (_vector[3] == _only)
				{
					if (_vector[4] == _only)
					{
						value = _wages[OO_O_];
					}
					else
					{
						value = _wages[_O_O_];
					}
				}
				else
				{
					if (_vector[4] == _only)
					{
						value = _wages[O__O_];
					}
					else
					{
						value = _wages[_O___];
					}
				}
			}
		}
		else
		{
			if (_vector[2] == _only)
			{
				if (_vector[3] == _only)
				{
					if (_vector[4] == _only)
					{
						value = _wages[OOO__];
					}
					else
					{
						value = _wages[_OO__];
					}
				}
				else
				{
					if (_vector[4] == _only)
					{
						value = _wages[O_O__];
					}
					else
					{
						value = _wages[__O__];
					}
				}
			}
			else
			{
				if (_vector[3] == _only)
				{
					if (_vector[4] == _only)
					{
						value = _wages[OO___];
					}
					else
					{
						value = _wages[_O___];
					}
				}
				else
				{
					if (_vector[4] == _only)
					{
						value = _wages[O____];
					}
					else
					{
						value = 0;
					}
				}
			}
		}
	}
	if (_only == _enemy)
	{
		return -(value);
	}
	else
	{
		return value;
	}
}

CountingAlgorithm::CountingAlgorithm()
{
	int wage;
	int i = 0;
	std::fstream file("algorithm_data.txt");
	while (!file.eof())
	{
		file >> wage;
		_wages[i] = wage;
		i++;
	}
	file.close();
}
int CountingAlgorithm::get_point_value(const int i, const int j, const Tab & tab, const Mark mark)
{
	int value = 0;
	for (int q = 0; q < 5; q++)
	{
		value += get_line_value(i, j - q, i, j, No, tab, mark, Action::My_Action);
		value += get_line_value(i - q, j - q, i, j, NE, tab, mark, Action::My_Action);
		value += get_line_value(i - q, j, i, j, Ea, tab, mark, Action::My_Action);
		value += get_line_value(i + q, j - q, i, j, SE, tab, mark, Action::My_Action);
		value -= get_line_value(i, j - q, i, j, No, tab, mark, Action::En_Action);
		value -= get_line_value(i - q, j - q, i, j, NE, tab, mark, Action::En_Action);
		value -= get_line_value(i - q, j, i, j, Ea, tab, mark, Action::En_Action);
		value -= get_line_value(i + q, j - q, i, j, SE, tab, mark, Action::En_Action);
	}
	return value;
}
const sf::Vector2i CountingAlgorithm::execute(const Tab & tab, const Mark mark)
{
	std::list<std::pair<sf::Vector2i, int>> vector;
	std::vector<std::pair<sf::Vector2i, int>> vector_max;
	int max_value = 0;
	int point_value = 0;
	for (int i = 0; i < tab.get_width(); i++)
	{
		for (int j = 0; j < tab.get_height(); j++)
		{
			if (tab.get(i, j) == Mark::V)
			{
				point_value = get_point_value(i, j, tab, mark);
				if (point_value >= max_value)
				{
					vector.push_back(std::pair<sf::Vector2i, int>(sf::Vector2i(i, j), point_value));
					max_value = point_value;
				}
			}
		}
	}
	for (std::list<std::pair<sf::Vector2i, int>>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		if (it->second == max_value)
		{
			vector_max.push_back(*it);
		}
	}
	int radom = rand() % vector_max.size();
	return vector_max[radom].first;
}
void CountingAlgorithm::save_data()
{

}
CountingAlgorithm::~CountingAlgorithm()
{}