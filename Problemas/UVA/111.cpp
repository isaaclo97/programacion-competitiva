#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int N,K,num;
    scanf("%d",&N);
    int arr[N];
    int arraux[N];
    int dp[22][22];
    for(int i=0; i<N;i++) { scanf("%d",&num); arraux[num-1]=i; }
    while(scanf("%d",&K)==1)
    {
        memset(dp,0,sizeof(dp));
        arr[K-1]=0;
        for(int i=1; i<N;i++) { scanf("%d",&num); arr[num-1]=i; }
        //LIS
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N;j++)
            {
                if(arraux[i-1]==arr[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        /*
            2 3 4 1
          1 0 0 0 1
          2 1 1 1 1
          3 1 2 2 2
          4 1 2 3 3
        */
        printf("%d\n",dp[N][N]);
    }
    return 0;
}
