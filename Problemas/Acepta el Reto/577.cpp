
#include <bits/stdc++.h>
using namespace std;

//El problema pide saber cuantas soluciones posibles de cucharadas ha comido Mafalda
// 2 2 5 sería - 3 2, 4 1 y 5 0 (3)
// 7 5 10 seráía - 7 3, 8 2, 9 1, 10 0 (4)

int main(){;
    int cases; scanf("%d",&cases);
    while(cases--){
        int a,b,c,res=0; scanf("%d %d %d",&a,&b,&c);
        for(int i=a; i<=c;i++){
            if((c-i)<=b) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
