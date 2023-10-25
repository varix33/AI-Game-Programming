package awale.game;

import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import awale.action.Action;
import awale.ai.Evaluation1;
import awale.ai.Evaluation2;
import awale.mqtt.MqttPublish;
import awale.mqtt.MqttSubscribe;

public class Bot3 extends Bot {

	private static final Logger L = LogManager.getLogger();

	private MqttPublish mqttPublish;

	public Bot3() {
		super(true);
		setName("Bot3");

		addMqtt();
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

	@Override
	public Action chooseAction() {
		int mobility = mobility(getBoard());
		int depth = mobility < 16 ? 8 : 7;

		minMax.setEvaluation(getNbSeed() + getOpponent().getNbSeed() > 5 ? new Evaluation2() : new Evaluation1());

		Action action = minMax.decisionAlphaBeta(getBoard(), depth, true);

		System.out.printf("%s play %s\n", getName(), action);

		mqttPublish.publish(action.toString());

		return action;
	}

}
