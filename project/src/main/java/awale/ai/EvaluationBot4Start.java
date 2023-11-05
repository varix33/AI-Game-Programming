package awale.ai;

import awale.game.Player;

public class EvaluationBot4Start implements Evaluation
{
    @Override
    public int evaluate(Player p, int nbSeedCapturedByMe, int nbSeedCapturedByOpponent, int[][] board)
    {

        int diffNbSeedCaptured = nbSeedCapturedByMe - nbSeedCapturedByOpponent;
        int diffMobility = p.mobility(board) - p.getOpponent().mobility(board);

        return  diffMobility*3 + diffNbSeedCaptured;
    }
}
