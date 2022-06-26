#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

const int MAXN = 10001;

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
vector<edge> graph2[MAXN];
int dist[MAXN];
int dist2[MAXN];
int N,E;

int dijkstra2(int start, int end){
  dist2[start] = 0;
  priority_queue<state> pq;
  pq.push(state(start, 0));
  while(!pq.empty()){
    state cur = pq.top(); pq.pop();
    if(dist2[cur.node] < cur.dist) continue;
    if(cur.node == end) return cur.dist;
    for(unsigned int i=0;i<graph2[cur.node].size();i++){
      int dest = graph2[cur.node][i].to;
      int wht = graph2[cur.node][i].weight + cur.dist;
      if(dist2[dest] <= wht) continue;
      dist2[dest] = wht;
      pq.push(state(dest, wht));
    }
  }
  return -1;
}
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
  while(scanf("%d",&N)==1)
  {
    map<pair<int,int>,int> M;
    scanf("%d",&E);
    for(int i=0;i<N;i++) {dist[i]=INF; dist2[i]=INF; graph[i].clear(); graph2[i].clear();}
    for(int i=0; i<E;i++)
    {
    int from,to,weight; scanf("%d %d %d",&from,&to,&weight);
    from--; to--;
    graph[from].push_back(edge(from,to,weight));
    graph2[to].push_back(edge(to,from,weight));
    }
    int F, C,res,count=0,flag=1; scanf("%d %d",&F,&C); F--;
    dijkstra(F,N);
    for(int i=0; i<N;i++)  M[make_pair(F,i)]=dist[i];
    dijkstra2(F,N);
    for(int i=0; i<N;i++)  M[make_pair(i,F)]=dist2[i];
    for(int i=0; i<C;i++)
    {
        int toaux; scanf("%d",&toaux);
        toaux--;
        res=M[make_pair(F,toaux)];
        if(res==INF) flag=0;
        count+=res;
        res=M[make_pair(toaux,F)];
        if(res==INF) flag=0;
        count+=res;
  }
    if(flag==0) printf("Imposible\n");
    else printf("%d\n",count);
  }
  return 0;
}
