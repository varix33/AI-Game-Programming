#include "../../headers/ai/evaluation2.h"

int evaluate_evaluation2(Bot bot, int nbSeedCapturedByMe, int nbSeedCapturedByOpponent, int board[16][3])
{
    int diffNbSeedCaptured = nbSeedCapturedByMe - nbSeedCapturedByOpponent;
    int diffMobility = mobility(&(bot.player), board) - mobility(bot.player.opponent, board);

    // Others variables (to complete)

    return diffNbSeedCaptured * 3 + diffMobility;
}