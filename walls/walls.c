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
    if (game->players[game->curr_player].walls_remainingHor <= 0 && game->players[game->curr_player].walls_remainingVert <= 0)
    {
        return 0;
    }
    if (orientation == 'H' && game->players[game->curr_player].walls_remainingHor > 0) 
    {

        // Check hori overlap
        if (game->walls.horizontal[row][col] || game->walls.horizontal[row][col + 1])
        {
            return 0;
        }
        // Check vert cross
        if (game->walls.vertical[row][col] || game->walls.vertical[row][col + 1])
        {
            return 0;
        }
    }else if (orientation == 'V' && game->players[game->curr_player].walls_remainingVert > 0) 
    {
        // Check vert overlap
        if (game->walls.vertical[row][col] ||game->walls.vertical[row + 1][col])
        {
            return 0;
        }
        // Check hori cross
        if (game->walls.horizontal[row][col] ||game->walls.horizontal[row + 1][col])
        {
            return 0;
        }

    }else 
    {
        return 0;
    }
    //if error
    return 1;
}
//checking if the wall cuts off the goal row
int path_exists(const Game *game, int player)
{
    int visited[9][9] = {0};

    // BFS queue: at most 81 cells
    Position queue[81];
    int front = 0, rear = 0;

    // Determine the player's goal row
    int goal_row = (player == 0) ? 8 : 0;

    // Start BFS at the player's current position
    Position start = game->players[player].pos;

    queue[rear++] = start;
    visited[start.row][start.col] = 1;

    // Directions: up, down, left, right
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (front < rear)
    {
        Position current = queue[front++];

        // if goal reached
        if (current.row == goal_row)
        {
            return 1;
        }

        // Explore all four neighbouring cells
        for (int i = 0; i < 4; i++)
        {
            int nr = current.row + dr[i];
            int nc = current.col + dc[i];

            // Check board boundaries
            if (nr < 0 || nr >= 9 ||
                nc < 0 || nc >= 9)
            {
                continue;
            }

            // Skip already visited cells
            if (visited[nr][nc])
            {
                continue;
            }

            // Check whether a wall blocks this movement
            int blocked = 0;

            if (i == 0) // Up
            {
                blocked = game->walls.horizontal[current.row - 1][current.col];
            }
            else if (i == 1) // Down
            {
                blocked = game->walls.horizontal[current.row][current.col];
            }
            else if (i == 2) // Left
            {
                blocked = game->walls.vertical[current.row][current.col - 1];
            }
            else if (i == 3) // Right
            {
                blocked = game->walls.vertical[current.row][current.col];
            }

            if (blocked)
            {
                continue;
            }

            // This cell is reachable
            visited[nr][nc] = 1;

            queue[rear++] = (Position){nr, nc};
        }
    }

    // Queue exhausted without reaching the goal
    return 0;
}
// Place a wall

int walls_place(Game *game, char orientation, int row, int col)
{
    orientation = toupper((unsigned char)orientation);

    // First check ordinary placement validity
    if (!walls_valid_placement(game, orientation, row, col))
    {
        return 0;
    }

    // Temporarily place the proposed wall
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

    // Check if the placed wall is legal
    if (!path_exists(game, 0) || !path_exists(game, 1))
    {
        // Tear it down
        if (orientation == 'H')
        {
            game->walls.horizontal[row][col] = 0;
            game->walls.horizontal[row][col + 1] = 0;
        }
        else
        {
            game->walls.vertical[row][col] = 0;
            game->walls.vertical[row + 1][col] = 0;
        }

        return 0;
    }

    //wall usage
    if (orientation == 'H')
    {
        game->players[game->curr_player].walls_remainingHor--;
    }
    else
    {
        game->players[game->curr_player].walls_remainingVert--;
    }

    return 1;
}
