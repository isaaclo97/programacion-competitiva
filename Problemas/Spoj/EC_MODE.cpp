#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

const int MAXN = 1005;
int cases,N,E,r,w,u,v;

struct edge{
  int from, to ,aux;
  double weight;
  edge(){}
  edge(int a, int b, double c, int d){
    from = a;
    to = b;
    weight = c;
    aux=d;
  }
  bool operator<(const edge &other)const{ // sobrecarga de operadores para ordenar
    return weight < other.weight;
  }
};
vector<edge> graph;
vector<pair<int,int>> edges;
struct UF{
    int parents[MAXN];
    int sz[MAXN];
    int components;
    double res2;
    double res1;
    UF(int n){
        for(int i=0;i<n;i++){
            parents[i] = i; sz[i] = 1;
        }
        components = n;
        res2=res1=0;
    }
    int find(int n){
        return n == parents[n] ? n : find(parents[n]);
    }
    bool isConnected(int a, int b){
        return find(a) == find(b);
    }
    void connect(int a, int b, double weight, double aux){
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
        if(aux==1) res1+=weight;
        else res2 += weight;
        components--;
    }
};

int main(){
  int c=1;
  scanf("%d",&cases);
  while(cases--)
  {
  graph.clear();
  edges.clear();
  scanf("%d %d %d %d %d",&N,&r,&w,&u,&v);
  UF uf = UF(N);
  for(int i=0;i<N;i++){
  int x,y;
  scanf("%d%d",&x,&y);
  edges.push_back(make_pair(x,y));
  }
  for(int i=0;i<N;i++)
      {
          for(int j=i+1;j<N;j++)
             {
                      double d = sqrt(pow((edges[i].first - edges[j].first),2)+pow((edges[i].second -  edges[j].second),2));
                      int daux;
                      if(d>r) { d*=v; daux=1;}
                      else { d*=u; daux=0;}
                      graph.push_back(edge(i,j,d,daux));
            }
      }
  sort(graph.begin(), graph.end());
  for(unsigned int i=0; i<graph.size();i++)
      if(uf.components==w || uf.components==1) break;
      else  uf.connect(graph[i].from, graph[i].to, graph[i].weight , graph[i].aux);
  printf("Caso #%d: %.3f %.3f\n",c++,uf.res2,uf.res1);
  }
  return 0;
}
