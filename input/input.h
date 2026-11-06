#ifndef INPUT_H
#define INPUT_H

typedef enum {
    MOVE,
    PLACE_WALL
} ActionType;

typedef struct {
    ActionType type;
    int row;
    int col;
    char orientation;
} Action;

/* Returns 1 on success, -1 on invalid input, 0 on EOF */
int input(Action *action);

#endif