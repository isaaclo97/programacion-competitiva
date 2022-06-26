#include<bits/stdc++.h>
using namespace std ;
int m1[]={1,0,-1,0};
int m2[]={0,1,0,-1};
bool visited[21][21] ;
int r,c,x,y ;
char arr[21][21] ;

bool bfs(int iniciox, int inicioy)
{
    queue<pair<int,int>> q;
    pair<int,int> p;
    visited[iniciox][inicioy] = true;
    q.push(make_pair(iniciox, inicioy));

    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(int i=0; i<4; i++ )
        {
            x = m1[i]+p.first;
            y = m2[i]+p.second;
            if( x>=0 && x<r && y>=0 && y<c && (arr[x][y] == '.'||arr[x][y]=='F'))
            {
                if(!visited[x][y])
                {
                    visited[x][y]=true;
                    if(arr[x][y]=='F')
                    {
                        return true;
                    }
                    q.push(make_pair(x,y));
                }
            }
        }
    }
    return false;
}
int main()
{
    int iniciox,finx;
    while(scanf("%d%d",&r,&c)==2)
    {
        memset(visited,false,sizeof(visited));
        for(int i=0; i<r;i++)
            for(int j=0; j<c;j++)
            {
                char a;
                cin>>a;
                if(a=='S')
                {
                 iniciox=i; finx=j;
                }
                arr[i][j]=a;
            }
        if(bfs(iniciox,finx))
        cout<<"SI\n";
        else
         cout<<"NO\n";
    }
    return 0 ;
}
