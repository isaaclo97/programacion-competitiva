// Adjacency matrix implementation of Stoer-Wagner min cut algorithm.
//
// Running time:
//     O(|V|^3)
//
// INPUT:
//     - graph, constructed using AddEdge()
//
// OUTPUT:
//     - (min cut value, nodes in half of min cut)

#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

const int INF = 1000000000;

pair<int, VI> GetMinCut(VVI &weights) {
  int N = weights.size();
  VI used(N), cut, best_cut;
  int best_weight = -1;

  for (int phase = N-1; phase >= 0; phase--) {
    VI w = weights[0];
    VI added = used;
    int prev, last = 0;
    for (int i = 0; i < phase; i++) {
      prev = last;
      last = -1;
      for (int j = 1; j < N; j++)
    if (!added[j] && (last == -1 || w[j] > w[last])) last = j;
      if (i == phase-1) {
    for (int j = 0; j < N; j++) weights[prev][j] += weights[last][j];
    for (int j = 0; j < N; j++) weights[j][prev] = weights[prev][j];
    used[last] = true;
    cut.push_back(last);
    if (best_weight == -1 || w[last] < best_weight) {
      best_cut = cut;
      best_weight = w[last];
    }
      } else {
    for (int j = 0; j < N; j++)
      w[j] += weights[last][j];
    added[last] = true;
      }
    }
  }
  return make_pair(best_weight, best_cut);
}
struct Node {
    int x, y, v;// x->y, v
    int next;
} edge[105];
int e, head[105], dis[105], previ[105], record[105];
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
                    dis[y] = std::min(dis[x], edge[i].v);
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

int main() {
  e=0;
  memset(head, -1, sizeof(head));
  int N,aux=2;
  cin >> N;
  char S,T; cin>>S>>T;
  map<char,int> M; M[S]=1; M[T]=N;
  VVI weights(N, VI(N));
  for (int i = 0; i < N; i++) {
      char a, b; int c;
      cin >> a >> b >> c;
      if(M[a]==0) { M[a]=aux; aux++; }
      if(M[b]==0) { M[b]=aux; aux++; }
      weights[M[a]][M[b]] =  c;
      addEdge(M[a],M[b],c);
    }
    pair<int, VI> res = GetMinCut(weights);
    int flow = maxflow(1, N);
    cout<<flow-res.first<<'\n';
    return 0;
}
