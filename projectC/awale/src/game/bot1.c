#include "../../headers/game/bot1.h"

Bot1 createBot1()
{
    Bot1 bot1;
    bot1.bot = createBot();
    bot1.bot.player.name = "Bot1";
    bot1.bot.player.chooseAction = chooseAction_bot1;

    return bot1;
}

Action chooseAction_bot1() {
    // TODO
}
