
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2500 + 7;
const int inf = 0x3f3f3f3f;

struct Edge{
    int from, to, cap, flow;
};

struct Dinic{
    int n, m, s, t;
    vector<Edge>edges;
    vector<int>G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];

    void init(int nn){
        edges.clear();
        for (int i = 0; i < nn; ++i)G[i].clear();
    }

    void addEdge(int from,int to,int cap){
        edges.push_back((Edge){from,to,cap,0});
        edges.push_back((Edge){to,from,0,0});
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BFS(){
        memset(vis,0,sizeof vis);
        queue<int>Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while(!Q.empty()){
            int x = Q.front(); Q.pop();
            for (unsigned int i = 0; i < G[x].size(); ++i){
                Edge& e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x,int a){
        if (x == t || a == 0) return a;
        int flow = 0, f;
        for (int& i = cur[x]; i < G[x].size(); ++i){
            Edge& e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to,min(a,e.cap-e.flow))) > 0){
                e.flow += f;
                edges[G[x][i]^1 ].flow -= f;
                flow += f;
                a -= f;
                if (!a)break;
            }

        }
        return flow;
    }

    int maxflow(int s,int t){
        this->s = s; this->t = t;
        int flow = 0;
        while(BFS()){
            memset(cur,0,sizeof cur);
            flow += DFS(s,inf);
        }
        return flow;
    }

}dic;

int N,M;

int main(){
    //freopen("C:\\Users\\isaac\\CLionProjects\\URJC_Entenamientos\\caperucita.out","r",stdin);
    //freopen("C:\\Users\\isaac\\CLionProjects\\URJC_Entenamientos\\caperucita.res","w",stdout);
    int cases; scanf("%d",&cases);
    while(cases--){
        scanf("%d %d",&N,&M);
        int lobo,caperucita;
        map<int,int> grafo[N*M];
        for(int i=0; i<N;i++) {
            cin.ignore();
            for (int j = 0; j < M; j++) {
                char val;
                scanf("%c", &val);
                if (val != '#') {
                    int dig = i*M+j;
                    if (i*M<=(dig + 1) && (dig + 1)<(i+1)*M) grafo[dig][dig + 1] = 1000;
                    if (i*M<=(dig - 1) && (dig - 1)<(i+1)*M) grafo[dig][dig - 1] = 1000;
                    if (0<=(dig + M) && (dig + M)<N*M) grafo[dig][dig + M] = 1000;
                    if (0<=(dig - M) && (dig - M)<N*M) grafo[dig][dig - M] = 1000;
                }
                if (val == 'C') caperucita=i*M+j;
                if (val == 'L') lobo=i*M+j;
            }
        }
        int totalNum = N*M;
        dic.init(totalNum*2);
        for(int i=0;i<totalNum;i++){
            if(grafo[caperucita][i]!=0 || i==caperucita || i==lobo) dic.addEdge(i,i+totalNum,1000);
            else dic.addEdge(i,i+totalNum,1);
            for(auto k : grafo[i]) dic.addEdge(i+totalNum,k.first,k.second);
        }
        int flow  = dic.maxflow(caperucita,lobo);
        if(flow>4) printf("IMPOSIBLE\n");
        else printf("%d\n",flow);
    }
    return 0;
}
