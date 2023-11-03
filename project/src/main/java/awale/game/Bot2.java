package awale.game;

import awale.ai.MinMax;

import awale.action.Action;
import awale.ai.EvaluationBot2End;
import awale.ai.EvaluationBot2Start;

public class Bot2 extends Bot {

	public Bot2() {
		super();
		setName("Bot2");
		this.minMax = new MinMax(this, new EvaluationBot2Start());
	}

	@Override
	public Action chooseAction() {
		int depth = 7;
		int mobility = mobility(getBoard());

		if (mobility < 12) {
			depth = 8;
		}

		if (getNbSeed() + getOpponent().getNbSeed() > 10)
			minMax.setEvaluation(new EvaluationBot2End());
		else
			minMax.setEvaluation(new EvaluationBot2Start());

		Action action = minMax.decisionAlphaBeta(getBoard(), depth, true);
		System.out.println(getName() + " play " + action);

		return action;
	}
}
