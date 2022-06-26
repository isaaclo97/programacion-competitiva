#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int model[21][21];
bool mark[210][21];
int memo[210][21];
int m1[21];
int g,mn;

int dp(int money, int c)
{
    if(money<0) return -INF;
    if(c==g) return mn-money;
    int &best = memo[money][c];
    if(mark[money][c]) return best;
    mark[money][c]=true;
    int ans = -INF;
    for(int i=0; i<m1[c]; i++)
        ans = max(ans, dp(money-model[c][i],c+1));
    return best = ans;
}
int main()
{
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        memset(mark,false,sizeof(mark));
        scanf("%d%d",&mn,&g);
        for(int i=0; i<g;i++)
        {
            scanf("%d",&m1[i]);
            for(int j=0; j<m1[i]; j++) scanf("%d",&model[i][j]);
        }
        int res = dp(mn,0);
        if(res==-INF) printf("no solution\n");
        else printf("%d\n",res);
    }
    return 0;
}
