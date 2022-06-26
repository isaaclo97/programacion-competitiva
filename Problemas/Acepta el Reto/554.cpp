
#include <bits/stdc++.h>
using namespace std;

int n,k;
int MOD = 1000000007;
int arr[15];
int memo[105];

int DP(int steps){
    if(steps==0) return 1;
    if(steps<0) return 0;
    int &best = memo[steps];
    if(memo[steps]!=-1) return memo[steps];
    int sum = 0;
    for(int i=0; i<k;i++) sum=((sum%MOD)+(DP(steps-arr[i])%MOD))%MOD;
    return best = sum;
}

int main(){
    while(scanf("%d",&n)==1 && n!=0){
        scanf("%d",&k);
        for(int i=0; i<k;i++) scanf("%d",&arr[i]);
        //Se puede bajar el tiempo si se ordena el array de menor a mayor y en el for de arriba se para el bucle cuando no existen mas soluciones :)
        for(int i=0; i<=n;i++) memo[i]=-1;
        printf("%d\n",DP(n));
    }
    return 0;
}
