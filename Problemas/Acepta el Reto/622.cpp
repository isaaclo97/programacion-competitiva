
#include <bits/stdc++.h>
using namespace std;

int main(){
    int examenes;
    while(scanf("%d",&examenes) && examenes!=0){
        int total=0,num,notaesperada;
        for(int i=0; i<examenes;i++) {scanf("%d",&num); total+=num;}
        scanf("%d",&notaesperada);
        int notanecesaria = (notaesperada*(examenes+1))-total;
        if(notanecesaria<=10 && notanecesaria>=0) printf("%d\n",notanecesaria);
        else printf("IMPOSIBLE\n");
    }
    return 0;
}

/*
2
10 10
0
2
0 0
10
0

IMPOSIBLE
IMPOSIBLE
*/
