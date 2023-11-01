#include "../../headers/game/player.h"

Player createPlayer(char *name)
{
    Player player;
    player.name = name;
    player.nbSeed = 0;
    player.opponent = NULL;

    return player;
}

void setOpponent(Player *player, Player *opponent)
{
    player->opponent = opponent;
}

void setBoard(Player *player, int board[16][3])
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            player->board[i][j] = board[i][j];
        }
    }
}

void setHoleVerify(Player *player, Verification holeVerify)
{
    player->holeVerify = holeVerify;
}

void setName(Player *player, const char *name)
{
    player->name = name;
}

void setNbSeed(Player *player, int nbSeed)
{
    player->nbSeed = nbSeed;
}

bool holeIsCorrect(Player *player, int holeNum)
{
    return player->holeVerify.satisfy(holeNum);
}

bool isStarved(Player *player)
{

    for (int i = 0; i < 16; i++)
    {
        if (holeIsCorrect(player, i) && (player->board[i][0] + player->board[i][1] + player->board[i][2]) != 0)
        {
            return false;
        }
    }

    return true;
}

int mobility(Player *player, int board[16][3])
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
