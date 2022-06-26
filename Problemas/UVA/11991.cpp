#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main() {

    int n,m;
    while (scanf("%d%d", &n,&m)==2) {
        int a,b,aux;
        map<pair<int,int>,int> M;
        map<int,int> Ma;
        for(int i=0; i<n;i++)
        {
            cin>>aux; Ma[aux]++; M[make_pair(aux,Ma[aux])]=i+1;
        }
        for(int i=0; i<m;i++)
        {
            cin>>a>>b; cout<<M[make_pair(b,a)]<<'\n';
        }
    }
    return 0;
}

