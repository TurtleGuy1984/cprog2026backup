#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>

#include "walls.h"


// Check whether a wall can be placed
int walls_valid_placement(const Game *game, char orientation, int row, int col) {

    orientation = toupper(orientation);

    // Check coordinates
    if (row < 0 || row >= 8 || col < 0 || col >= 8)
    {
        return 0;
    }
    // Check available walls
    if (game->players[game->curr_player].walls_remaining <= 0)
    {
        return 0;
    }
    if (orientation == 'H') 
    {

        // Check overlapping horizontal walls
        if (game->walls.horizontal[row][col] || game->walls.horizontal[row][col + 1])
        {
            return 0;
        }
        // Check for crossing vertical walls
        if (game->walls.vertical[row][col] || game->walls.vertical[row][col + 1])
        {
            return 0;
        }
    }else if (orientation == 'V') 
    {
        // Check overlapping vertical walls
        if (game->walls.vertical[row][col] ||game->walls.vertical[row + 1][col])
        {
            return 0;
        }
        // Check crossing horizontal walls
        if (game->walls.horizontal[row][col] ||game->walls.horizontal[row + 1][col])
        {
            return 0;
        }

    }else 
    {
        return 0;
    }
    return 1;
}


// Place a wall
int walls_place(Game *game, char orientation, int row, int col) {

    orientation = toupper(orientation);

    if (!walls_valid_placement(game, orientation, row, col))
    {
        return 0;
    }

    if (orientation == 'H') 
    {
        game->walls.horizontal[row][col] = 1;
        game->walls.horizontal[row][col + 1] = 1;
    }
    else if (orientation == 'V')
    {
        game->walls.vertical[row][col] = 1;
        game->walls.vertical[row + 1][col] = 1;
    }

    (game->players[game->curr_player].walls_remaining)--;

    return 1;
}
