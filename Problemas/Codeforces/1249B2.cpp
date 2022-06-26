#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200100;
const int INF = 0x3f3f3f3f;

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
int check[MAXN];
int index=0;

int N,E;

int dijkstra(int start, int end){
  dist[start] = 0;
  priority_queue<state> pq;
  pq.push(state(start, 0));
  while(!pq.empty()){
    state cur = pq.top(); pq.pop();
    if(dist[cur.node] < cur.dist) continue;
    if(cur.node == end) return cur.dist;
    for(int i=0;i<graph[cur.node].size();i++){
      int dest = graph[cur.node][i].to;
      int wht = graph[cur.node][i].weight + cur.dist;
      if(dist[dest] <= wht) continue;
      dist[dest] = wht;
      check[dest]=index;
      check[cur.node]=index;
      pq.push(state(dest, wht));
    }
  }
  return -1;
}

int main(){
   int n,m; scanf("%d",&n);
   while(n--){
      scanf("%d",&m);
      N=E=m;
      memset(dist,0x3f,sizeof(dist));
      int arr[m+1];
      for(int i=1;i<=N;i++) graph[i].clear(); // limpia el grafo
        for(int i=1;i<=E;i++){
        int to; scanf("%d",&to); arr[i]=to;
        graph[i].push_back(edge(i,to,1));
        }
      memset(check,-1,sizeof(check));
      vector<int> V;
      index=-1;
      memset(dist,0x3f,sizeof(dist));
      for(int i=1; i<=m;i++) {
          //memset(dist,0x3f,sizeof(dist));
          int indexRes;
          if(check[i]==-1) { index++; V.push_back(dijkstra(arr[i],i)+1); indexRes=index;  }
          else indexRes=check[i];
          if(i==1) printf("%d",V[indexRes]);
          else printf(" %d",V[indexRes]);
      }
      printf("\n");
      for(int i=1;i<=N;i++) graph[i].clear();
   }
  return 0;
}