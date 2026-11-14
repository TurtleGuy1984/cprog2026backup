#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>

#include "board.h"

// Check legal move
int valmove(const Game *game, int row, int col)
{
    int p = game->curr_player;

    Position current = game->players[p].pos;
    Position opponent = game->players[1 - p].pos;

    // Check board boundaries
    if (row < 0 || row >= 9 || col < 0 || col >= 9)
    {
        return 0;
    }

    int dr = row - current.row;
    int dc = col - current.col;

    // CASE 1: Normal movement (one square)
    if (abs(dr) + abs(dc) == 1)
    {
        // Cannot move onto opponent
        if (row == opponent.row && col == opponent.col)
        {
            return 0;
        }

        // Check horizontal walls
        if (row < current.row &&
            game->walls.horizontal[row][col])
        {
            return 0;
        }

        if (row > current.row &&
            game->walls.horizontal[current.row][col])
        {
            return 0;
        }

        // Check vertical walls
        if (col < current.col &&
            game->walls.vertical[row][col])
        {
            return 0;
        }

        if (col > current.col &&
            game->walls.vertical[row][current.col])
        {
            return 0;
        }

        return 1;
    }

    // CASE 2: Straight jump (two squares)
    if (abs(dr) + abs(dc) == 2 &&
        (dr == 0 || dc == 0))
    {
        // The opponent must be exactly between us and destination
        if (current.row + dr / 2 != opponent.row ||
            current.col + dc / 2 != opponent.col)
        {
            return 0;
        }

        // Check walls between current pawn and opponent,
        // and between opponent and destination
        if (dr < 0 &&
            (game->walls.horizontal[current.row - 1][current.col] ||
             game->walls.horizontal[opponent.row - 1][opponent.col]))
        {
            return 0;
        }

        if (dr > 0 &&
            (game->walls.horizontal[current.row][current.col] ||
             game->walls.horizontal[opponent.row][opponent.col]))
        {
            return 0;
        }

        if (dc < 0 &&
            (game->walls.vertical[current.row][current.col - 1] ||
             game->walls.vertical[opponent.row][opponent.col - 1]))
        {
            return 0;
        }

        if (dc > 0 &&
            (game->walls.vertical[current.row][current.col] ||
             game->walls.vertical[opponent.row][opponent.col]))
        {
            return 0;
        }

        return 1;
    }
    // CASE 3: Diagonal jump
if (abs(dr) == 1 && abs(dc) == 1)
{
    // Opponent must be adjacent
    if (abs(opponent.row - current.row) +
        abs(opponent.col - current.col) != 1)
        return 0;

    // Destination must be beside the opponent
    if (abs(row - opponent.row) +
        abs(col - opponent.col) != 1)
        return 0;

    // Opponent must be between current position and destination
    if (row == current.row || col == current.col)
        return 0;

    // Check that the edge from current pawn to opponent is not blocked
    if (opponent.row < current.row &&
        game->walls.horizontal[opponent.row][opponent.col])
        return 0;

    if (opponent.row > current.row &&
        game->walls.horizontal[current.row][current.col])
        return 0;

    if (opponent.col < current.col &&
        game->walls.vertical[opponent.row][opponent.col])
        return 0;

    if (opponent.col > current.col &&
        game->walls.vertical[current.row][current.col])
        return 0;

    // Check the edge from opponent to diagonal destination
    if (row < opponent.row &&
        game->walls.horizontal[row][opponent.col])
        return 0;

    if (row > opponent.row &&
        game->walls.horizontal[opponent.row][opponent.col])
        return 0;

    if (col < opponent.col &&
        game->walls.vertical[opponent.row][col])
        return 0;

    if (col > opponent.col &&
        game->walls.vertical[opponent.row][opponent.col])
        return 0;

    return 1;
}

    return 0;
}

// Move the current pawn
void playermove(Game *game, int row, int col) {

    if (valmove(game, row, col)) {
        int p = game->curr_player;

        game->players[p].pos.row = row;
        game->players[p].pos.col = col;
    }
}