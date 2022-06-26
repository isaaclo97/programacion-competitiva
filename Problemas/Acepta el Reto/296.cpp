
#include <bits/stdc++.h>
using namespace std;

struct intervalo{
    int start,end;
};
bool compare(intervalo a, intervalo b){
    if(a.start == b.start) return a.end>b.end;
    return a.start<b.start;
}
int main(){
    int C,F,N;
    while(scanf("%d %d %d",&C,&F,&N)==3 && (C!=0 || F!=0 ||N!=0)){
        int s,e;
        vector<intervalo> V;
        for(int i=0; i<N;i++){
            scanf("%d %d",&s,&e); V.push_back(intervalo{s,e});
        }
        sort(V.begin(),V.end(),compare);
        int res = 0;
        int curEnd = C, maximo=C;
        for(int i=0; i<N && curEnd<F;i++){
            if (V[i].start > curEnd) {
                curEnd = maximo; res++;
            }
            if (V[i].start <= curEnd && V[i].end > maximo)
                maximo = V[i].end;
        }
        if (curEnd >= F) printf("%d\n",res);
        else if (maximo >= F) printf("%d\n",res+1);
        else printf("Imposible\n");
    }
    return 0;
}
