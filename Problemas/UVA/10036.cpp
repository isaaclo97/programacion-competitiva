#include <bits/stdc++.h>
using namespace std;

int arr[10005];
int memo[10005][105];
int K,N;

bool DP(int vali,int mod)
{
    if(vali==N && mod==0) return true;
    else if(vali==N) return false;
    int &best = memo[vali][mod];
    if(memo[vali][mod]!=-1) return best;
    return (best = (DP(vali+1,((mod+arr[vali])%K+K)%K)) || DP(vali+1,((mod-arr[vali])%K+K)%K));
}

int main()
{
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&N,&K);
        for(int i=0; i<N;i++)  scanf("%d",&arr[i]);
        memset(memo,-1,sizeof(memo));
        if(DP(1,(arr[0]+K)%K)) printf("Divisible\n");
        else printf("Not divisible\n");
    }
    return 0;
}
