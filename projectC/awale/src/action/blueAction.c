#include "../../headers/action/blueAction.h"

BlueAction createBlueAction(int holeNumber, Player player)
{
    BlueAction blueAction;
    blueAction.action.holeNumber = holeNumber;
    blueAction.player = player;

    return blueAction;
}

int execute_blueAction(BlueAction *blueAction, int board[16][3])
{
    int nbSeed = board[blueAction->action.holeNumber][0];
    board[blueAction->action.holeNumber][0] = 0;

    if (nbSeed != 0)
    {
        int i = blueAction->action.holeNumber;

        for (; nbSeed > 0; i = (i + 1) % 16)
        {
            if (!holeIsCorrect(&(blueAction->player), i) && i != blueAction->action.holeNumber)
            {
                board[i][0]++;
                nbSeed--;
            }
        }

        i = (i == 0) ? 15 : i - 1;

        return seedCapturing(i, board);
    }

    return 0;
}

char *toStringBlueAction(BlueAction *blueAction)
{
    char *actionStr = toStringAction(&(blueAction->action));
    char *result = malloc(strlen(actionStr) + 2);
    strcpy(result, actionStr);
    strcat(result, "B");
    free(actionStr);
    return result;
}
