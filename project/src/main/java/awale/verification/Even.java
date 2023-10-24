package awale.verification;

public class Even implements Verification {
    @Override
    public boolean satisfy(int nb) {
        return nb % 2 == 1;
    } // cause the even hole has an odd index in de hole list
}
