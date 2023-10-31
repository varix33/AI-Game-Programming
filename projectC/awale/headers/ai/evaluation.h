#ifndef evaluation_h
#define evaluation_h

#include "../game/player.h"

// TODO
typedef struct Evaluation
{
    int (*evaluate)(Player player, int nbSeedCapturedByMe, int nbSeedCapturedByOpponent, int board[16][3]);
} Evaluation;

#endif