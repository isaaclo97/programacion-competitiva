import java.util.*;
public class Aer124
{

    public static int acarreos(String s1, String s2)
    {
        int cuenta=0; //cuenta de acarreos
        int acarreo=0; //acarreo actual
        int i=0; //posición por la izquierda
        boolean terminado=false; //bandera para controlar el bucle
        while (!terminado)
        {
            //Coger el siguiente dígito de cada número por la izquierda. 
            //Si he superado la longitud, el dígito en el que estoy es 0
            int i1=i<s1.length()?s1.charAt(s1.length()-i-1)-'0':0; 
            int i2=i<s2.length()?s2.charAt(s2.length()-i-1)-'0':0;
            int suma=acarreo+i1+i2; //sumamos ambos mas el posible acarreo anterior
            acarreo=suma>=10?1:0; //Hay acarreo si la suma es es > 10
            cuenta+=acarreo;
            i++; //pasar al siguiente por la izquierda
            //terminamos si hemos sobrepasado la longitud de alguna de las dos cifras y no hay acarreos
            terminado=!(acarreo>0) && (i>=s1.length() || i>s2.length());
        }
        return cuenta;
    }
   
    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        boolean terminar=false;
        do
        {
            String s1=in.next(); //lee primer número como cadena
            String s2=in.next(); //lee segundo como cadena
            in.nextLine(); //cambia de lína (no es necesario)
            terminar=s1.equals("0")&&s2.equals("0");
            if (!terminar)
            {
                System.out.println(acarreos(s2,s1));
            }
        } while (!terminar);
        
    }
}
