#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

bool solve(long long int n, int s)
{
    if(s==1) return true;
    return solve(n/10,s-1) && (n%s==0);
}
int main()
{
    long long int n;
    while(scanf("%lld",&n)==1 && n!=0)
    {
        if(solve(n,to_string(n).length())) printf("POLIDIVISIBLE\n");
        else printf("NO POLIDIVISIBLE\n");
    }
    return 0;
}
