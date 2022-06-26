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
    for(int i=0;i<graph[cur.node].size();i++){
      int dest = graph[cur.node][i].to;
      int wht = graph[cur.node][i].weight + cur.dist;
      if(dist[dest] <= wht) continue;
      dist[dest] = wht;
      pq.push(state(dest, wht));
    }
  }
  return -1;
}

int main()
{
    int ca = 1,aux;
    while(scanf("%d",&aux)==1)
    {
        for(int i=1;i<=20;i++) graph[i].clear(); // limpia el grafo
        int from = 1;
        for(int i=0; i<aux;i++)
        {
            int to; scanf("%d",&to);
            graph[from].push_back(edge(from,to,1));
            graph[to].push_back(edge(to, from, 1));
        }
        for(int i=2; i<20;i++)
        {
            cin>>aux;
            from=i;
            for(int j=0; j<aux;j++)
            {
                int to; scanf("%d",&to);
                graph[from].push_back(edge(from,to,1));
                graph[to].push_back(edge(to, from, 1));
            }
        }
        cin>>aux;
     printf("Test Set #%d\n",ca++);
     for(int i=0; i<aux;i++)
     {
          memset(dist,INF,sizeof(dist));
         int a,b; cin>>a>>b;
         printf("%2d to %2d: %d\n",a,b,dijkstra(a,b));
     }
     cout<<endl;
    }
    return 0;
}

