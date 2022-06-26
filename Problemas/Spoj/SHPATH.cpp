#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
 
const int MAXN = 10005;
 
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
 
  int cases; cin>>cases;
  while(cases--)
  {
    cin>>N;
    map<string,int> M;
    for(int i=0;i<=N;i++) graph[i].clear();
    for(int i=0; i<N;i++)
    {
        string name; cin>>name;
        M[name]=i;
        scanf("%d",&E);
        for(int j=0;j<E;j++){
        int to, weight; scanf("%d %d", &to, &weight);
        to--;
        graph[i].push_back(edge(i,to,weight));
        }
    }
    int cases2; cin>>cases2;
    while(cases2--)
    {
        memset(dist,INF,sizeof(dist));
        string n1,n2; cin>>n1>>n2;
        printf("%d\n",dijkstra(M[n1],M[n2]));
    }
    M.clear();
  }
  return 0;
}
