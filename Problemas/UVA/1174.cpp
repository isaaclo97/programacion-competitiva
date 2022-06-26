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
  int node, dist,res;
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
  int cases; cin>>cases;
  string line;
  while(cases--)
  {
    getline(cin,line);
    cin.ignore();
    scanf("%d %d",&N,&E);
    memset(visited,0,sizeof(visited));
    map<string,int> M;
    int c=1;
    for(int i=1;i<=N;i++) {dist[i]=INF; graph[i].clear();}
    for(int i=0; i<E;i++)
    {
        string to,from; int weight; cin>>to>>from>>weight;
        if(M[to]==0) { M[to]=c; c++;}
        if(M[from]==0) { M[from]=c; c++;}
        graph[M[from]].push_back(edge(M[from],M[to],weight));
        graph[M[to]].push_back(edge(M[to], M[from], weight));
    }
    printf("%d\n",prim(1));
    if(cases!=0) cout<<'\n';
  }
  return 0;
}
