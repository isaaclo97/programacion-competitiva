#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n,j;
string flowers;
int memo[105][105];

int dp(int pos, int dist)
{
    if(pos==n-1) return dist;
    int &best = memo[pos][dist];
    if(memo[pos][dist]!=-1) return best;
    int val = INF;
    for(int i=1; i<=j && pos+i<n;i++)
        if(flowers[i+pos]=='1') val=min(val,dp(i+pos,dist+1));
    return best=val;
}
int main()
{
    scanf("%d%d",&n,&j);
    memset(memo,-1,sizeof(memo));
    cin.ignore();
    getline(cin,flowers);
    int res = dp(0,0);
    if(res!=INF) printf("%d\n",res);
    else printf("-1\n");
    return 0;
}
