package awale.game;

import awale.ai.*;
import awale.mqtt.MqttPublish;
import awale.mqtt.MqttSubscribe;

import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import awale.action.Action;

public class Bot1 extends Bot {

	private static final Logger L = LogManager.getLogger();

	private MqttPublish mqttPublish;

	public Bot1() {
		super();
		setName("Bot1");
		this.minMax = new MinMax(this, new EvaluationBot1Start());

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
		int depth = 8;

		if (getOpponent().nbRedSeed() < 3) {
			depth = 7;
		}

		if (getOpponent().mobility(getBoard()) < 6) {
			minMax.setEvaluation(new EvaluationBot1End());
		}

		Action action = minMax.decisionAlphaBeta(getBoard(), depth, true);
		System.out.println(getName() + " play " + action);

		mqttPublish.publish(action.toString());

		return action;
	}

}
