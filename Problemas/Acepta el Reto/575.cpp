
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
vector<int> adj[MAXN+1], adjRev[MAXN+1], order, component;
vector<bool> used;
void DFS(int u){
    used[u] = true;
    for (auto &v : adj[u])
        if (!used[v]) DFS(v);
    order.push_back(u);
}
void DFS2(int u){
    used[u] = true;
    component.push_back(u);
    for (auto &v : adjRev[u])
        if (!used[v]) DFS2(v);
}


int main() {
    int n;
    while(scanf("%d", &n)==1){
        n++;
        int nodes,u,v;
        while(scanf("%d",&nodes)==1 && nodes!=0){
            u = nodes;
            int c; scanf("%d",&c);
            for (int i = 0; i < c; i ++) {
                scanf("%d", &v);
                adj[u].push_back(v);
                adjRev[v].push_back(u);
            }
        }
        used.assign(n, false);
        for (int i = 0; i < n; ++i)
            if (!used[i]) DFS(i);
        used.assign(n, false);
        reverse(order.begin(), order.end());
        int res = 0;
        for (auto &v : order){
            if (used[v]) continue;
            DFS2(v);
            res = max(res,(int)component.size());
            component.clear();
        }
        printf("%d\n",res);
        for(int i=0; i<=n;i++) {
            adj[i].clear();
            adjRev[i].clear();
        }
        order.clear();
        component.clear();
        used.clear();
    }

    return 0;
}
