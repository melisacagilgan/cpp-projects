#pragma once

#include "Board.h"
#include "Player.h"

class Game
{
private:
	int game_round;
	Player *player1;
	Player *player2;
	Board *small_boards[9];
	Board *large_boards[18];

public:
	Game(Player &p1, Player &p2)
	{
		game_round = 0;

		this->player1 = &p1;
		this->player2 = &p2;

		for (int i = 0; i < 9; i++)
		{
			small_boards[i] = new Board(player1->get_symbol(), player2->get_symbol());
		}

		for (int i = 0; i < 18; i++)
		{
			large_boards[i] = new Board(player1->get_symbol(), player2->get_symbol());
		}
	}

	~Game()
	{
		for (int i = 0; i < 9; i++)
		{
			delete small_boards[i];
		}

		for (int i = 0; i < 18; i++)
		{
			delete large_boards[i];
		}
	}

	// Returns the current round of the game
	int get_game_round() const
	{
		return game_round;
	}

	// Prints the available board numbers
	void print_numbering()
	{
		for (int i = 0; i < 3; i++)
		{
			if (small_boards[i]->get_status() == '0')
			{
				cout << i + 1;
			}
		}
		cout << endl;

		for (int i = 3; i < 6; i++)
		{
			if (small_boards[i]->get_status() == '0')
			{
				cout << i + 1;
			}
		}
		cout << endl;

		for (int i = 6; i < 9; i++)
		{
			if (small_boards[i]->get_status() == '0')
			{
				cout << i + 1;
			}
		}
		cout << endl;
	}

	// Returns true if there is any available board left
	bool any_boards_available()
	{
		for (int i = 0; i < 9; i++)
		{
			if (small_boards[i]->get_status() == '0')
			{
				return true;
			}
		}
		return false;
	}

	// Prints all the boards with their updated status
	void display_boards()
	{
		for (int i = 0; i < 3; i++)
		{
			small_boards[0]->display_board(i);
			cout << "\t";
			small_boards[1]->display_board(i);
			cout << "\t";
			small_boards[2]->display_board(i);
			cout << endl;
		}
		cout << endl;

		for (int i = 0; i < 3; i++)
		{
			small_boards[3]->display_board(i);
			cout << "\t";
			small_boards[4]->display_board(i);
			cout << "\t";
			small_boards[5]->display_board(i);
			cout << endl;
		}
		cout << endl;

		for (int i = 0; i < 3; i++)
		{
			small_boards[6]->display_board(i);
			cout << "\t";
			small_boards[7]->display_board(i);
			cout << "\t";
			small_boards[8]->display_board(i);
			cout << endl;
		}
	}

	// Prints available boards and board numbers
	void print_boards()
	{
		display_boards();
		cout << "Available boards" << endl;
		print_numbering();
	}

	// Gameplay
	void play(int coin)
	{
		int board_no = -1;
		int round_started = 1;
		game_round++;
		do
		{
			if (round_started == 1)
			{
				cout << "--------------------\nROUND " << game_round << endl;
				round_started = 0;
			}
			if (game_round == 3)
			{
				continue;
			}
			else
			{
				if (coin == 0)
				{
					cout << "--------------------\nPlayer 1's turn:" << endl;
					print_boards();
					if (board_no != -1)
					{
						cout << "You must play on board " << board_no + 1 << "." << endl;
					}
					board_no = turn(player1->get_symbol(), board_no);
					if (round_over() == 0)
					{
						cout << "--------------------\nPlayer 2's turn:" << endl;
						print_boards();
						if (board_no != -1)
						{
							cout << "You must play on board " << board_no + 1 << "." << endl;
						}
						board_no = turn(player2->get_symbol(), board_no);
					}
				}
				else
				{
					cout << "--------------------\nPlayer 2's turn:" << endl;
					print_boards();
					if (board_no != -1)
					{
						cout << "You must play on board " << board_no + 1 << "." << endl;
					}
					board_no = turn(player2->get_symbol(), board_no);
					if (round_over() == 0)
					{
						cout << "--------------------\nPlayer 1's turn:" << endl;
						print_boards();
						if (board_no != -1)
						{
							cout << "You must play on board " << board_no + 1 << "." << endl;
						}
						board_no = turn(player1->get_symbol(), board_no);
					}
				}

				// Checks if the round is over
				if (round_over() != 0)
				{
					int player_no = round_over();
					if (player_no == 1)
					{
						player1->increment_won_games();
					}
					if (player_no == 2)
					{
						player2->increment_won_games();
					}
					cout << "--------------------" << endl;
					cout << "Round " << game_round << " is over!" << endl;
					if (player_no == -1)
					{
						cout << "Round " << game_round << " finished in a draw." << endl;
					}
					else
					{
						cout << "Player " << player_no << " won round " << game_round << "." << endl;
					}

					if (is_finished())
					{
						game_over();
						game_round = 4;
						continue;
					}

					save_boards();
					for (int i = 0; i < 9; i++)
					{
						small_boards[i]->clear_board();
					}
					game_round++;
					round_started = 1;
				}
			}
		} while (game_round < 3);

		if (game_round == 3 && !is_finished())
		{
			cout << "--------------------" << endl;
			display_large_boards();
			third_round();
			if (is_finished())
			{
				game_over();
			}
		}
	}

