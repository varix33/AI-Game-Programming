package awale;

import awale.game.AutoMqtt;
import awale.game.BoardingGame;
import awale.game.Bot1;
import awale.game.Bot2;
import awale.game.Bot5;
import awale.game.startingMode.Manual;
import awale.game.startingMode.Random;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.io.File;

public class Main {

	private static final Logger L = LogManager.getLogger();

	public static void main(String[] args) {
		deletePaho();

		BoardingGame Game = new BoardingGame(new Bot2(), new Bot2(), new Random());
		Game.play();
	}

	/**
	 * Suppression des dossiers paho (MQTT)
	 */
	private static void deletePaho() {
		L.debug("Supression des dossiers paho (MQTT)");

		File[] fichiers = new File(System.getProperty("user.dir")).listFiles();

		if (fichiers != null) {
			for (File fichier : fichiers) {
				if (fichier.isDirectory() && fichier.getName().startsWith("paho")) {
					File file = new File(fichier, ".lck");
					file.delete();
					fichier.delete();
				}
			}
		}
	}

}