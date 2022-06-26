#include<bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std ;
int m1[]={1,0,-1,0};
int m2[]={0,1,0,-1};
bool visited[1001][1001] ;
int r,c,x,y,finlabx,finlaby,res=INF;
char arr[1001][1001] ;
struct BFSstate{
    int first;
    int second;
    int length;
};
int bfs(int iniciox, int inicioy)
{
    queue<BFSstate> q;
    BFSstate p;
    visited[iniciox][inicioy] = true;
    if(arr[iniciox][inicioy]=='D' ||arr[finlabx][finlaby]=='D') return res;
    p.first=iniciox; p.second=inicioy; p.length=1;
    q.push(p);

    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            x = m1[i]+p.first;
            y = m2[i]+p.second;
            if( x>=0 && x<r && y>=0 && y<c && (arr[x][y]=='.'||arr[x][y]=='P') &&p.length<res)
            {
                if(!visited[x][y])
                {
                    visited[x][y]=true;
                    if(arr[x][y]=='P')
                    {
                        res=p.length;
                    }
                    else
                    {
                    BFSstate aux;
                    aux.first=x; aux.second=y; aux.length=p.length+1;
                    q.push(aux);
                    }
                }
            }
        }
    }
    return res;
}
int main()
{
    int iniciox,finx;
    int cases;
    cin>>cases;
    while(cases--)
    {
        res=INF;
        scanf("%d%d",&c,&r);
        for(int i=0; i<r;i++)
            for(int j=0; j<c;j++)
                visited[i][j]=false;

        for(int i=0; i<r;i++)
            for(int j=0; j<c;j++)
            {
                char a;
                cin>>a;
                if(a=='E')
                {
                 iniciox=i; finx=j;
                }
                else if(a=='P')
                {
                    finlabx=i;finlaby=j;
                }
                arr[i][j]=a;
            }
        for(int i=0; i<r;i++)
            for(int j=0; j<c;j++)
            {
                char a=arr[i][j];
                if(a>='0'&&a<='9')
                {
                    arr[i][j]=a;
                    for(int m=1; m<=(a-48)&&(m+i)<r;m++) //Poner hacia derecha
                        if(arr[m+i][j]=='#') break;
                        else if(!(arr[i+m][j]<='9' && arr[i+m][j]>'0')) arr[m+i][j]='D';
                    for(int p=1; p<=(a-48)&&(p+j)<c;p++) //Poner hacia abajo
                        if(arr[i][p+j]=='#') break;
                        else if(!(arr[i][p+j]<='9' && arr[i][p+j]>'0')) arr[i][p+j]='D';
                    for(int m=1; m<=(a-48)&&(i-m)>-1;m++) //Poner hacia izquierda
                        if(arr[i-m][j]=='#') break;
                        else if(!(arr[i-m][j]<='9' && arr[i-m][j]>'0'))arr[i-m][j]='D';
                    for(int p=1; p<=(a-48)&&(j-p)>-1;p++) //Poner hacia arriba
                        if(arr[i][j-p]=='#') break;
                        else if(!(arr[i][j-p]<='9' && arr[i][j-p]>'0'))arr[i][j-p]='D';
                }
            }
        if(bfs(iniciox,finx)!=INF)
        cout<<res<<endl;
        else
         cout<<"NO\n";
    }
    return 0 ;
}
