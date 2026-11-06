#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>

#include "player.h"

// readyplayerone
void player_init(Player *player, int row, int col) {

    player->pos.row = row;
    player->pos.col = col;

    player->walls_remainingHor= 5;
    player->walls_remainingVert= 5;
}

// readyplayertwo
int player2(int player) {

    if (player == 0)
    {
        return 1;
    }
    if (player == 1)
    {
        return 0;
    }
    return -1;
}
