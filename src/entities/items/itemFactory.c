#include "rogue.h"
#include "item.h"
#include "weapon.h"

Item * createSword(int attack, int health) {
	Item * item = malloc(sizeof(Item));
	item->type = WEAPON_TYPE;
	strcpy(item->string, "Sword");

	Weapon * weapon = malloc(sizeof(Weapon));
	weapon->attack = attack;
	weapon->attack = health;

	item->item.weapon = weapon;

	return item;
}