#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    long long int cases,di,se,dt;
    scanf("%lld",&cases);
    while (cases--)
    {
        scanf("%lld%lld%lld",&dt,&se,&di);
        if (di == 1) printf("%lld\n",dt/se);
        else printf("%lld\n",(dt-(se-(di-1)))/se);
    }
    return 0;
}
