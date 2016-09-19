import java.math.BigInteger;
import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = 2016;
		BigInteger fact[] = new BigInteger[N];
		fact[0] = BigInteger.ONE;
		for (int i = 1; i < N; i++) {
			fact[i] = fact[i-1].multiply(new BigInteger(Integer.toString(i)));
		}
		N = 1002;
		BigInteger cat[] = new BigInteger[N];
		for (int i = 1; i < N; i++) {
			cat[i] = fact[2*i].divide(fact[i]).divide(fact[i+1]);
		}
		while (in.hasNext()) {
			N = in.nextInt();
			System.out.println(cat[N]);
		}
	}
}
