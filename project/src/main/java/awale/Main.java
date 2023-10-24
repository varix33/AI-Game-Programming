package awale;

import awale.game.BoardingGame;
import awale.game.Bot1;
import awale.game.Bot2;
import awale.game.startingMode.AutoMqtt;
import awale.game.startingMode.Manual;
import awale.game.startingMode.Random;


public class Main {
    public static void main(String[] args) {

        BoardingGame Game = new BoardingGame(new Bot1(), new AutoMqtt(), new Manual());
        Game.play();
    }
}