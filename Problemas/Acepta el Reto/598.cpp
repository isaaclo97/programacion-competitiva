
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    while(scanf("%d %d",&N,&M)==2){
        map<int,int> tallas,tenemos;
        int aux;
        for(int i=0; i<N;i++) { scanf("%d",&aux); tallas[aux]++; }
        for(int i=0; i<M;i++) { scanf("%d",&aux); tenemos[aux]++; }
        int sum = 0;
        for(int i=1; i<=100;i++){
            int asignadas = min(tallas[i], tenemos[i]);
            tallas[i]-=asignadas;
            tenemos[i]-=asignadas;
            if (tallas[i] > 0) {
                asignadas = min(tallas[i], tenemos[i+1]);
                tallas[i]-=asignadas;
                tenemos[i+1]-=asignadas;
            }
            sum += tallas[i];
        }
        printf("%d\n",sum);
    }
    return 0;
}
