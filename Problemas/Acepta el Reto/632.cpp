
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M,T;
    while(scanf("%d %d %d",&N,&M,&T)==3){
        int num;
        int fh[N],sh[M];
        vector<int> acfh,acsh;
        acfh.push_back(0); acsh.push_back(0);
        for(int i=0; i<N;i++) scanf("%d",&fh[i]);
        for(int i=N-1; i>=0;i--) acfh.push_back(acfh[acfh.size()-1]+fh[i]);
        for(int i=0; i<M;i++) scanf("%d",&sh[i]);
        for(int i=M-1; i>=0;i--) acsh.push_back(acsh[acsh.size()-1]+sh[i]);
        if((acfh[N]+acsh[M])<=T) {
            printf("%d\n",N+M);
            continue;
        }
        if(T==0 || (N==0 && M==0)) {
            printf("0\n");
            continue;
        }
        int maxValue = 0;
        for(int i=0; i<=N;i++){
            if(acfh[i]>T) break;
            int buscar = T-acfh[i];
            vector<int>::iterator low=upper_bound(acsh.begin(), acsh.end(), buscar);
            int idx = (low- acsh.begin());
            if(acsh[idx]>buscar) idx--;
            idx = min(idx,M);
            maxValue = max(maxValue,i+idx);
        }
        printf("%d\n",maxValue);
    }
    return 0;
}
