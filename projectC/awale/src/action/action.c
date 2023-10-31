#include "../../headers/action/action.h"

Action createAction(int holeNumber)
{
    Action action;
    action.holeNumber = holeNumber;

    return action;
}

int getHoleNumber(Action *action)
{
    return action->holeNumber;
}

int seedCapturing(int lastHoleSowed, int board[16][3])
{
    int i = lastHoleSowed;
    int nbSeedCaptured = 0;
    int nbSeed;

    nbSeed = board[i][0] + board[i][1] + board[i][2];

    while (nbSeed == 2 || nbSeed == 3)
    {
        nbSeedCaptured += nbSeed;
        board[i][0] = 0;
        board[i][1] = 0;
        board[i][2] = 0;
        i = (i == 0) ? 15 : i - 1;
        nbSeed = board[i][0] + board[i][1] + board[i][2];
    }

    return nbSeedCaptured;
}

char *toStringAction(Action *action)
{
    char str[20];
    sprintf(str, "%d", getHoleNumber(action));
    return strdup(str);
}
