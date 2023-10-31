#include "../../headers/game/boardingGame.h"

BoardingGame createBoardingGame(Bot *b1, Bot *b2, StartingMode mode)
{
    BoardingGame boardingGame;

    for (int i = 0; i < 16; i++)
    {
        boardingGame.board[i][0] = 2;
        boardingGame.board[i][1] = 2;
        boardingGame.board[i][2] = 1;
    }

    // Select which player starts regarding the mode selected (manual/random)
    mode.execute(boardingGame.bots, b1, b2, boardingGame.board);

    return boardingGame;
}

int remainingSeed(BoardingGame *boardingGame)
{
    int nbSeed = 0;

    for (int i = 0; i < 16; i++)
    {
        nbSeed += boardingGame->board[i][0] + boardingGame->board[i][1] + boardingGame->board[i][2];
    }

    return nbSeed;
}

void printBoarding(BoardingGame *boardingGame)
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
        printf(ANSI_BLUE "%d" ANSI_RESET, boardingGame->board[i][0]);
        printf(ANSI_RED "%d" ANSI_RESET, boardingGame->board[i][1]);
        printf(ANSI_GREEN "%d" ANSI_RESET, boardingGame->board[i][2]);
        printf(") ");
    }

    printf("\n");

    for (int i = 15; i >= 8; i--)
    {
        printf("(");
        printf(ANSI_BLUE "%d" ANSI_RESET, boardingGame->board[i][0]);
        printf(ANSI_RED "%d" ANSI_RESET, boardingGame->board[i][1]);
        printf(ANSI_GREEN "%d" ANSI_RESET, boardingGame->board[i][2]);
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

bool isGameOver(BoardingGame *boardingGame)
{
    int player0NbSeed = *(boardingGame->bots[0].player->nbSeed);
    int player1NbSeed = *(boardingGame->bots[1].player->nbSeed);

    // Less than 10 seeds
    if (remainingSeed(boardingGame) < 10)
    {
        printf("Less than 10 seeds !\n");

        if (player0NbSeed > player1NbSeed)
        {
            printf("%s won with %d seeds!\n", boardingGame->bots[0].player->name, player0NbSeed);
        }
        else if (player0NbSeed < player1NbSeed)
        {
            printf("%s won with %d seeds!\n", boardingGame->bots[1].player->name, player1NbSeed);
        }
        else
        {
            printf("Draw !!\n");
        }

        return true;
    }

    // More than 40 seeds
    if (player0NbSeed > 40)
    {
        printf("%s won with %d seeds!\n", boardingGame->bots[0].player->name, player0NbSeed);

        return true;
    }
    if (player1NbSeed > 40)
    {
        printf("%s won with %d seeds!\n", boardingGame->bots[1].player->name, player1NbSeed);

        return true;
    }

    // Draw
    if (player0NbSeed == 40 && player1NbSeed == 40)
    {
        printf("Draw !!\n");

        return true;
    }

    return false;
}

void playGame(BoardingGame *boardingGame)
{
    bool gameOver = false;

    printf("GAME START\n");
    printf("%s starts with odd holes\n", boardingGame->bots[0].player->name);
    printf("%s continue with even holes\n", boardingGame->bots[1].player->name);

    printBoarding(boardingGame);

    for (int i = 0; !gameOver; i = (i + 1) % 2)
    {
        playBot(&(boardingGame->bots[i]), boardingGame->bots[i].player->board);
        gameOver = true;
        // printBoarding(boardingGame);

        // // Starving
        // if (boardingGame->players[i].opponent)
        // {
        //     boardingGame->players[i].nbSeed = 80 - boardingGame->players[i].opponent->nbSeed;
        //     printf("%s starved %s and obtained the last seeds !", boardingGame->players[i].name, boardingGame->players[i].opponent->name);
        // }

        // gameOver = isGameOver(boardingGame);
    }
}
