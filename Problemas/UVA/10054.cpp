#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define trav(i, v) for(auto &i : v)
#define has(c, e) ((c).find(e) != (c).end())
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()
#define debug(x) cerr << #x << ": " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct edge{
int u, v;
bool used;
};
void Eulerdfs(int u, vi &nxt, vi &Euler, vector<edge> &E, const vector<vi> &adj) {
while(nxt[u] < adj[u].size()){
int go = adj[u][nxt[u]++];
if(!E[go].used){
E[go].used = 1;
int to = (E[go].u ^ E[go].v ^ u);
Eulerdfs(to, nxt, Euler, E, adj);
}
}
Euler.push_back(u);
}
vi Eulerian(int u, vector<edge> &E, const vector<vi> &adj) {
    vi nxt (adj.size(), 0); vi Euler;
    Eulerdfs(u, nxt, Euler, E, adj);
    reverse(Euler.begin(), Euler.end());
    return Euler;
}


int main()
{
    int cases,ca=1;
    scanf("%d",&cases);
    while(cases--)
    {
        int n; scanf("%d",&n);
        vector<edge> E;
        vector<vector<int>> adj(51);
        vector<int> degree(51);
        for(int i=0; i<n;i++)
        {
            int x,y; scanf("%d%d",&x,&y);
            E.push_back({x,y,false});
            adj[x].push_back(E.size()-1);
            adj[y].push_back(E.size()-1);
            degree[x - 1]++;
            degree[y - 1]++;
        }
        printf("Case #%d\n",ca++);
        bool good = true;
        int start = -1;
        for (int i = 0; i < 50; i++) {
            if (degree[i] % 2) {
                good = false;
                break;
            }
            else if (degree[i] && start == -1)
                start = i;
        }
        if(!good) printf("some beads may be lost\n");
        else{
        vector<int> res = Eulerian(start+1,E,adj);
        for(int i=0; i<sz(res)-1;i++) printf("%d %d\n",res[i],res[(i+1)%sz(res)]);
        }
        printf("\n");
    }
    return 0;
}
