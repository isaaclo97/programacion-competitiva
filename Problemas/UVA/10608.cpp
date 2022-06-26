#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
const int MAXN = 100100;

struct UF{
    int parents[MAXN];
    int sz[MAXN];
    int components;
    int mst_sum;
    UF(int n){
        for(int i=0;i<n;i++){
            parents[i] = i; sz[i] = 1;
        }
    }
    int find(int n){
        return n == parents[n] ? n : find(parents[n]);
    }
    bool isConnected(int a, int b){
        return find(a) == find(b);
    }
    int connect(int a, int b){
        int A,B; A = find(a); B = find(b);
        if(A!=B)
        {
            if(sz[A] > sz[B]){
                parents[B] = A;
                sz[A] += sz[B];
                return sz[A];
            }
            else{
                parents[A] = B;
                sz[B] += sz[A];
                return sz[B];
            }
        }
        return sz[A];
    }
};

int a=1;
int N=100000,E;

int main(){
    int cases;
    cin>>cases;
    while(cases--)
    {
        map<string,int> M;
        int contador=1;
        string a,b;
        cin>>E;
        UF uf = UF(N);
        for(int i=0;i<E;i++)
        {
            cin>>a>>b;
            if(M[a]==0) {M[a]=contador; contador++;}
            if(M[b]==0) {M[b]=contador; contador++;}
            cout<<uf.connect(M[a],M[b])<<endl;
        }
    }
    return 0;
}
