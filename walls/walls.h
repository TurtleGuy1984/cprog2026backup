
#ifndef WALLS_H
#define WALLS_H

#include "../game/game.h"

// Do you wanna build a *WALL*
int walls_valid_placement(const Game *game, char orientation, int row, int col);

// WEGONNABUILDAWALL
int walls_place(Game *game, char orientation, int row, int col);

#endif
