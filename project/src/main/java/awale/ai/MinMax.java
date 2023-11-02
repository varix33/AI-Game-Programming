package awale.ai;

import awale.action.Action;
import awale.action.BlueAction;
import awale.action.RedAction;
import awale.action.TransparentBlueAction;
import awale.action.TransparentRedAction;
import awale.game.Bot;
import awale.game.Player;
import awale.mqtt.MqttPublish;
import awale.mqtt.MqttSubscribe;

import java.util.Deque;
import java.util.Properties;

import org.apache.commons.exec.CommandLine;
import org.apache.commons.exec.DefaultExecutor;
import org.apache.commons.exec.PumpStreamHandler;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class MinMax {

	private static final Logger L = LogManager.getLogger();

	protected final Bot player;
	private Evaluation evaluation;
	protected int nbMove;
	private MqttPublish mqttPublish;

	public MinMax(Bot player, Evaluation evaluation) {
		this.player = player;
		this.evaluation = evaluation;
		nbMove = 0;

		addMqtt();
	}

	public void setEvaluation(Evaluation evaluation) {
		this.evaluation = evaluation;
	}

	protected int[][] deepCopy(int[][] board) {
		int[][] boardCopy = new int[16][3];
		for (int i = 0; i < 16; i++) {
			boardCopy[i][0] = board[i][0];
			boardCopy[i][1] = board[i][1];
			boardCopy[i][2] = board[i][2];
		}
		return boardCopy;
	}

	public Action decisionAlphaBeta(int[][] board, int depthMax, boolean information) {
		int alpha = Integer.MIN_VALUE;
		int val;
		int nbSeedCapturedByPlayer;
		int[][] boardDeepCopy;
		Action action = null;

		nbMove++;

		if (depthMax == 0)
			throw new RuntimeException("depth must be greater than 0");

		long startTime = System.currentTimeMillis();

//		for (Action a : possibleAction(player, board)) {
//			boardDeepCopy = deepCopy(board);
//			nbSeedCapturedByPlayer = a.execute(boardDeepCopy);
//			val = alphaBetaValue(boardDeepCopy, nbSeedCapturedByPlayer, 0, depthMax - 1, alpha, Integer.MAX_VALUE,
//					false);
//			if (val > alpha) {
//				action = a;
//				alpha = val;
//			}
//		}
		
//		try {
//			CommandLine cmdLine = new CommandLine("./main.exe");
//
//			for (int i = 0; i < 16; i++) {
//				cmdLine.addArgument(String.valueOf(board[i][0]));
//				cmdLine.addArgument(String.valueOf(board[i][1]));
//				cmdLine.addArgument(String.valueOf(board[i][2]));
//			}
//			
//			cmdLine.addArgument("1");
//			cmdLine.addArgument("8");
//			
//			ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
//			DefaultExecutor exec = new DefaultExecutor();
//			PumpStreamHandler streamHandler = new PumpStreamHandler(byteArrayOutputStream, System.err);
//			exec.setStreamHandler(streamHandler);
//			exec.execute(cmdLine);
//
//			System.err.println(byteArrayOutputStream.toString());
//			mqttPublish.publish(byteArrayOutputStream.toString());
//		} catch (IOException e) {
//			L.error("Probleme lors de la generation de la licence : {}", e.getMessage());
//		}
//		
		try {
			Runtime rt = Runtime.getRuntime();
			String[] commands = new String[51];
			
			commands[0] = "./main";
			
			for (int i = 0; i < 16; i++) {
				commands[i * 3 + 1] = String.valueOf(board[i][0]);
				commands[i * 3 + 2] = String.valueOf(board[i][1]);
				commands[i * 3 + 3] = String.valueOf(board[i][2]);
			}
			commands[49] = "1";
			commands[50] = "7";
			
			for (int i = 0; i < 51; i++) {
				System.out.println(commands[i]);
			}
			
			Process proc = rt.exec(commands);

			BufferedReader reader = new BufferedReader(new InputStreamReader(proc.getInputStream()));
	        String line;
	        while ((line = reader.readLine()) != null) {
	            System.out.println(line);
	        }
		    
//		    System.out.println(output); // Imprimer la sortie dans la console
//		    mqttPublish.publish(output); // Publier la sortie via MQTT
		} catch (Exception e) {
		    L.error("Probleme lors de la generation de la licence : {}", e);
		}
		
		mqttPublish.publish(action.toString());

		long endTime = System.currentTimeMillis();

		if (information)
			printInfo(alpha, depthMax, endTime - startTime, player.mobility(board));

		return action;
	}

	protected int alphaBetaValue(int[][] board, int nbSeedPlayer, int nbSeedOpponent, int depth, int alpha, int beta,
			boolean isMax) {
		if (depth == 0)
			return evaluation.evaluate(player, nbSeedPlayer, nbSeedOpponent, board);

		Deque<Action> actions;
		int[][] boardDeepCopy;
		if (isMax) {
			actions = possibleAction(player, board);
			if (actions.isEmpty()) {
				return evaluation.evaluate(player, nbSeedPlayer, nbSeedOpponent, board);
			}

			for (Action a : actions) {
				boardDeepCopy = deepCopy(board);
				int nbSeedCapturedByPlayer = a.execute(boardDeepCopy);
				alpha = Integer.max(alpha, alphaBetaValue(boardDeepCopy, nbSeedCapturedByPlayer + nbSeedPlayer,
						nbSeedOpponent, depth - 1, alpha, beta, false));
				if (alpha >= beta)
					return alpha;
			}
			return alpha;
		} else {
			actions = possibleAction(player.getOpponent(), board);
			if (actions.isEmpty())
				return evaluation.evaluate(player, nbSeedPlayer, nbSeedOpponent, board);

			for (Action a : actions) {
				boardDeepCopy = deepCopy(board);
				int nbSeedCapturedByOpponent = a.execute(boardDeepCopy);
				beta = Integer.min(beta, alphaBetaValue(boardDeepCopy, nbSeedPlayer,
						nbSeedCapturedByOpponent + nbSeedOpponent, depth - 1, alpha, beta, true));
				if (beta <= alpha)
					return beta;
			}
			return beta;
		}
	}

	public Deque<Action> possibleAction(Player player, int[][] board) {
		Deque<Action> actions = new ArrayDeque<>();

		for (int i = 0; i < 16; i++)
			if (player.holeIsCorrect(i) && board[i][2] > 0)
				actions.push(new TransparentBlueAction(i, player));
		for (int i = 0; i < 16; i++)
			if (player.holeIsCorrect(i) && board[i][0] > 0)
				actions.push(new BlueAction(i, player));
		for (int i = 0; i < 16; i++)
			if (player.holeIsCorrect(i) && board[i][2] > 0)
				actions.push(new TransparentRedAction(i, player));
		for (int i = 0; i < 16; i++)
			if (player.holeIsCorrect(i) && board[i][1] > 0)
				actions.push(new RedAction(i, player));
		return actions;
	}

	protected void printInfo(int alpha, int depth, long time, int mobility) {
		final String ANSI_GREEN = "\u001B[32m";
		final String ANSI_RESET = "\u001B[0m";
		System.out.print(ANSI_GREEN);
		System.out.print("| mobility = " + mobility);
		System.out.print(" | eval = " + alpha);
		System.out.print(" | depth = " + depth);
		System.out.print(" | time = " + time + " |\n");
		System.out.print("| score " + player.getName() + " = " + player.getNbSeed());
		System.out.print(" | score " + player.getOpponent().getName() + " = " + player.getOpponent().getNbSeed());
		System.out.print("| nbMove = " + nbMove + " |\n");
		System.out.println(ANSI_RESET);
	}

	private void addMqtt() {
		InputStream inputStream = MqttSubscribe.class.getClassLoader().getResourceAsStream("application.properties");

		if (inputStream == null) {
			L.error("Le fichier application.properties n'a pas été trouvé dans le classpath.");

			System.exit(-1);
		}

		Properties properties = new Properties();

		try {
			properties.load(inputStream);
		} catch (IOException e) {
			L.error(e);
		}

		this.mqttPublish = new MqttPublish(properties.getProperty("game.opponent"), properties.getProperty("mqtt.host"),
				properties.getProperty("mqtt.port"));
	}

}
