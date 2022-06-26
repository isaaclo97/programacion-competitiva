#include <bits/stdc++.h>
using namespace std;

vector<int> adj[11],ap;
vector<pair<int,int> >bridges;
int disc[11],low[11],parent[11],visited[11];

pair<int,int> minmax(int x,int y)
{
    pair<int,int> ret;
    if(x<y) ret=make_pair(x,y);
    else ret=make_pair(y,x);
    return ret;
}

void dfs(int vertex,int vistime)
{
    visited[vertex]=1;
    disc[vertex]=low[vertex]=vistime;
    int child=0;
    for(int i=0;i<(int)adj[vertex].size();i++)
        if(!visited[adj[vertex][i]])
        {
            child++;
            parent[adj[vertex][i]]=vertex;
            dfs(adj[vertex][i],vistime+1);
            low[vertex]=min(low[vertex],low[adj[vertex][i]]);
            if(parent[vertex]==-1){
                bridges.push_back(minmax(vertex,adj[vertex][i]));
                if(child>1)
                    ap.push_back(vertex);
            }
            else if(low[adj[vertex][i]]>disc[vertex]){
                bridges.push_back(minmax(vertex,adj[vertex][i]));
                ap.push_back(vertex);
            }
            else if(low[adj[vertex][i]]==disc[vertex])
                ap.push_back(vertex);

        }
        else if(parent[vertex]!=adj[vertex][i])
            low[vertex]=min(low[vertex],disc[adj[vertex][i]]);

}
int main()
{
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(parent,-1,sizeof(parent));
    dfs(0,0);
    sort(ap.begin(),ap.end());
    sort(bridges.begin(),bridges.end());
    printf("%d\n",ap.size());
    for(unsigned i=0;i<ap.size();i++) printf("%d ",ap[i]);
    printf("\n%d\n",bridges.size());
    for(unsigned i=0;i<bridges.size();i++)  printf("%d %d\n", bridges[i].first,bridges[i].second);
    return 0;
}
