#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

const int MAXN = 105;

struct edge{
int from, to, weight; edge(){}
edge(int a, int b, int c){
from = a; to = b; weight = c; }};
struct state{
int node, dist; state(){}
state(int a, int b){node = a; dist = b; }
bool operator<(const state &other)const{
return other.dist < dist; } };
vector<edge> graph[MAXN];
int dist[MAXN]; int a=1, b=3; int N,E;
int dijkstra(int start, int end){ dist[start] = 0;
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
} } return -1; }

int main()
{
    int a,b,ca=1;
    while(scanf("%d%d",&a,&b)==2 && (a!=0 || b!=0))
    {
        int aux = 1;
        map<int,int> M;
        if(M[a]==0) { M[a]=aux; aux++;}
        if(M[b]==0) { M[b]=aux; aux++;}
        graph[M[a]].push_back(edge(M[a],M[b],1));
        //cout<<M[a]<<" -> "<<M[b]<<endl;
        while(scanf("%d%d",&a,&b)==2 && (a!=0 || b!=0))
        {
            if(M[a]==0) { M[a]=aux; aux++;}
            if(M[b]==0) { M[b]=aux; aux++;}
            graph[M[a]].push_back(edge(M[a],M[b],1));
            //cout<<M[a]<<" -> "<<M[b]<<endl;
        }

        double total=0,div=(aux-1)*(aux-2);
        for(int i=1; i<aux;i++)
        {
            memset(dist,INF,sizeof(dist));
            dijkstra(i,aux);
            for(int j=1; j<aux;j++)  if(i!=j) total+=dist[j]; //cout<<i<<" ->"<<j<<" = "<<dist[j]<<endl;}
        }
        printf("Case %d: average length between pages = %.3f clicks\n",ca++,(double)total/div);
        for(int i=1;i<=aux;i++) graph[i].clear();
    }
    return 0;
}
