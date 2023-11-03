package awale.ai;

import awale.game.Bot;

public class EvaluationBot1End implements Evaluation {

	@Override
	public int evaluate(Bot bot, int nbSeedCapturedByMe, int nbSeedCapturedByOpponent, int[][] board, int depth) {
		int diffNbSeedCaptured = nbSeedCapturedByMe - nbSeedCapturedByOpponent * 2;
		int diffMobility = bot.mobility(board) - bot.getOpponent().mobility(board);

		// Others variables (to complete)

		return diffNbSeedCaptured + diffMobility;
	}

}
