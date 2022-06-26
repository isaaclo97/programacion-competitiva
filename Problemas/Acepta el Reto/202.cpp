#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long int memo[1001][1001];
long int dp(int n, int k)
{
    if(k<0 || n<k) return 0;
    if(k==n) return 1;
    if(memo[n][k]!=-1) return memo[n][k];
    return memo[n][k] = (dp(n-1,k)%MOD + dp(n-1,k-1)%MOD)%MOD;
}
int main()
{
    memset(memo,-1,sizeof(memo));
    int n,k;
    while(scanf("%d%d",&n,&k)==2 && (n!=0 || k!=0))
    {
        if(n==0 || n<k) printf("0\n");
        else printf("%ld\n",dp(n,k)%MOD);
    }
    return 0;
}
