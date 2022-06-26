#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
 
struct Node {
    int x, y, v;// x->y, v
    int next;
} edge[500005];
int e, head[500005], dis[500005], previ[500005], record[500005];
void addEdge(int x, int y, int v) {
    edge[e].x = x, edge[e].y = y, edge[e].v = v;
    edge[e].next = head[x], head[x] = e++;
    edge[e].x = y, edge[e].y = x, edge[e].v = 0;
    edge[e].next = head[y], head[y] = e++;
}
int maxflow(int s, int t) {
    int flow = 0;
    int i, x, y;
    while(1) {
        memset(dis, 0, sizeof(dis));
        dis[s] =  0xffff; // oo
        queue<int> Q;
        Q.push(s);
        while(!Q.empty()) {
            x = Q.front();
            Q.pop();
            for(i = head[x]; i != -1; i = edge[i].next) {
                y = edge[i].y;
                if(dis[y] == 0 && edge[i].v > 0) {
                    previ[y] = x;
                    record[y] = i;
                    dis[y] = min(dis[x], edge[i].v);
                    Q.push(y);
                }
            }
            if(dis[t])  break;
        }
        if(dis[t] == 0) break;
        flow += dis[t];
        for(x = t; x != s; x = previ[x]) {
            int ri = record[x];
            edge[ri].v -= dis[t];
            edge[ri^1].v += dis[t];
        }
    }
    return flow;
}
 
int main()
{
    //freopen("C:/Users/Isaac/Documents/QT/Entregar/in.txt","r",stdin);
    e=0;
    memset(head,-1,sizeof(head));
    int n; scanf("%d",&n);
    int S=1,T=n+1,c;
    char a,b;
    map<char,int> M; M['S']=1; M['T']=n+1;
    int cnt=2;
    for(int j=0; j<n;j++)
    {
        cin>>a>>b>>c;
        if(M[a]==0) { M[a]=cnt; cnt++; }
        if(M[b]==0) { M[b]=cnt; cnt++; }
        addEdge(M[a],M[b],c);
    }
    int flow = maxflow(S,T);
    printf("%d\n",flow);
    return 0;
}
