#ifndef minmax_h
#define minmax_h

#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include "evaluation.h"
#include "deque.h"
#include "../action/blueAction.h"
#include "../action/redAction.h"
#include "../action/transparentBlueAction.h"
#include "../action/transparentRedAction.h"

#define ANSI_GREEN_1 "\x1B[32m"
#define ANSI_RESET_1 "\x1B[0m"

// TODO
typedef struct MinMax
{
    Player *player;
    Evaluation *evaluation;
    int nbMove;
} MinMax;

// TODO
MinMax createMinMax(Player *player, Evaluation *evaluation);
// TODO
void setEvaluation(MinMax *minMax, Evaluation *evaluation);
// TODO
void deepCopy(int board[16][3], int boardCopy[16][3]);
// TODO
Action decisionAlphaBeta(MinMax *minMax, int board[16][3], int depthMax, bool information);
// TODO
int alphaBetaValue(MinMax *minMax, int board[16][3], int nbSeedPlayer, int nbSeedOpponent, int depth, int alpha, int beta, bool isMax);
// TODO
Deque *possibleAction(Player *player, int board[16][3]);
// TODO
void printInfo(MinMax *minMax, int alpha, int depth, long time, int mobility);

#endif