#include "../../headers/ai/minMax.h"

MinMax createMinMax(Player *player, Evaluation *evaluation)
{
    MinMax minMax;
    // minMax.player = player;
    // minMax.evaluation = evaluation;
    // minMax.nbMove = 0;

    return minMax;
}

void setEvaluation(MinMax *minMax, Evaluation *evaluation)
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
    printf("%s", minMax->player.holeVerify->satisfy(2) ? "tt" : "ff");
    int alpha = INT_MIN;
    int val;
    int nbSeedCapturedByPlayer;
    int boardDeepCopy[16][3];
    Action action;

    // minMax->nbMove++;

    // if (depthMax == 0)
    // {
    //     // TODO
    //     fprintf(stderr, "Depth must be greater than 0\n");
    //     exit(EXIT_FAILURE);
    // }

    // clock_t startTime = clock();

    // Deque *actions = possibleAction(&(minMax->player), board);
    // Node *current = actions->front;
    // int i = 0;

    // while (current != NULL)
    // {
    //     Action a = getActionAt(actions, i);

    //     deepCopy(board, boardDeepCopy);
    //     nbSeedCapturedByPlayer = a.execute(boardDeepCopy);
    //     val = alphaBetaValue(minMax, boardDeepCopy, nbSeedCapturedByPlayer, 0, depthMax - 1, alpha, INT_MAX, false);

    //     if (val > alpha)
    //     {
    //         action = &a;
    //         alpha = val;
    //     }

    //     i++;
    //     current = current->next;
    // }

    // clock_t endTime = clock();

    // if (information)
    // {
    //     printInfo(minMax, alpha, depthMax, endTime - startTime, mobility(minMax->player, board));
    // }

    return action;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

int min(int x, int y)
{
    return x < y ? x : y;
}

int alphaBetaValue(MinMax *minMax, int board[16][3], int nbSeedPlayer, int nbSeedOpponent, int depth, int alpha, int beta, bool isMax)
{
    if (depth == 0)
    {
        return minMax->evaluation->evaluate(*(minMax->player), nbSeedPlayer, nbSeedOpponent, board);
    }

    Deque *actions;
    int boardDeepCopy[16][3];

    if (isMax)
    {
        actions = possibleAction(minMax->player, board);

        Node *current = actions->front;
        int i = 0;

        if (actions->front == NULL)
        {
            return minMax->evaluation->evaluate(*(minMax->player), nbSeedPlayer, nbSeedOpponent, board);
        }

        while (current != NULL)
        {
            Action a = getActionAt(actions, i);

            deepCopy(board, boardDeepCopy);
            int nbSeedCapturedByPlayer = a.execute(boardDeepCopy);
            alpha = max(alpha, alphaBetaValue(minMax, boardDeepCopy, nbSeedCapturedByPlayer + nbSeedPlayer, nbSeedOpponent, depth - 1, alpha, beta, false));

            if (alpha >= beta)
            {
                return alpha;
            }
        }

        return alpha;
    }

    actions = possibleAction(minMax->player->opponent, board);

    Node *current = actions->front;
    int i = 0;

    if (actions->front == NULL)
    {
        return minMax->evaluation->evaluate(*(minMax->player), nbSeedPlayer, nbSeedOpponent, board);
    }

    while (current != NULL)
    {
        Action a = getActionAt(actions, i);

        deepCopy(board, boardDeepCopy);
        int nbSeedCapturedByOpponent = a.execute(boardDeepCopy);
        beta = min(beta, alphaBetaValue(minMax, boardDeepCopy, nbSeedPlayer, nbSeedCapturedByOpponent + nbSeedOpponent, depth - 1, alpha, beta, true));

        if (beta <= alpha)
        {
            return beta;
        }
    }

    return beta;
}

Deque *possibleAction(Player *player, int board[16][3])
{
    Deque *actions = createDeque();

    for (int i = 0; i < 16; i++)
    {
        if (holeIsCorrect(player, i) && board[i][2] > 0)
        {
            // TODO pushBack, pushFront ?
            // pushBack(actions, createTransparentBlueAction(i, *player).action);
        }
    }

    // for (int i = 0; i < 16; i++)
    // {
    //     if (holeIsCorrect(player, i) && board[i][0] > 0)
    //     {
    //         pushBack(actions, createBlueAction(i, *player).action);
    //     }
    // }

    // for (int i = 0; i < 16; i++)
    // {
    //     if (holeIsCorrect(player, i) && board[i][2] > 0)
    //     {
    //         pushBack(actions, createTransparentRedAction(i, *player).action);
    //     }
    // }

    // for (int i = 0; i < 16; i++)
    // {
    //     if (holeIsCorrect(player, i) && board[i][1] > 0)
    //     {
    //         pushBack(actions, createRedAction(i, *player).action);
    //     }
    // }

    return actions;
}

void printInfo(MinMax *minMax, int alpha, int depth, long time, int mobility)
{
    printf("%s", ANSI_GREEN_1);
    printf("| mobility = %d | eval = %d | depth = %d | time = %ld |\n", mobility, alpha, depth, time);
    printf("| score %s = %d | score %s = %d | nbMove = %d |\n", minMax->player->name, minMax->player->nbSeed, minMax->player->opponent->name, minMax->player->opponent->nbSeed, minMax->nbMove);
    printf("%s\n", ANSI_RESET_1);
}