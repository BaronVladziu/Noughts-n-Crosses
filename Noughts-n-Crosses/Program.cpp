#include "header.h"
#include "Tab.h"
#include "Program.h"
#include "IconVoid.h"
#include "IconNought.h"
#include "IconCross.h"
#include "Algorithm.h"
#include "TestAlgorithm.h"
#include "CountingAlgorithm.h"

bool Program::if_N(const int i, const int j, const Mark mark) const
{
	if (_tab.get(i, j - 2) == mark && _tab.get(i, j - 1) == mark &&
		_tab.get(i, j) == mark && _tab.get(i, j + 1) == mark &&
		_tab.get(i, j + 2) == mark)
	{
		return true;
	}
	return false;
}
bool Program::if_E(const int i, const int j, const Mark mark) const
{
	if (_tab.get(i - 2, j) == mark && _tab.get(i - 1, j) == mark &&
		_tab.get(i, j) == mark && _tab.get(i + 1, j) == mark &&
		_tab.get(i + 2, j) == mark)
	{
		return true;
	}
	return false;
}
bool Program::if_NE(const int i, const int j, const Mark mark) const
{
	if (_tab.get(i + 2, j - 2) == mark && _tab.get(i + 1, j - 1) == mark &&
		_tab.get(i, j) == mark && _tab.get(i - 1, j + 1) == mark &&
		_tab.get(i - 2, j + 2) == mark)
	{
		return true;
	}
	return false;
}
bool Program::if_SE(const int i, const int j, const Mark mark) const
{
	if (_tab.get(i - 2, j - 2) == mark && _tab.get(i - 1, j - 1) == mark &&
		_tab.get(i, j) == mark && _tab.get(i + 1, j + 1) == mark &&
		_tab.get(i + 2, j + 2) == mark)
	{
		return true;
	}
	return false;
}
bool Program::check_if_win(const Mark mark) const
{
	//czy ktoœ wygra³
	for (int i = 0; i < _tab.get_width(); i++)
	{
		for (int j = 0; j < _tab.get_height(); j++)
		{
			//która czêœæ tablicy
			int komorka_pozioma;
			int komorka_pionowa;
			if (i - 2 < 0)
			{
				komorka_pozioma = -1;
			}
			else if (i + 2 >= _tab.get_width())
			{
				komorka_pozioma = 1;
			}
			else
			{
				komorka_pozioma = 0;
			}
			if (j - 2 < 0)
			{
				komorka_pionowa = -1;
			}
			else if (j + 2 >= _tab.get_height())
			{
				komorka_pionowa = 1;
			}
			else
			{
				komorka_pionowa = 0;
			}
			//sprawdzanie
			if (komorka_pozioma != 0 && komorka_pionowa == 0)
			{
				if (if_N(i, j, mark))
				{
					return true;
				}
			}
			else if (komorka_pozioma == 0 && komorka_pionowa != 0)
			{
				if (if_E(i, j, mark))
				{
					return true;
				}
			}
			else if (komorka_pozioma == 0 && komorka_pionowa == 0)
			{
				if (if_N(i, j, mark))
				{
					return true;
				}
				if (if_E(i, j, mark))
				{
					return true;
				}
				if (if_NE(i, j, mark))
				{
					return true;
				}
				if (if_SE(i, j, mark))
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool Program::check_if_draw() const
{
	for (int i = 0; i < _tab.get_width(); i++)
	{
		for (int j = 0; j < _tab.get_height(); j++)
		{
			if (_tab.get(i, j) == Mark::V)
			{
				return false;
			}
		}
	}
	return true;
}
void Program::game_end_actions(const Mark winners_mark)
{
	if (winners_mark == Mark::X)
	{
		_wins_X++;
	}
	if (winners_mark == Mark::O)
	{
		_wins_O++;
	}
	if (winners_mark == Mark::V)
	{
		_wins_V++;
	}
	std::cout << "--- X wins: " << _wins_X << " --- O wins: " << _wins_O << " --- Draws: " << _wins_V << " ---" << std::endl;
	_tab.clear();
	_algorytm1.reset(new CountingAlgorithm());
	//_algorytm2.reset(new TestAlgorithm());
	_algorytm2.reset(new CountingAlgorithm());
	if (_who_starts == Who_Starts::X_started)
	{
		_who_starts = Who_Starts::O_starts;
		std::cout << "O starts" << std::endl;
	}
	if (_who_starts == Who_Starts::O_started)
	{
		_who_starts = Who_Starts::X_starts;
		std::cout << "X starts" << std::endl;
	}
}
void Program::draw()
{
	//wyœwietlanie
	_window.clear();
	for (int i = 0; i < _tab.get_width(); i++)
	{
		for (int j = 0; j < _tab.get_height(); j++)
		{
			if (_tab.get(i, j) == Mark::O)
			{
				_icon_nought->set_position(sf::Vector2f(i * _icon_nought->get_size().x, j * _icon_nought->get_size().y) + _start_vector);
				_icon_nought->draw(_window);
			}
			else if (_tab.get(i, j) == Mark::X)
			{
				_icon_cross->set_position(sf::Vector2f(i * _icon_cross->get_size().x, j * _icon_cross->get_size().y) + _start_vector);
				_icon_cross->draw(_window);
			}
			else
			{
				_icon_void->set_position(sf::Vector2f(i * _icon_void->get_size().x, j * _icon_void->get_size().y) + _start_vector);
				_icon_void->draw(_window);
			}
		}
	}
	_window.display();
}

Program::Program()
	: IF_HUMAN_PLAYER(true),
	_settings(0U, 0U, 8), _window(sf::VideoMode(800, 600), sf::String("Tabliczka"), sf::Style::Default, _settings),
	_icon_void(new IconVoid()), _icon_nought(new IconNought()), _icon_cross(new IconCross()), _start_vector(20, 20),
	_algorytm1(new CountingAlgorithm()), _algorytm2(new CountingAlgorithm()), _who_starts(Who_Starts::X_starts),
	_wins_X(0), _wins_O(0), _wins_V(0)
{
	std::cout << "X starts" << std::endl;
}
void Program::loop()
{
	while (_window.isOpen())
	{
		sf::Event event;
		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				_window.close();
			}
			if (IF_HUMAN_PLAYER == true)
			{
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
				{
					if (sf::Mouse::getPosition(_window).x > _start_vector.x &&
						sf::Mouse::getPosition(_window).x < _start_vector.x + (_tab.get_width() * _icon_void->get_size().x))
					{
						if (sf::Mouse::getPosition(_window).y > _start_vector.y &&
							sf::Mouse::getPosition(_window).y < _start_vector.y + (_tab.get_height() * _icon_void->get_size().x))
						{
							sf::Vector2i v1 = { int((sf::Mouse::getPosition(_window).x - _start_vector.x) / _icon_void->get_size().x),
								int((sf::Mouse::getPosition(_window).y - _start_vector.y) / _icon_void->get_size().y) };
							if (_tab.get(v1.x, v1.y) == Mark::V)
							{
								//dzia³ania gracza
								_tab.change(v1.x, v1.y, Mark::X);
								std::cout << "X: " << v1.x << ", " << v1.y << std::endl;
								if (check_if_win(Mark::X))
								{
									std::cout << "X won!" << std::endl;
									_tab.clear();
								}
								draw();
								//dzia³ania algorytmu
								sf::Vector2i v2 = _algorytm1->execute(_tab, Mark::O);
								if (_tab.get(v2.x, v2.y) == Mark::N)
								{
									std::cout << "O didn't hit the board and lost his turn!" << std::endl;
								}
								else if (_tab.get(v2.x, v2.y) == Mark::V)
								{
									_tab.change(v2.x, v2.y, Mark::O);
									std::cout << "O: " << v2.x << ", " << v2.y << std::endl;
									if (check_if_win(Mark::O))
									{
										std::cout << "O won!" << std::endl;
										_tab.clear();
									}
									draw();
								}
								else
								{
									std::cout << "O tried to cheat and lost his turn!" << std::endl;
								}
							}
						}
					}
				}
			}
		}
		if (IF_HUMAN_PLAYER == false)
		{
			if (_who_starts == Who_Starts::X_starts || _who_starts == Who_Starts::X_started || _who_starts == Who_Starts::O_started)
			{
				if (_who_starts == Who_Starts::X_starts)
				{
					_who_starts = Who_Starts::X_started;
				}
				//dzia³ania algorytmu1
				sf::Vector2i v1 = _algorytm1->execute(_tab, Mark::X);
				if (_tab.get(v1.x, v1.y) == Mark::N)
				{
					std::cout << "X didn't hit the board and lost his turn!" << std::endl;
				}
				else if (_tab.get(v1.x, v1.y) == Mark::V)
				{
					_tab.change(v1.x, v1.y, Mark::X);
					//std::cout << "X: " << v1.x << ", " << v1.y << std::endl;
					if (check_if_win(Mark::X))
					{
						std::cout << ">>>>> X won! <<<<<" << std::endl;
						game_end_actions(Mark::X);
					}
					if (check_if_draw())
					{
						std::cout << ">>>>> Draw! <<<<<" << std::endl;
						game_end_actions(Mark::V);
					}
					draw();
				}
				else
				{
					std::cout << "X tried to cheat and lost his turn!" << std::endl;
				}
			}
			if (_who_starts == Who_Starts::O_starts || _who_starts == Who_Starts::X_started || _who_starts == Who_Starts::O_started)
			{
				if (_who_starts == Who_Starts::O_starts)
				{
					_who_starts = Who_Starts::O_started;
				}
				//dzia³ania algorytmu2
				sf::Vector2i v2 = _algorytm2->execute(_tab, Mark::O);
				if (_tab.get(v2.x, v2.y) == Mark::N)
				{
					std::cout << "O didn't hit the board and lost his turn!" << std::endl;
				}
				else if (_tab.get(v2.x, v2.y) == Mark::V)
				{
					_tab.change(v2.x, v2.y, Mark::O);
					//std::cout << "O: " << v2.x << ", " << v2.y << std::endl;
					if (check_if_win(Mark::O))
					{
						std::cout << ">>>>> O won! <<<<<" << std::endl;
						_algorytm2->save_data();
						game_end_actions(Mark::O);
					}
					if (check_if_draw())
					{
						std::cout << ">>>>> Draw! <<<<<" << std::endl;
						game_end_actions(Mark::V);
					}
					draw();
				}
				else
				{
					std::cout << "O tried to cheat and lost his turn!" << std::endl;
				}
			}
		}
		else
		{
			draw();
		}
	}
}
Program::~Program()
{}