package awale.ai;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

import awale.action.Action;
import awale.game.Bot;

public class MinMaxParallelism extends MinMax {

	public MinMaxParallelism(Bot player, Evaluation evaluation) {
		super(player, evaluation);
	}

	@Override
	public Action decisionAlphaBeta(int[][] board, int depthMax, boolean information) {
		Action action = null;
		int alpha = Integer.MIN_VALUE;
		int val;

		nbMove++;

		if (depthMax == 0) {
			throw new RuntimeException("depth must be greater than 0");
		}

		long startTime = System.currentTimeMillis();

		ExecutorService executor = Executors.newFixedThreadPool(player.possibleAction(board).size());
		List<Callable<TaskResult>> tasks = new ArrayList<>();

		for (Action a : player.possibleAction(board)) {
			tasks.add(new TaskThread(this, board, a, depthMax, alpha));
		}

		try {
			List<Future<TaskResult>> results = executor.invokeAll(tasks);

			for (Future<TaskResult> result : results) {
				TaskResult taskResult = result.get();
				val = taskResult.value;
				Action a = taskResult.action;

				if (val > alpha) {
					action = a;
					alpha = val;
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		executor.shutdown();

		long endTime = System.currentTimeMillis();

		if (information) {
			printInfo(alpha, depthMax, endTime - startTime, player.mobility(board));
		}

		return action;
	}

	public int alphaBeta(int[][] board, Action action, int depthMax, int alpha) {
		int[][] boardDeepCopy = deepCopy(board);
		int nbSeedCapturedByPlayer = action.execute(boardDeepCopy);
		int result = alphaBetaValue(boardDeepCopy, nbSeedCapturedByPlayer, 0, depthMax - 1, alpha, Integer.MAX_VALUE,
				false);

		return result;
	}

}
