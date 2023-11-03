package awale.ai;

import awale.game.Bot;

public class EvaluationBot3End implements Evaluation {
    @Override
    public int evaluate(Bot bot, int nbSeedCapturedByMe, int nbSeedCapturedByOpponent, int[][] board, int depth) {

        if (bot.getOpponent().getNbSeed() + nbSeedCapturedByOpponent >= 40)
            return -9990;
        if (bot.getNbSeed() + nbSeedCapturedByMe > 40)
            return 9990 + depth;
        if (bot.isStarved(board))
            return -9990;
        if(bot.getOpponent().isStarved(board))
            return 9990 + depth;

        int diffNbSeedCaptured = nbSeedCapturedByMe - nbSeedCapturedByOpponent;
        int diffMobility = bot.mobility(board) - bot.getOpponent().mobility(board);

        return diffNbSeedCaptured*3 + diffMobility;
    }
}
