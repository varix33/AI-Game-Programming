#ifndef bot_h
#define bot_h

#include "player.h"

typedef struct Bot
{
    Player player;
} Bot;

Bot createBot();

#endif
