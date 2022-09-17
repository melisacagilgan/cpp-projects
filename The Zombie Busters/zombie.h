#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <string.h>

class Zombie : public Entities
{
public:
  friend std::ostream &operator<<(std::ostream &out, const Zombie &zombie)
  {
    out << zombie.name;
    return out;
  }

  int getScore() const { return score; }

  int getHealth() const { return health; }

  void decHealth(int damage) { health -= damage; }

  int getDamage() const { return damage; }

protected:
  char name[32];
  int damage;
  int health;
  int score;
};

class LargeZombie : public Zombie
{
public:
  LargeZombie()
  {
    strcpy(name, "Large Zombie");
    size = 3;
    displayCharacter = 'L';
    damage = 8;
    health = 12;
    score = 100;
    type = ZombieType;
  }
};

class MediumZombie : public Zombie
{
public:
  MediumZombie()
  {
    strcpy(name, "Medium Zombie");
    size = 2;
    displayCharacter = 'M';
    damage = 4;
    health = 8;
    score = 75;
    type = ZombieType;
  }
};

class SmallZombie : public Zombie
{
public:
  SmallZombie()
  {
    strcpy(name, "Small Zombie");
    size = 1;
    displayCharacter = 'S';
    damage = 2;
    health = 4;
    score = 50;
    type = ZombieType;
  }
};

#endif