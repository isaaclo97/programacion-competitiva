#include <bits/stdc++.h>
using namespace std;

int num[11][7] = {
    {1,1,1,0,1,1,1}, //4
    {0,0,1,0,0,1,0}, //3 6
    {1,0,1,1,1,0,1}, //2 6
    {1,0,1,1,0,1,1}, //2 5
    {0,1,1,1,0,1,0}, //1 5 7
    {1,1,0,1,0,1,1}, //3 5
    {1,1,0,1,1,1,1}, //3
    {1,0,1,0,0,1,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}, //5
    {0,0,0,0,0,0,0}
};
int results[11][11];
void solve()
{
    /*
      -     1
     | |    2   3
      -     4
     | |    5   6
      -     7
    */
    for (int i = 0; i < 11; i++)
        for (int j = i; j < 11; j++) {
            int cnt = 0;
            for (int k = 0; k < 7; k++)
                if (num[i][k] != num[j][k]) cnt++;
            results[i][j] = results[j][i] = cnt;
        }
}
int main()
{
    int n,n1;
    solve();
    while(scanf("%d",&n)==1 && n!=-1)
    {
        long long int total = 0;
        int cnt = 1;
        total += results[10][n];
        while(scanf("%d",&n1)==1 && n1!=-1)
        {
           cnt++;
           total+=results[n][n1];
           n=n1;
        }
        total += results[n][10];
        printf("%lld\n",cnt*total);
    }
    return 0;
}
