#ifndef bot2_h
#define bot2_h

#include "bot.h"
#include "../action/action.h"

typedef struct Bot2
{
    Bot *bot;
} Bot2;

Bot2 createBot2();
Action chooseAction_bot2(Bot *bot);

#endif