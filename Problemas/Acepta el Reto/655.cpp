#include <bits/stdc++.h>
using namespace std;

int nodes,states,s1,s2,t;
vector<pair<int,int>> graph[10005];
int memo[10005];

int DP(int node){
    if(graph[node].size()==0) return 0;
    int &best = memo[node];
    if(best!=-1) return best;
    int sum = 0;
    for(int i=0;i<graph[node].size();i++){
        sum=max(sum,DP(graph[node][i].first)+graph[node][i].second);
    }
    return best=sum;
}

void print_DP(int node) {
    if(graph[node].size()==0) { printf("%d\n",node); return; }
    for (int i=0; i<graph[node].size(); i++) {
        if (DP(graph[node][i].first)  == memo[node]-graph[node][i].second) {
            printf("%d ",node);
            print_DP(graph[node][i].first);
            return;
        }
    }
}

int main(){
    while(scanf("%d %d",&nodes,&states)==2 && (nodes!=0 ||states!=0)){
        for(int i=0; i<=nodes;i++){ graph[i].clear(); memo[i]=-1; }
        for(int i=0; i<states;i++){
            scanf("%d %d %d",&s1,&s2,&t); graph[s1].push_back({s2,t});
        }
        for(int i=0; i<=nodes;i++) sort(graph[i].begin(),graph[i].end());
        int res = 0;
        for(int i=1;i<=nodes;i++) res=max(res,DP(i));
        printf("%d\n",res);
        for(int i=1;i<=nodes;i++)
            if(memo[i]==res) { print_DP(i); break; }
    }
    return 0;
}