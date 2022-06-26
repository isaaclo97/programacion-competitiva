
#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

const int MAXN = 105;

int T[MAXN][MAXN];
int cost[MAXN][MAXN];
int dis[MAXN][10*MAXN];
int N,A;
void solve()
{
    priority_queue<pair<int,int> > pq ;
    pq.push(make_pair(0,1)) ;
    dis[1][0] = 0 ;
    while( !pq.empty() )
    {
        pair<int,int> now ;
        now = pq.top();
        pq.pop();
        for (int i=1 ; i <= N ; i++ )
        {
            if( i == now.second || (now.first+T[now.second][i])>A ) continue ;
            int tt = now.first + T[now.second][i];
            if(  dis[i][tt] > dis[now.second][now.first] + cost[now.second][i] )
            {
                dis[i][tt] = dis[now.second][now.first] + cost[now.second][i];
                pq.push( make_pair( tt , i ) ) ;
            }
        }
    }
}
int main()
{
  while(scanf("%d %d",&N,&A) == 2 && (N!=0 || A!=0))
   {
      for (int i =1; i <= N; i++)
          for (int j=0; j<=A; j++) dis[i][j] = INF ;
       for (int i=1; i<=N; i++)
           for (int j=1; j<=N; j++) scanf("%d",&T[i][j]);
       for (int i=1; i<=N; i++)
           for (int j=1; j<=N; j++) scanf("%d",&cost[i][j]);
       solve();
       int ans = INF , aux;
       for (int i=0; i<=A; i++)
       {
            if(ans > dis[N][i] )
            {
                ans = dis[N][i];
                aux = i ;
            }
       }
       if(ans==INF) printf("-1\n");
       else printf("%d %d\n",ans,aux);
   }

    return 0;
}
