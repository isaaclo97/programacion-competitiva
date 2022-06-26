#include<bits/stdc++.h>
using namespace std;

int color[110];
vector<int> adj[110];
bool posible;
bool visitado[110];
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
    int edge,x,y,N;
    while(scanf("%d",&N)!=EOF)
      {
        posible=true;
        memset(color,-1,sizeof(color));
        memset(visitado,false,sizeof(visitado));
        cin>>edge;
        for(int i=0;i<edge;i++)
        {
         cin>>x>>y;
         adj[x].push_back(y);
         adj[y].push_back(x);
        }
        for (int i = 0; i < N&&posible; i++)
            if (!visitado[i])
                bipartite(i);

        if(posible)
        cout<<"SI\n";
        else
        cout<<"NO\n";
        for(int i=0; i<N;i++)
            adj[i].clear();
   }
    return 0;
}
