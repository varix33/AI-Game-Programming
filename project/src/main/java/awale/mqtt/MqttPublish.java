package awale.mqtt;

import org.eclipse.paho.client.mqttv3.MqttAsyncClient;
import org.eclipse.paho.client.mqttv3.MqttClient;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;
import org.eclipse.paho.client.mqttv3.persist.MemoryPersistence;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * Classe pour publier des messages via MQTT
 *
 * @author Phénix333
 */
public class MqttPublish {

	private static final Logger L = LogManager.getLogger();

	/**
	 * Le nom de notre adversaire à qui envoyer le message
	 */
	private String opponent;
	/**
	 * Le client MQTT
	 */
	private MqttClient client;

	/**
	 * Constructeur avec des paramètres
	 *
	 * @param opponent -> String
	 * @param host     -> String
	 * @param port     -> String
	 */
	public MqttPublish(String opponent, String host, String port) {
		L.debug("Constructeur avec des parametres | opponent : {}, host : {}, port : {}", opponent, host, port);

		this.opponent = opponent;

		String broker = String.format("tcp://%s:%s", host, port);
		MemoryPersistence persistence = new MemoryPersistence();

		try {
			client = new MqttClient(broker, MqttAsyncClient.generateClientId(), persistence);

			MqttConnectOptions connOpts = new MqttConnectOptions();

			client.connect(connOpts);
		} catch (MqttException e) {
			L.error("MqttException : {}", e.getMessage());

			// Je pars du principe que vue que le projet se base sur MQTT si la
			// fonction pour envoyer un message ne fonctionne plus le projet ne peux
			// fonctionner
			System.exit(-1);
		}
	}

	/**
	 * Envoi un message sur un topic spécifique
	 *
	 * @param theMessage -> String : le message à envoyer
	 */
	public void publish(String theMessage) {
		L.debug("Envoi un message sur un topic specifique | message : {}", theMessage);

		MqttMessage message = new MqttMessage(theMessage.getBytes());

		try {
			this.client.publish(String.format("awale/%s", this.opponent), message);
		} catch (MqttException e) {
			L.error("MqttException : {}", e.getMessage());

			// Je pars du principe que vue que le projet se base sur MQTT si la
			// fonction pour envoyer un message ne fonctionne plus le projet ne peux
			// fonctionner
			System.exit(-1);
		}

		L.debug("Message envoye");
	}

}
