#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int di[]={1,1,1,-1,-1,-1,0,0};
int dj[]={1,0,-1,1,0,-1,1,-1};
bool visited[101][101];
int r,c;
char arr[101][101];

void dfs(int a, int b){

    visited[a][b]=true;
    for(int i=0;i<8;i++){
        int I=a+di[i];
        int J=b+dj[i];
        if(I>=0 && I<r && J>=0 && J<c && !visited[I][J]){
            visited[I][J]=true;
            if(arr[I][J]=='@') dfs(I,J);
        }
    }
}
int main()
{
    while(scanf("%d%d",&r,&c)==2 && (c!=0 ||r!=0))
    {
        int count=0;
        for(int i=0; i<r;i++)
            for(int j=0; j<c;j++)
                visited[i][j]=false;

        for(int i=0; i<r;i++)
            for(int j=0; j<c;j++)
            {
                char a;
                cin>>a;
                arr[i][j]=a;
            }
        for(int i=0;i<r;i++)
            for(int j=0; j<c;j++)
                if(!visited[i][j] && arr[i][j]=='@')
                {
                    visited[i][j]=true;
                    dfs(i,j);
                    count++;
                }
                else  visited[i][j]=true;
        cout<<count<<"\n";
    }
    return 0 ;
}
