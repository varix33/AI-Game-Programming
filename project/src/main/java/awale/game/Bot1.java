package awale.game;

import awale.ai.*;

import awale.action.Action;

public class Bot1 extends Bot {

	public Bot1() {
		super();
		setName("Bot1");
		this.minMax = new MinMax(this, new EvaluationBot1Start());
	}

	@Override
	public Action chooseAction() {
		int depth = 8;

		if (getOpponent().nbRedSeed() < 3) {
			depth = 7;
		}

		if (getOpponent().mobility(getBoard()) < 6) {
			minMax.setEvaluation(new EvaluationBot1End());
		}

		Action action = minMax.decisionAlphaBeta(getBoard(), depth, true);
		System.out.println(getName() + " play " + action);

		return action;
	}
	
}
