#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    long long int g,m,n;
    while(scanf("%lld%lld%lld",&g,&m,&n)==3 && (g!=0 || m!=0 || n!=0))
    {
        long long int res=0;
        for(int i=0;i<n;i++) { res+=g; g*=m;}
        printf("%lld\n",res);
    }
    return 0;
}
