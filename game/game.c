#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>

#include "game.h"

// Initialize the game
void game_init(Game *game) {

    memset(game, 0, sizeof(Game));

    // Starting positions
    game->players[0].pos.row = 0;
    game->players[0].pos.col = 4;

    game->players[1].pos.row = 8;
    game->players[1].pos.col = 4;

    // Give each player 10 walls
    game->players[0].walls_remaining = MAX_WALLS;
    game->players[1].walls_remaining = MAX_WALLS;

    // Player 1 starts
    game->curr_player = 0;
}

// Switch turns
void myturn(Game *game) 
{
    game->curr_player = 1 - game->curr_player;
}

// Check winning condition
int win(const Game *game, int player) {

    if (player == 0) 
    {
        return game->players[0].pos.row == SIZE - 1;
    }

    if (player == 1) 
    {
        return game->players[1].pos.row == 0;
    }

    return 0;
}
