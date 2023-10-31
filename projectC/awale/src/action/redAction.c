#include "../../headers/action/redAction.h"

RedAction createRedAction(int holeNumber, Player player)
{
    RedAction redAction;
    redAction.action.holeNumber = holeNumber;
    redAction.player = player;

    return redAction;
}

int execute_redAction(RedAction *redAction, int board[16][3])
{
    int nbSeed = board[redAction->action.holeNumber][1];
    board[redAction->action.holeNumber][1] = 0;

    if (nbSeed != 0)
    {
        int i = redAction->action.holeNumber;

        for (; nbSeed > 0; i = (i + 1) % 16)
        {
            if (i != redAction->action.holeNumber)
            {
                board[i][1]++;
                nbSeed--;
            }
        }

        i = (i == 0) ? 15 : i - 1;

        return seedCapturing(i, board);
    }

    return 0;
}

char *toStringRedAction(RedAction *redAction)
{
    char *actionStr = toStringAction(&(redAction->action));
    char *result = malloc(strlen(actionStr) + 2);
    strcpy(result, actionStr);
    strcat(result, "R");
    free(actionStr);
    return result;
}
