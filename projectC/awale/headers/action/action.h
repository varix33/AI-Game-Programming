#ifndef action_h
#define action_h

#include <stdio.h>
#include <string.h>

// TODO
typedef struct Action
{
    int holeNumber;

    int (*execute)(int board[16][3]);
} Action;

// TODO
Action createAction(int holeNumber);
// TODO
int getHoleNumber(Action *action);
// TODO
int seedCapturing(int lastHoleSowed, int board[16][3]);
// TODO
char *toStringAction(Action *action);

#endif
