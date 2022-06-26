
#include <bits/stdc++.h>
using namespace std;

/*
 Existen 360 grados y 12 horas por lo que
 360/12 = 30 y como son horas y cada hora tiene 60 minutos
 30 / 60 = 0.5
 Para minutos sería 360/60 = 6
 Con esto tenemos que cada 0.5 grados corresponde a un movimiento
 de la aguja de la hora y cada 6 grados del minuto.
 
 Si suponemos como uno de los valores la hora, sacando de estos valores
 la parte entera y nos quedamos con la decimal, la parte decima debe
 corresponder con los valores del minutero (puesto que las dos agujas
 se desplazan), si coincide estableciendo como hora el primer número o
 el segundo tendremos solución en el que coincidan, si no será ERROR.
*/

int main(){

    int cases; scanf("%d",&cases);
    while(cases--){
        double a,b; scanf("%lf %lf",&a,&b);
        double cur = (double)(a-(30*(int)(a/30)))*2;
        bool testRemainingValueOfHourAreMinutes = cur ==(b/6);
        cur = (double)(b-(30*(int)(b/30)))*2;
        bool testARemainingValueOfHourAreMinutes = cur==(a/6);

        //Asumimos a como hora y b como minutero
        if(testRemainingValueOfHourAreMinutes)
            printf("%02d:%02d\n",(int)a/30, (int)b/6);
        else if(testARemainingValueOfHourAreMinutes)
            printf("%02d:%02d\n",(int)b/30, (int)a/6);
        else printf("ERROR\n");
    }
}
