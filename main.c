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

        if (win(&game, game.curr_player)) 
        {
            dispBoard(&game);
            printf("Congratulations player %d, u is win!  :D\n", game.curr_player + 1);
            break;
        }

        myturn(&game);
    }

    return 0;
}