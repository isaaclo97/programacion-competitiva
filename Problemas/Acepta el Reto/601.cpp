
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10100;
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

int N,E,S,T,P;

int dijkstra(int start, int end){
  dist[start] = 0;
  priority_queue<state> pq;
  pq.push(state(start, 0));
  while(!pq.empty()){
    state cur = pq.top(); pq.pop();
    if(dist[cur.node] < cur.dist) continue;
    //if(cur.node == end) return cur.dist;
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
  while(scanf("%d %d %d %d",&N,&S,&T,&P)==4){
      for(int i=0;i<=N;i++) { graph[i].clear(); dist[i]=INF; }// limpia el grafo
      for(int i=0;i<P;i++){
        int from, to, weight; scanf("%d %d %d",&from, &to, &weight);
        graph[to].push_back(edge(to,from,weight));
      }
      dijkstra(S,-1);
      int res = 0;
      for(int i=1;i<=N;i++) if(dist[i]<=T && i!=S) res++;
      printf("%d\n",res);
  }
  return 0;
}

/*
5 5 0 4
1 4 47
4 2 13
3 2 15
5 3 4
8 7 1600 12
1 2 745
1 7 998
2 8 177
1 3 129
1 4 157
5 8 124
1 5 487
1 6 999
3 8 478
4 8 145
6 8 854
7 8 768
4 1 50 4
4 2 65
1 2 25
3 4 74
1 3 58
10 2 1500 13
1 7 158
2 7 999
3 10 998
4 5 997
5 9 996
5 3 995
1 8 994
9 10 993
5 2 992
1 6 999
2 6 999
2 8 999
4 10 998
5 3 800 10
4 3 895
3 5 485
4 5 217
5 1 785
3 2 147
5 2 856
4 2 175
1 2 578
1 3 745
4 1 145
6 2 600 8
1 2 1
2 3 1
3 6 1
1 4 100
4 5 100
5 6 100
1 3 10
2 6 10


0
1
0
1
1
1

*/
