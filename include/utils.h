#ifndef UTILS_H
#define UTILS_H

#include "level.h"
#include "position.h"
#include "player.h"
#include "monster.h"

void pathFind(Position * start, Position * end);

void screenSetUp();
void printGameHub(Level * level);
void printInventory(Player * player);
void combat(Player * player, Monster * monster, int order);

#endif