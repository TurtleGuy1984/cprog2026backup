
#ifndef PLAYER_H
#define PLAYER_H

#include "../game/game.h"

// Initialize a player's position and wall count
void player_init(Player *player, int row, int col);

// Get the opponent's player number
int player2(int player);

#endif
