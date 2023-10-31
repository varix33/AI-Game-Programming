#include "../../headers/game/bot1.h"

Bot1 createBot1()
{
    Bot1 bot1;
    bot1.bot = createBot("Bot1");
    printf("ttt %c\n", *(bot1.bot->player->name));
    printf("ttt %c\n", *(bot1.bot->player->name));
    // printf("ttt %d\n", *(bot1.bot->player->nbSeed));
    // bot1.bot->chooseAction = chooseAction_bot1;

    return bot1;
}

Action chooseAction_bot1(Bot *bot)
{
    int depth = 6;
    int mob = mobility(bot->player, bot->player->board);

    if (mob < 9)
    {
        depth = 8;
    }
    else if (mob < 20)
    {
        depth = 7;
    }

    Evaluation evaluation;
    evaluation.evaluate = evaluate_evaluation2;
    setEvaluation(&(bot->minMax), &(evaluation));

    Action action = decisionAlphaBeta(&(bot->minMax), bot->player->board, depth, true);
    printf("%s play %s", bot->player->name, toStringAction(&(action)));

    return action;
}
