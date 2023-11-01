
#ifndef player_h
#define player_h

#include <stdbool.h>
#include <stdio.h>
#include "../verification/verification.h"
#include "../action/action.h"

// TODO
typedef struct Player
{
    int nbSeed;
    const char *name;
    struct Player *opponent;
    Verification holeVerify;
    int board[16][3];
} Player;

// TODO
Player createPlayer(char *name);
// TODO
void setOpponent(Player *player, Player *opponent);
// TODO
void setBoard(Player *player, int board[16][3]);
// TODO
void setHoleVerify(Player *player, Verification holeVerify);
// TODO
void setName(Player *player, const char *name);
// TODO
void setNbSeed(Player *player, int nbSeed);
// TODO
bool holeIsCorrect(Player *player, int holeNum);
// TODO
bool isStarved(Player *player);
// TODO
int mobility(Player *player, int board[16][3]);

#endif
