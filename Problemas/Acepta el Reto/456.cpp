#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main() {
    int cases; cin>>cases;
    while(cases--)
    {
        double n,m,T; cin>>n>>m>>T;
        double res = T/(n*m);
        if(res==(int(T/(n*m)))) cout<<(int)res<<'\n';
        else cout<<(int)res+1<<'\n';
    }
    return 0;
}
