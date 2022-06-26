#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

pair<int,int> memo[105][105];
vector<int> V[105];

pair<int,int> DP(int x)
{
   if(V[x].size()==0) { return {0,x};}
   pair<int,int> res = {0,INF};
   for(unsigned int i=0; i<V[x].size();i++){
           pair<int,int> &best = memo[x][V[x][i]];
           pair<int,int> r;
           if(best.first!=-1) r = best;
           else
           {
               r =  DP(V[x][i]);
               best.first = r.first+1;
               best.second = r.second;
           }
           if(res.first==best.first) res.second=min(res.second,best.second);
           else if(best.first>res.first) res.second=best.second;
           res.first=max(best.first,res.first);
   }
   return res;
}
int main(){
    int ca = 1,nodes;
    while(scanf("%d",&nodes)==1 && nodes!=0)
    {

        int x,y,start;
        for(int i=0; i<101;i++) V[i].clear();
        for(int i=0; i<101;i++)
           for(int j=0; j<101;j++) memo[i][j].first = -1;
        scanf("%d",&start);
        while(scanf("%d %d",&x,&y)==2 && (x!=0 || y!=0)) V[x].push_back(y);
        pair<int,int> res = DP(start);
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",ca++,start,res.first,res.second);
    }
    return 0;
}
