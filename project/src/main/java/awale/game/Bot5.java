package awale.game;

import awale.action.Action;
import awale.ai.Evaluation1;
import awale.ai.Evaluation2;

public class Bot5 extends Bot {

	public Bot5() {
		super(true);
		setName("Bot5");
	}

	@Override
	public Action chooseAction() {
		int mobility = mobility(getBoard());
		int depth = mobility < 12 ? 8 : 7;

		minMax.setEvaluation(getNbSeed() + getOpponent().getNbSeed() > 5 ? new Evaluation2() : new Evaluation1());

		Action action = minMax.decisionAlphaBeta(getBoard(), depth, true);

		System.out.printf("%s play %s\n", getName(), action);

		return action;
	}

}
