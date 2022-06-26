#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

long long int binomialCoeff(long long int n, long long int k)
{
    long long int C[k+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (long long int i = 1; i <= n; i++)
        for (long long int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j-1];
    return C[k];
}

int main()
{
    long long int n,k;
    while(scanf("%lld%lld",&n,&k)==2 && (n!=0 || k!=0)) printf("%lld things taken %lld at a time is %lld exactly.\n",n,k,binomialCoeff(n, k));
    return 0;
}
