#ifndef ITEM_H
#define ITEM_H

#include "position.h"
#include "weapon.h"

typedef enum { WEAPON_TYPE, POTION_TYPE } ItemType;

typedef struct Item
{
	ItemType type;
	Position * position;

	union {
		Weapon * weapon;
//		Potion * potion;
	} item;

	char string[256];

} Item;

Item * createSword(int attack, int health);

#endif