package awale.game.startingMode;

import awale.game.Bot;
import awale.game.Human;
import awale.game.Player;
import awale.verification.Even;
import awale.verification.Odd;

import java.util.Scanner;

public class Manual implements StartingMode {

	@Override
	public void execute(Player[] players, Player p1, Player p2, int[][] board) {
		Scanner sc = new Scanner(System.in);

		p1.setOpponent(p2);
		p2.setOpponent(p1);
		p1.setBoard(board);
		p2.setBoard(board);

		if (p1 instanceof Human && p2 instanceof Human) {
			throw new RuntimeException("Human vs Human can't be launched in Manual");
		} else if (p1 instanceof Bot && p2 instanceof Bot) {
			throw new RuntimeException("Bot vs Bot can't be launched in Manual");
		} else {
			Player human;
			Player bot;

			if (p1 instanceof Human) {
				human = p1;
				bot = p2;
			} else {
				human = p2;
				bot = p1;
			}

			System.out.print("bot opponent : ");
			String opponentName = sc.nextLine();
			human.setName(opponentName);
			String answer;

			do {
				System.out.print("do your opponent starts ? (y/n) : ");
				answer = sc.nextLine();

				if (!answer.equals("y") && !answer.equals("n")) {
					System.out.println("Wrong Format");
				}
			} while (!answer.equals("y") && !answer.equals("n"));

			switch (answer) {
			case "y" -> {
				human.setHoleVerify(new Odd());
				bot.setHoleVerify(new Even());
				players[0] = human;
				players[1] = bot;
			}
			case "n" -> {
				human.setHoleVerify(new Even());
				bot.setHoleVerify(new Odd());
				players[1] = human;
				players[0] = bot;
			}
			}
		}
	}

}
