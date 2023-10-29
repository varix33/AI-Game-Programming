#ifndef bot1_h
#define bot1_h

#include "bot.h"
#include "../action/action.h"

typedef struct Bot1
{
    Bot bot;
} Bot1;

Bot1 createBot1();
Action chooseAction_bot1();

#endif