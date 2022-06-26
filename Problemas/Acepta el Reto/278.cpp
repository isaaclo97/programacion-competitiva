#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
int cases; cin>>cases;
    while(cases--)
    {
        int h,m,s,D,H,M,S,total=0;
        scanf("%d:%d:%d:%d",&D,&H,&M,&S);
        total = D*24*3600+H*3600+M*60+S;
        while(scanf("%d:%d:%d",&h,&m,&s) && (h!=0||m!=0||s!=0))
        {total-=h*3600; total-=m*60;total-=s;}
        if(total>0) cout<<"SI\n";
        else cout<<"NO\n";
    }
    return 0;
}
