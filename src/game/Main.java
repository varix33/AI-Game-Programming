package game;

import game.startingMode.Manual;
import game.startingMode.Random;

import java.util.Scanner;
public class Main {
    public static void main(String[] args) {

        BoardingGame Game = new BoardingGame(new Human(), new Bot2(), new Manual());
        Game.play();
    }
}