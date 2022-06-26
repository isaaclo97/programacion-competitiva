
#include <bits/stdc++.h>
using namespace std;

int memo[250005];
int data[250005];
int N;

bool DP(int idx){
    if(idx>N) return false;
    if(idx==N) return true;
    int &best = memo[idx];
    if(best!=-1) return best;
    return best = DP(idx+data[idx]+1);
}

int main(){
    while(scanf("%d",&N)==1 && N!=0){
        for(int i=0; i<N;i++){
            scanf("%d",&data[i]);
            memo[i]=-1;
        }
        memo[N]=-1;
        bool sol = false;
        for(int i=1; i<=N && !sol;i++){
            sol = DP(i);
            if(sol) printf("%d\n",i);
        }
    }
    return 0;
}
