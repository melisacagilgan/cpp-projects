#ifndef WARRIOR_H
#define WARRIOR_H

#include "zombie.h"
#include <string.h>
#include <vector>

class Warrior : public Entities
{
public:
  Warrior()
  {
    size = 1;
    type = WarriorType;
  }

  friend std::ostream &operator<<(std::ostream &out, const Warrior &player)
  {
    int totalScore = 0;
    out << "Health: " << player.health << std::endl;
    out << "Ammunition: " << player.ammonution << std::endl;
    out << "(" << player.characterName << ") killed: ";

    if (player.killedZombies.empty())
    {
      out << "No one";
    }
    else
    {
      for (Zombie *zombie : player.killedZombies)
      {
        totalScore += zombie->getScore();
        out << *zombie << " ";
      }
    }

    out << std::endl;
    out << "Total score: " << totalScore << std::endl;
    return out;
  }

  virtual void attack(Zombie *zombie) = 0;

  int getX() const { return x; }

  int getY() const { return y; }

  void setX(int _x) { x = _x; }

  void setY(int _y) { y = _y; }

  bool isAlive() const { return health > 0; }

  void incrementAmmo(int extraAmmo) { ammonution += extraAmmo; }

  void incHealth(int heal)
  {
    health += heal;
    if (health > 100)
    {
      health = 100;
    }
  }

  const char *getCharName() const { return characterName; }

protected:
  int health;
  int ammonution;
  int rangedDamage;
  int meleeDamage;
  char characterName[32];
  int x;
  int y;
  std::vector<Zombie *> killedZombies;
};

class Chichonne : public Warrior
{
private:
  int dice;
  int killNumber = 0;

public:
  void attack(Zombie *zombie) override
  {
    while (zombie->getHealth() > 0 && isAlive())
    {
      std::cout << "Player Health: " << health << std::endl
                << "Zombie Health: " << zombie->getHealth() << std::endl;
      if (ammonution > 0)
      {
        dice = std::rand() % 6 + 1;
        if (dice == 5 || dice == 6)
        {
          zombie->decHealth(rangedDamage + 5);
        }
        if (dice == 1 || dice == 2)
        {
          zombie->decHealth(rangedDamage - 2);
        }
        ammonution -= 1;
      }

      else
      {
        if (killNumber >= 2)
        {
          zombie->decHealth(meleeDamage + 2);
        }
        else
        {
          zombie->decHealth(meleeDamage);
        }
      }

      if (zombie->getHealth() <= 0)
      {
        if (ammonution == 0)
        {
          killNumber += 1;
        }
        killedZombies.push_back(zombie);
      }

      else
      {
        health -= zombie->getDamage();
      }
    }
    std::cout << "Player Health: " << health << std::endl
              << "Zombie Health: " << zombie->getHealth() << std::endl;
  }

  Chichonne() : Warrior()
  {
    strncpy(characterName, "Chichonne", 32);
    displayCharacter = 'C';
    health = 100;
    ammonution = 30;
    rangedDamage = 5;
    meleeDamage = 4;
  }
};

class Derick : public Warrior
{
public:
  void attack(Zombie *zombie) override
  {
    while (zombie->getHealth() > 0 && isAlive())
    {
      std::cout << "Player Health: " << health << std::endl
                << "Zombie Health: " << zombie->getHealth() << std::endl;
      if (ammonution > 0)
      {
        int dice = std::rand() % 6 + 1;
        if (dice == 5 || dice == 6)
        {
          zombie->decHealth(rangedDamage + 5);
        }
        if (dice == 1 || dice == 2)
        {
          zombie->decHealth(rangedDamage - 3);
        }
        if (zombie->getHealth() <= 0)
        {
          killedZombies.push_back(zombie);
        }
        ammonution -= 1;
        if (ammonution > 0 && zombie->getHealth() > 0)
        {
          int dice = std::rand() % 6 + 1;
          if (dice == 5 || dice == 6)
          {
            zombie->decHealth(rangedDamage + 5);
          }
          if (dice == 1 || dice == 2)
          {
            zombie->decHealth(rangedDamage - 3);
          }
          if (zombie->getHealth() <= 0)
          {
            killedZombies.push_back(zombie);
          }
          else
          {
            health -= zombie->getDamage();
          }
          ammonution -= 1;
        }
      }
      else
      {
        zombie->decHealth(meleeDamage);
        if (zombie->getHealth() > 0)
        {
          health -= zombie->getDamage();
        }
      }
    }
    std::cout << "Player Health: " << health << std::endl
              << "Zombie Health: " << zombie->getHealth() << std::endl;
  }

  Derick() : Warrior()
  {
    strncpy(characterName, "Derick", 32);
    displayCharacter = 'D';
    health = 100;
    ammonution = 30;
    rangedDamage = 10;
    meleeDamage = 1;
  }
};

#endif