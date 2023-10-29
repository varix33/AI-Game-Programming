#include "../../../headers/game/startingMode/random.h"

void execute_random(Player players[2], Player p1, Player p2, int board[16][3])
{
    setOpponent(&p1, &p2);
    setOpponent(&p2, &p1);
    setBoard(&p1, board);
    setBoard(&p2, board);

    // TODO for Human / MQTT

    srand(time(0));

    Verification oddVerifier;
    oddVerifier.satisfy = satisfy_odd;
    Verification evenVerifier;
    evenVerifier.satisfy = satisfy_even;

    if (rand() % 2 == 0)
    {
        setHoleVerify(&p1, oddVerifier);
        setHoleVerify(&p2, evenVerifier);
        players[0] = p1;
        players[1] = p2;
    }
    else
    {
        setHoleVerify(&p1, evenVerifier);
        setHoleVerify(&p2, oddVerifier);
        players[1] = p1;
        players[0] = p2;
    }
}
