#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    int memo[n+1][m+1];
    int matrix[n+1][m+1];
    for(int i=1; i<=n;i++)
       for(int j=1; j<=m;j++)  scanf("%d",&matrix[i][j]);
    memset(memo,0,sizeof(memo));
    /*
    1 2 3   1  3 6
    4 5 6   5  12 21
    7 8 9   12 27 45
    */
    for(int i=1; i<=n;i++)
       for(int j=1; j<=m;j++)
           memo[i][j]=memo[i-1][j]+memo[i][j-1]+matrix[i][j]-memo[i-1][j-1];
    int query; scanf("%d",&query);
    int n1,m1;
    for(int i=0; i<query;i++)
    {
        scanf("%d%d",&n1,&m1);
        printf("%d\n",memo[n1][m1]);
    }
    return 0;
}
