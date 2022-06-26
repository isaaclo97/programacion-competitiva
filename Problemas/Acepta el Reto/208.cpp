#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    long long int n,m;
    while(scanf("%lld%lld",&n,&m)==2 && (n!=0 || m!=0))
    {
        long long int t = (n*(n+1))/2;
        long long int r = (n-m)+1;
        long long int r1 = (r*(r+1))/2;
        cout<<t-r1<<'\n';
    }
    return 0;
}
