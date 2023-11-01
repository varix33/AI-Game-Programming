#include "../../headers/game/bot2.h"

Bot2 createBot2()
{
    Bot2 bot2;
    bot2.bot = createBot("Bot2");
    // printf("ttt %s\n", bot2.bot->player->name);
    // bot2.bot->chooseAction = chooseAction_bot2;

    return bot2;
}

Action chooseAction_bot2(Bot *bot)
{
    // int depth = 6;
    // int mob = mobility(bot->player, bot->player->board);

    // if (mob < 9)
    // {
    //     depth = 8;
    // }
    // else if (mob < 20)
    // {
    //     depth = 7;
    // }

    // Evaluation evaluation;

    // if (*(bot->player->nbSeed) + *(bot->player->opponent->nbSeed) > 5)
    // {

    //     evaluation.evaluate = evaluate_evaluation2;
    // }
    // else
    // {
    //     evaluation.evaluate = evaluate_evaluation1;
    // }

    // setEvaluation(&(bot->minMax), &(evaluation));

    // Action action = decisionAlphaBeta(&(bot->minMax), bot->player->board, depth, true);
    // printf("%s play %s", bot->player->name, toStringAction(&(action)));
    Action action;

    return action;
}
