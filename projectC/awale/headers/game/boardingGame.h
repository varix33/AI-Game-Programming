#ifndef boardinggame_h
#define boardinggame_h

#include <stdio.h>
#include <stdbool.h>
#include "startingMode/startingMode.h"

#define ANSI_RESET "\033[0m"
#define ANSI_RED "\033[31m"
#define ANSI_BLUE "\033[34m"
#define ANSI_GREEN "\033[32m"

// TODO
typedef struct BoardingGame
{
    int board[16][3];
    Bot bots[2];
} BoardingGame;

// TODO
BoardingGame createBoardingGame(Bot b1, Bot b2, StartingMode mode);
// TODO
int remainingSeed(BoardingGame *boardingGame);
// TODO
void printBoarding(BoardingGame *boardingGame);
// TODO
bool isGameOver(BoardingGame *boardingGame);
// TODO
void playGame(BoardingGame *boardingGame);

#endif
