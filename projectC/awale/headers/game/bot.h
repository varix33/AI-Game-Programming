#ifndef bot_h
#define bot_h

#include "../ai/minMax.h"
#include "../ai/evaluation.h"
#include "../ai/evaluation1.h"
#include "../ai/evaluation2.h"

// TODO
typedef struct Bot
{
    Player *player;
    MinMax minMax;

    Action (*chooseAction)(struct Bot *bot);
} Bot;

// TODO
Bot *createBot(char *name);
// TODO
void setMinMax(Bot *bot, MinMax minMax);
// TODO
void playBot(Bot *bot, int board[16][3]);

#endif
