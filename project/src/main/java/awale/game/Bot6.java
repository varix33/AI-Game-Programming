package awale.game;

import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import awale.action.Action;
import awale.ai.EvaluationBot6End;
import awale.ai.EvaluationBot6Start;
import awale.ai.MinMaxParallelism;
import awale.mqtt.MqttPublish;
import awale.mqtt.MqttSubscribe;

public class Bot6 extends Bot {

	private static final Logger L = LogManager.getLogger();

	private MqttPublish mqttPublish;

	public Bot6() {
		super(true);
		setName("Bot6");
		this.minMax = new MinMaxParallelism(this, new EvaluationBot6Start());

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
		int depth = 7;
		int mobility = mobility(getBoard());
		
		if (mobility < 10 || getOpponent().nbRedSeed() < 3) {
			depth = 8;
		}

		if ((mobility(getBoard()) - getOpponent().mobility(getBoard())) > 12) {
			minMax.setEvaluation(new EvaluationBot6End());
		} else {
			minMax.setEvaluation(new EvaluationBot6Start());
		}

		Action action = minMax.decisionAlphaBeta(getBoard(), depth, true);
		System.out.printf("%s play %s\n", getName(), action);

		mqttPublish.publish(action.toString());

		return action;
	}

}
