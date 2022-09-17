#ifndef RESOURCE_H
#define RESOURCE_H
#include "warrior.h"

class Resource : public Entities
{
public:
  virtual void applyEffect(Warrior *player) = 0;
};

class LargeMedkit : public Resource
{
public:
  void applyEffect(Warrior *player) override { player->incHealth(20); }
  LargeMedkit()
  {
    size = 2;
    displayCharacter = '*';
    type = LargeMedkitType;
  }
};

class SmallMedkit : public Resource
{
public:
  void applyEffect(Warrior *player) override { player->incHealth(10); }
  SmallMedkit()
  {
    size = 1;
    displayCharacter = '+';
    type = SmallMedkitType;
  }
};

class Ammunition : public Resource
{
public:
  void applyEffect(Warrior *player) override { player->incrementAmmo(10); }
  Ammunition()
  {
    size = 1;
    displayCharacter = 'A';
    type = AmmunitionType;
  }
};

#endif