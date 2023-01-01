#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10100;

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
  int node, dist;
  state(){}
  state(int a, int b){
    node = a; dist = b;
  }
  bool operator<(const state &other)const{ // sobrecarga de operadores para ordenar
    return other.dist < dist;
  }
};

vector<edge> graph[MAXN];
int dist[MAXN];
int N,E,a,b,w;

bool dijkstra(int start, int end){
  dist[start] = 0;
  priority_queue<state> pq;
  pq.push(state(start, 0));
  while(!pq.empty()){
    state cur = pq.top(); pq.pop();
    if(dist[cur.node] < cur.dist) continue;
    if(cur.node == end) return true;
    for(int i=0;i<graph[cur.node].size();i++){
      int dest = graph[cur.node][i].to;
      int wht = graph[cur.node][i].weight + cur.dist;
      if(dist[dest] <= wht || graph[cur.node][i].weight<w) continue;
      dist[dest] = wht;
      pq.push(state(dest, wht));
    }
  }
  return false;
}

int main(){
  while(scanf("%d %d",&N,&E)==2) {
      for (int i = 1; i <= N; i++) graph[i].clear(); // limpia el grafo
      for (int i = 0; i < E; i++) {
          int from, to, weight;
          scanf("%d %d %d", &from, &to, &weight);
          graph[from].push_back(edge(from, to, weight));
          graph[to].push_back(edge(to, from, weight)); // borrar linea si es dirigido
      }
      int cases; scanf("%d",&cases);
      while(cases--){
          memset(dist, 0x3f3f3f3f, sizeof(dist));
          scanf("%d %d %d",&a,&b,&w);
          if(dijkstra(a,b)) printf("SI\n");
          else printf("NO\n");
      }
  }
  return 0;
}