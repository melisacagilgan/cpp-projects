#include "Game.h"

int main()
{
	char answer;
	cout << "---------------------------------------" << endl;
	cout << "  WELCOME TO THE ULTIMATE TIC-TAC-TOE" << endl;
	cout << "---------------------------------------" << endl
		 << endl;
	do
	{
		char c1, c2;
		answer = '0';
		do
		{
			cout << "Enter the first player's character: ";
			cin >> c1;

			cout << "Enter the second player's character: ";
			cin >> c2;

			if (c1 == c2)
			{
				cout << "Error! Character of each player has to be distinct." << endl;
			}
			else if (c1 == '-')
			{
				cout << "Error! Character of a player has to be different than '-' " << endl;
				cout << "Enter the first player's character: ";
				cin >> c1;
			}
			else if (c2 == '-')
			{
				cout << "Error! Character of a player has to be different than '-' " << endl;
				cout << "Enter the second player's character: ";
				cin >> c2;
			}

		} while (c1 == c2 || c1 == '-' || c2 == '-');

		Player p1(c1);
		Player p2(c2);
		Game game(p1, p2);

		int coin;
		coin = p1.flip_a_coin();
		cout << "A coin is flipped. Who gets heads goes first." << endl;

		if (coin == 0)
		{
			cout << "Player 1 -> Heads" << endl;
			cout << "Player 2 -> Tails" << endl;
			cout << "Player 1 goes first!" << endl;
		}
		else
		{
			cout << "Player 1 -> Tails" << endl;
			cout << "Player 2 -> Heads" << endl;
			cout << "Player 2 goes first!" << endl;
		}

		cout << endl
			 << "GAME HAS STARTED!" << endl;
		game.play(coin);

		if (game.is_finished())
		{
			cout << "\nWould you like to play again? (Y/N) ";
			cin >> answer;
			cout << endl;
		}
	} while (answer == 'Y');
	return 0;
}