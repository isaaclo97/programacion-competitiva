
#include <bits/stdc++.h>
using namespace std;


int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int poblacion,ironman,spiderman,saltos;
        scanf("%d %d %d %d",&poblacion,&ironman,&spiderman,&saltos);
        queue<int> S;
        for(int i=1; i<=poblacion;i++) S.push(i);
        //Thanos no escatima en muertes. Si el número de personas total es impar,
        //eliminará a una persona más que las que sobrevivan.
        int iters = poblacion/2;
        if(iters*2!=poblacion) iters++;
        bool iron = true;
        bool spider = true;
        while(iters--){
            for(int i=0; i<saltos;i++){
                int t = S.front(); S.pop();
                S.push(t);
            }
            int remove = S.front(); S.pop();
            if(remove==ironman) iron=false; //muere
            if(remove==spiderman) spider=false; //muere
        }
        if(iron && !spider) printf("No quiero irme, Sr. Stark!\n"); //Spiderman está entre los asesinados y Iron Man no
        else if(!iron && spider) printf("No quiero irme, Peter!\n"); //Spiderman el que sobrevive y Iron Man el que muere
        else printf("No hay abrazo\n"); //ambos sobreviven o ambos mueren
    }
    return 0;
}
