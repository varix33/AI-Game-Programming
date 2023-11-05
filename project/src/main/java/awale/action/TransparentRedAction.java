package awale.action;
import awale.game.Player;

public class TransparentRedAction extends Action
{
    public TransparentRedAction(int holeNumber, Player player) {
        super(holeNumber, player);
    }

    @Override
    public int execute(int[][] board)
    {
        int nbSeed = board[holeNumber][2];
        board[holeNumber][2] = 0;

        if(nbSeed != 0)
        {
            int i = holeNumber;
            for (; nbSeed > 0; i = (i + 1) % 16)
                if (i != holeNumber)
                {
                    board[i][2]++;
                    nbSeed--;
                }
            i = (i == 0) ? 15: i-1;
            return seedCapturing(i, board);
        }
        return 0;
    }

    @Override
    public String toString() {
        return super.toString() + "TR";
    }
}