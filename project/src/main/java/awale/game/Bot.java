package awale.game;

import awale.ai.*;
import awale.verification.Verification;

public abstract class Bot extends Player {
	
    protected MinMax minMax;

    public Bot() {
        super();
        this.minMax = new MinMax(this, new Evaluation1());
    }
    public Bot (String name, Verification holeVerify, int [][] board) {
        super(name, holeVerify, board);
        this.minMax = new MinMax(this, new Evaluation1());
    }

    public void setMinMax(MinMax minMax) { this.minMax = minMax; }

}
