#include <bits/stdc++.h>
#define MOD 1000007
using namespace std;

int n;
int memo[110][110];
bool visited[110][110];
char arr[110][110];

//x altura y fila
int DP(int x, int y)
{
    if(y>=n || y<0 || x<0 || arr[x][y]=='B') return 0;
    if(x==0 && arr[x][y]!='B') return 1;
    int &best = memo[x][y];
    if(visited[x][y]) return best;
    visited[x][y]=true;
    int cur,cur2;
    if(arr[x-1][y+1]=='B') cur = DP(x-2,y+2);
    else cur=DP(x-1,y+1);
    if(arr[x-1][y-1]=='B') cur2 = DP(x-2,y-2);
    else cur2=DP(x-1,y-1);
    return best = (cur%MOD + cur2%MOD)%MOD;
}
int main()
{
    int ca=1;
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&n);
        int x,y;
        memset(memo,0,sizeof(memo));
        memset(visited,false,sizeof(visited));
        memset(arr,' ',sizeof(arr));
        for(int i=0; i<n;i++)
            for(int j=0; j<n;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]=='W') {x=i; y=j;}
            }
        printf("Case %d: %d\n",ca++,DP(x,y)%MOD);
    }
    return 0;
}
