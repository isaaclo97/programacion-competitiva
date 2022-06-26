#include <cmath>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef int L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const L INF = 0x3f3f3f3f;

map<int,int> M;

struct MinCostMaxFlow {
  int N;
  VVL cap, flow, cost;
  VI found;
  VL dist, pi, width;
  VPII dad;

  MinCostMaxFlow(int N) :
    N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)),
    found(N), dist(N), pi(N), width(N), dad(N) {}

  void AddEdge(int from, int to, L cap, L cost) {
    this->cap[from][to] = cap;
    this->cost[from][to] = cost;
  }

  void Relax(int s, int k, L cap, L cost, int dir) {
    L val = dist[s] + pi[s] - pi[k] + cost;
    if (cap && val < dist[k]) {
      dist[k] = val;
      dad[k] = make_pair(s, dir);
      width[k] = min(cap, width[s]);
    }
  }

  L Dijkstra(int s, int t) {
    fill(found.begin(), found.end(), false);
    fill(dist.begin(), dist.end(), INF);
    fill(width.begin(), width.end(), 0);
    dist[s] = 0;
    width[s] = INF;

    while (s != -1) {
      int best = -1;
      found[s] = true;
      for (int k = 0; k < N; k++) {
        if (found[k]) continue;
        Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
        Relax(s, k, flow[k][s], -cost[k][s], -1);
        if (best == -1 || dist[k] < dist[best]) best = k;
      }
      s = best;
    }

    for (int k = 0; k < N; k++)
      pi[k] = min(pi[k] + dist[k], INF);
    return width[t];
  }

  pair<L, L> GetMaxFlow(int s, int t) {
    L totflow = 0, totcost = 0;
    while (L amt = Dijkstra(s, t)) {
      totflow += amt;
      for (int x = t; x != s; x = dad[x].first) {
        if (dad[x].second == 1) {
          flow[dad[x].first][x] += amt;
          totcost += M[amt * cost[dad[x].first][x]];
        } else {
          flow[x][dad[x].first] -= amt;
          totcost -= M[amt * cost[x][dad[x].first]];
        }
      }
    }
    return make_pair(totflow, totcost);
  }
};

int main(){
    //freopen("C:/Users/Isaac/Documents/QT/Entregar/in.txt","r",stdin);
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        int n; scanf("%d",&n);
        int T = 2+2*n+n*n;
        MinCostMaxFlow mcmf(T);
        for(int i=1; i<=n;i++) mcmf.AddEdge(0,i,1,0);
        int flag=1;
        for(int i=1; i<=n;i++){
            for(int j=1; j<=n;j++)
            {
                int x; scanf("%d",&x); M[1000-x]=x;
                mcmf.AddEdge(i,i*n+j,1,1000-x);
                mcmf.AddEdge(i*n+j,n*n+n+j,1,0);
                if(flag==1)  mcmf.AddEdge(n*n+n+j,T-1,1,0);
            }
            flag=2;
        }
        pair<int, int> res = mcmf.GetMaxFlow(0, T-1);
        //printf("%d\n",res.first);
        printf("%d\n",res.second);
    }
    return 0;
}