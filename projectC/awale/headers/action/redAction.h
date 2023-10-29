#ifndef redaction_h
#define redaction_h

#include <stdlib.h>
#include "action.h"
#include "../game/player.h"

typedef struct RedAction
{
    Action action;
} RedAction;

// TODO pointer ?
RedAction createRedAction(int holeNumber, Player player);
// TODO pointer ?
int execute_redAction(RedAction *redAction, int board[16][3]);
char *toStringRedAction(RedAction *redAction);

#endif