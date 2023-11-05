package awale.game;

import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import awale.action.Action;
import awale.ai.EvaluationBot3End;
import awale.ai.EvaluationBot3Start;
import awale.ai.MinMax;
import awale.mqtt.MqttPublish;
import awale.mqtt.MqttSubscribe;

public class Bot3 extends Bot {
	
	private static final Logger L = LogManager.getLogger();
	
	private MqttPublish mqttPublish;

	public Bot3() {
		super();
		setName("Bot3");
		this.minMax = new MinMax(this, new EvaluationBot3Start());
		
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

		if (getOpponent().nbRedSeed() < 3) {
			depth = 8;
		}

		if ((mobility(getBoard()) - getOpponent().mobility(getBoard())) > 12) {
			minMax.setEvaluation(new EvaluationBot3End());
		} else {
			minMax.setEvaluation(new EvaluationBot3Start());
		}

		Action action = minMax.decisionAlphaBeta(getBoard(), depth, true);
		System.out.println(getName() + " play " + action);
		
		mqttPublish.publish(action.toString());

		return action;
	}
}
