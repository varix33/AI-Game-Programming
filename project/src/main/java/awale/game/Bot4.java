package awale.game;

import awale.action.Action;
import awale.ai.EvaluationBot4Start;
import awale.ai.MinMax;

public class Bot4 extends Bot {

	public Bot4() {
		super();
		setName("Bot4");
		this.minMax = new MinMax(this, new EvaluationBot4Start());
	}

	@Override
	public Action chooseAction() {
		int depth = 8;
		int mobility = mobility(getBoard());

		if (mobility < 12) {
			depth = 7;
		}

		minMax.setEvaluation(new EvaluationBot4Start());
		Action action = minMax.decisionAlphaBeta(getBoard(), depth, true);
		System.out.println(getName() + " play " + action);

		return action;
	}
}
