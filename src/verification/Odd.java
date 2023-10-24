package verification;

public class Odd implements Verification {
    @Override
    public boolean satisfy(int nb) { return nb % 2 == 0; } // cause the odd hole has an even index in de hole list
}
