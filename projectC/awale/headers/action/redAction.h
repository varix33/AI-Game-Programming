#ifndef redaction_h
#define redaction_h

#include <stdlib.h>
#include "../game/player.h"

// TODO
typedef struct RedAction
{
    Action action;
    Player player;
} RedAction;

// TODO
RedAction createRedAction(int holeNumber, Player player);
// TODO
int execute_redAction(RedAction *redAction, int board[16][3]);
// TODO
char *toStringRedAction(RedAction *redAction);

#endif