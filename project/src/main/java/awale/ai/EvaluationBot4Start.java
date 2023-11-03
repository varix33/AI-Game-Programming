package awale.ai;

import awale.game.Bot;

public class EvaluationBot4Start implements Evaluation {

	@Override
	public int evaluate(Bot bot, int nbSeedCapturedByMe, int nbSeedCapturedByOpponent, int[][] board, int depth) {
		int diffNbSeedCaptured = nbSeedCapturedByMe - nbSeedCapturedByOpponent;
		int diffMobility = bot.mobility(board) - bot.getOpponent().mobility(board);

		// Others variables (to complete)

		return diffNbSeedCaptured * 5 + diffMobility;
	}

}
