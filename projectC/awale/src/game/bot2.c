#include "../../headers/game/bot2.h"

Bot2 createBot2()
{
    Bot2 bot2;
    bot2.bot = createBot();
    bot2.bot.player.name = "Bot2";
    bot2.bot.player.chooseAction = chooseAction_bot2;

    return bot2;
}

Action chooseAction_bot2() {
    // TODO
}
