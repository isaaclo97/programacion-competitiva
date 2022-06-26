
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
int paths[MAXN];

int N,E;

//https://www.geeksforgeeks.org/number-of-shortest-paths-in-an-undirected-weighted-graph/

int dijkstra(int start, int end){
    dist[start] = 0;
    paths[start] = 1;
    priority_queue<state> pq;
    map<pair<int,int>,bool> settled;
    pq.push(state(start, 0));
    while(!pq.empty()){
        state cur = pq.top(); pq.pop();
        for(int i=0;i<graph[cur.node].size();i++){
            int dest = graph[cur.node][i].to;
            if(settled[make_pair(dest,cur.node)]) continue;
            int cost = dist[cur.node] + graph[cur.node][i].weight;
            if(dist[dest] > cost) {
                dist[dest] = cost;
                pq.push(state(dest, graph[cur.node][i].weight + cur.dist));
                paths[dest] = paths[cur.node];
            }
            else if (dist[dest] == cost) {
                paths[dest] += paths[cur.node];
            }
            settled[make_pair(dest,cur.node)]=true;
        }
    }
    return paths[end];
}

int main(){
    while(scanf("%d %d",&N,&E)==2) { ;
        for (int i = 0; i <= N; i++) { dist[i]=INF; paths[i]=0; graph[i].clear(); } // limpia el grafo
        for (int i = 0; i < E; i++) {
            int from, to, weight;
            scanf("%d %d %d", &from, &to, &weight);
            graph[from].push_back(edge(from, to, weight));
            graph[to].push_back(edge(to, from, weight)); // borrar linea si es dirigido
        }
        printf("%d\n",dijkstra(1, N));
    }
    return 0;
}
