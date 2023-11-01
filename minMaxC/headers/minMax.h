#ifndef minmax_h
#define minmax_h

#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_RESET "\033[0m"
#define ANSI_RED "\033[31m"
#define ANSI_BLUE "\033[34m"
#define ANSI_GREEN "\033[32m"

// OK
bool satisfy_odd(int nb);
// OK
bool satisfy_even(int nb);
// OK
void deepCopy(int board[16][3], int boardCopy[16][3]);
// OK
bool holeIsCorrect(int player, int holeNum);
// OK
bool isStarved(int player, int board[16][3]);
// OK
int mobility(int player, int board[16][3]);
// OK
void printInfo(int alpha, int depth, long time, int mobility, char *name, int nbSeed, char *opponentName, int opponentNbSeed, int nbMove);
// OK
void printBoarding(int board[16][3]);
// OK
int evaluate(int player, int nbSeedCapturedByMe, int nbSeedCapturedByOpponent, int board[16][3]);
// OK
int execute_blueAction(int player, int holeNumber, int board[16][3]);
// OK
int execute_redAction(int player, int holeNumber, int board[16][3]);
// OK
int execute_transparentBlueAction(int player, int holeNumber, int board[16][3]);
// OK
int execute_transparentRedAction(int player, int holeNumber, int board[16][3]);
// OK
int max(int x, int y);
// OK
int min(int x, int y);
// OK
void possibleAction(int player, int board[16][3], bool actions[16][3]);
// OK
int alphaBetaValue(int player, int board[16][3], int nbSeedPlayer, int nbSeedOpponent, int depth, int alpha, int beta, bool isMax);
// OK
char *toStringAction(int i, char *color);
// OK
char *decisionAlphaBeta(int player, int nbMove, int board[16][3], int depthMax, bool information);

#endif