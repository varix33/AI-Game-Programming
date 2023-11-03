package awale.game;

import awale.game.startingMode.StartingMode;

public class BoardingGame {

	private final int[][] board;
	private final Player[] players;

	public BoardingGame(Player p1, Player p2, StartingMode mode) {
		players = new Player[2];
		board = new int[16][3];

		for (int i = 0; i < 16; i++) {
			board[i][0] = 2;
			board[i][1] = 2;
			board[i][2] = 1;
		}

		// Select which player starts regarding the mode selected (manual/random)
		mode.execute(players, p1, p2, board);
	}

	/* Return the number of remaining seeds on the BoardingGame */
	public int remainingSeed() {
		int nbSeed = 0;

		for (int i = 0; i < 16; i++) {
			nbSeed += board[i][0] + board[i][1] + board[i][2];
		}

		return nbSeed;
	}

	public void play() {
		boolean gameOver = false;

		System.out.println("GAME START");
		System.out.println(players[0].getName() + " starts with odd holes");
		System.out.println(players[1].getName() + " continue with even holes");

		printBoarding();

		for (int i = 0; !gameOver; i = (i + 1) % 2) {
			players[i].play();
			printBoarding();

			// Starving
			if (players[i].getOpponent().isStarved(board)) {
				players[i].setNbSeed(80 - players[i].getOpponent().getNbSeed());
				System.out.println(players[i].getName() + " starved " + players[i].getOpponent().getName()
						+ " and obtained the last seeds !");
			}

			gameOver = isGameOver();
		}
	}

	private boolean isGameOver() {
		// Less than 10 seeds
		if (remainingSeed() < 10) {
			System.out.println("Less than 10 seeds !");

			if (players[0].getNbSeed() > players[1].getNbSeed()) {
				System.out.println(players[0].getName() + " won with " + players[0].getNbSeed() + " seeds !");
			}

			else if (players[0].getNbSeed() < players[1].getNbSeed()) {
				System.out.println(players[1].getName() + " won with " + players[1].getNbSeed() + " seeds !");
			} else {
				System.out.println("Draw !!");
			}

			return true;
		}
		// More than 40 seeds
		if (players[0].getNbSeed() > 40) {
			System.out.println(players[0].getName() + " won with " + players[0].getNbSeed() + " seeds !");

			return true;
		}

		if (players[1].getNbSeed() > 40) {
			System.out.println(players[1].getName() + " won with " + players[1].getNbSeed() + " seeds !");

			return true;
		}

		// Draw
		if (players[0].getNbSeed() == 40 && players[1].getNbSeed() == 40) {
			System.out.println("Draw !!");

			return true;
		}

		return false;
	}

	public void printBoarding() {
		final String ANSI_RESET = "\u001B[0m";
		final String ANSI_RED = "\u001B[31m";
		final String ANSI_BLUE = "\u001B[34m";
		final String ANSI_GREEN = "\u001B[32m";

		System.out.println();

		for (int i = 1; i <= 8; i++) {
			System.out.printf("%-5s", "[" + i + "]");
			System.out.print(" ");
		}

		System.out.println("\n");

		for (int i = 0; i < 8; i++) {
			System.out.print("(");
			System.out.print(ANSI_BLUE + board[i][0] + ANSI_RESET);
			System.out.print(ANSI_RED + board[i][1] + ANSI_RESET);
			System.out.print(ANSI_GREEN + board[i][2] + ANSI_RESET);
			System.out.print(") ");
		}

		System.out.println();

		for (int i = 15; i >= 8; i--) {
			System.out.print("(");
			System.out.print(ANSI_BLUE + board[i][0] + ANSI_RESET);
			System.out.print(ANSI_RED + board[i][1] + ANSI_RESET);
			System.out.print(ANSI_GREEN + board[i][2] + ANSI_RESET);
			System.out.print(") ");
		}

		System.out.println("\n");

		for (int i = 16; i > 8; i--) {
			System.out.printf("%-5s", "[" + i + "]");
			System.out.print(" ");
		}

		System.out.println("\n");
	}

}
