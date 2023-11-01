#include <stdio.h>
#include "headers/game/startingMode/random.h"
#include "headers/game/bot1.h"
#include "headers/game/bot2.h"
#include "headers/game/boardingGame.h"

int main()
{
    StartingMode mode;
    mode.execute = execute_random;
    Bot bot1 = createBot1().bot;
    // Bot *bot2 = createBot2().bot;

    // printf("tt %d\n", *(bot1->player->nbSeed));
    // printf("tt %s\n", bot2->player->name);
    // printf("%d\n", bot1->player->nbSeed);
    // printf("%d\n", bot2->player->nbSeed);
    // bot2->player->nbSeed += 5;
    // printf("%d\n", bot1->player->nbSeed);
    // printf("%d\n", bot2->player->nbSeed);

    // BoardingGame game = createBoardingGame(&bot1, &bot2, mode);
    printf("par ici");
    // playGame(&game);

    return 0;
}
