#ifndef transparentredaction_h
#define transparentredaction_h

#include <stdlib.h>
#include "../game/player.h"

// TODO
typedef struct TransparentRedAction
{
    Action action;
    Player player;
} TransparentRedAction;

// TODO
TransparentRedAction createTransparentRedAction(int holeNumber, Player player);
// TODO
int execute_transparentRedAction(TransparentRedAction *transparentRedAction, int board[16][3]);
// TODO
char *toStringTransparentRedAction(TransparentRedAction *transparentRedAction);

#endif