#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

string str1,str2;

int editDist(int m ,int n)
{
    int dp[m+1][n+1];
        for (int i=0; i<=m; i++)
            for (int j=0; j<=n; j++)
            {

                if (i==0) dp[i][j] = j;
                else if (j==0) dp[i][j] = i;
                else if (str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        return dp[m][n];
}


int main() {
        int cases; cin>>cases;
        while(cases--)
        {
        cin>>str1>>str2;
        printf("%d\n",editDist(str1.length(),str2.length()));
        }
    return 0;
}
