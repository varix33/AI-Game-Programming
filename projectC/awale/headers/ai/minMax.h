#ifndef minmax_h
#define minmax_h

#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include "evaluation.h"
#include "../game/bot.h"
#include "deque.h"

#define ANSI_GREEN "\x1B[32m"
#define ANSI_RESET "\x1B[0m"

typedef struct MinMax
{
    Bot *player;
    Evaluation evaluation;
    int nbMove;
} MinMax;

// TODO pointer ?
MinMax createMinMax(Bot *player, Evaluation evaluation);
// TODO pointer ?
void setEvaluation(MinMax *minMax, Evaluation evaluation);
// TODO pointer ?
void deepCopy(int board[16][3], int boardCopy[16][3]);
// TODO pointer ?
Action decisionAlphaBeta(MinMax *minMax, int board[16][3], int depthMax, bool information);
// TODO pointer ?
int alphaBetaValue(int board[16][3], int nbSeedPlayer, int nbSeedOpponent, int depth, int alpha, int beta, bool isMax);
// TODO pointer ?
Deque *possibleAction(Player player, int board[16][3]);
// TODO pointer ?
void printInfo(MinMax *minMax, int alpha, int depth, long time, int mobility);

#endif