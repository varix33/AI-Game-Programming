package awale.game;

import awale.action.Action;
import awale.ai.EvaluationBot3End;
import awale.ai.EvaluationBot3Start;
import awale.ai.MinMax;

public class Bot3 extends Bot {

	public Bot3() {
		super();
		setName("Bot3");
		this.minMax = new MinMax(this, new EvaluationBot3Start());
	}

	@Override
	public Action chooseAction() {
		int depth = 8;
		int mobility = mobility(getBoard());

		if (getOpponent().nbRedSeed() < 3) {
			depth = 8;
		}

		if ((mobility(getBoard()) - getOpponent().mobility(getBoard())) > 12) {
			minMax.setEvaluation(new EvaluationBot3End());
		} else {
			minMax.setEvaluation(new EvaluationBot3Start());
		}

		Action action = minMax.decisionAlphaBeta(getBoard(), depth, true);
		System.out.println(getName() + " play " + action);

		return action;
	}
}
