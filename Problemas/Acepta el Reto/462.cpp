#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases; cin>>cases;
    while(cases--)
    {
        long long int n,H,M,S,D;
        scanf("%lld %lld:%lld:%lld",&n,&H,&M,&S);
        long long int total = H*3600+M*60+S;
        total*=n;
        D=total/(3600*24);
        total-=(D*3600*24);
        H=total/3600;
        total-=(H*3600);
        M=total/60;
        total-=(M*60);
        S=total;
        printf("%lld %02lld:%02lld:%02lld\n",D,H,M,S);
    }
    return 0;
}
