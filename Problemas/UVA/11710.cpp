#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

const int MAXN = 200100;

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
int dist[MAXN];

int N,E;

int prim(int start){
  priority_queue<state> pq;
  pq.push(state(start, 0));
  dist[start] = 0;
  int sum = 0;
  while(!pq.empty()){
    state cur = pq.top(); pq.pop();
    if(dist[cur.node] < cur.dist) continue;
    if(visited[cur.node]) continue;
    sum += cur.dist;
    visited[cur.node] = true;
    for(unsigned int i=0;i<graph[cur.node].size();i++){
      int dest = graph[cur.node][i].to;
      int wht = graph[cur.node][i].weight;
      if(visited[dest]) continue;
      pq.push(state(dest, wht));
      dist[dest] = wht;
    }
  }
  return sum;
}
int main(){
  while(scanf("%d %d",&N,&E)==2 && (N!=0||E!=0))
  {
     memset(visited,0,sizeof(visited));
    for(int i=1;i<=N;i++) {dist[i]=INF; graph[i].clear();} // limpia el grafo
    map<string,int> M;
    for(int i=0; i<N;i++) {string r; cin>>r; M[r]=i+1;}
    for(int i=0;i<E;i++){
    string a,b; int weight; cin>>a>>b>>weight;
    graph[M[a]].push_back(edge(M[a],M[b],weight));
    graph[M[b]].push_back(edge(M[b], M[a], weight)); // borrar linea si es dirigido
    }
    string aux; cin>>aux;
    int res = prim(M[aux]);
    int flag=1;
    for(int i=1; i<=N;i++) if(dist[i]==INF) {flag=0; break;}
    if(flag==0) printf("Impossible\n");
    else printf("%d\n",res);
  }
  return 0;
}