	// Handles turn of player
	int turn(char p_char, int board_no)
	{
		if (board_no == -1)
		{
			board_no++;
			do
			{
				cout << "Select a board number: ";
				cin >> board_no;
				board_no -= 1;
				if (board_no < 0 || board_no > 9)
				{
					cout << "Invalid board number! Please re-select." << endl;
				}
				else
				{
					if (small_boards[board_no]->get_status() != '0')
					{
						cout << "Board is already won! Please re-select." << endl;
					}
				}
			} while (board_no < 0 || board_no > 9 || small_boards[board_no]->get_status() != '0');
		}

		cout << "Available moves" << endl;
		map<int, string> moves = available_moves(board_no, p_char);
		display_moves(board_no, moves);

		int move;
		do
		{
			cout << "Select a move: ";
			cin >> move;
			if (moves.find(move) == moves.end())
			{
				cout << "Invalid move selection! Please re-select." << endl;
			}
		} while (moves.find(move) == moves.end());

		int x = moves.find(move)->second[1] - '0';
		int y = moves.find(move)->second[3] - '0';
		make_move(p_char, board_no, x, y);

		if (small_boards[board_no]->get_status() == 'D')
		{
			int result = !small_boards[board_no];
			if (result == 1)
			{
				small_boards[board_no]->set_status(player1->get_symbol());
			}
			else
			{
				small_boards[board_no]->set_status(player2->get_symbol());
			}
		}

		if (small_boards[board_no]->get_status() == p_char)
		{
			if (player1->get_symbol() == p_char)
			{
				cout << "Player 1 won on the board " << board_no + 1 << "." << endl;
			}
			if (player2->get_symbol() == p_char)
			{
				cout << "Player 2 won on the board " << board_no + 1 << "." << endl;
			}
		}

		board_no = next_move_board(x, y);

		return board_no;
	}

	// Returns the available moves for the given board and player character
	map<int, string> available_moves(int board_no, char p_char)
	{
		return small_boards[board_no]->available_moves(p_char);
	}

	void display_moves(int board_no, map<int, string> const &moves)
	{
		small_boards[board_no]->display_moves(moves);
	}

	// Player makes a move on the board
	void make_move(char p_char, int board_no, int x, int y)
	{
		small_boards[board_no]->make_move(p_char, x, y);
	}

	// Returns the board number of the next move
	int next_move_board(int x, int y)
	{
		if (x == 0)
		{
			if (y == 0)
			{
				if (small_boards[0]->get_status() != '0')
				{
					return -1;
				}
				return 0;
			}
			else if (y == 1)
			{
				if (small_boards[1]->get_status() != '0')
				{
					return -1;
				}
				return 1;
			}
			else
			{
				if (small_boards[2]->get_status() != '0')
				{
					return -1;
				}
				return 2;
			}
		}
		else if (x == 1)
		{
			if (y == 0)
			{
				if (small_boards[3]->get_status() != '0')
				{
					return -1;
				}
				return 3;
			}
			else if (y == 1)
			{
				if (small_boards[4]->get_status() != '0')
				{
					return -1;
				}
				return 4;
			}
			else
			{
				if (small_boards[5]->get_status() != '0')
				{
					return -1;
				}
				return 5;
			}
		}
		else
		{
			if (y == 0)
			{
				if (small_boards[6]->get_status() != '0')
				{
					return -1;
				}
				return 6;
			}
			else if (y == 1)
			{
				if (small_boards[7]->get_status() != '0')
				{
					return -1;
				}
				return 7;
			}
			else
			{
				if (small_boards[8]->get_status() != '0')
				{
					return -1;
				}
				return 8;
			}
		}
	}

