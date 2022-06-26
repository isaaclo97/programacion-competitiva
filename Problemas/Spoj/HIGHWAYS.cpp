#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
 
const int MAXN = 100005;
 
struct edge{
  int from, to, weight;
  edge(){}
  edge(int a, int b, int c){
    from = a;
    to = b;
    weight = c;
  }
};
 
vector<edge> graph[MAXN];
int dis[MAXN];
int N,E;
 
int dijkstra(int s, int d){
    queue<int> q;
    memset(dis,INF,sizeof(dis));
    dis[s] = 0;
    q.push(s);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(unsigned int i=0;i<graph[node].size();i++){
            int nextNode = (graph[node][i]).to;
            if(dis[nextNode] > dis[node] + graph[node][i].weight){
                q.push(nextNode);
                dis[nextNode] = dis[node] + graph[node][i].weight;
            }
        }
    }
    return dis[d];
}
 
int main(){
  int cases; cin>>cases;
  while(cases--)
  {
    int F, En;
    scanf("%d %d %d %d",&N,&E, &F,&En);
    for(int i=1;i<=N;i++) { graph[i].clear();  } 
    for(int i=0;i<E;i++){
    int from, to, weight; scanf("%d %d %d",&from, &to, &weight);
    graph[from].push_back(edge(from,to,weight));
    graph[to].push_back(edge(to,from,weight));
    }
    int res = dijkstra(F,En);
    if (res==INF) printf("NONE\n");
    else printf("%d\n",res);
  }
  return 0;
} 
