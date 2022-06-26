
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    while(scanf("%d",&cases)==1 && cases!=0){
        int memo[22];
        int madrigueras[cases+1];
        for(int i=0; i<cases;i++){
            scanf("%d",&madrigueras[i]);
        }
        for(int i=0; i<21;i++) memo[i]=0;

        long long int res = 0;
        madrigueras[cases]=21;
        for(int i=0; i<cases;i++){
            if(memo[madrigueras[i]]>i){
                res+=memo[madrigueras[i]]-i;
                continue;
            }
            for(int j=i+1;j<=cases;j++){
                if(madrigueras[j]>madrigueras[i]){
                    res+=j-i;
                    memo[madrigueras[i]]=j;
                    break;
                }
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
