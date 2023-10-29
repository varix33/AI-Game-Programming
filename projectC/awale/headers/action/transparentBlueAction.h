#ifndef transparentblueaction_h
#define transparentblueaction_h

#include <stdlib.h>
#include "action.h"
#include "../game/player.h"

typedef struct TransparentBlueAction
{
    Action action;
} TransparentBlueAction;

// TODO pointer ?
TransparentBlueAction createTransparentBlueAction(int holeNumber, Player player);
// TODO pointer ?
int execute_transparentBlueAction(TransparentBlueAction *transparentBlueAction, int board[16][3]);
char *toStringTransparentBlueAction(TransparentBlueAction *transparentBlueAction);

#endif