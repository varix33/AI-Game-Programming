package awale.ai;

import awale.game.Bot;

@FunctionalInterface
public interface Evaluation {
    public int evaluate(Bot bot, int nbSeedCapturedByMe, int nbSeedCapturedByOpponent, int[][] board);
}

