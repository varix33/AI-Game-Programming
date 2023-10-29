package awale.game.startingMode;

import awale.game.Player;

@FunctionalInterface
public interface StartingMode {

	public void execute(Player[] players, Player p1, Player p2, int[][] board);

}
