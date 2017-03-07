#ifndef ROGUE_H
#define ROGUE_H

#include <curses.h>
#include <stdlib.h>
#include <time.h>

/****** Struct Definitions ******/

typedef struct Game {
	struct Level * levels[10];
	int currentLevel;
} Game;

typedef struct Level {
	char ** tiles;
	int level;
	int numberOfRooms;
	struct Room ** rooms;
	struct Monster ** monsters;
	int numberOfMonsters;
	struct Player * user;
} Level;

typedef struct Position {
	int x;
	int y;
	//TILE_TYPE tile;
} Position;

typedef struct Room {
	Position position;
	int height;
	int width;

	struct Door ** doors;
	int numberOfDoors;
	//Monster ** monsters;
	//Item ** items;
} Room;

typedef struct Door {
	Position position;
	int connected;

} Door;

typedef struct Player {
	Position * position;
	int health;
	int attack;
	int gold;
	int maxHealth;
	int exp;
	//Room * room;
} Player;

typedef struct Monster {
	char string[2];
	char symbol;
	int health;
	int attack;
	int speed;
	int defence;
	int pathfinding;
	int alive;
	Position * position;
} Monster;

/****** Global Variables ******/
int MAX_HEIGHT;
int MAX_WIDTH;


int gameLoop(Game * game);
void drawLevel(Level * level);
void pathFind(Position * start, Position * end);

/* screen functions */
int screenSetUp();
int printGameHub(Level * level);

/* level/map functions */
Level * createLevel(int level);
Room ** roomsSetUp();
char ** saveLevelPositions();
void connectDoors(Level * level);

/* player functions */ 
Player *  playerSetUp();
Position * handleInput(int input, Player * user);
int checkPosition(Position * newPosition, Level * level);
int playerMove(Position * newPosition, Player * user, char ** level);
int placePlayer(Room ** rooms, Player * user);
void drawPlayer(Player * player);

/* room functions */
Room * createRoom(int grid, int numberOfDoors);
int drawRoom(Room * room);

/* monster functions */
int addMonsters(Level * level);
Monster * selectMonster(int level);
Monster * createMonster(char symbol, int health, int attack, int speed, int defence, int pathfinding);
int killMonster(Monster * monster);
int setStartingPosition(Monster * monster, Room * room);
int moveMonsters(Level * level);
int pathfindingSeek(Position * start, Position * destination);
int pathfindingRandom(Position * position);
Monster * getMonsterAt(Position * position, Monster ** monsters);
void drawMonster(Monster * monster);

/* combat functions */
int combat(Player * player, Monster * monster, int order);


#endif