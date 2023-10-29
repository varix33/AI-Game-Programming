#include "../../headers/action/transparentRedAction.h"

TransparentRedAction createTransparentRedAction(int holeNumber, Player player)
{
    TransparentRedAction transparentRedAction;
    transparentRedAction.action.holeNumber = holeNumber;
    transparentRedAction.action.player = player;

    return transparentRedAction;
}

int execute_transparentRedAction(TransparentRedAction *transparentRedAction, int board[16][3])
{
    int nbSeed = board[transparentRedAction->action.holeNumber][2];
    board[transparentRedAction->action.holeNumber][2] = 0;

    if (nbSeed != 0)
    {
        int i = transparentRedAction->action.holeNumber;

        for (; nbSeed > 0; i = (i + 1) % 16)
        {
            if (!i != transparentRedAction->action.holeNumber)
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

char *toStringTransparentRedAction(TransparentRedAction *transparentRedAction)
{
    char *actionStr = toStringAction(&(transparentRedAction->action));
    char *result = malloc(strlen(actionStr) + 3);
    strcpy(result, actionStr);
    strcat(result, "TB");
    free(actionStr);
    return result;
}
