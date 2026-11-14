
#ifndef GAME_H
#define GAME_H

// Represents a position on the board
typedef struct {
    int row;
    int col;
} Position;

// Represents a player
typedef struct {
    Position pos;
    int walls_remainingVert;
    int walls_remainingHor;
} Player;

// Represents all walls on the board
typedef struct {
    int horizontal[8][9];
    int vertical[9][8];
} Walls;

// Represents the complete game state
typedef struct {
    Player players[2];
    Walls walls;
    int curr_player;
} Game;
void game_init(Game *game);
void myturn(Game *game);
int win(const Game *game, int player);

#endif
