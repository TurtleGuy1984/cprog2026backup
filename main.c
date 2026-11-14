#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>
//Introducing the...*drumroll* HEADERS
#include "game/game.h"
#include "board/board.h"
#include "walls/walls.h"
#include "display/display.h"
#include "input/input.h"

int main(void) {
    Game game;
    Action action;
    int result;
    int inf  = 42;
    game_init(&game);
    /*for (int col = 0; col < 9; col++) 
    {
        game.walls.horizontal[0][col] = 1;
    }
    printf("Player 1 path: %d\n", path_exists(&game, 0));
    printf("Player 2 path: %d\n", path_exists(&game, 1));
    minor testing of the BFS path search...it works so far
    */
    while (inf==42) 
    {
        dispBoard(&game);
        dispTurn(&game);

        result = input(&action);

        if (result == 0) 
        {
            printf("\nInput fin\n");
            break;
        }

        if (result == -1) 
        {
            printf("Bad input >:( Redo\n");
            continue;
        }
        if (action.type == QUIT) 
        {
            printf("\nRincewind gazed upon the vast, incomprehensible board before him.\nThen, deciding that it was probably best left incomprehensible, he turned on his heel and legged it.\n");
            break;
        }
        if (action.type == MOVE) 
        {
            if (!valmove(&game, action.row, action.col)) 
            {
                printf("Bad input >:( Redo\n");
                continue;
            }

            playermove(&game, action.row, action.col);
        }
        else if (action.type == PLACE_WALL) 
        {
            if (!walls_place(&game, action.orientation, action.row, action.col)) 
            {
                printf("Bad wall >:( Rebuild\n");
                continue;
            }
        }

        myturn(&game);
    }

    return 0;
}