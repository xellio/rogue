#include "rogue.h"
#include "game.h"
#include "level.h"
#include "utils.h"

void render(Game * game) {
	clear();
	printGameHub(game->levels[game->currentLevel - 1]);
	drawLevel(game->levels[game->currentLevel - 1]);	
}

void gameLoop(Game * game) {
	int ch = '\0';
	Position * newPosition;
	Level * level;

	if (game->currentLevel == 0) {
		game->levels[game->currentLevel] = createLevel(1);
		game->currentLevel++;
	}
	level = game->levels[game->currentLevel - 1];

	/* main game loop */
	while(1) {

		if (ch == 'q' || ch == 'Q') {
			break;
		}
		if (ch == 'i' || ch == 'I') {
			printInventory(level->user);
		} else {
			newPosition = handleInput(ch, level->user);
			checkPosition(newPosition, level);
			moveMonsters(level);

			render(game);

			if (level->user->health <= 0) {
				game->currentLevel = 0;
				return;
			}
		}
		ch = getch();
	}
}