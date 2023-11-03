package awale.game;

import awale.action.Action;
import awale.ai.EvaluationBot1Start;
import awale.ai.EvaluationBot2Start;

public class Bot5 extends Bot {

	public Bot5() {
		super(true);
		setName("Bot5");
	}

	@Override
	public Action chooseAction() {
		int mobility = mobility(getBoard());
		int depth = mobility < 12 ? 8 : 7;

		minMax.setEvaluation(
				getNbSeed() + getOpponent().getNbSeed() > 5 ? new EvaluationBot2Start() : new EvaluationBot1Start());

		Action action = minMax.decisionAlphaBeta(getBoard(), depth, true);

		System.out.printf("%s play %s\n", getName(), action);

		return action;
	}

}
