#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>

#include "input.h"


int input(Action *action) {
    char command;
    int row, col;

    printf("Enter action (M row col / W H row col / W V row col): ");

    if (scanf(" %c", &command) != 1) 
    {
        return 0;
    }

    command = toupper(command);

    if (command == 'M') 
    {
        if (scanf("%d %d", &row, &col) != 2) 
        {
            return -1;
        }

        action->type = MOVE;
        action->row = row;
        action->col = col;
        action->orientation = '\0';

        return 1;
    }

    if (command == 'W') 
    {
        if (scanf(" %c %d %d", &action->orientation, &row, &col) != 3) 
        {
            return -1;
        }

        action->orientation = toupper(action->orientation);

        if (action->orientation != 'H' && action->orientation != 'V') 
        {
            return -1;
        }

        action->type = PLACE_WALL;
        action->row = row;
        action->col = col;

        return 1;
    }

    return -1;
}