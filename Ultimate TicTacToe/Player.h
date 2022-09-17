#pragma once

#include <ctime>

class Player
{
private:
	char symbol;
	int won_games;

public:
	Player(char symbol)
	{
		this->symbol = symbol;

		won_games = 0;
	}

	void set_symbol()
	{
		this->symbol = symbol;
	}

	char get_symbol() const
	{
		return symbol;
	}

	void increment_won_games()
	{
		won_games++;
	}

	int get_won_games() const
	{
		return won_games;
	}

	int flip_a_coin()
	{
		srand((unsigned int)time(NULL));
		return (int)(rand() % 2);
	}
};