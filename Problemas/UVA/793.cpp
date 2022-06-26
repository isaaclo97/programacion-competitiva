#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;


const int MAXN = 100100;

struct edge{
  int from, to, weight;
  edge(){}
  edge(int a, int b){
    from = a;
    to = b;
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
    void connect(int a, int b){
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
        components--;
    }
};

int a=1;
int N;

int main(){
    int cases; cin>>cases; cin.ignore();
    string s;
    while(cases--)
    {
        int cont1,cont2,N,x,y;
        char c;
        scanf("\n%d\n",&N);
        UF uf = UF(N+1);
        cont1=cont2=0;

        while(1){
               if(!getline(cin,s) || s.empty()) break;
               sscanf(s.c_str(),"%c %d %d",&c,&x,&y);
               if(c=='c')
               {
                   uf.connect(x, y);
               }
               else
               {
                    if(uf.isConnected(x,y)) cont1++;
                    else cont2++;
                }
                }
                printf("%d,%d\n",cont1,cont2);
                if(cases!=0) printf("\n");
    }
  return 0;
}
