package game;

import action.*;
import verification.Verification;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Human extends Player{

    public Human() { super(); }
    public Human(String name, Verification holeVerify, int[][] board) {
        super(name, holeVerify, board);
    }

    @Override
    protected Action chooseAction() {
        Matcher matcher;
        Scanner sc = new Scanner(System.in);
        String color = "";
        int holeNum = -1;

        do {
            System.out.print(getName() + ": ");
            matcher = Pattern.compile("\\b(1[0-6]|[1-9])(B|R|TB|TR)\\b").matcher(sc.nextLine());
            if(matcher.find()) {
                holeNum = Integer.parseInt(matcher.group(1))-1;
                color = matcher.group(2);
                if(!holeIsCorrect(holeNum))
                    System.out.println("Wrong hole");
            }
            else
                System.out.println("Wrong Format");
        } while (holeNum == -1 || !holeIsCorrect(holeNum));

        switch (color) {
            case "B" -> {return new BlueAction(holeNum, this); }
            case "R" -> {return new RedAction(holeNum, this); }
            case "TB" -> {return new TransparentBlueAction(holeNum, this); }
            case "TR" -> {return new TransparentRedAction(holeNum, this); }
            default -> {throw new RuntimeException("Seed color entered is incorrect");}
        }
    }
}
