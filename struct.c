/*obsoletecode
typedef struct {
    int row, column;
} Pos;
typedef struct {
    Pos position;
    int wall_left;
} Player;
typedef struct {
    int hori[0][0];
    int vert[0][0];
} Wall;
typedef struct {
    Player players[2];
    Wall walls;
    int curr_player;
} Game;*/