#include "../../../headers/game/startingMode/random.h"

void execute_random(Bot bots[2], Bot *b1, Bot *b2, int board[16][3])
{
    // TODO for Human / MQTT

    srand(time(0));

    Verification oddVerifier;
    oddVerifier.satisfy = satisfy_odd;
    Verification evenVerifier;
    evenVerifier.satisfy = satisfy_even;

    if (rand() % 2 == 0)
    {
        setHoleVerify(b1->player, &oddVerifier);
        setHoleVerify(b2->player, &evenVerifier);
        bots[0] = *(b1);
        bots[1] = *(b2);
    }
    else
    {
        setHoleVerify(b1->player, &evenVerifier);
        setHoleVerify(b2->player, &oddVerifier);
        bots[1] = *(b1);
        bots[0] = *(b2);
    }

    setOpponent(b1->player, b2->player);
    setOpponent(b2->player, b1->player);
    // setBoard(b1->player, board);
    // setBoard(b2->player, board);
}