	// Returns 1 if player 1 wins, 2 if player 2 wins, -1 if the round is over in a draw, 0 if the round is not over
	int round_over()
	{
		// Checking if any board is won horizontally
		if (small_boards[0]->get_status() == player1->get_symbol() && small_boards[1]->get_status() == player1->get_symbol() && small_boards[2]->get_status() == player1->get_symbol())
		{
			return 1;
		}
		if (small_boards[0]->get_status() == player2->get_symbol() && small_boards[1]->get_status() == player2->get_symbol() && small_boards[2]->get_status() == player2->get_symbol())
		{
			return 2;
		}
		if (small_boards[3]->get_status() == player1->get_symbol() && small_boards[4]->get_status() == player1->get_symbol() && small_boards[5]->get_status() == player1->get_symbol())
		{
			return 1;
		}
		if (small_boards[3]->get_status() == player2->get_symbol() && small_boards[4]->get_status() == player2->get_symbol() && small_boards[5]->get_status() == player2->get_symbol())
		{
			return 1;
		}
		if (small_boards[6]->get_status() == player1->get_symbol() && small_boards[7]->get_status() == player1->get_symbol() && small_boards[8]->get_status() == player1->get_symbol())
		{
			return 1;
		}
		if (small_boards[6]->get_status() == player2->get_symbol() && small_boards[7]->get_status() == player2->get_symbol() && small_boards[8]->get_status() == player2->get_symbol())
		{
			return 2;
		}

		// Checking if any board is won vertically
		if (small_boards[0]->get_status() == player1->get_symbol() && small_boards[3]->get_status() == player1->get_symbol() && small_boards[6]->get_status() == player1->get_symbol())
		{
			return 1;
		}
		if (small_boards[0]->get_status() == player2->get_symbol() && small_boards[3]->get_status() == player2->get_symbol() && small_boards[6]->get_status() == player2->get_symbol())
		{
			return 2;
		}
		if (small_boards[1]->get_status() == player1->get_symbol() && small_boards[4]->get_status() == player1->get_symbol() && small_boards[7]->get_status() == player1->get_symbol())
		{
			return 1;
		}
		if (small_boards[1]->get_status() == player2->get_symbol() && small_boards[4]->get_status() == player2->get_symbol() && small_boards[7]->get_status() == player2->get_symbol())
		{
			return 2;
		}
		if (small_boards[2]->get_status() == player1->get_symbol() && small_boards[5]->get_status() == player1->get_symbol() && small_boards[8]->get_status() == player1->get_symbol())
		{
			return 1;
		}
		if (small_boards[2]->get_status() == player2->get_symbol() && small_boards[5]->get_status() == player2->get_symbol() && small_boards[8]->get_status() == player2->get_symbol())
		{
			return 2;
		}

		// Checking if any board is won by diagonals
		if (small_boards[0]->get_status() == player1->get_symbol() && small_boards[4]->get_status() == player1->get_symbol() && small_boards[8]->get_status() == player1->get_symbol())
		{
			return 1;
		}
		if (small_boards[0]->get_status() == player2->get_symbol() && small_boards[4]->get_status() == player2->get_symbol() && small_boards[8]->get_status() == player2->get_symbol())
		{
			return 2;
		}
		if (small_boards[2]->get_status() == player1->get_symbol() && small_boards[4]->get_status() == player1->get_symbol() && small_boards[6]->get_status() == player1->get_symbol())
		{
			return 1;
		}
		if (small_boards[2]->get_status() == player2->get_symbol() && small_boards[4]->get_status() == player2->get_symbol() && small_boards[6]->get_status() == player2->get_symbol())
		{
			return 2;
		}

		// Checking if any board is won by corners
		if (small_boards[0]->get_status() == player1->get_symbol() && small_boards[2]->get_status() == player1->get_symbol() && small_boards[6]->get_status() == player1->get_symbol())
		{
			return 1;
		}
		if (small_boards[0]->get_status() == player1->get_symbol() && small_boards[2]->get_status() == player1->get_symbol() && small_boards[8]->get_status() == player1->get_symbol())
		{
			return 1;
		}
		if (small_boards[0]->get_status() == player2->get_symbol() && small_boards[2]->get_status() == player2->get_symbol() && small_boards[6]->get_status() == player2->get_symbol())
		{
			return 2;
		}
		if (small_boards[0]->get_status() == player2->get_symbol() && small_boards[2]->get_status() == player2->get_symbol() && small_boards[8]->get_status() == player2->get_symbol())
		{
			return 2;
		}
		if (small_boards[0]->get_status() == player1->get_symbol() && small_boards[6]->get_status() == player1->get_symbol() && small_boards[8]->get_status() == player1->get_symbol())
		{
			return 1;
		}
		if (small_boards[2]->get_status() == player1->get_symbol() && small_boards[6]->get_status() == player1->get_symbol() && small_boards[8]->get_status() == player1->get_symbol())
		{
			return 1;
		}
		if (small_boards[0]->get_status() == player2->get_symbol() && small_boards[6]->get_status() == player2->get_symbol() && small_boards[8]->get_status() == player2->get_symbol())
		{
			return 2;
		}
		if (small_boards[2]->get_status() == player2->get_symbol() && small_boards[6]->get_status() == player2->get_symbol() && small_boards[8]->get_status() == player2->get_symbol())
		{
			return 2;
		}

		// Checking if there is any board available
		if (any_boards_available() == false)
		{
			return -1;
		}
		return 0;
	}

