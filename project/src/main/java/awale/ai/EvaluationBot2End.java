package awale.ai;

import awale.game.Bot;

public class EvaluationBot2End implements Evaluation {
    @Override
    public int evaluate(Bot bot, int nbSeedCapturedByMe, int nbSeedCapturedByOpponent, int[][] board, int depth) {

        int diffNbSeedCaptured = nbSeedCapturedByMe*2 - nbSeedCapturedByOpponent*3;
        int diffMobility = bot.mobility(board) - bot.getOpponent().mobility(board);

        // others variables (to complete)

        return  diffMobility;
    }
}
