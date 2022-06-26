#include <bits/stdc++.h>
using namespace std;

int main(){
    int q; scanf("%d",&q);
    while(q--){
        long long int n; scanf("%lld",&n);
        long long int aux,par,impar; par=impar=0;
        for(long long int i=0; i<n;i++){
            scanf("%lld",&aux);
            if(aux%2==0) par++;
            else impar++;
        }
        long long int m,res=0; scanf("%lld",&m);
        for(long long int i=0; i<m;i++){
            long long int aux; scanf("%lld",&aux);
            if(aux%2==0) res+=par;
            else if(aux%2!=0) res+=impar;
        }
        printf("%lld\n",res);
    }
    return 0;
}
