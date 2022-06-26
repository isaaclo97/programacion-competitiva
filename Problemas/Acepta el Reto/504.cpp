#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
const int MAXN = 20001;

struct edge{
  int from, to, weight;
  edge(){}
  edge(int a, int b, int c){
    from = a;
    to = b;
    weight = c;
  }
};

struct state{
  int node, dist, calles;
  state(){}
  state(int a, int b, int c){
    node = a; dist = b; calles=c;
  }
  bool operator<(const state &other)const{ // sobrecarga de operadores para ordenar
    if(other.dist == dist) return other.calles<calles; return other.dist < dist;
  }
};

vector<edge> graph[MAXN];
int dist[MAXN];
int N,E,dijkcalles;

int dijkstra(int start, int end){
  for(int i=0;i<=N;i++) dist[i]=INF;
  dist[start] = 0;
  priority_queue<state> pq;
  pq.push(state(start, 0,0));
  while(!pq.empty()){
    state cur = pq.top(); pq.pop();
    if(dist[cur.node] < cur.dist) continue;
    if(cur.node == end) { dijkcalles = cur.calles; return cur.dist; }
    for(unsigned int i=0;i<graph[cur.node].size();i++){
      int dest = graph[cur.node][i].to;
      int wht = graph[cur.node][i].weight + cur.dist;
      if(dist[dest] < wht) continue;
      dist[dest] = wht;
      pq.push(state(dest, wht,cur.calles+1));
    }
  }
  return -1;
}

int BFS(int start, int target){
    queue<pair<int,int> > q;
    q.push(make_pair(start,0));
    bool visited[N+1]; memset(visited,false,sizeof(visited));
    visited[start] = true;
    while(!q.empty()){
        pair<int,int> current = q.front(); q.pop();
        if(current.first == target) return current.second;
        for(unsigned int i=0;i<graph[current.first].size();i++){
            int dest = graph[current.first][i].to;
            if(visited[dest]) continue;
            visited[dest] = true;
            q.push(make_pair(dest,current.second+1));
        }
    }
return -1;
}
int main()
{
    while(scanf("%d\n%d",&N,&E)==2)
    {
      for(int i=0;i<=N;i++) graph[i].clear();
      for(int i=0;i<E;i++){
        int from, to, weight; scanf("%d %d %d",&from, &to, &weight);
        graph[from].push_back(edge(from,to,weight));
        graph[to].push_back(edge(to, from, weight));
      }
      int query; scanf("%d",&query);
      for(int i=0; i<query;i++)
      {
        int a,b; scanf("%d%d",&a,&b);
        int calles = BFS(a,b);
        if(calles==-1) printf("SIN CAMINO\n");
        else{
            printf("%d ",dijkstra(a,b));
            if(calles==dijkcalles) printf("SI\n");
            else printf("NO\n");
        }
      }
      printf("----\n");
    }
    return 0;
}
