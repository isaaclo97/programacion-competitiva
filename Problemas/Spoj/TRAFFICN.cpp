#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

const int MAXN = 10005;

vector<pair<int,int>> graph[MAXN],Rgraph[MAXN];
int dist[MAXN],Rdist[MAXN];
bool flagG[MAXN], flagR[MAXN];

int N,E,res;

void dijkstra(int s, vector<pair<int,int>> *graph, int *dist, bool *flag) {
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > Q;
    Q.push(make_pair(0,s));
    int u, v, w, i, sz;
    dist[s] = 0;
    while(!Q.empty()) {
        u = Q.top().second;
        Q.pop();
        if(flag[u]) continue;
        sz = graph[u].size();
        for(i = 0; i < sz; i++) {
            v = graph[u][i].second;
            w = graph[u][i].first;
            if(!flag[v] && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                Q.push(make_pair(dist[v], v));
            }
        }
        flag[u] = true;
    }
}

int main(){

  int cases; cin>>cases;
  while(cases--)
  {
    int k,s,t;
    scanf("%d %d %d %d %d",&N,&E,&k,&s,&t);
    s--; t--;
    for(int i=0;i<=N;i++) {flagR[i]=false; flagG[i]=false; dist[i]=INF; Rdist[i]=INF; graph[i].clear(); Rgraph[i].clear();}
    for(int j=0;j<E;j++){
        int to,from, weight; scanf("%d %d %d", &from,&to, &weight);
        to--; from--;
        graph[from].push_back(make_pair(weight,to));
        Rgraph[to].push_back(make_pair(weight,from));
    }
    dijkstra(s,graph,dist,flagG);
    dijkstra(t,Rgraph,Rdist,flagR);
    res = INF;
    for(int i=0; i<k;i++)
    {
        int from,to,weight;  scanf("%d %d %d", &from,&to, &weight);
        from--; to--;
        res = min(res,min(dist[t],min(dist[from]+weight+Rdist[to],dist[to]+weight+Rdist[from])));
    }
    if(res==INF) printf("-1\n");
    else printf("%d\n",res);
  }
  return 0;
}
