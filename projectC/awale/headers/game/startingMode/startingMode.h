#ifndef startingmode_h
#define startingmode_h

#include "../player.h"

typedef struct StartingMode
{
    void (*execute)(Player players[2], Player p1, Player p2, int board[16][3]);
} StartingMode;

#endif