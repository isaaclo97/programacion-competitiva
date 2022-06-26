#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int round(int num)
{
    if (num%10<5)return num-(num%10);
    return num+(10-(num%10));
}
int main()
{
    int n,d,aux,total=0;
     scanf("%d%d",&n,&d);
    int memo[n][d+1];
    int arracu[n];
    for(int i=0; i<n;i++) { scanf("%d",&aux); total+=aux; arracu[i]=total;}
    for(int i = 0; i<=d;i++)
        for(int j=0; j<n;j++)
        {
            if(i==0) memo[j][i]=round(arracu[j]);
            else
            {
            int mini = round(arracu[j]);
            for(int k=0; k<j;k++)
            {
                aux = round(memo[k][i-1]+round(arracu[j]-arracu[k]));
                mini=min(mini,aux);
            }
            memo[j][i]=mini;
            }
        }
    printf("%d\n",round(memo[n-1][d]));
    return 0;
}
