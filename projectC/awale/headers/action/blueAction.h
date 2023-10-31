#ifndef blueaction_h
#define blueaction_h

#include <stdlib.h>
#include "../game/player.h"

// TODO
typedef struct BlueAction
{
    Action action;
    Player player;
} BlueAction;

// TODO
BlueAction createBlueAction(int holeNumber, Player player);
// TODO
int execute_blueAction(BlueAction *blueAction, int board[16][3]);
// TODO
char *toStringBlueAction(BlueAction *blueAction);

#endif