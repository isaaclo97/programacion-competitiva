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
    e=0;
    memset(head,-1,sizeof(head));
    int n,m; scanf("%d%d",&n,&m);
    int flag=1,S=1,T=500000;
    for(int j=0; j<n;j++)
    {
        int x;
        scanf("%d",&x);
        addEdge(S,x+m+1,x);
        for(int i=1; i<=m;i++)
        {
            if(x%i==0) addEdge(x+m+1,i+1,1);
            if(flag==1) addEdge(i+1,T,1);
        }
        flag=2;
    }
    int flow = maxflow(S,T);
    printf("%d\n",flow);
    return 0;
}
