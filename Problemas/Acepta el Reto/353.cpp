
#include <bits/stdc++.h>
using namespace std;

int totalTime,n;
int profundidad[105],oro[105];
int memo[10005][105];
vector<pair<int,int>> res;

int solve(int time, int id){
    if(time<0) return -0x3f3f3f;
    if(n==id) return 0;
    int &best = memo[time][id];
    if(best!=-1) return best;
    return best = max(solve(time-profundidad[id]*3,id+1)+oro[id],solve(time,id+1));
}

void print_DP(int time, int id) {
    if(time<0 || n==id)  return;
    if(solve(time-profundidad[id]*3,id+1)+oro[id] == memo[time][id]){
        print_DP(time-profundidad[id]*3,id+1);
        res.push_back({profundidad[id],oro[id]});
        //printf("%d %d\n",profundidad[id],oro[id]);
    }
    else if(solve(time,id+1) == memo[time][id]) print_DP(time,id+1);
}

int main(){
    while(scanf("%d",&totalTime)==1){
        scanf("%d",&n);
        for(int i=0; i<n;i++)  scanf("%d %d",&profundidad[i],&oro[i]);
        for(int i=0; i<=totalTime;i++)
            for(int j=0; j<=n;j++)
                memo[i][j]=-1;
        //memset(memo,-1,sizeof(memo));
        printf("%d\n",max(0,solve(totalTime,0)));
        print_DP(totalTime,0);
        printf("%d\n",res.size());
        for(int i = res.size()-1; i>=0; i--){
            printf("%d %d\n",res[i].first,res[i].second);
        }
        printf("----\n");
        res.clear();
    }
    return 0;
}
