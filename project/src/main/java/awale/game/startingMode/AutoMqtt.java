package awale.game.startingMode;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.eclipse.paho.client.mqttv3.MqttMessage;

import awale.action.Action;
import awale.action.BlueAction;
import awale.action.RedAction;
import awale.action.TransparentBlueAction;
import awale.action.TransparentRedAction;
import awale.game.Player;
import awale.verification.Verification;

public class AutoMqtt extends Player {

	private static final Logger L = LogManager.getLogger();

	private String move = null;

	public AutoMqtt() {
		super();
	}

	public AutoMqtt(String name, Verification holeVerify, int[][] board) {
		super(name, holeVerify, board);
	}

	@Override
	public void messageArrived(String topic, MqttMessage message) throws Exception {
		L.debug("Nouveau message Mqtt | topic : {}, message : {}", topic, message);

		System.out.printf("Nouveau message envoye : %s\n", message.toString());

		this.move = message.toString();
	}

	@Override
	protected Action chooseAction() {
		Matcher matcher;
		String color = "";
		int holeNum = -1;

		do {
			while (move == null) {
				try {
					Thread.sleep(10);
				} catch (InterruptedException e) {
					L.error(e);
				}
			}

			System.out.println(getName() + ": ");
			matcher = Pattern.compile("\\b(1[0-6]|[1-9])(B|R|TB|TR)\\b").matcher(move);

			if (matcher.find()) {
				holeNum = Integer.parseInt(matcher.group(1)) - 1;
				color = matcher.group(2);

				if (!holeIsCorrect(holeNum)) {
					System.out.println("Wrong hole");
					move = null;
				}
			} else {
				System.out.println("Wrong Format");
				move = null;
			}
		} while (holeNum == -1 || !holeIsCorrect(holeNum));

		this.move = null;

		switch (color) {
		case "B" -> {
			return new BlueAction(holeNum, this);
		}
		case "R" -> {
			return new RedAction(holeNum, this);
		}
		case "TB" -> {
			return new TransparentBlueAction(holeNum, this);
		}
		case "TR" -> {
			return new TransparentRedAction(holeNum, this);
		}
		default -> {
			throw new RuntimeException("Seed color entered is incorrect");
		}
		}
	}

}
