#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int emp,sal,sev;
int arr[25];
int n;

int memo[5001][25];
bool mark[5001][25];

int DP(int e,int m){
    if(m>=n) return 0;
    if(e>=5001 || e<0) return INF;
    int &best=memo[e][m];
    if(mark[e][m]) return best;
    mark[e][m]=true;
    best=INF;
    best=min(DP(e+1,m)+emp,best);
    if(e>=arr[m])
        best=min(best,DP(e,m+1)+(sal*e));
    best=min(best,DP(e-1,m)+sev);
    return best;
}

int main()
{
    int cnt=1;
    while(scanf("%d",&n)==1 && n!=0)
    {
        memset(mark,false,sizeof(mark));
        cin>>emp>>sal>>sev;
        for(int i=0; i<n;i++) cin>>arr[i];
        printf("Case %d, cost = $%d\n",cnt++,DP(0,0));
    }
    return 0;
}
