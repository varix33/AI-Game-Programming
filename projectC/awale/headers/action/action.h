#ifndef action_h
#define action_h

#include <stdio.h>
#include <string.h>
#include "../game/player.h"

// TODO pointer or not
typedef struct Action
{
    Player player;
    int holeNumber;

    int (*execute)(int board[16][3]);
} Action;

// TODO pointer or not
Action createAction(int holeNumber, Player player);
int getHoleNumber(Action *action);
// TODO pointer or not
int seedCapturing(int lastHoleSowed, int board[16][3]);
char *toStringAction(Action *action);

#endif
