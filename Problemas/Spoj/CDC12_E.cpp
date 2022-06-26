#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

const int MAXN = 1000000;

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
int H,W,K;

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
      int wht = graph[cur.node][i].weight + cur.dist+1;
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
    int F,E;

    scanf("%d %d %d",&H,&W,&K);
    for(int i=0;i<=H*W;i++) {dist[i]=INF; graph[i].clear();}
    char arr[H][W];
    for(int i=0; i<H;i++)
        for(int j=0; j<W;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='R') { F=i*W+j; arr[i][j]='0'; }
            else if(arr[i][j]=='D') {E=i*W+j; arr[i][j]='0';}
            else if(arr[i][j]=='.') arr[i][j]='0';
        }
    //cout<<F<<E<<endl;
    for(int i=0; i<H;i++)
        for(int j=0; j<W;j++)
            {
             if(i+1!=H)  graph[i*W+j].push_back(edge(i*W+j,(i+1)*W+j,arr[i+1][j]-48)); //cout<<i*W+j<<(i+1)*W+j<<endl; }
             if(j!=0)    graph[i*W+j].push_back(edge(i*W+j,i*W+j-1,arr[i][j-1]-48)); //cout<<i*W+j<<i*W+j-1<<endl;}
             if(i!=0)    graph[i*W+j].push_back(edge(i*W+j,(i-1)*W+j,arr[i-1][j]-48)); //cout<<i*W+j<<(i-1)*W+j<<endl;}
             if(j+1!=W)  graph[i*W+j].push_back(edge(i*W+j,i*W+j+1,arr[i][j+1]-48)); //cout<<i*W+j<<i*W+j+1<<endl;}

            }
        int res = dijkstra(F,E);
        //cout<<res<<endl;
        if(res==-1 || res>=K) printf("Scenario #%d: Ronny will be destroyed\n",c++);
        else printf("Scenario #%d: %d\n",c++,res);
  }
  return 0;
}
