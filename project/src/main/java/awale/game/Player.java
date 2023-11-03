package awale.game;

import java.util.ArrayDeque;
import java.util.Deque;

import awale.action.*;
import awale.verification.Verification;
import awale.mqtt.MqttSubscribe;

public abstract class Player extends MqttSubscribe {

	private int nbSeed;
	private String name;
	private Player opponent;
	private Verification holeVerify;
	private int[][] board;

	public Player() {
		this.nbSeed = 0;
	}

	public Player(String name, Verification holeVerify, int[][] board) {
		this.holeVerify = holeVerify;
		this.name = name;
		this.board = board;
		this.nbSeed = 0;
	}

	public Player getOpponent() {
		return this.opponent;
	}

	public void setOpponent(Player opponent) {
		this.opponent = opponent;
	}

	public int[][] getBoard() {
		return board;
	}

	public void setBoard(int[][] board) {
		this.board = board;
	}

	public Verification getHoleVerify() {
		return holeVerify;
	}

	public void setHoleVerify(Verification holeVerify) {
		this.holeVerify = holeVerify;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getNbSeed() {
		return nbSeed;
	}

	public void setNbSeed(int nbSeed) {
		this.nbSeed = nbSeed;
	}

	public Boolean holeIsCorrect(int holeNum) {
		return holeVerify.satisfy(holeNum);
	}

	protected abstract Action chooseAction();

	public void play() {
		Action action = chooseAction();
		int nbSeed = action.execute(getBoard());

		if (nbSeed > 0) {
			System.out.println(getName() + " took " + nbSeed + " seeds");
			setNbSeed(getNbSeed() + nbSeed);
		}
	}

	public boolean isStarved(int[][] board) {
		for (int i = 0; i < 16; i++) {
			if (holeIsCorrect(i) && (board[i][0] + board[i][1] + board[i][2]) != 0) {
				return false;
			}
		}

		return true;
	}

	public int mobility(int[][] board) {
		int mobility = 0;

		for (int i = 0; i < 16; i++) {
			if (holeIsCorrect(i)) {
				if (board[i][0] > 0) {
					mobility += 1;
				}

				if (board[i][1] > 0) {
					mobility += 1;
				}

				if (board[i][2] > 0) {
					mobility += 2;
				}
			}
		}

		return mobility;
	}

	public int nbBlueSeed() {
		int nbSeed = 0;

		for (int i = 0; i < 16; i++) {
			if (holeIsCorrect(i)) {
				nbSeed += board[i][0];
			}
		}

		return nbSeed;
	}

	public int nbRedSeed() {
		int nbSeed = 0;

		for (int i = 0; i < 16; i++) {
			if (holeIsCorrect(i)) {
				nbSeed += board[i][1];
			}
		}

		return nbSeed;
	}

	public int nbTransparentSeed() {
		int nbSeed = 0;

		for (int i = 0; i < 16; i++) {
			if (holeIsCorrect(i)) {
				nbSeed += board[i][2];
			}
		}

		return nbSeed;
	}

	public Deque<Action> possibleAction(int[][] board) {
		Deque<Action> actions = new ArrayDeque<>();

		for (int i = 0; i < 16; i++) {
			if (holeIsCorrect(i) && board[i][2] > 1) {
				actions.push(new TransparentBlueAction(i, this));
			}
		}

		for (int i = 0; i < 16; i++) {
			if (holeIsCorrect(i) && board[i][0] > 0) {
				actions.push(new BlueAction(i, this));
			}
		}

		for (int i = 0; i < 16; i++) {
			if (holeIsCorrect(i) && board[i][2] > 0) {
				actions.push(new TransparentRedAction(i, this));
			}
		}

		for (int i = 0; i < 16; i++) {
			if (holeIsCorrect(i) && board[i][1] > 0) {
				actions.push(new RedAction(i, this));
			}
		}

		return actions;
	}

}
