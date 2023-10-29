#ifndef boardinggame_h
#define boardinggame_h

#include <stdio.h>
#include <stdbool.h>
#include "player.h"
#include "startingMode/startingMode.h"

#define ANSI_RESET "\033[0m"
#define ANSI_RED "\033[31m"
#define ANSI_BLUE "\033[34m"
#define ANSI_GREEN "\033[32m"

typedef struct BoardingGame
{
    int board[16][3];
    Player players[2];
} BoardingGame;

// Déclarations des fonctions TODO
BoardingGame createBoardingGame(Player p1, Player p2, StartingMode mode);
// OK
int remainingSeed(BoardingGame *boardingGame);
// OK
void printBoarding(BoardingGame *boardingGame);
// OK
bool isGameOver(BoardingGame *boardingGame);
// TODO
void play(BoardingGame *boardingGame);

#endif
