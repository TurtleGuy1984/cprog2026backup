#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>

#include "display.h"


void dispBoard(const Game *game) {
    for (int row = 0; row < SIZE; row++) 
    {

        /* Print cells + vertical walls */
        for (int col = 0; col < SIZE; col++) 
        {
            char cell = '.';

            if (game->players[0].pos.row == row && game->players[0].pos.col == col)
            {
                cell = '1';
            }else if (game->players[1].pos.row == row && game->players[1].pos.col == col)
            {
                cell = '2';
            }

            printf(" %c ", cell);

            if (col < SIZE - 1) 
            {
                if (row < 8 && game->walls.vertical[row][col])
                {
                    printf("|");
                }else
                {
                    printf(" ");
                }
            }
        }

        printf("\n");

        /* Print horizontal walls */
        if (row < SIZE - 1) {
            for (int col = 0; col < SIZE; col++) 
            {
                if (col < 8 && game->walls.horizontal[row][col])
                {
                    printf("---");
                }else
                {
                    printf("   ");
                }
                if (col < SIZE - 1)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    printf("Player 1 horizontal walls remaining: %d\n", game->players[0].walls_remainingHor);
    printf("Player 1 vertical walls remaining: %d\n", game->players[0].walls_remainingHor);

    printf("Player 2 horizontal walls remaining: %d\n", game->players[1].walls_remainingHor);
    printf("Player 2 vertical walls remaining: %d\n", game->players[1].walls_remainingVert);
}

void dispTurn(const Game *game) {
    printf("\nPlayer %d's turn\n", game->curr_player + 1);
}