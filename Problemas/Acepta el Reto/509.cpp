#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int C,F;
int arr[101][101];
long long int memo[101][101];
int sx[]={1,0}; //2 direcciones abajo y derecha
int sy[]={0,1};

long long int DP(int x,int y)
{
    if(y==C-1 && x==F-1) return 2;
    long long int &best = memo[x][y];
    if(best!=INF) return memo[x][y];
    long long int actual = INF;
    for(int i=0; i<2;i++)
    {
       int I=x+sx[i];
       int J=y+sy[i];
       if(I>=0 && I<F && J>=0 && J<C) actual = min(actual,DP(I,J));
    }
    actual-=arr[x][y];
    if(actual<2) actual=2;
    return best = actual;
}

int main()
{
    while(scanf("%d%d",&C,&F)==2)
    {
        for(int i=0; i<F;i++)
            for(int j=0; j<C;j++) { memo[i][j]=INF; scanf("%d",&arr[i][j]);}
        printf("%lld\n",DP(0,0));
    }
    return 0;
}
