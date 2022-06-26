#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

const int MAXN = 505;

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
vector<int> V[MAXN];
int N=505,E;

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
    freopen("C:/Users/Isaac/Desktop/in.txt","r",stdin);
    freopen("C:/Users/Isaac/Desktop/out.txt","w",stdout);
  while(scanf("%d",&E)==1)
  {
    for(int i=0;i<=N;i++) {V[i].clear(); graph[i].clear();}
    for(int j=0;j<E;j++){
        int to,from, weight; scanf("%d %d %d", &from,&to, &weight);
        graph[from].push_back(edge(from,to,weight));
        graph[to].push_back(edge(to,from,weight));
    }
    int F; cin>>F;
    int T; cin>>T;
    for(int i=0; i<T;i++)
    {
        for(int i=0;i<=501;i++) dist[i]=INF;
        int arrival; scanf("%d",&arrival);
        if(V[arrival].size()!=0)
        {
            if(V[arrival][0]==-1) printf("NO PATH\n");
            else printf("%d\n",V[arrival][0]);
        }
        else
        {
        int res = dijkstra(F,arrival);
        if(res==-1) printf("NO PATH\n");
        else printf("%d\n",res);
        V[arrival].push_back(res);
        }
    }
  }
  return 0;
}
