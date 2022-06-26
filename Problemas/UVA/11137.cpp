#include <bits/stdc++.h>
using namespace std;

long long int memo[10005][25];
int coin[25];

long long int DP(int sum, int i)
{
    if(sum==0) return 1;
    if(i==24 || sum<0 || sum-coin[i]<0) return 0;
    long long int &best = memo[sum][i];
    if(best!=-1) return best;
    return best = DP(sum-coin[i],i) + DP(sum,i+1);
}

int main()
{
    for(int i=1; i<=23;i++) coin[i]=i*i*i;
    int N;         memset(memo,-1,sizeof(memo));
    while(scanf("%d",&N)==1)
        printf("%lld\n",DP(N,1));
    return 0;
}
