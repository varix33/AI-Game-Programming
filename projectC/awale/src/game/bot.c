#include "../../headers/game/bot.h"

Bot createBot()
{
    Bot bot;
    bot.player = createPlayer();

    return bot;
}
