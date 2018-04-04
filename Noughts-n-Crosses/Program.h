#pragma once
#include "header.h"
#include "Tab.h"
#include "Algorithm.h"

enum Who_Starts
{
	X_starts,
	O_starts,
	X_started,
	O_started
};

class Program
{
	const bool IF_HUMAN_PLAYER;
	sf::ContextSettings _settings;
	sf::RenderWindow _window;
	Tab _tab;
	std::unique_ptr<Icon> _icon_void;
	std::unique_ptr<Icon> _icon_nought;
	std::unique_ptr<Icon> _icon_cross;
	sf::Vector2f _start_vector;
	std::unique_ptr<Algorithm> _algorytm1;
	std::unique_ptr<Algorithm> _algorytm2;
	Who_Starts _who_starts;
	int _wins_O;
	int _wins_X;
	int _wins_V;

	bool if_N(const int i, const int j, const Mark mark) const;
	bool if_E(const int i, const int j, const Mark mark) const;
	bool if_NE(const int i, const int j, const Mark mark) const;
	bool if_SE(const int i, const int j, const Mark mark) const;
	bool check_if_win(const Mark mark) const;
	bool check_if_draw() const;
	void game_end_actions(const Mark winners_mark);
	void draw();

public:
	Program();
	void loop();
	~Program();
};