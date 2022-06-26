#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int x,y;
int memo[10005];

long int dp(int n)
{
    if(n==0) return x;
    if(n==1) return y;
    if(memo[n]!=-1) return memo[n];
    return memo[n]=(dp(n-1)%MOD + dp(n-2)%MOD)%MOD;
}
int main()
{
    int n;
    while(scanf("%d%d%d",&n,&x,&y)==3)
    {
        for(int i=0; i<=n;i++) memo[i]=-1;
        printf("%ld\n",dp(n));
    }
    return 0;
}
