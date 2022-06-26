#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        int x,y,x1,y1; cin>>x>>y>>x1>>y1;
        int res = abs(x-x1) + abs(y-y1);
        int res1 = abs(x-x1);
        if(x<n && x1<n && y<n && y1<n && res%2==0) { if(x!=x1 && y!=y1 && (res1+y==y1 || y-res1==y1)) cout<<1<<'\n'; else if(x==x1 && y1==y) cout<<"0\n"; else cout<<2<<'\n';}
        else cout<<"IMPOSIBLE\n";
    }
    return 0;
}
