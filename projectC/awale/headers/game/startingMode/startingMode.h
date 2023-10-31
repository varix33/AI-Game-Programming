#ifndef startingmode_h
#define startingmode_h

#include "../bot.h"

// TODO
typedef struct StartingMode
{
    void (*execute)(Bot bots[2], Bot *b1, Bot *b2, int board[16][3]);
} StartingMode;

#endif