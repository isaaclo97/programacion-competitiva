
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    while(scanf("%d %d",&N,&M)==2 && (N!=0 || M!=0)){
        long long int total = 0,res=0;
        long long int dias[M],last=0;
        for(int i=0; i<M;i++){
            scanf("%lld",&dias[i]);
            if(i<N) total+=dias[i];
            else{
                total+=dias[i];
                total-=dias[last];
                last++;
            }
            res=max(res,total);
        }
        printf("%lld\n",res);
    }
    return 0;
}
