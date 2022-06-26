#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
bool winx,wino;
int m,n,c;
char board[201][201];
void checkDiagonal(int a,int b)
{
    int cx=0,co=0;
        for(int i=a,j=b;i<m&&j<n&&!winx&&!wino;j++,i++)
        {
            if(board[i][j]=='x'){ cx++; co=0;}
            else if(board[i][j]=='o') { co++; cx=0;}
            else { break;}
            if(cx>=c) winx=true;
            if(co>=c) wino=true;
        }
        cx=0,co=0;
        for(int i=a,j=b;i<m&&j<n&&!winx&&!wino;j--,i--)
        {
            if(board[i][j]=='x'){ cx++; co=0;}
            else if(board[i][j]=='o') { co++; cx=0;}
            else { break;}
            if(cx>=c) winx=true;
            if(co>=c) wino=true;
        }
        cx=0,co=0;
        for(int i=a,j=b;i<m&&j<n&&!winx&&!wino;j++,i--)
        {
            if(board[i][j]=='x'){ cx++; co=0;}
            else if(board[i][j]=='o') { co++; cx=0;}
            else { break;}
            if(cx>=c) winx=true;
            if(co>=c) wino=true;
        }
        cx=0,co=0;
        for(int i=a,j=b;i<m&&j<n&&!winx&&!wino;j--,i++)
        {
            if(board[i][j]=='x'){ cx++; co=0;}
            else if(board[i][j]=='o') { co++; cx=0;}
            else { break;}
            if(cx>=c) winx=true;
            if(co>=c) wino=true;
        }
}
int main()
{
    //freopen("C:/Users/Isaac/Desktop/in.txt","r",stdin);
    int cases,a=0,b=0,cx=0,co=0;
    cin>>cases;
    while(cases--)
    {
    winx=false,wino=false;
    cin>>n>>m>>c;
    for(int i=0; i<m;i++)
        for(int j=0; j<n;j++)
            cin>>board[i][j];
    //check row
    for(int i=0; i<m&&!winx&&!wino;i++)
    {
        cx=co=0;
        for(int j=0; j<n&&!winx&&!wino;j++)
        {
            if(board[i][j]=='x'){ cx++; co=0;}
            else if(board[i][j]=='o') { co++; cx=0;}
            else { cx=0; co=0;}
            if(cx>=c) winx=true;
            if(co>=c) wino=true;
            if(board[i][j]!='.') checkDiagonal(i,j);
        }
    }
    //check column
    for(int i=0; i<n&&!winx&&!wino;i++)
    {
        cx=co=0;
        for(int j=0; j<m&&!winx&&!wino;j++)
        {
            if(board[j][i]=='x'){ cx++; co=0;}
            else if(board[j][i]=='o') { co++; cx=0;}
            else { cx=0; co=0;}
            if(cx>=c) winx=true;
            if(co>=c) wino=true;
        }
    }

    if(winx) a++;
    if(wino) b++;
    }
    cout<<a<<':'<<b<<endl;
    return 0;
}
