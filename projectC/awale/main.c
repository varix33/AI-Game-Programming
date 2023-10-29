#include <stdio.h>
#include "headers/game/startingMode/startingMode.h"
#include "headers/game/startingMode/random.h"
#include "headers/game/bot1.h"
#include "headers/game/bot2.h"
#include "headers/game/boardingGame.h"

int main()
{
    StartingMode mode;
    mode.execute = execute_random;

    BoardingGame game = createBoardingGame(createBot1().bot.player, createBot2().bot.player, mode);

    play(&game);

    return 0;
}
