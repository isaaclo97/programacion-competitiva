#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int x, y, v;// x->y, v
    int next;
} edge[50005];
int e, head[1005], dis[1005], previ[1005], record[1005];
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
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        e=0;
        memset(head,-1,sizeof(head));
        int n,m; scanf("%d%d",&n,&m);
        for(int i=0; i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            addEdge(x+1,y+1,1);
        }
        int S,T,k; scanf("%d%d%d",&S,&T,&k);
        addEdge(1,S+1,k+1);
        addEdge(T+1,n+2,k+1);
        int flow = maxflow(1,n+2);
        //cout<<flow<<'\n';
        if(flow>=(k+1)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
