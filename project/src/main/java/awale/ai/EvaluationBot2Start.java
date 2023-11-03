package awale.ai;

import awale.game.Bot;

public class EvaluationBot2Start implements Evaluation {

	@Override
	public int evaluate(Bot bot, int nbSeedCapturedByMe, int nbSeedCapturedByOpponent, int[][] board, int depth) {
		int diffNbSeedCaptured = nbSeedCapturedByMe * 2 - nbSeedCapturedByOpponent * 3;
		int diffMobility = bot.mobility(board) - bot.getOpponent().mobility(board);

		// Others variables (to complete)

		return diffNbSeedCaptured * 4 + diffMobility;
	}

}
