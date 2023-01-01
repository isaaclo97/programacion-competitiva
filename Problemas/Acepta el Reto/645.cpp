#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10100;

struct edge{
    long long int from, to, weight;
    edge(){}
    edge(long long int a,long long int b,long long  int c){
        from = a;
        to = b;
        weight = c;
    }
    bool operator<(const edge &other)const{ // sobrecarga de operadores para ordenar
        return weight < other.weight;
    }
};

struct UF{
    long long int parents[MAXN];
    long long int sz[MAXN];
    long long int components;
    long long int mst_sum;
    UF(long long int n){
        for(long long int i=0;i<n;i++){
            parents[i] = i; sz[i] = 1;
        }
        components = n;
        mst_sum = 0;
    }
    long long int find(long long int n){
        return n == parents[n] ? n : find(parents[n]);
    }
    bool isConnected(long long int a, long long int b){
        return find(a) == find(b);
    }
    void connect(long long int a,long long int b,long long int weight){
        if(isConnected(a, b)) return;
        long long int A,B; A = find(a); B = find(b);
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
    long long  int N,E;
    while(scanf("%lld %lld",&N,&E)==2 && (N!=0||E!=0)) {
        vector<edge> edges;
        UF uf = UF(N);
        for (int i = 0; i < E; i++) {
            long long int from, to, weight;
            scanf("%lld %lld %lld", &from, &to, &weight); from--; to--;
            edges.push_back(edge(from, to, weight));
            edges.push_back(edge(to, from, weight));
        }
        sort(edges.begin(), edges.end());
        for (long long int i = 0; i < edges.size(); i++) uf.connect(edges[i].from, edges[i].to, edges[i].weight);
        if(uf.components!=1) printf("No hay puentes suficientes\n");
        else printf("%lld\n", uf.mst_sum);
    }
    return 0;
}