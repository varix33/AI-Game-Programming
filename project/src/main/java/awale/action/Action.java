package awale.action;

import awale.game.Player;

public abstract class Action {

	public int holeNumber;
	private final Player player;

	public Action(int holeNumber, Player player) {
		this.holeNumber = holeNumber;
		this.player = player;
	}

	public int getHoleNumber() {
		return holeNumber;
	}

	public Player getPlayer() {
		return player;
	}

	public abstract int execute(int[][] board);

	public int seedCapturing(int lastHoleSowed, int[][] board) {
		int i = lastHoleSowed;
		int nbSeedCaptured = 0;
		int nbSeed;

		nbSeed = board[i][0] + board[i][1] + board[i][2];
		while (nbSeed == 2 || nbSeed == 3) {
			nbSeedCaptured += nbSeed;
			board[i][0] = 0;
			board[i][1] = 0;
			board[i][2] = 0;
			i = (i == 0) ? 15 : i - 1;
			nbSeed = board[i][0] + board[i][1] + board[i][2];
		}
		return nbSeedCaptured;
	}

	@Override
	public String toString() {
		return "" + (getHoleNumber() + 1);
	}

}
