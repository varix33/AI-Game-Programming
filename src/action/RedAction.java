package action;
import game.Player;

public class RedAction extends Action {
    public RedAction(int holeNumber, Player player) {
        super(holeNumber, player);
    }

    @Override
    public int execute(int [][] board) {
        int nbSeed = board[holeNumber][1];
        board[holeNumber][1] = 0;

        if (nbSeed != 0) {
            int i = holeNumber;
            for (; nbSeed > 0; i = (i + 1) % 16)
                if (i != holeNumber) {
                    board[i][1]++;
                    nbSeed--;
                }
            i = (i == 0) ? 15 : i - 1;
            return seedCapturing(i, board);
        }
        return 0;
    }

    @Override
    public String toString() {
        return super.toString() + "R";
    }
}
