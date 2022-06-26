#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int memo[105][105];
int arr[105][105];
int x,y;

int DP(int xval,int yval, int last)
{
    if(xval<0 || xval>=x || yval<0 || yval>=y || last<=arr[xval][yval]) return 0;
    int &best = memo[xval][yval];
    if(memo[xval][yval]!=-1) return best;
    return best = max(DP(xval+1,yval,arr[xval][yval]),max(DP(xval-1,yval,arr[xval][yval]),max(DP(xval,yval-1,arr[xval][yval]),DP(xval,yval+1,arr[xval][yval]))))+1;
}
int main(){
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        string name; cin>>name;
        scanf("%d%d",&x,&y);
        memset(memo,-1,sizeof(memo));
        int res = 0;
        for(int i=0; i<x;i++)
            for(int j=0; j<y;j++) scanf("%d",&arr[i][j]);
        for(int i=0; i<x;i++)
            for(int j=0; j<y;j++)
            {
                res=max(DP(i,j,INF),res);
            }
        cout<<name;
        printf(": %d\n",res);
    }
    return 0;
}
