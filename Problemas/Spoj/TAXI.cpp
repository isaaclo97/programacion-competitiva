#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (unsigned int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);

  int ct = 0;
  for (unsigned int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}
int main() {
    freopen("C:/Users/Isaac/Documents/QT/Entregar/in.txt","r",stdin);
    int a,b,cases; scanf("%d",&cases);
    while(cases--)
    {
        int s,c,N,M; scanf("%d%d%d%d",&N,&M,&s,&c);
        VVI adj(M, VI(N));
        //for (int i = 0; i <= M; i++) adj[i].clear();
        vector<pair<int,int>> P;
        for (int i = 0; i < N; i++) {
            scanf("%d%d",&a,&b);
            P.push_back({a,b});
        }
        for (int i = 0; i < M; i++) {
            scanf("%d%d",&a,&b);
            for(int j=0; j<N;j++)
            {
                pair<int,int> person = P[j];
                if(((abs(person.first-a)+abs(person.second-b))<=s*c/200)) adj[i][j]=1;
            }
        }
        vector<int> V; vector<int> V_;
        printf("%d\n",BipartiteMatching(adj, V,V_));
        //printf("%d\n", hopcroft_karp());
        //for (int i = 0; i <= M; i++) adj[i].clear();
    }
    return 0;
}
