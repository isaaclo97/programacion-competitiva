#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 7;
const int inf = 0x3f3f3f3f;

struct Edge{
    int from, to, cap, flow;
};

struct Dinic{
    int n, m, s, t;
    vector<Edge>edges;
    vector<int>G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];

    void init(int nn){
        edges.clear();
        for (int i = 0; i < nn; ++i)G[i].clear();
    }

    void addEdge(int from,int to,int cap){
        edges.push_back((Edge){from,to,cap,0});
        edges.push_back((Edge){to,from,0,0});
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BFS(){
        memset(vis,0,sizeof vis);
        queue<int>Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while(!Q.empty()){
            int x = Q.front(); Q.pop();
            for (unsigned int i = 0; i < G[x].size(); ++i){
                Edge& e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x,int a){
        if (x == t || a == 0) return a;
        int flow = 0, f;
        for (int& i = cur[x]; i < G[x].size(); ++i){
            Edge& e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to,min(a,e.cap-e.flow))) > 0){
                e.flow += f;
                edges[G[x][i]^1 ].flow -= f;
                flow += f;
                a -= f;
               if (!a)break;


            }

        }
        return flow;
    }

    int maxflow(int s,int t){
        this->s = s; this->t = t;
        int flow = 0;
        while(BFS()){
            memset(cur,0,sizeof cur);
            flow += DFS(s,inf);
        }
        return flow;
    }

}dic;

int main() {

    int  n,m,x,ca=1, k,cases;
    scanf("%d",&cases);
    while(cases--) {
      scanf("%d %d", &n, &m);
      dic.init(n+m+1);
      int S,T; S=1; T=n+m+1;
      int cromos[100][100];
      memset(cromos,0,sizeof(cromos));
      for(int i = 1; i <=n; i++)
      {
        scanf("%d",&k);
        for(int j = 0; j <k; j++) {
           scanf("%d",&x);
           cromos[i][x]++;
        }
      }
      for(int i=1; i<=m;i++)
      {
          dic.addEdge(S,n+i,cromos[1][i]);
          dic.addEdge(n+i,T,1);
      }
      for(int i=2; i<=n;i++)
      {
          for(int j=1; j<=m;j++)
          {
              if(cromos[i][j]==0) dic.addEdge(n+j,i,1);
              else if(cromos[i][j]>1) dic.addEdge(i,n+j,cromos[i][j]-1);
          }
      }
      int flow = dic.maxflow(S,T);
      printf("Case #%d: %d\n",ca++,flow);
    }
    return 0;
}
