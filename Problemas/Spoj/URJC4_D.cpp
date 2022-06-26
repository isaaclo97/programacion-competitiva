#include<bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int color[100100];
vector<int> adj[100100];
bool posible;
bool visitado[100100];
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
    int edge,x,y,N,cases;
    cin>>cases;
    while(cases--)
      {
        posible=true;
        memset(color,-1,sizeof(color));
        memset(visitado,false,sizeof(visitado));
        cin>>N>>edge;
        for(int i=0; i<=N;i++)
            adj[i].clear();
        for(int i=0;i<edge;i++)
        {
         cin>>x>>y;
         adj[x].push_back(y);
         adj[y].push_back(x);
        }
        for (int i = 0; i < N&&posible; i++)
            if (!visitado[i])
                bipartite(i);

        if(posible) cout<<"SI\n";
        else cout<<"NO\n";
   }
    return 0;
}
