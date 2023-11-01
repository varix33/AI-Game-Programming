#include "../headers/minMax.h"

// PLayer 1
bool satisfy_even(int nb)
{
    return nb % 2 == 0;
}

// Player 2
bool satisfy_odd(int nb)
{
    return nb % 2 == 1;
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

bool holeIsCorrect(int player, int holeNum)
{
    return player == 1 ? satisfy_even(holeNum) : satisfy_odd(holeNum);
}

bool isStarved(int player, int board[16][3])
{

    for (int i = 0; i < 16; i++)
    {
        if (holeIsCorrect(player, i) && (board[i][0] + board[i][1] + board[i][2]) != 0)
        {
            return false;
        }
    }

    return true;
}

int mobility(int player, int board[16][3])
{
    int mobility = 0;

    for (int i = 0; i < 16; i++)
    {
        if (holeIsCorrect(player, i))
        {
            if (board[i][0] > 0)
                mobility += 1;
            if (board[i][1] > 0)
                mobility += 1;
            if (board[i][2] > 0)
                mobility += 2;
        }
    }

    return mobility;
}

void printInfo(int alpha, int depth, long time, int mobility, char *name, int nbSeed, char *opponentName, int opponentNbSeed, int nbMove)
{
    printf("%s", ANSI_GREEN);
    printf("| mobility = %d | eval = %d | depth = %d | time = %ld |\n", mobility, alpha, depth, time);
    printf("| score %s = %d | score %s = %d | nbMove = %d |\n", name, nbSeed, opponentName, opponentNbSeed, nbMove);
    printf("%s\n", ANSI_RESET);
}

void printBoarding(int board[16][3])
{
    printf("\n");

    for (int i = 1; i <= 8; i++)
    {
        char str[10];
        sprintf(str, "[%d]", i);
        printf("%-5s", str);
        printf(" ");
    }

    printf("\n\n");

    for (int i = 0; i < 8; i++)
    {
        printf("(");
        printf(ANSI_BLUE "%d" ANSI_RESET, board[i][0]);
        printf(ANSI_RED "%d" ANSI_RESET, board[i][1]);
        printf(ANSI_GREEN "%d" ANSI_RESET, board[i][2]);
        printf(") ");
    }

    printf("\n");

    for (int i = 15; i >= 8; i--)
    {
        printf("(");
        printf(ANSI_BLUE "%d" ANSI_RESET, board[i][0]);
        printf(ANSI_RED "%d" ANSI_RESET, board[i][1]);
        printf(ANSI_GREEN "%d" ANSI_RESET, board[i][2]);
        printf(") ");
    }

    printf("\n\n");

    for (int i = 16; i > 8; i--)
    {
        char str[10];
        sprintf(str, "[%d]", i);
        printf("%-5s", str);
        printf(" ");
    }

    printf("\n\n");
}

int evaluate(int player, int nbSeedCapturedByMe, int nbSeedCapturedByOpponent, int board[16][3])
{
    int diffNbSeedCaptured = nbSeedCapturedByMe - nbSeedCapturedByOpponent;
    int diffMobility = mobility(player, board) - mobility(player % 2 + 1, board);

    return diffNbSeedCaptured * 3 + diffMobility;
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

int execute_blueAction(int player, int holeNumber, int board[16][3])
{
    int nbSeed = board[holeNumber][0];
    board[holeNumber][0] = 0;

    if (nbSeed != 0)
    {
        int i = holeNumber;

        for (; nbSeed > 0; i = (i + 1) % 16)
        {
            if (!holeIsCorrect(player, i) && i != holeNumber)
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

int execute_redAction(int player, int holeNumber, int board[16][3])
{
    int nbSeed = board[holeNumber][1];
    board[holeNumber][1] = 0;

    if (nbSeed != 0)
    {
        int i = holeNumber;

        for (; nbSeed > 0; i = (i + 1) % 16)
        {
            if (i != holeNumber)
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

int execute_transparentBlueAction(int player, int holeNumber, int board[16][3])
{
    int nbSeed = board[holeNumber][2];
    board[holeNumber][2] = 0;

    if (nbSeed != 0)
    {
        int i = holeNumber;

        for (; nbSeed > 0; i = (i + 1) % 16)
        {
            if (!holeIsCorrect(player, i) && i != holeNumber)
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

int execute_transparentRedAction(int player, int holeNumber, int board[16][3])
{
    int nbSeed = board[holeNumber][2];
    board[holeNumber][2] = 0;

    if (nbSeed != 0)
    {
        int i = holeNumber;

        for (; nbSeed > 0; i = (i + 1) % 16)
        {
            if (i != holeNumber)
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

// actions[16][3] : [16] 0 to 15 cases / [3] blue/red/transparent seeds
void possibleAction(int player, int board[16][3], bool actions[16][3])
{
    for (int i = 0; i < 16; i++)
    {

        actions[i][0] = holeIsCorrect(player, i) && board[i][0] > 0;
        actions[i][1] = holeIsCorrect(player, i) && board[i][1] > 0;
        actions[i][2] = holeIsCorrect(player, i) && board[i][2] > 0;
    }
}

int max(int x, int y)
{
    return x > y ? x : y;
}

int min(int x, int y)
{
    return x < y ? x : y;
}

int alphaBetaValue(int player, int board[16][3], int nbSeedPlayer, int nbSeedOpponent, int depth, int alpha, int beta, bool isMax)
{
    if (depth == 0)
    {
        return evaluate(player, nbSeedPlayer, nbSeedOpponent, board);
    }

    int boardDeepCopy[16][3];
    int nbSeedCapturedByPlayer;
    int nbSeedCapturedByOpponent;

    if (isMax)
    {
        bool noAction = true;

        for (int i = 0; i < 16; i++)
        {

            if (holeIsCorrect(player, i) && board[i][1] > 0)
            {
                noAction = false;

                deepCopy(board, boardDeepCopy);
                nbSeedCapturedByPlayer = execute_redAction(player, i, boardDeepCopy);
                alpha = max(alpha, alphaBetaValue(player, boardDeepCopy, nbSeedCapturedByPlayer + nbSeedPlayer, nbSeedOpponent, depth - 1, alpha, beta, false));

                if (alpha >= beta)
                {
                    return alpha;
                }
            }

            if (holeIsCorrect(player, i) && board[i][0] > 0)
            {
                noAction = false;

                deepCopy(board, boardDeepCopy);
                nbSeedCapturedByPlayer = execute_blueAction(player, i, boardDeepCopy);
                alpha = max(alpha, alphaBetaValue(player, boardDeepCopy, nbSeedCapturedByPlayer + nbSeedPlayer, nbSeedOpponent, depth - 1, alpha, beta, false));

                if (alpha >= beta)
                {
                    return alpha;
                }
            }

            if (holeIsCorrect(player, i) && board[i][2] > 0)
            {
                noAction = false;

                deepCopy(board, boardDeepCopy);
                nbSeedCapturedByPlayer = execute_transparentRedAction(player, i, boardDeepCopy);
                alpha = max(alpha, alphaBetaValue(player, boardDeepCopy, nbSeedCapturedByPlayer + nbSeedPlayer, nbSeedOpponent, depth - 1, alpha, beta, false));

                if (alpha >= beta)
                {
                    return alpha;
                }

                deepCopy(board, boardDeepCopy);
                nbSeedCapturedByPlayer = execute_transparentBlueAction(player, i, boardDeepCopy);
                alpha = max(alpha, alphaBetaValue(player, boardDeepCopy, nbSeedCapturedByPlayer + nbSeedPlayer, nbSeedOpponent, depth - 1, alpha, beta, false));

                if (alpha >= beta)
                {
                    return alpha;
                }
            }
        }

        if (noAction)
        {
            return evaluate(player, nbSeedPlayer, nbSeedOpponent, board);
        }

        return alpha;
    }

    bool noAction = true;

    for (int i = 0; i < 16; i++)
    {
        if (holeIsCorrect(player % 2 + 1, i) && board[i][1] > 0)
        {
            noAction = false;

            deepCopy(board, boardDeepCopy);
            nbSeedCapturedByOpponent = execute_redAction(player % 2 + 1, i, boardDeepCopy);
            beta = min(beta, alphaBetaValue(player, boardDeepCopy, nbSeedPlayer, nbSeedCapturedByOpponent + nbSeedOpponent, depth - 1, alpha, beta, true));

            if (alpha >= beta)
            {
                return beta;
            }
        }

        if (holeIsCorrect(player % 2 + 1, i) && board[i][0] > 0)
        {
            noAction = false;

            deepCopy(board, boardDeepCopy);
            nbSeedCapturedByOpponent = execute_blueAction(player % 2 + 1, i, boardDeepCopy);
            beta = min(beta, alphaBetaValue(player, boardDeepCopy, nbSeedPlayer, nbSeedCapturedByOpponent + nbSeedOpponent, depth - 1, alpha, beta, true));

            if (alpha >= beta)
            {
                return beta;
            }
        }

        if (holeIsCorrect(player % 2 + 1, i) && board[i][2] > 0)
        {
            noAction = false;

            deepCopy(board, boardDeepCopy);
            nbSeedCapturedByOpponent = execute_transparentRedAction(player % 2 + 1, i, boardDeepCopy);
            beta = min(beta, alphaBetaValue(player, boardDeepCopy, nbSeedPlayer, nbSeedCapturedByOpponent + nbSeedOpponent, depth - 1, alpha, beta, true));

            if (alpha >= beta)
            {
                return beta;
            }

            deepCopy(board, boardDeepCopy);
            nbSeedCapturedByOpponent = execute_transparentBlueAction(player % 2 + 1, i, boardDeepCopy);
            beta = min(beta, alphaBetaValue(player, boardDeepCopy, nbSeedPlayer, nbSeedCapturedByOpponent + nbSeedOpponent, depth - 1, alpha, beta, true));

            if (alpha >= beta)
            {
                return beta;
            }
        }
    }

    if (noAction)
    {
        return evaluate(player, nbSeedPlayer, nbSeedOpponent, board);
    }

    return beta;
}

char *toStringAction(int i, char *color)
{
    i++;
    char result[5];
    sprintf(result, "%d%s", i, color);
    char *action = (char *)malloc(strlen(result) + 1);
    strcpy(action, result);

    return action;
}

char *decisionAlphaBeta(int player, int nbMove, int board[16][3], int depthMax, bool information)
{
    int alpha = INT_MIN;
    int val;
    char *action = NULL;
    int nbSeedCapturedByPlayer;
    int boardDeepCopy[16][3];

    clock_t startTime = clock();

    for (int i = 0; i < 16; i++)
    {
        if (holeIsCorrect(player, i) && board[i][1] > 0)
        {
            deepCopy(board, boardDeepCopy);
            nbSeedCapturedByPlayer = execute_redAction(player, i, boardDeepCopy);
            val = alphaBetaValue(player, boardDeepCopy, nbSeedCapturedByPlayer, 0, depthMax - 1, alpha, INT_MAX, false);

            if (val > alpha)
            {
                action = toStringAction(i, "R");
                alpha = val;
            }
        }

        if (holeIsCorrect(player, i) && board[i][0] > 0)
        {

            deepCopy(board, boardDeepCopy);
            nbSeedCapturedByPlayer = execute_blueAction(player, i, boardDeepCopy);
            val = alphaBetaValue(player, boardDeepCopy, nbSeedCapturedByPlayer, 0, depthMax - 1, alpha, INT_MAX, false);

            if (val > alpha)
            {
                action = toStringAction(i, "B");
                alpha = val;
            }
        }

        if (holeIsCorrect(player, i) && board[i][2] > 0)
        {
            deepCopy(board, boardDeepCopy);
            nbSeedCapturedByPlayer = execute_transparentRedAction(player, i, boardDeepCopy);
            val = alphaBetaValue(player, boardDeepCopy, nbSeedCapturedByPlayer, 0, depthMax - 1, alpha, INT_MAX, false);

            if (val > alpha)
            {
                action = toStringAction(i, "TR");
                alpha = val;
            }

            deepCopy(board, boardDeepCopy);
            nbSeedCapturedByPlayer = execute_transparentBlueAction(player, i, boardDeepCopy);
            val = alphaBetaValue(player, boardDeepCopy, nbSeedCapturedByPlayer, 0, depthMax - 1, alpha, INT_MAX, false);

            if (val > alpha)
            {
                action = toStringAction(i, "TB");
                alpha = val;
            }
        }
    }

    clock_t endTime = clock();

    if (information)
    {
        printInfo(alpha, depthMax, endTime - startTime, mobility(player, board), "Colin", 0, "Antoine", 0, nbMove);
    }

    return action;
}
