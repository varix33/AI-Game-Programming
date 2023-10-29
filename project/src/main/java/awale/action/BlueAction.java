package awale.action;

import awale.game.Player;

public class BlueAction extends Action {

	public BlueAction(int holeNumber, Player player) {
		super(holeNumber, player);
	}

	@Override
	public int execute(int[][] board) {
		int nbSeed = board[holeNumber][0];
		board[holeNumber][0] = 0;

		if (nbSeed != 0) {
			int i = holeNumber;
			for (; nbSeed > 0; i = (i + 1) % 16)
				if (!getPlayer().holeIsCorrect(i) && i != holeNumber) {
					board[i][0]++;
					nbSeed--;
				}
			i = (i == 0) ? 15 : i - 1;
			return seedCapturing(i, board);
		}
		return 0;
	}

	@Override
	public String toString() {
		return super.toString() + "B";
	}

}
