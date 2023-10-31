#include "../../headers/action/transparentBlueAction.h"

TransparentBlueAction createTransparentBlueAction(int holeNumber, Player player)
{
    TransparentBlueAction transparentBlueAction;
    transparentBlueAction.action.holeNumber = holeNumber;
    transparentBlueAction.player = player;

    return transparentBlueAction;
}

int execute_transparentBlueAction(TransparentBlueAction *transparentBlueAction, int board[16][3])
{
    int nbSeed = board[transparentBlueAction->action.holeNumber][2];
    board[transparentBlueAction->action.holeNumber][2] = 0;

    if (nbSeed != 0)
    {
        int i = transparentBlueAction->action.holeNumber;

        for (; nbSeed > 0; i = (i + 1) % 16)
        {
            if (!holeIsCorrect(&(transparentBlueAction->player), i) && i != transparentBlueAction->action.holeNumber)
            {
                board[i][2]++;
                nbSeed--;
            }
        }

        i = (i == 0) ? 15 : i - 1;

        return seedCapturing(i, board);
    }

    return 0;
}

char *toStringTransparentBlueAction(TransparentBlueAction *transparentBlueAction)
{
    char *actionStr = toStringAction(&(transparentBlueAction->action));
    char *result = malloc(strlen(actionStr) + 3);
    strcpy(result, actionStr);
    strcat(result, "TB");
    free(actionStr);
    return result;
}
