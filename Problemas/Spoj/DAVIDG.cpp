#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

const int MAXN = 1005;

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

bool visited[MAXN];
int arr1[MAXN];
int arr2[MAXN];
int dist[MAXN];
int cases,N,E,c;

int prim(int start){
  priority_queue<state> pq;
  pq.push(state(start, 0));
  int sum = 0;
  dist[start]=0;
  while(!pq.empty()){
    state cur = pq.top(); pq.pop();
    if(visited[cur.node] || cur.dist > dist[cur.node]) continue;
    sum += cur.dist;
    visited[cur.node] = true;
    for(int i=0;i<N;i++){
        if(visited[i] || i==cur.node) continue;
        int dista = ceil(sqrt(pow(arr1[i]-arr1[cur.node],2)+pow((arr2[i]-arr2[cur.node]),2))*E);
        if(dist[i] > dista)
        {
        dist[i]=dista;
        pq.push(state(i,dista));
        }
    }
  }
  return sum;
}

int main(){
  scanf("%d",&cases); c=1;
  while(cases--)
  {
  scanf("%d %d",&N,&E);
  for(int i=0;i<N;i++){
  dist[i]=INF;
  visited[i]=false;
  scanf("%d %d",&arr1[i],&arr2[i]);
  }
  int res = prim(0);
  printf("Scenario #%d: %d\n",c++,(res%100000007));
  }
  return 0;
}
