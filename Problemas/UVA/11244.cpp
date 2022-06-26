#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int di[]={1,1,1,-1,-1,-1,0,0};
int dj[]={1,0,-1,1,0,-1,1,-1};
bool visited[101][101];
int r,c,m;
char arr[101][101];

void dfs(int a, int b){

    visited[a][b]=true;
    for(int i=0;i<8;i++){
        int I=a+di[i];
        int J=b+dj[i];
        if(I>=0 && I<r && J>=0 && J<c && !visited[I][J]){
            visited[I][J]=true;
            if(arr[I][J]=='*'){m++; dfs(I,J);}
        }
    }
}

int main()
{
    while(scanf("%d%d",&r,&c)==2 && (r!=0||c!=0))
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
                if(!visited[i][j] && arr[i][j]=='*')
                {
                    m=1;
                    visited[i][j]=true;
                    dfs(i,j);
                    if(m==1) count++;
                }
                else  visited[i][j]=true;
        printf("%d\n",count);
    }
    return 0 ;
}
