package awale.game;

import awale.action.Action;
import awale.ai.EvaluationBot2End;
import awale.ai.EvaluationBot3Start;
import awale.ai.EvaluationBot4Start;
import awale.ai.MinMax;
import awale.mqtt.MqttPublish;
import awale.mqtt.MqttSubscribe;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

public class BotOpponent extends Bot {

	private static final Logger L = LogManager.getLogger();

	private MqttPublish mqttPublish;

	public BotOpponent() {
		super();
		setName("Bot4");
		this.minMax = new MinMax(this, new EvaluationBot4Start());

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
		int depth;
		int mobility = mobility(getBoard());

		if (mobility < 12)
			depth = 7;
		else
			depth = 8;

		minMax.setEvaluation(new EvaluationBot4Start());
		Action action = minMax.decisionAlphaBeta(getBoard(), depth, true);
		System.out.println(getName() + " play " + action);

		mqttPublish.publish(action.toString());

		return action;
	}
}