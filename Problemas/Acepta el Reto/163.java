import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        String aux = s.nextLine();
        while(!aux.equals("FIN")) {
            BigInteger bigInt = new BigInteger(aux, 16);
            bigInt = bigInt.add(BigInteger.ONE);
            String res = bigInt.toString(16);
            System.out.println(res.toUpperCase());
            aux = s.nextLine();
        }
    }
}
