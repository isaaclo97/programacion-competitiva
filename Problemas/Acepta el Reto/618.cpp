
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,val,q,from,to;
    while(scanf("%d",&n)==1 && n!=0){
        long long int acum[n+1];
        acum[0]=0;
        for(int i=1; i<=n;i++){
            scanf("%d",&val);
            acum[i]=acum[i-1]+val;
        }
        scanf("%d",&q);
        for(int i=0; i<q;i++){
            scanf("%d %d",&from,&to);
            long long int res = acum[to-1]-acum[from];
            printf("%lld\n",res);
        }
        printf("---\n");
    }
    return 0;
}
