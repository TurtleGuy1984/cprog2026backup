#ifndef BOARD_H
#define BOARD_H

#include "../game/game.h"

// Check whether a pawn can move to a given position
int valmove(const Game *game, int row, int col);

// Move the current player's pawn
void playermove(Game *game, int row, int col);

#endif
