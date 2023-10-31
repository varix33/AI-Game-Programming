#ifndef transparentblueaction_h
#define transparentblueaction_h

#include <stdlib.h>
#include "../game/player.h"

// TODO
typedef struct TransparentBlueAction
{
    Action action;
    Player player;
} TransparentBlueAction;

// TODO
TransparentBlueAction createTransparentBlueAction(int holeNumber, Player player);
// TODO
int execute_transparentBlueAction(TransparentBlueAction *transparentBlueAction, int board[16][3]);
// TODO
char *toStringTransparentBlueAction(TransparentBlueAction *transparentBlueAction);

#endif