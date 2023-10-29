#ifndef transparentredaction_h
#define transparentredaction_h

#include <stdlib.h>
#include "action.h"
#include "../game/player.h"

typedef struct TransparentRedAction
{
    Action action;
} TransparentRedAction;

// TODO pointer ?
TransparentRedAction createTransparentBlueAction(int holeNumber, Player player);
// TODO pointer ?
int execute_transparentRedAction(TransparentRedAction *transparentRedAction, int board[16][3]);
char *toStringTransparentRedAction(TransparentRedAction *transparentRedAction);

#endif