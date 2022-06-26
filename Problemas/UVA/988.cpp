#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,aux,val,flag=0;
    while(scanf("%d",&n)==1)
    {
        if(flag==1) { printf("\n"); cin.ignore();}
        vector<int> V[n];
        for(int i=0; i<n;i++)
        {
            scanf("%d",&aux);
            for(int j=0; j<aux;j++)
            {
              scanf("%d",&val);
              V[i].push_back(val);
            }
        }
        int dp[1000];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (V[i].empty()) res += dp[i];
            for (int v : V[i]) dp[v] += dp[i];
        }
        printf("%d\n",res);
        flag=1;
    }
    return 0;
}
