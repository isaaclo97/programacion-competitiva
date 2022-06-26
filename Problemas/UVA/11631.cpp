#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

const int MAXN = 200100;

struct edge{
  int from, to, weight;
  edge(){}
  edge(int a, int b, int c){
    from = a;
    to = b;
    weight = c;
  }
  bool operator<(const edge &other)const{ // sobrecarga de operadores para ordenar
    return weight < other.weight;
  }
};

struct UF{
    int parents[MAXN];
    int sz[MAXN];
    int components;
    int mst_sum;
    UF(int n){
        for(int i=0;i<n;i++){
            parents[i] = i; sz[i] = 1;
        }
        components = n;
        mst_sum = 0;
    }
    int find(int n){
        return n == parents[n] ? n : find(parents[n]);
    }
    bool isConnected(int a, int b){
        return find(a) == find(b);
    }
    void connect(int a, int b, int weight){
        if(isConnected(a, b)) return;
        int A,B; A = find(a); B = find(b);
        if(sz[A] > sz[B]){
            parents[B] = A;
            sz[A] += sz[B];
        }
        else{
            parents[A] = B;
            sz[B] += sz[A];
        }
        mst_sum += weight;
        components--;
    }
};

int N,E;

int main(){
  while(scanf("%d %d",&N,&E)==2 && (N!=0||E!=0))
  {
  vector<edge> edges;
  UF uf = UF(N);
  int total = 0;
    for(int i=0;i<E;i++){
    int from, to, weight; scanf("%d %d %d",&from, &to, &weight);
    total+=weight;
    edges.push_back(edge(from,to,weight));
    }
  sort(edges.begin(), edges.end());
  for(int i=0;i<E;i++) uf.connect(edges[i].from, edges[i].to, edges[i].weight);
  printf("%d\n",total-uf.mst_sum);
  }
  return 0;
}