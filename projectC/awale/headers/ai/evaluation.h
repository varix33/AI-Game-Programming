#ifndef evaluation_h
#define evaluation_h

#include "../game/bot.h"

typedef struct Evaluation
{
    int (*evaluate)(Bot bot, int nbSeedCapturedByMe, int nbSeedCapturedByOpponent, int board[16][3]);
} Evaluation;

#endif