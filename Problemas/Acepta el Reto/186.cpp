#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int t,g;
    while(scanf("%d%d",&t,&g)==2 && (t!=0 || g!=0))
    {
        map<int,int> M;
        string n; int a;
        for(int i=1; i<=t;i++) {M[i]++;}
        for(int i=0; i<g;i++) {cin>>a>>n; M[a]++;}
        int flag=0,res = -1,sol=0;
        for(auto m:M) { if(sol==m.second) flag=1; if(sol<m.second) { sol=m.second; res=m.first; flag=0; } }
        if(flag==1) cout<<"EMPATE\n";
        else cout<<res<<'\n';
    }
    return 0;
}
