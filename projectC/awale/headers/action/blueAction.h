#ifndef blueaction_h
#define blueaction_h

#include <stdlib.h>
#include "action.h"
#include "../game/player.h"

typedef struct BlueAction
{
    Action action;
} BlueAction;

// TODO pointer ?
BlueAction createBlueAction(int holeNumber, Player player);
// TODO pointer ?
int execute_blueAction(BlueAction *blueAction, int board[16][3]);
char *toStringBlueAction(BlueAction *blueAction);

#endif