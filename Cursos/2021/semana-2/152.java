import java.util.HashMap;
import java.util.Scanner;

public class AER152 {

    public static void main (String [] args){
        Scanner entrada = new Scanner(System.in);
        int n = entrada.nextInt();
        while (n!= 0){
            HashMap <Integer, Integer> mapa = new HashMap<>();
            for (int i = 0; i < n; i++){
                //Este bucle lee los elementos de la entrada
                //Comprueba si esta en el mapa o no
                //Y si está, suma 1. Si no está, pone un 1.
                int ni = entrada.nextInt();
                if (mapa.containsKey(ni)){
                    mapa.put(ni, mapa.get(ni)+1);
                } else {
                    mapa.put(ni, 1);
                }
            }
            int max = 0;
            int mejor_clave = -1;
            for (Integer elemento : mapa.keySet()){
                int apariciones = mapa.get(elemento);
                if (apariciones > max){
                    max = apariciones;
                    mejor_clave = elemento;
                }
            }
            System.out.println(mejor_clave);
            n = entrada.nextInt();
        }
    }
}
