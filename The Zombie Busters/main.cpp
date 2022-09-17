#include "board.h"
#include "entities.h"
#include "resource.h"
#include "warrior.h"
#include "zombie.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

Warrior *chooseCharacter(int choice)
{
  if (choice == 1)
  {
    return new Derick();
  }
  else if (choice == 2)
  {
    return new Chichonne();
  }
}

Board generateBoard()
{
  std::cout << "---------------------------------------------------------------------" << std::endl;
  std::cout << "                      Welcome to our Board Game!\nThe Zombie Busters: Cleaning of Paradise Island from Zombie Infection\n"
            << std::endl;

  int size;

  while (true)
  {
    std::cout << "Please enter the size of the game board: ";
    std::cin >> size;
    if (size >= 5)
    {
      break;
    }
    std::cout << "Invalid size, please re-enter your size." << std::endl;
  }

  Board board(size);

  std::vector<Entities *> entities; // Array of entities

  // Ammunition
  int noAmmunition = 2 * floor(size * size / 25);
  for (int i = 0; i < noAmmunition; i++)
  {
    entities.push_back(new Ammunition());
  }

  // Zombie
  int noZombie = 2 * floor(size * size / 25);
  for (int i = 0; i < noZombie; i++)
  {
    switch (std::rand() % 3)
    {
    case 0:
      entities.push_back(new LargeZombie());
      break;
    case 1:
      entities.push_back(new MediumZombie());
      break;
    case 2:
      entities.push_back(new SmallZombie());
      break;
    }
  }

  // Medkit
  int noMedkit = 3 * floor(size * size / 25);

  for (int i = 0; i < noMedkit; i++)
  {
    switch (std::rand() % 2)
    {
    case 0:
      entities.push_back(new SmallMedkit());
      break;
    case 1:
      entities.push_back(new LargeMedkit());
      break;
    }
  }

  // Deploy entities.
  for (Entities *entity : entities)
  {
    board.deploy_(entity);
  }

  return board;
}

void playerTurn(Board &board, Warrior *player)
{
  std::cout << *player << std::endl;
  board.move(player);
  std::cout << board << std::endl;
  std::cout << "------------------------------" << std::endl
            << std::endl;
};

int main()
{
  std::srand(std::time(nullptr));
  Board board = generateBoard();

  int player1Dice = std::rand() % 6 + 1;
  int player2Dice = std::rand() % 6 + 1;

  do
  {
    std::cout << "\nPlayer1 rolled a dice: " << player1Dice << std::endl;
    std::cout << "Player2 rolled a dice: " << player2Dice << std::endl;
    if (player1Dice == player2Dice)
    {
      std::cout << "Tie! Let's roll again." << std::endl;
      player1Dice = std::rand() % 6 + 1;
      player2Dice = std::rand() % 6 + 1;
      std::cout << "\nPlayer1 rolled a dice: " << player1Dice << std::endl;
      std::cout << "Player2 rolled a dice: " << player2Dice << std::endl;
    }
  } while (player1Dice == player2Dice);

  int charChoice;
  Warrior *player1 = nullptr;
  Warrior *player2 = nullptr;

  // Player1 starts first
  if (player1Dice > player2Dice)
  {
    std::cout << "Player1 goes first!" << std::endl;
    do
    {
      std::cout << "Player1, Please choose a character.\n    Derick Dreams(1) and Chichonne Mohawk(2): ";
      std::cin >> charChoice;
      if (charChoice < 1 || charChoice > 2)
      {
        std::cout << "Invalid choice! Please re-enter.\n  Derick Dreams(1) and Chichonne Mohawk(2): ";
        std::cin >> charChoice;
      }
      else
      {
        player1 = chooseCharacter(charChoice);
        if (charChoice == 1)
        {
          player2 = chooseCharacter(2);
        }
        if (charChoice == 2)
        {
          player2 = chooseCharacter(1);
        }
      }
    } while (charChoice < 1 || charChoice > 2);
  }

  // Player2 starts first
  if (player1Dice < player2Dice)
  {
    std::cout << "Player2 goes first!" << std::endl;
    do
    {
      std::cout << "Player2, Please choose a character.\n  Derick Dreams(1) and Chichonne Mohawk(2): ";
      std::cin >> charChoice;
      if (charChoice < 1 || charChoice > 2)
      {
        std::cout << "Invalid choice!Please re-enter.\nDerick Dreams(1) and Chichonne Mohawk(2): ";
        std::cin >> charChoice;
      }
      else
      {
        player2 = chooseCharacter(charChoice);
        if (charChoice == 1)
        {
          player1 = chooseCharacter(2);
        }
        if (charChoice == 2)
        {
          player1 = chooseCharacter(1);
        }
      }
    } while (charChoice < 1 || charChoice > 2);
  }

  std::cout << "Player1 is " << player1->getCharName();
  std::cout << "\nPlayer2 is " << player2->getCharName();
  std::cout << "\n\nThe game has been started!\n";

  board.deploy_(player1);
  board.deploy_(player2);

  // Game starts.

  std::cout << board << std::endl;

  if (player1Dice >= player2Dice)
  {
    std::cout << "Player1: " << std::endl;
    playerTurn(board, player1);

    std::cout << "Player2: " << std::endl;
    playerTurn(board, player2);
  }
  else
  {
    std::cout << "Player2: " << std::endl;
    playerTurn(board, player2);

    std::cout << "Player1: " << std::endl;
    playerTurn(board, player1);
  }

  while (true)
  {
    // Checks if there still zombie exist in board.
    if (!board.isExist(ZombieType))
    {
      std::cout << "You win!" << std::endl;

      break;
    }
    // Checks whatever if 2 players are dead or not.
    else if (!(player1->isAlive() || player2->isAlive()))
    {
      std::cout << "You lost!" << std::endl;
      break;
    }

    if (player1Dice >= player2Dice)
    {
      if (player1->isAlive())
      {
        std::cout << "Player1: " << std::endl;
        playerTurn(board, player1);
      }

      if (player2->isAlive())
      {
        std::cout << "Player2: " << std::endl;
        playerTurn(board, player2);
      }
    }
    else
    {

      if (player2->isAlive())
      {
        std::cout << "Player2: " << std::endl;
        playerTurn(board, player2);
      }

      if (player1->isAlive())
      {
        std::cout << "Player1: " << std::endl;
        playerTurn(board, player1);
      }
    }

    std::cout << *player1 << std::endl;
    std::cout << *player2 << std::endl;
  }

  return 0;
}