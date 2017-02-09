#include "rogue.h"

Level * createLevel(int level) {
	Level * newLevel;
	newLevel = malloc(sizeof(Level));

	newLevel->level = level;
	newLevel->numberOfRooms = 6;
	newLevel->rooms = roomsSetUp();
	connectDoors(newLevel);
	newLevel->tiles = saveLevelPositions();

	newLevel->user = playerSetUp();
	placePlayer(newLevel->rooms, newLevel->user);
	
	addMonsters(newLevel);

	return newLevel;
}

Room ** roomsSetUp() {
	int x;
	Room ** rooms;
	rooms = malloc(sizeof(Room)*6);

	for (x = 0; x < 6; x++) {
		rooms[x] = createRoom(x, 4);
		drawRoom(rooms[x]);
	}


//	connectDoors(rooms[0]->doors[3], rooms[1]->doors[1]);
//	pathFind(rooms[0]->doors[3], rooms[1]->doors[1]);
//	connectDoors(rooms[1]->doors[2], rooms[2]->doors[0]);

	return rooms;
}

void connectDoors(Level * level) {
	int i, j;
	int randomRoom, randomDoor;
	int count;


	for (i = 0; i < level->numberOfRooms; i++) {
		for (j = 0; j < level->rooms[i]->numberOfDoors; j++) {
			
			if (level->rooms[i]->doors[j]->connected == 1) {
				continue;
			}

			count = 0;

			while (count < 5) {

				randomRoom = rand() % level->numberOfRooms;
				randomDoor = rand() % level->rooms[randomRoom]->numberOfDoors;

				if (level->rooms[randomRoom]->doors[randomDoor]->connected == 1 || randomRoom == i) {
					count++;
					continue;
				}

				pathFind(&level->rooms[randomRoom]->doors[randomDoor]->position, &level->rooms[i]->doors[j]->position);
				
				level->rooms[randomRoom]->doors[randomDoor]->connected = 1;
				level->rooms[i]->doors[j]->connected = 1;
				break;
			}

		}
	}
}

char ** saveLevelPositions() {
	int x, y;
	char ** positions;
	positions = malloc(sizeof(char *) * MAX_HEIGHT);

	for (y = 0; y < MAX_HEIGHT; y++) {
		positions[y] = malloc(sizeof(char) * MAX_WIDTH);
		for (x = 0; x < MAX_WIDTH; x++) {
			positions[y][x] = mvinch(y, x);
		}
	}

	return positions;
}