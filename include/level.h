#ifndef LEVEL_H
#define LEVEL_H

#include "position.h"
#include "monster.h"
#include "player.h"
#include "room.h"

typedef struct Level {
	char ** tiles;
	int level;
	int numberOfRooms;
	struct Room ** rooms;
	struct Monster ** monsters;
	int numberOfMonsters;
	struct Player * user;
} Level;

Level * createLevel(int level);
Room ** roomsSetUp();

void drawLevel(Level * level);
void connectDoors(Level * level);

char ** saveLevelPositions();

void addMonsters(Level * level);
void moveMonsters(Level * level);

void checkPosition(Position * newPosition, Level * level);

#endif