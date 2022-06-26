#include <bits/stdc++.h>
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
bool visited[MAXN];

int a=1;
int N,E;

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
    while(scanf("%d %d",&N,&E)==2)
    {
      memset(visited,0,sizeof(visited));
      for(int i=1;i<=N;i++) graph[i].clear(); // limpia el grafo

        for(int i=0;i<E;i++){
        int from, to, weight; scanf("%d %d %d",&from, &to, &weight);
        graph[from].push_back(edge(from,to,weight));
        graph[to].push_back(edge(to, from, weight)); // borrar linea si es dirigido
        }
        int flag=1;
        int res = prim(a);
        for(int i=1;i<=N;i++) {if(!visited[i]) flag=0;}
        if(flag==1) printf("%d\n",res);
        else printf("Imposible\n");
    }
  return 0;
}