	// Saves boards for the first and second round and forms large boards
	void save_boards()
	{
		if (game_round == 1)
			for (int i = 0; i < 9; i++)
			{
				large_boards[i] = new Board(*small_boards[i]);
			}

		if (game_round == 2)
		{
			for (int i = 9; i < 18; i++)
			{
				large_boards[i] = new Board(*small_boards[i - 9]);
			}
		}
	}

	// Handles the third round of the game
	void third_round()
	{
		char result;
		int p1_won = 0;
		int p2_won = 0;
		int coin = player1->flip_a_coin();
		cout << "\nA coin is flipped. ";
		if (coin == 0)
		{
			cout << "Result: +" << endl;
			for (int i = 0; i < 9; i++)
			{
				char round1_status = large_boards[i]->get_status();
				char round2_status = large_boards[i + 9]->get_status();
				result = round1_status + round2_status;
				if (result == player1->get_symbol())
				{
					p1_won++;
				}
				if (result == player2->get_symbol())
				{
					p2_won++;
				}
			}
		}
		else
		{
			cout << "Result: -" << endl;
			for (int i = 0; i < 9; i++)
			{
				char round1_status = large_boards[i]->get_status();
				char round2_status = large_boards[i + 9]->get_status();
				result = round1_status - round2_status;
				if (result == player1->get_symbol())
				{
					p1_won++;
				}
				if (result == player2->get_symbol())
				{
					p2_won++;
				}
			}
		}
		cout << "Player 1 won " << p1_won << " board(s)." << endl;
		cout << "Player 2 won " << p2_won << " board(s)." << endl;
		if (p1_won > p2_won)
		{
			cout << "Player 1 won round 3." << endl;
			player1->increment_won_games();
		}
		else if (p2_won > p1_won)
		{
			cout << "Player 2 won round 3." << endl;
			player2->increment_won_games();
		}
		else
		{
			cout << "Third round ends in tie!" << endl;
		}
		game_round++;
	}

	// Displays the large boards from round 1 and 2
	void display_large_boards()
	{
		cout << "Board from round 1:" << endl;
		for (int i = 0; i < 3; i++)
		{
			large_boards[0]->display_board(i);
			cout << "\t";
			large_boards[1]->display_board(i);
			cout << "\t";
			large_boards[2]->display_board(i);
			cout << endl;
		}
		cout << endl;

		for (int i = 0; i < 3; i++)
		{
			large_boards[3]->display_board(i);
			cout << "\t";
			large_boards[4]->display_board(i);
			cout << "\t";
			large_boards[5]->display_board(i);
			cout << endl;
		}
		cout << endl;

		for (int i = 0; i < 3; i++)
		{
			large_boards[6]->display_board(i);
			cout << "\t";
			large_boards[7]->display_board(i);
			cout << "\t";
			large_boards[8]->display_board(i);
			cout << endl;
		}

		cout << "\nBoard from round 2:" << endl;
		for (int i = 0; i < 3; i++)
		{
			large_boards[9]->display_board(i);
			cout << "\t";
			large_boards[10]->display_board(i);
			cout << "\t";
			large_boards[11]->display_board(i);
			cout << endl;
		}
		cout << endl;

		for (int i = 0; i < 3; i++)
		{
			large_boards[12]->display_board(i);
			cout << "\t";
			large_boards[13]->display_board(i);
			cout << "\t";
			large_boards[14]->display_board(i);
			cout << endl;
		}
		cout << endl;

		for (int i = 0; i < 3; i++)
		{
			large_boards[15]->display_board(i);
			cout << "\t";
			large_boards[16]->display_board(i);
			cout << "\t";
			large_boards[17]->display_board(i);
			cout << endl;
		}
	}

	// Prints the game result, if the game is over
	void game_over()
	{
		cout << "--------------------\nGAME OVER!" << endl;
		int p1_won = player1->get_won_games();
		int p2_won = player2->get_won_games();
		cout << "Player 1 won " << p1_won << " round(s)." << endl;
		cout << "Player 2 won " << p2_won << " round(s)." << endl;
		if (p1_won > p2_won)
		{
			cout << "Player 1 won the game!" << endl;
		}

		if (p2_won > p1_won)
		{
			cout << "Player 2 won the game!" << endl;
		}

		if (p1_won == p2_won)
		{
			cout << "Draw!" << endl;
		}
		cout << "--------------------" << endl;
	}

	// Returns true if the game is over
	bool is_finished()
	{
		if (player1->get_won_games() == 2 || player2->get_won_games() == 2)
		{
			return true;
		}
		if (player1->get_won_games() == 1 && player2->get_won_games() == 1 && game_round > 3)
		{
			return true;
		}
		return false;
	}
};