package awale.mqtt;

import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;
import org.eclipse.paho.client.mqttv3.MqttAsyncClient;
import org.eclipse.paho.client.mqttv3.MqttCallback;
import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;

/**
 * Classe pour recevoir des messages via MQTT
 *
 * @author Phénix333
 */
public class MqttSubscribe implements MqttCallback {

	private static final Logger L = LogManager.getLogger();

	/**
	 * Constructeur avec des paramètres
	 */
	public MqttSubscribe() {
		L.debug("Constructeur avec des parametres");

		subscribeMqtt();
	}

	/**
	 * Initialise les variables pour la réception de messages et de s'inscrire au
	 * topic
	 */
	public void subscribeMqtt() {
		L.debug("Initialise les variables pour la reception de messages et de s'inscrire au topic");

		InputStream inputStream = MqttSubscribe.class.getClassLoader().getResourceAsStream("application.properties");

		if (inputStream == null) {
			L.error("application.properties not found in the classpath");

			System.exit(-1);
		}

		Properties properties = new Properties();

		try {
			properties.load(inputStream);
		} catch (IOException e) {
			L.error(e);
		}
		
		L.info("New game between {} VS {}", properties.getProperty("game.name"), properties.getProperty("game.opponent"));

		String broker = String.format("tcp://%s:%s", properties.getProperty("mqtt.host"),
				properties.getProperty("mqtt.port"));

		try {
			MqttClient client = new MqttClient(broker, MqttAsyncClient.generateClientId());
			MqttConnectOptions connOpts = new MqttConnectOptions();

			client.connect(connOpts);
			client.setCallback(this);
			client.subscribe(String.format("awale/%s", properties.getProperty("game.name")));
		} catch (MqttException e) {
			L.error("MQTT error connection : {}", e.getMessage());
		}
	}

	@Override
	public void connectionLost(Throwable cause) {
		L.debug(cause);
	}

	@Override
	public void messageArrived(String topic, MqttMessage message) throws Exception {
		L.debug("");
	}

	@Override
	public void deliveryComplete(IMqttDeliveryToken token) {
		L.debug("");
	}

}
