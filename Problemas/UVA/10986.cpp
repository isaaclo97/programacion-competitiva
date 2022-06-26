#include<bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

const int MAXN = 100100;

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

int a=1, b=3;
int N,E;

int dijkstra(int start, int end){
  dist[start] = 0;
  priority_queue<state> pq;
  pq.push(state(start, 0));
  while(!pq.empty()){
    state cur = pq.top(); pq.pop();
    if(dist[cur.node] < cur.dist) continue;
    if(cur.node == end) return cur.dist;
    for(unsigned int i=0;i<graph[cur.node].size();i++){
      int dest = graph[cur.node][i].to;
      int wht = graph[cur.node][i].weight + cur.dist;
      if(dist[dest] <= wht) continue;
      dist[dest] = wht;
      pq.push(state(dest, wht));
    }
  }
  return -1;
}

int main(){
  int cases,c=1; scanf("%d",&cases);
  while(cases--)
  {
   int s,t;
    scanf("%d %d %d %d",&N,&E,&s,&t);
  memset(dist,0x3f,sizeof(dist));
  for(int i=0;i<=N;i++) graph[i].clear(); // limpia el grafo
    for(int i=0;i<E;i++){
    int from, to, weight; scanf("%d %d %d",&from, &to, &weight);
    graph[from].push_back(edge(from,to,weight));
    graph[to].push_back(edge(to, from, weight)); // borrar linea si es dirigido
    }
  int aux = dijkstra(s,t);
  if(aux==-1) printf("Case #%d: unreachable\n",c++);
  else printf("Case #%d: %d\n",c++,aux);
  }
  return 0;
}
