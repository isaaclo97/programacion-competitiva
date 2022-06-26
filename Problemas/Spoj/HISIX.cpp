#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

const int MAXN = 200002;

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
        scanf("%d",&N);
        for(int i=0;i<=N*2;i++) { dist[i]=INF; graph[i].clear(); }
        map<string,int> M;
        int count=1;
        for(int i=0; i<N;i++)
        {
            string n1,n2; int weight; cin>>n1>>n2>>weight;
            if(M[n1]==0) {M[n1]=count; count++;}
            if(M[n2]==0) {M[n2]=count; count++;}
            graph[M[n1]].push_back(edge(M[n1],M[n2],weight));
            graph[M[n2]].push_back(edge(M[n2],M[n1],weight));
        }
       int T=-INF;
       for(int i=1; i<count;i++)
       {
       dijkstra(i,count);
       for(int i=1;i<count;i++) { T=max(T,dist[i]); dist[i]=INF;}
       }
       if(T==INF) printf("Case #%d: INFINITE\n",c++);
       else printf("Case #%d: %d\n",c++,T);
      }
  return 0;
 }
