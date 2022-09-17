#ifndef BOARD_H
#define BOARD_H

#include "entities.h"
#include "resource.h"
#include "warrior.h"

class Cell
{
public:
  Cell(){};

  Cell(Entities *_entity) { entity = _entity; }

  friend std::ostream &operator<<(std::ostream &out, const Cell &cell)
  {
    if (cell.isVisible)
    {
      out << *cell.entity;
    }
    else
    {
      out << ".";
    }
    return out;
  }

  bool isEmpty() const { return entity == nullptr; }

  Entities *getEntity() const { return entity; }

  void setEntity(Entities *_entity) { entity = _entity; }

  void setVisible(bool visible) { isVisible = visible; }

private:
  Entities *entity = nullptr;
  bool isVisible = false;
};

class Board
{
public:
  Board(int _size)
  {
    boardSize = _size;
    cells = new Cell[boardSize * boardSize];
  }

  friend std::ostream &operator<<(std::ostream &out, const Board &board)
  {
    for (int row = 0; row < board.boardSize; row++)
    {
      for (int col = 0; col < board.boardSize; col++)
      {
        out << " " << *board.get(row, col) << " ";
      }
      out << std::endl;
    }
    return out;
  }

  Cell *get(int row, int col) const { return &cells[row * boardSize + col]; }

  void removeEntity(const Entities *entity)
  {
    for (int i = 0; i < (boardSize * boardSize); i++)
    {
      if (!cells[i].isEmpty() && cells[i].getEntity() == entity)
      {
        cells[i].setVisible(false);
        cells[i].setEntity(nullptr);
      }
    }
  }

  void move(Warrior *player)
  {
    int x, y;
    // x and y starts from (1 ,1) NOT (0, 0)
    while (true)
    {
      std::cout << "x: ";
      std::cin >> x;
      std::cout << "y: ";
      std::cin >> y;
      if (player->getX() == x && player->getY() == y)
      {
        std::cout << "You cannot move to same location." << std::endl;
      }
      else if (x < 0 || x >= boardSize || y < 0 || y >= boardSize)
      {
        std::cout << "Invalid coordinates." << std::endl;
      }
      else if (!isCellEmpty(y, x) && get(y, x)->getEntity()->getType() == WarriorType)
      {
        std::cout << "There is another player in given coordinates." << std::endl;
      }
      else
      {
        break;
      }
    }

    // If cell that player moving is not empty.
    if (!isCellEmpty(y, x))
    {
      Entities *entity = get(y, x)->getEntity();
      EntityType type = entity->getType();

      if (type == AmmunitionType)
      {
        std::cout << "Found Ammunition." << std::endl;
        reveal(AmmunitionType);
        removeEntity(entity); // Removes ammunition from board.
        ((Resource *)entity)->applyEffect(player);
      }
      else if (type == SmallMedkitType)
      {
        std::cout << "Found Small Medkit." << std::endl;
        reveal(SmallMedkitType);
        ((Resource *)entity)->applyEffect(player);
        removeEntity(entity); // Removes small medkit from board.
      }
      else if (type == LargeMedkitType)
      {
        std::cout << "Found Large Medkit." << std::endl;
        reveal(LargeMedkitType);
        ((Resource *)entity)->applyEffect(player);
        removeEntity(entity); // Removes large medkit from board
      }
      else if (type == ZombieType)
      {
        std::cout << "Found Zombie." << std::endl;
        player->attack((Zombie *)entity);
        if (player->isAlive())
        {
          removeEntity(entity); // Removes zombie from board.
        }
        else
        {
          removeEntity(player); // Removes player from board.
        }
      }
    }
    if (player->isAlive())
    {
      removeEntity(player);      // Removes player from board.
      placeEntity(player, y, x); // Places new player cell in board.
    }
  }

  void placeEntity(Entities *entity, int y, int x)
  {
    cells[y * boardSize + x].setEntity(entity);
    if (entity->getType() == WarriorType)
    {
      cells[y * boardSize + x].setVisible(true);
    }
    else
    {
      cells[y * boardSize + x].setVisible(true);
    }
  }

  void deploy_(Entities *entity)
  {
    while (true)
    {
      int y = std::rand() % boardSize;
      int x = std::rand() % boardSize;
      if (isCellEmpty(y, x))
      {
        if (entity->getSize() == 1)
        {
          placeEntity(entity, y, x);
          if (entity->getType() == WarriorType)
          {
            ((Warrior *)entity)->setX(x);
            ((Warrior *)entity)->setY(y);
          }
          break;
        }
        else if (entity->getSize() == 2)
        {
          if (isCellEmpty(y, x + 1))
          {
            placeEntity(entity, y, x);
            placeEntity(entity, y, x + 1);
            break;
          }
          else if (isCellEmpty(y + 1, x))
          {
            placeEntity(entity, y, x);
            placeEntity(entity, y + 1, x);
            break;
          }
          else if (isCellEmpty(y + 1, x + 1))
          {
            placeEntity(entity, y, x);
            placeEntity(entity, y + 1, x + 1);
            break;
          }
          else if (isCellEmpty(y + 1, x - 1))
          {
            placeEntity(entity, y, x);
            placeEntity(entity, y + 1, x - 1);
            break;
          }
        }
        else if (entity->getSize() == 3)
        {
          if (isCellEmpty(y, x + 1) && isCellEmpty(y, x + 2))
          {
            placeEntity(entity, y, x);
            placeEntity(entity, y, x + 1);
            placeEntity(entity, y, x + 2);
            break;
          }
          else if (isCellEmpty(y + 1, x) && isCellEmpty(y + 2, x))
          {
            placeEntity(entity, y, x);
            placeEntity(entity, y + 1, x);
            placeEntity(entity, y + 2, x);
            break;
          }
          else if (isCellEmpty(y + 1, x + 1) && isCellEmpty(y + 2, x + 2))
          {
            placeEntity(entity, y, x);
            placeEntity(entity, y + 1, x + 1);
            placeEntity(entity, y + 2, x + 2);
            break;
          }
          else if (isCellEmpty(y + 1, x - 1) && isCellEmpty(y + 2, x - 2))
          {
            placeEntity(entity, y, x);
            placeEntity(entity, y + 1, x - 1);
            placeEntity(entity, y + 2, x - 2);
            break;
          }
        }
      }
    }
  }

  void reveal(EntityType entityClass)
  {
    for (int i = 0; i < (boardSize * boardSize); i++)
    {
      if (!cells[i].isEmpty() && cells[i].getEntity()->getType() == entityClass)
      {
        cells[i].setVisible(true);
      }
    }
  }

  bool isCellEmpty(int y, int x)
  {
    if (y >= boardSize || y < 0 || x >= boardSize || x < 0)
    {
      return false;
    }
    return cells[y * boardSize + x].isEmpty();
  }

  bool isExist(EntityType type)
  {
    for (int i = 0; i < (boardSize * boardSize); i++)
    {
      if (!cells[i].isEmpty() && cells[i].getEntity()->getType() == type)
      {
        return true;
      }
    }
    return false;
  }

private:
  int boardSize;
  Cell *cells;
};
#endif