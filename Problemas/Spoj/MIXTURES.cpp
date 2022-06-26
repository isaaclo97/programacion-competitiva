#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
 
long long int dp[105][105];
long long int arr[105];
 
long long int sum(int j,int e)
{
    long long res=0;
    for(int i=j; i<=e;i++)
    {
        res+=arr[i];
        res%=100;
    }
    return res;
}
long long int solve(int i, int j)
{
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=INF;
    for(int k=i; k<=j;k++)
    {
        long long int temp = solve(i,k)+solve(k+1,j);
        temp+=sum(i,k)*sum(k+1,j); //arr[i-1]*arr[k]*arr[j];
        dp[i][j]=min(dp[i][j],temp);
        //dp[i][j] =min(dp[i][j],solve(i,k)+solve(k+1,j)+sum(i,k)*sum(k+1,j));
    }
    return dp[i][j];
}
 
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<n;i++) cin>>arr[i];
    cout<<solve(0,n-1)<<'\n';
    }
    return 0;
} 
