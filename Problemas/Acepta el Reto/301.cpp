#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int coins[51];
int cantidad[51];
int sol[51];
int memo[51][10001];
int total,casos;

int DP(int moneda, int restante)
{
    if(restante==0) return 0;
    if(restante<0 || moneda>=casos)  return INF;
    int &best = memo[moneda][restante];
    if(best!=-1) return best;
    int check = INF;
    for(int i=0; i<=cantidad[moneda];i++) check = min(check,DP(moneda+1,restante-coins[moneda]*i)+i);
    return best=check;
}

void print_DP(int moneda, int restante) {
    if(restante==0 || restante<0 || moneda>=casos) return;
    for(int i=cantidad[moneda]; i>=0;i--)
        if (DP(moneda+1,restante-coins[moneda]*i)+i == memo[moneda][restante]) {
            print_DP(moneda+1,restante-coins[moneda]*i);
            for(int j=0; j<i;j++) sol[moneda]--;
            break;
        }
}

int main()
{
    while(scanf("%d",&casos)==1)
    {
     for(int i=0; i<casos;i++) scanf("%d",&coins[i]);
     for(int i=0; i<casos;i++) { scanf("%d",&cantidad[i]); sol[i]=cantidad[i]; }
     scanf("%d",&total);
     for(int i=0; i<=casos;i++)
         for(int j=0; j<=total;j++) memo[i][j]=-1;
     int res = DP(0,total);
     if(res!=INF) {
         printf("SI");
         print_DP(0,total);
         for(int i=0; i<casos;i++) printf(" %d",cantidad[i]-sol[i]);
         printf("\n");
    }
     else printf("NO\n");
    }
    return 0;
}
