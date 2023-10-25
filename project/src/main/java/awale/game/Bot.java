package awale.game;

import awale.ai.Evaluation1;
import awale.ai.MinMax;
import awale.ai.MinMaxParallelism;
import awale.verification.Verification;

public abstract class Bot extends Player {

	protected MinMax minMax;
	private boolean parallelism;

	public Bot() {
		super();
		this.minMax = new MinMax(this, new Evaluation1());
		this.parallelism = false;
	}

	public Bot(boolean parallelism) {
		super();
		this.minMax = new MinMaxParallelism(this, new Evaluation1());
		this.parallelism = true;
	}

	public Bot(String name, Verification holeVerify, int[][] board) {
		super(name, holeVerify, board);

		this.minMax = this.parallelism ? new MinMaxParallelism(this, new Evaluation1())
				: new MinMax(this, new Evaluation1());
	}

	public void setMinMax(MinMax minMax) {
		this.minMax = minMax;
	}

}
