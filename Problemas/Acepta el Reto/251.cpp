#include <bits/stdc++.h>
using namespace std;

int n,m;
int coins[10];

long long int solve()
{
    queue<pair<int,int>> q;
    q.push({0,0});
    long long int res = 0;
    bool visited[2005];
    memset(visited,false,sizeof(visited));
    while(!q.empty())
    {
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0; i<n;i++)
        {
            if(!visited[coins[i]+cur.first] && cur.second+1<=m)
            {
                res++;
                visited[coins[i]+cur.first]=true;
                q.push({coins[i]+cur.first,cur.second+1});
            }
        }
    }
    return res;
}
int main()
{

   int cases; scanf("%d",&cases);
   while(cases--)
   {
       scanf("%d%d",&n,&m);
       for(int i=0; i<n;i++) scanf("%d",&coins[i]);
       printf("%lld\n",solve());
   }
   return 0;
}
