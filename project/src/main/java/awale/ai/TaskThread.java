package awale.ai;

import java.util.concurrent.Callable;

import awale.action.Action;

public class TaskThread implements Callable<TaskResult> {

	private MinMaxParallelism instance;
	private int[][] board;
	private Action action;
	private int depthMax;
	private int alpha;

	public TaskThread(MinMaxParallelism instance, int[][] board, Action action, int depthMax, int alpha) {
		this.instance = instance;
		this.board = board;
		this.action = action;
		this.depthMax = depthMax;
		this.alpha = alpha;
	}

	@Override
	public TaskResult call() {
		int result = instance.alphaBeta(board, action, depthMax, alpha);

		return new TaskResult(action, result);
	}

}
