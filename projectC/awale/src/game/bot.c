#include "../../headers/game/bot.h"

Bot createBot(char *name)
{
    Bot bot;
    Evaluation evaluation;
    evaluation.evaluate = evaluate_evaluation1;
    bot.player = createPlayer(name);
    bot.minMax = createMinMax(&(bot.player), &(evaluation));

    return bot;
}

void setMinMax(Bot *bot, MinMax minMax)
{
    bot->minMax = minMax;
}

void playBot(Bot *bot, int board[16][3])
{
    Action action = bot->chooseAction(bot);
    printf("pat ici");
    // int nbSeed = action.execute(board);

    // if (nbSeed > 0)
    // {
    //     printf("%s took %d seeds", bot->player.name, nbSeed);
    //     bot->player.nbSeed += nbSeed;
    // }
}
