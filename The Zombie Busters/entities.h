#ifndef ENTITIES_H
#define ENTITIES_H
#include <iostream>

typedef enum
{
  ResourceType,
  AmmunitionType,
  SmallMedkitType,
  LargeMedkitType,
  WarriorType,
  ZombieType
} EntityType;

class Entities
{
public:
  friend std::ostream &operator<<(std::ostream &out, Entities &entity)
  {
    out << entity.displayCharacter;
    return out;
  }

  EntityType getType() const { return type; }
  int getSize() const { return size; }

protected:
  char displayCharacter;
  int size;
  EntityType type;
};
#endif