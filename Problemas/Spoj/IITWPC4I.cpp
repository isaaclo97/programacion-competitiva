#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

const int MAXN = 100005;
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


int main(){
  int cases,N,E; scanf("%d",&cases);
  while(cases--)
  {
  scanf("%d %d",&N,&E);
  UF uf = UF(N+1);
  vector<edge> edges;
  int arr[N];
  for(int i=0; i<N;i++) cin>>arr[i];
  for(int i=0; i<N;i++) if(arr[i]!=0) edges.push_back(edge(i,N,0));
  for(int i=0;i<E;i++){
  int from,to,w;
  scanf("%d %d %d",&from,&to,&w);
  from--; to--;
  edges.push_back(edge(from,to,w));
  }
  long long int res=0;
  sort(edges.begin(), edges.end());
  for(unsigned int i=0;i<edges.size();i++)
  {
      if(!uf.isConnected(edges[i].from,edges[i].to))
      {
          res+=edges[i].weight;
          uf.connect(edges[i].from, edges[i].to, edges[i].weight);
      }
   }
  int flag=0;
  for(int i=1; i<=N&&flag==0;i++)
      if (!uf.isConnected(0, i)) flag=1;
  if(flag==1) printf("impossible\n");
  else printf("%lld\n",res);
  }
  return 0;
}
