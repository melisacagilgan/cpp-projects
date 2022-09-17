#pragma once

#include <iostream>
#include <map>
using namespace std;

class Board
{
private:
	char board[3][3];
	char status;
	char p1;
	char p2;

public:
	Board(char p1, char p2)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				board[i][j] = '-';
			}
		}

		this->p1 = p1;
		this->p2 = p2;
		status = '0';
	}

	Board(const Board &b)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				board[i][j] = b.board[i][j];
			}
		}
		status = b.status;
		p1 = b.p1;
		p2 = b.p2;
	}

	void set_status(char status)
	{
		this->status = status;
	}

	char get_status() const
	{
		return status;
	}

	void set_p1(char p1)
	{
		this->p1 = p1;
	}

	char get_p1() const
	{
		return p1;
	}

	void set_p2(char p2)
	{
		this->p2 = p2;
	}

	char get_p2() const
	{
		return p2;
	}

	// Displays the specified row of the board
	void display_board(int i)
	{
		cout << board[i][0] << board[i][1] << board[i][2];
	}

	// Clears the board by setting all the cells to '-' and the status to '0'
	void clear_board()
	{
		status = '0';

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				board[i][j] = '-';
			}
		}
	}

	// Returns the available moves of the board
	map<int, string> available_moves(char p_char)
	{
		int count = 1;
		char str[6];
		map<int, string> moves;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == '-')
				{
					str[0] = '(';
					str[1] = i + '0';
					str[2] = ',';
					str[3] = j + '0';
					str[4] = ')';
					str[5] = '\0';
					moves.insert(pair<int, string>(count++, str));
				}
			}
		}

		return moves;
	}

	// Displays the available moves of the board
	void display_moves(map<int, string>
						   moves)
	{
		for (pair<int, string> i : moves)
		{
			cout << i.first << ". " << i.second << endl;
		}
	}

	// Player makes a move on the board
	void make_move(char p_char, int x, int y)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == x && j == y)
				{
					if (board[i][j] == '-')
					{
						board[i][j] = p_char;
						is_win(p_char);
					}
					else
					{
						cout << "Invalid move! Please replay." << endl;
					}
				}
			}
		}
	}

	// Checks if the player has won the board
	void is_win(char p_char)
	{
		// Checking board horizontaly
		for (int i = 0; i < 3; i++)
		{
			if (board[i][0] == p_char && board[i][1] == p_char && board[i][2] == p_char)
			{
				status = p_char;
			}
		}

		// Checking board vertically
		for (int j = 0; j < 3; j++)
		{
			if (board[0][j] == p_char && board[1][j] == p_char && board[2][j] == p_char)
			{
				status = p_char;
			}
		}

		// Checking board diagonally
		if (board[0][0] == p_char)
		{
			if (board[2][2] == p_char)
			{
				if (board[0][2] == p_char || board[2][0] == p_char)
				{
					status = p_char;
				}
				if (board[1][1] == p_char)
				{
					status = p_char;
				}
			}
		}
		else if (board[0][2] == p_char && board[2][0] == p_char)
		{
			if (board[2][2] == p_char || board[0][0] == p_char)
			{
				status = p_char;
			}
			if (board[1][1] == p_char)
			{
				status = p_char;
			}
		}
		else
		{
			if (board_filled())
			{
				status = 'D';
			}
		}
	}

	// Returns true if the board is full, false otherwise
	bool board_filled()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == '-')
				{
					return false;
				}
			}
		}
		return true;
	}

	// Overloaded ! operator to handle the draw situation when the board is full and no one has won
	int operator!()
	{
		int index = 1, p1_count = 0, p2_count = 0;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == p1)
				{
					p1_count += index;
				}
				if (board[i][j] == p2)
				{
					p2_count += index;
				}
				index++;
			}
		}

		// Returns 1, If first player's total is more than the second one, 0 otherwise
		if (p1 > p2)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	// Overloaded + operator to find the third round's winner
	char operator+(const Board &b)
	{
		char result;
		if (status == p1 && b.status == p2 || status == p1 && b.status == p1 || status == p2 && b.status == p1 || status == '0' && b.status == p1 || status == p1 && b.status == '0')
		{
			result = p1;
		}
		else if (status == p2 && b.status == p2 || status == '0' && b.status == p2 || status == p2 && b.status == '0')
		{
			return p2;
		}
		else if (status == '0' && b.status == '0')
		{
			return '0';
		}
	}

	// Overloaded - operator to find the third round's winner
	char operator-(const Board &b)
	{
		char result;
		if (status == p1 && b.status == p2 || status == p1 && b.status == p1 || status == p2 && b.status == p1 || status == '0' && b.status == p1 || status == p1 && b.status == '0')
		{
			result = p2;
		}
		else if (status == p1 && b.status == p1 || status == '0' && b.status == p1 || status == p1 && b.status == '0')
		{
			return p1;
		}
		else if (status == '0' && b.status == '0')
		{
			return '0';
		}
	}
};
