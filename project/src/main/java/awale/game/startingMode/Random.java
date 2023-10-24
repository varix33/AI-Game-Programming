package awale.game.startingMode;

import awale.game.Bot;
import awale.game.Human;
import awale.game.Player;
import awale.verification.Even;
import awale.verification.Odd;

import java.util.Scanner;

public class Random implements StartingMode {
    @Override
    public void execute(Player[] players, Player p1, Player p2, int[][] board){
        Scanner sc = new Scanner(System.in);
        java.util.Random r = new java.util.Random();
        String name;

        p1.setOpponent(p2);
        p2.setOpponent(p1);
        p1.setBoard(board);
        p2.setBoard(board);

        if (p1 instanceof Human && p2 instanceof Human) {
            System.out.print("player 1 : ");
            name =  sc.nextLine();
            p1.setName(name);
            System.out.print("player 2 : ");
            name =  sc.nextLine();
            p2.setName(name);
        }
        else if (p1 instanceof Human || p2 instanceof Human) {
            System.out.print("bot opponent : ");
            name =  sc.nextLine();
            if(p1 instanceof Human)
                p1.setName(name);
            else
                p2.setName(name);
        }

        if (r.nextInt(2) == 0) {
            p1.setHoleVerify(new Odd());
            p2.setHoleVerify(new Even());
            players[0] = p1;
            players[1] = p2;
        }else {
            p1.setHoleVerify(new Even());
            p2.setHoleVerify(new Odd());
            players[1] = p1;
            players[0] = p2;
        }
    }
}
