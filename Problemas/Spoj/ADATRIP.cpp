#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
 
const int MAXN = 500005;
 
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
vector<pair<int,int>> V[MAXN];
int N,E,T;
 
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
  while(scanf("%d %d %d",&N,&E,&T)==3)
  {
    for(int i=0;i<=N;i++) {V[i].clear(); graph[i].clear();}
    for(int j=0;j<E;j++){
        int to,from, weight; scanf("%d %d %d", &from,&to, &weight);
        graph[from].push_back(edge(from,to,weight));
        graph[to].push_back(edge(to,from,weight));
    }
    for(int i=0; i<T;i++)
    {
        for(int i=0;i<=N;i++) dist[i]=INF;
        int arrival; scanf("%d",&arrival);
        if(V[arrival].size()!=0)
        {
            printf("%d %d\n",V[arrival][0].first,V[arrival][0].second);
        }
        else
        {
        dijkstra(arrival,N);
        map<int,int> M;
        for(int i=0; i<N;i++)
            if(dist[i]!=INF)
              M[dist[i]]++;
        int aux=-INF,aux2;
        for(auto m: M)
            if(m.first>aux){ aux=m.first; aux2=m.second;}
        printf("%d %d\n",aux,aux2);
        V[arrival].push_back(make_pair(aux,aux2));
        }
    }
  }
  return 0;
} 
