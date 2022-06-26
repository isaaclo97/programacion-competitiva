#include <bits/stdc++.h>
#define INF 0x3f3f3f
using namespace std;

int n,m,t;
bool visited1[10005];
bool visited[10005];
int memo[10005];

//all possible combinations
void possible(int time)
{
    if(time>t) return;
    if(visited1[time]) return;
    visited1[time]=true;
    possible(time+n);
    possible(time+m);
}
//less beer combinations
int DP(int time)
{
    if(time<0) return -INF;
    if(time==0) return 0;
    int &best = memo[time];
    if(visited[time]) return best;
    visited[time]=true;
    return best=max(DP(time-n),DP(time-m))+1;
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&t)==3)
    {
       memset(memo,-1,sizeof(memo));
       memset(visited1,false,sizeof(visited1));
       memset(visited,false,sizeof(visited));
       possible(0);
       if(!visited1[t]){
           for(int i=t; i>=0; i--) //less time = less beer
               if(visited1[i]) { printf("%d %d\n",DP(i),(t-i)); break;}
       }
       else printf("%d\n",DP(t));
    }
    return 0;
}
