#include "../../headers/game/boardingGame.h"

BoardingGame createBoardingGame(Player p1, Player p2, StartingMode mode)
{
    BoardingGame boardingGame;

    for (int i = 0; i < 16; i++)
    {
        boardingGame.board[i][0] = 2;
        boardingGame.board[i][1] = 2;
        boardingGame.board[i][2] = 1;
    }

    // Select which player starts regarding the mode selected (manual/random)
    mode.execute(boardingGame.players, p1, p2, boardingGame.board);

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
    // Less than 10 seeds
    if (remainingSeed(boardingGame) < 10)
    {
        printf("Less than 10 seeds !\n");

        if (boardingGame->players[0].nbSeed > boardingGame->players[1].nbSeed)
        {
            printf("%s won with %d seeds!\n", boardingGame->players[0].name, boardingGame->players[0].nbSeed);
        }
        else if (boardingGame->players[0].nbSeed < boardingGame->players[1].nbSeed)
        {
            printf("%s won with %d seeds!\n", boardingGame->players[1].name, boardingGame->players[1].nbSeed);
        }
        else
        {
            printf("Draw !!\n");
        }

        return true;
    }

    // More than 40 seeds
    if (boardingGame->players[0].nbSeed > 40)
    {
        printf("%s won with %d seeds!\n", boardingGame->players[0].name, boardingGame->players[0].nbSeed);

        return true;
    }
    if (boardingGame->players[1].nbSeed > 40)
    {
        printf("%s won with %d seeds!\n", boardingGame->players[1].name, boardingGame->players[1].nbSeed);

        return true;
    }

    // Draw
    if (boardingGame->players[0].nbSeed == 40 && boardingGame->players[1].nbSeed == 40)
    {
        printf("Draw !!\n");

        return true;
    }

    return false;
}

void play(BoardingGame *boardingGame)
{
    bool gameOver = false;

    printf("GAME START\n");
    printf("%s starts with odd holes\n", boardingGame->players[0].name);
    printf("%s continue with even holes\n", boardingGame->players[1].name);

    printBoarding(boardingGame);

    // TODO
    // for (int i = 0; !gameOver; i = (i + 1) % 2)
    // {
    //     boardingGame->players[i].play();
    //     printBoarding();

    //     // Starving
    //     if (boardingGame->players[i].getOpponent().isStarved())
    //     {
    //         boardingGame->players[i].setNbSeed(80 - boardingGame->players[i].getOpponent().getNbSeed());
    //         printf("%s starved %s and obtained the last seeds !", boardingGame->players[i].name, boardingGame->players[i].opponent.name);
    //     }

    //     gameOver = isGameOver();
    // }
}
