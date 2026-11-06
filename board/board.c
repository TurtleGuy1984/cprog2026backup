#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>

#include "board.h"


// Check legal move
int valmove(const Game *game, int row, int col) {

    int p = game->curr_player;

    Position current = game->players[p].pos;
    Position opponent = game->players[1 - p].pos;

    // Check board boundz
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) 
    {
        return 0;
    }

    int dr = abs(row - current.row);
    int dc = abs(col - current.col);

    if (dr + dc != 1) 
    {
        return 0;
    }
    if (row == opponent.row && col == opponent.col) 
    {
        return 0;
    }
    if (row < current.row && game->walls.horizontal[row][col]) 
    {
        return 0;
    }
    if (row > current.row && game->walls.horizontal[current.row][col]) 
    {
        return 0;
    }
    if (col < current.col && game->walls.vertical[row][col]) 
    {
        return 0;
    }
    if (col > current.col && game->walls.vertical[row][current.col]) 
    {
        return 0;
    }

    return 1;
}

// Move the current pawn
void playermove(Game *game, int row, int col) {

    if (valmove(game, row, col)) {
        int p = game->curr_player;

        game->players[p].pos.row = row;
        game->players[p].pos.col = col;
    }
}
