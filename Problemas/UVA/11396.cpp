#include<bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int color[310];
vector<int> adj[310];
bool posible;
bool visitado[310];
void bipartite(int s)
{
queue<int> Q;
color[s]=1;
Q.push(s);
visitado[s]=true;
while(!Q.empty())
{
    s=Q.front();
    Q.pop();
    for(unsigned int i=0;i<adj[s].size();++i)
    {
        int u=adj[s][i];
        if(color[u]==-1)
        {
            color[u]=1-color[s];
            Q.push(u);
            visitado[u]=true;
        }
        else if(color[u]==color[s])
            posible = false;
    }
}
}

int main()
{
    int x,y,N;
    while(scanf("%d",&N)==1 && N!=0)
      {
        posible=true;
        memset(color,-1,sizeof(color));
        memset(visitado,false,sizeof(visitado));
        while(scanf("%d%d",&x,&y)==2 && (x!=0||y!=0))
        {
         adj[x].push_back(y);
         adj[y].push_back(x);
        }
        for (int i = 0; i < N&&posible; i++)
            if (!visitado[i])
                bipartite(i);

        if(posible) cout<<"YES\n";
        else  cout<<"NO\n";
        for(int i=0; i<=N;i++)  adj[i].clear();
   }
    return 0;
}
