package awale.ai;

import awale.action.*;
import awale.game.Bot;

import java.util.Deque;

public class MinMax {
    private final Bot player;
    private Evaluation evaluation;
    private int lastEval;
    private int nbMove;

    public MinMax(Bot player, Evaluation evaluation) {
        this.player = player;
        this.evaluation = evaluation;
        nbMove = 0;
        lastEval = 0;
    }

    public void setEvaluation(Evaluation evaluation) {
        this.evaluation = evaluation;
    }

    public int getLastEval() { return lastEval; }

    private int[][] deepCopy(int[][] board) {
        int[][] boardCopy = new int[16][3];
        for (int i = 0; i < 16; i++) {
            boardCopy[i][0] = board[i][0];
            boardCopy[i][1] = board[i][1];
            boardCopy[i][2] = board[i][2];
        }
        return boardCopy;
    }

    public Action decisionAlphaBeta(int [][] board, int depthMax, boolean information) {
        int alpha = Integer.MIN_VALUE;
        int val;
        int nbSeedCapturedByPlayer;
        int [][] boardDeepCopy;
        Action action = null;

        nbMove++;

        if (depthMax == 0)
            throw  new RuntimeException("depth must be greater than 0");

        long startTime = System.currentTimeMillis();

        for (Action a: player.possibleAction(board)) {
            boardDeepCopy = deepCopy(board);
            nbSeedCapturedByPlayer = a.execute(boardDeepCopy);
            val = alphaBetaValue(boardDeepCopy, nbSeedCapturedByPlayer, 0, depthMax-1, alpha, Integer.MAX_VALUE, false);

            if (val > alpha) {
                action = a;
                alpha = val;
            }
        }

        long endTime = System.currentTimeMillis();


        if (information)
            printInfo(alpha, depthMax,endTime-startTime, player.mobility(board));
        lastEval = alpha;
        return action;
    }

    private int alphaBetaValue(int [][] board, int nbSeedPlayer, int nbSeedOpponent, int depth, int alpha, int beta, boolean isMax ) {
        if (depth == 0)
            return evaluation.evaluate(player, nbSeedPlayer, nbSeedOpponent, board);

        Deque<Action> actions;
        int [][] boardDeepCopy;
        if(isMax){
            actions = player.possibleAction(board);
            if(actions.isEmpty()) {
                return evaluation.evaluate(player, nbSeedPlayer, nbSeedOpponent, board);
            }

            for(Action a: actions){
                boardDeepCopy = deepCopy(board);
                int nbSeedCapturedByPlayer = a.execute(boardDeepCopy);
                alpha = Integer.max(alpha, alphaBetaValue(boardDeepCopy, nbSeedCapturedByPlayer+nbSeedPlayer, nbSeedOpponent, depth-1, alpha, beta, false));
                if (alpha >= beta)
                    return alpha;
            }
            return alpha;
        }
        else{
            actions = player.getOpponent().possibleAction(board);
            if(actions.isEmpty())
                return evaluation.evaluate(player, nbSeedPlayer, nbSeedOpponent, board);

            for(Action a: actions){
                boardDeepCopy = deepCopy(board);
                int nbSeedCapturedByOpponent = a.execute(boardDeepCopy);
                beta = Integer.min(beta, alphaBetaValue(boardDeepCopy, nbSeedPlayer, nbSeedCapturedByOpponent+nbSeedOpponent, depth-1, alpha, beta, true));
                if (beta <= alpha)
                    return beta;
            }
            return beta;
        }
    }

    private void printInfo(int alpha, int depth, long time, int mobility ) {
        final String ANSI_GREEN = "\u001B[32m";
        final String ANSI_RESET = "\u001B[0m";
        System.out.print(ANSI_GREEN);
        System.out.print("| mobility = "+mobility);
        System.out.print(" | eval = "+alpha);
        System.out.print(" | depth = "+depth);
        System.out.print(" | time = "+time+" |\n");
        System.out.print("| score "+player.getName()+" = "+player.getNbSeed());
        System.out.print(" | score "+player.getOpponent().getName()+" = "+player.getOpponent().getNbSeed());
        System.out.print("| nbMove = "+nbMove+" |\n");
        System.out.println(ANSI_RESET);
    }

}
