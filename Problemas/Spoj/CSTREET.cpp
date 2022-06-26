#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
 
const int MAXN = 1005;
 
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
 
bool visited[MAXN];
vector<edge> graph[MAXN];
int cases,N,E,c;
 
int prim(int start){
  priority_queue<state> pq;
  pq.push(state(start, 0));
  int sum = 0;
  while(!pq.empty()){
    state cur = pq.top(); pq.pop();
    if(visited[cur.node]) continue;
    sum += cur.dist;
    visited[cur.node] = true;
    for(unsigned int i=0;i<graph[cur.node].size();i++){
      int dest = graph[cur.node][i].to;
      int wht = graph[cur.node][i].weight;
      if(visited[dest]) continue;
      pq.push(state(dest, wht));
    }
  }
  return sum;
}
 
int main(){
  scanf("%d",&cases); c=1;
  while(cases--)
  {
  int p; cin>>p;
  scanf("%d %d",&N,&E);
  for(int i=0; i<N;i++) {visited[i]=false; graph[i].clear(); }
  for(int i=0;i<E;i++){
  int from,to,w;
  scanf("%d %d %d",&from,&to,&w);
  from--; to--;
  graph[from].push_back(edge(from,to,w*p));
  graph[to].push_back(edge(to,from,w*p));
  }
  printf("%d\n",prim(0));
  }
  return 0;
}
