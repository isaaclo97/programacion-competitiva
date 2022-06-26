#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        long long  x,r;
        for (r = sqrt(2*n); r >= 1; r--) {
            x = (2*n - r*(r-1)) / (2*r);
            if (2*n == r * (2*x + r - 1)) break;
        }
        printf("%lld\n",r);
    }
    return 0;
}
