package awale.ai;

import awale.game.Bot;

public class Evaluation1 implements Evaluation {

	@Override
	public int evaluate(Bot bot, int nbSeedCapturedByMe, int nbSeedCapturedByOpponent, int[][] board) {
		int diffNbSeedCaptured = nbSeedCapturedByMe - nbSeedCapturedByOpponent;
		int diffMobility = bot.mobility(board) - bot.getOpponent().mobility(board);

		// others variables (to complete)

		return diffNbSeedCaptured * 2 + diffMobility;
	}

}
