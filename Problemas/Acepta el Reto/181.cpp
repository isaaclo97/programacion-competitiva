#include <bits/stdc++.h>
using namespace std;

#define INF 0

bool mark[18][18];
int memo[18][18];
char board[18][18];
int a;

int DP(int begin,int end)
{
    if(begin==0&&end==a-1) return 1;
    if(begin>a-1 || end>a-1 || end <0 || begin<0) return 0;
    if(board[begin][end]=='X') return 0;
    int &best = memo[begin][end];
    if(mark[begin][end]) return best;
    mark[begin][end] = true;
    return best = DP(begin,end+1)+DP(begin-1,end);
}

int main()
{
    char b;
    cin>>a;
    while(a!=0)
    {
        for(int i=0; i<a;i++)
            for(int j=0; j<a;j++)
            {
                cin>>b;
                board[i][j]=b;
            }
        memset(mark,false,sizeof(mark));
        memset(memo,INF,sizeof(memo));
        cout<<DP(a-1,0)<<endl;
        cin>>a;
    }
    return 0;
}
