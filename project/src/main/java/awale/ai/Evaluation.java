package awale.ai;

import awale.game.Player;

@FunctionalInterface
public interface Evaluation {

	public int evaluate(Player p, int nbSeedCapturedByMe, int nbSeedCapturedByOpponent, int[][] board);

}
