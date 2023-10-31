#include "../../headers/ai/evaluation1.h"

int evaluate_evaluation1(Player player, int nbSeedCapturedByMe, int nbSeedCapturedByOpponent, int board[16][3])
{
    int diffNbSeedCaptured = nbSeedCapturedByMe - nbSeedCapturedByOpponent;
    int diffMobility = mobility(&(player), board) - mobility(player.opponent, board);

    // Others variables (to complete)

    return diffNbSeedCaptured * 2 + diffMobility;
}
