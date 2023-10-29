#include "../../headers/ai/minMax.h"

MinMax createMinMax(Bot *player, Evaluation evaluation)
{
    MinMax minMax;
    minMax.player = player;
    minMax.evaluation = evaluation;
    minMax.nbMove = 0;

    return minMax;
}

void setEvaluation(MinMax *minMax, Evaluation evaluation)
{
    minMax->evaluation = evaluation;
}

void deepCopy(int board[16][3], int boardCopy[16][3])
{
    for (int i = 0; i < 16; i++)
    {
        boardCopy[i][0] = board[i][0];
        boardCopy[i][1] = board[i][1];
        boardCopy[i][2] = board[i][2];
    }
}

Action decisionAlphaBeta(MinMax *minMax, int board[16][3], int depthMax, bool information)
{
    int alpha = INT_MIN;
    int val;
    int nbSeedCapturedByPlayer;
    int boardDeepCopy[16][3];
    Action *action = NULL;

    minMax->nbMove++;

    if (depthMax == 0)
    {
        // TODO
        fprintf(stderr, "Depth must be greater than 0\n");
        exit(EXIT_FAILURE);
    }

    clock_t startTime = clock();

    Deque *actions = possibleAction(minMax->player->player, board);
    Node *current = actions->front;
    int i = 0;

    while (current != NULL)
    {
        Action a = getActionAt(actions, i);

        deepCopy(board, boardDeepCopy);
        nbSeedCapturedByPlayer = a.execute(boardDeepCopy);
        val = alphaBetaValue(boardDeepCopy, nbSeedCapturedByPlayer, 0, depthMax - 1, alpha, INT_MAX, false);

        if (val > alpha)
        {
            action = &a;
            alpha = val;
        }

        i++;
        current = current->next;
    }

    clock_t endTime = clock();

    if (information)
    {
        printInfo(minMax, alpha, depthMax, endTime - startTime, mobility(&(minMax->player->player), board));
    }

    return *action;
}

int alphaBetaValue(int board[16][3], int nbSeedPlayer, int nbSeedOpponent, int depth, int alpha, int beta, bool isMax)
{
    // TODO
    return 0;
}

Deque *possibleAction(Player player, int board[16][3])
{
    Deque *deque = createDeque();
    // TODO
    return deque;
}

void printInfo(MinMax *minMax, int alpha, int depth, long time, int mobility)
{
    printf("%s", ANSI_GREEN);
    printf("| mobility = %d | eval = %d | depth = %d | time = %f |\n", mobility, alpha, depth, time);
    printf("| score %s = %d | score %s = %d | nbMove = %d |\n", minMax->player->player.name, minMax->player->player.nbSeed, minMax->player->player.opponent->name, minMax->player->player.opponent->nbSeed, minMax->nbMove);
    printf("%s\n", ANSI_RESET);
}