
#ifndef player_h
#define player_h

#include <stdbool.h>
#include "../verification/verification.h"

typedef struct Action Action;

typedef struct Player
{
    int nbSeed;
    const char *name;
    struct Player *opponent;
    Verification holeVerify;
    int board[16][3];

    Action (*chooseAction)();
} Player;

Player createPlayer();
void setOpponent(Player *player, Player *opponent);
void setBoard(Player *player, int board[16][3]);
void setHoleVerify(Player *player, Verification holeVerify);
void setName(Player *player, const char *name);
void setNbSeed(Player *player, int nbSeed);
bool holeIsCorrect(Player *player, int holeNum);
bool isStarved(Player *player);
int mobility(Player *player, int board[16][3]);

#endif
