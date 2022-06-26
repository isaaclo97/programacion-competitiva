#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll oo = 0x3f3f3f3f3f3f3f3fLL;



#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define FORD(i, a, b) for(int i = (b)-1; i >= int(a); i--)
#define has(c, e) ((c).find(e) != (c).end())
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()


struct Edge{
    int u, v;
};


void ArticulationPointandBridges(vector<vi>& adj, vector<Edge> E, vi& articulation, vi& bridges) {
    int n = sz(adj), m = sz(E);
    articulation = vi(n, -1);
    bridges = vi(m, -1);
    vi dfs_low(n, -1), dfs_num(n ,-1), parent(n, -1);
    articulation = vi(n, 0);
    bridges = vi(m, 0);
    int dfsroot, rootc, cnt = 0;
    function<void(int)> ABdfs = [&](int u) {
        dfs_num[u] = dfs_low[u] = cnt++;
        for(int t : adj[u]){
            int v = E[t].u^E[t].v^u;
            if(dfs_num[v] == -1){
                if(u == dfsroot) rootc++;
                parent[v] = t;
                ABdfs(v);
                dfs_low[u] = min(dfs_low[u], dfs_low[v]);
                if(dfs_low[v] >= dfs_num[u])articulation[u] = 1;
                if(dfs_low[v] > dfs_num[u]) bridges[t] = 1;
            } else if (t != parent[u]){
                dfs_low[u] = min(dfs_low[u], dfs_num[v]);
            }
        }
    };
    FOR(i, 0, n) {
        if(dfs_num[i] == -1) {
            rootc = 0, dfsroot = i;
            ABdfs(i);
            if (rootc <= 1) articulation[i] = 0;
        }
    }
}


int main() {
    int x, y,n;
    char c;
    while(scanf("%d", &n) == 1 && n!=0)
    {

        vector<Edge> E;
        vector<vector<int>> adj(n+1);
        vi articulation;
        vi bridge;
        while(scanf("%d", &x) == 1 && x) {
            while(scanf("%d%c", &y, &c) == 2) {
                E.push_back({x,y});
                E.push_back({y,x});
                adj[x].push_back(E.size()-2);
                adj[y].push_back(E.size()-1);
                if(c == '\n')	break;
            }
        }
        ArticulationPointandBridges(adj,E,articulation,bridge);
        int arts = 0;
        for(auto val : articulation){
            if(val==1)arts++;
        }
        printf("%d\n", arts);
    }
    return 0;
}
