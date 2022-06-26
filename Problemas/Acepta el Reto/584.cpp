
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int maxHoras,encendidos,tiempoUsado;
        scanf("%d %d %d",&maxHoras,&encendidos,&tiempoUsado);
        int usosMios = maxHoras/tiempoUsado;
        if(usosMios==encendidos && (usosMios*tiempoUsado)==maxHoras) printf("AMBAS\n");
        else if(usosMios>=encendidos) printf("ENCENDIDOS\n");
        else printf("HORAS\n");
    }
    return 0;
}
