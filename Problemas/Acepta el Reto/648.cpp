#include <bits/stdc++.h>
using namespace std;

int puntuation, cases;
int sectores[55];

int memo[505];
int INF = 0x3f3f3f3f;

int DP(int total) {
    if (total == 0)  return 0;
    if (memo[total]!=-1) return memo[total];
    int min = INF;
    for (int i=0; i < cases; i++ ) {
        if(sectores[i] > total ) continue;
        int val = DP(total - sectores[i]);
        if(val < min) min = val;
    }
    return memo[total] = (min == INF ? min : min + 1);
}

void print_DP(int total) {
    if (total == 0) return;
    for (int i=0; i<cases; i++) {
        if(sectores[i] > total ) continue;
        if (DP(total - sectores[i])  == memo[total]-1) {
            printf(" %d",sectores[i]);
            print_DP(total - sectores[i]);
            return;
        }
    }
}


int main(){
    while(scanf("%d %d",&puntuation,&cases)==2){
        for(int i=0; i<cases;i++) scanf("%d",&sectores[i]);
        sort(sectores,sectores+cases,greater<int>());
        for(int i=0; i<=puntuation;i++) memo[i]=-1;
        int res = DP(puntuation);
        if(res!=INF){
            printf("%d:",res);
            print_DP(puntuation);
            printf("\n");
        }
        else printf("Imposible\n");
    }
    return 0;
}