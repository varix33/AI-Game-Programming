#include <stdio.h>
#include "headers/minMax.h"

int main()
{
    int board[16][3];

    board[0][0] = 5;
    board[0][1] = 0;
    board[0][2] = 1;

    board[1][0] = 5;
    board[1][1] = 0;
    board[1][2] = 0;

    board[2][0] = 4;
    board[2][1] = 0;
    board[2][2] = 0;

    board[3][0] = 0;
    board[3][1] = 0;
    board[3][2] = 1;

    board[4][0] = 0;
    board[4][1] = 0;
    board[4][2] = 0;

    board[5][0] = 0;
    board[5][1] = 4;
    board[5][2] = 1;

    board[6][0] = 0;
    board[6][1] = 0;
    board[6][2] = 0;

    board[7][0] = 0;
    board[7][1] = 1;
    board[7][2] = 0;

    board[8][0] = 0;
    board[8][1] = 0;
    board[8][2] = 0;

    board[9][0] = 0;
    board[9][1] = 0;
    board[9][2] = 0;

    board[10][0] = 0;
    board[10][1] = 0;
    board[10][2] = 0;

    board[11][0] = 0;
    board[11][1] = 0;
    board[11][2] = 0;

    board[12][0] = 0;
    board[12][1] = 0;
    board[12][2] = 1;

    board[13][0] = 0;
    board[13][1] = 0;
    board[13][2] = 0;

    board[14][0] = 1;
    board[14][1] = 0;
    board[14][2] = 0;

    board[15][0] = 0;
    board[15][1] = 0;
    board[15][2] = 0;

    printBoarding(board);

    printf("Action : %s\n", decisionAlphaBeta(1, 110, board, 8, true));

    return 0;
}