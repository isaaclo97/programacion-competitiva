#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long int memo[10005];
int num;

long long int DP(int n)
{
    if(n==-1) return 1;
    if(n<-1) return 0;
    long long int &best = memo[n];
    if(best!=-1) return best;
    long long int res = 0;
    for(int i=1; i<=10 && n-i>=0;i++)
       res= (res%MOD + DP(n-i-1)%MOD)%MOD;
    return best = res;
}
int main()
{
    memset(memo,-1,sizeof(memo));
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&num);
        printf("%lld\n",DP(num)%MOD);
    }
    return 0;
}
