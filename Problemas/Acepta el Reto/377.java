import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger s = BigInteger.valueOf(16);
		BigInteger c = BigInteger.valueOf(0);
		BigInteger o = BigInteger.valueOf(1);
        BigInteger f = BigInteger.valueOf(4);
        BigInteger n = BigInteger.valueOf(9);
        while (in.hasNextBigInteger()) {
            BigInteger x = in.nextBigInteger();
            BigInteger mod = x.mod(s);
            if (mod.equals(c) || mod.equals(f) || mod.equals(o) || mod.equals(n)) System.out.println("NO SE");
            else  System.out.println("IMPERFECTO");
        }
    }
}