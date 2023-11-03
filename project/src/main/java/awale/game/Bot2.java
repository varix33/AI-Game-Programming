package awale.game;

import awale.action.Action;
import awale.ai.Evaluation1;
import awale.ai.Evaluation2;

public class Bot2 extends Bot {

	public Bot2() {
		super();
		setName("Bot2");
	}

	@Override
	public Action chooseAction() {
		int depth;
		int mobility = mobility(getBoard());

		if (mobility < 9)
			depth = 8;
		else if (mobility < 20)
			depth = 7;
		else
			depth = 6;

		if (getNbSeed() + getOpponent().getNbSeed() > 5)
			minMax.setEvaluation(new Evaluation2());
		else
			minMax.setEvaluation(new Evaluation1());

		Action action = minMax.decisionAlphaBeta(getBoard(), depth, true);
		System.out.println(getName() + " play " + action);

		return action;
	}
}
