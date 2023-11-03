package awale.game;

import awale.ai.EvaluationBot2End;
import awale.ai.MinMax;
import awale.ai.MinMaxParallelism;
import awale.verification.Verification;

public abstract class Bot extends Player {

	protected MinMax minMax;
	private boolean parallelism;

	public Bot() {
		super();
	}

	public Bot(boolean parallelism) {
		super();

		this.parallelism = true;
	}

	public Bot(String name, Verification holeVerify, int[][] board) {
		super(name, holeVerify, board);

		this.minMax = this.parallelism ? new MinMaxParallelism(this, new EvaluationBot2End())
				: new MinMax(this, new EvaluationBot2End());
	}

	public void setMinMax(MinMax minMax) {
		this.minMax = minMax;
	}

}
