package awale.verification;

public class Odd implements Verification {

	@Override
	public boolean satisfy(int nb) {
		return nb % 2 == 0;
	} // Cause the odd hole has an even index in de hole list

}
