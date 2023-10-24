package awale.game;

import awale.action.Action;
import awale.ai.Evaluation2;
import awale.ai.MinMax;

public class Bot1 extends Bot {
    public Bot1() {
        super();
        setName("Bot1");
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

        minMax.setEvaluation(new Evaluation2());
        Action action = minMax.decisionAlphaBeta(getBoard(), depth, true);
        System.out.println(getName() + " play " + action);
        return action;
    }
}
