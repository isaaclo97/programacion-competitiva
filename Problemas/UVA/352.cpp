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
        if(I>=0 && I<r && J>=0 && J<r && !visited[I][J]){
            visited[I][J]=true;
            if(arr[I][J]=='1') dfs(I,J);
        }
    }
}

int main()
{
    int c = 1;
    while(scanf("%d",&r)==1)
    {
        int count=0;
        for(int i=0; i<r;i++)
            for(int j=0; j<r;j++)
                visited[i][j]=false;

        for(int i=0; i<r;i++)
            for(int j=0; j<r;j++)
            {
                char a;
                cin>>a;
                arr[i][j]=a;
            }
        for(int i=0;i<r;i++)
            for(int j=0; j<r;j++)
                if(!visited[i][j] && arr[i][j]=='1')
                {
                    visited[i][j]=true;
                    dfs(i,j);
                    count++;
                }
                else  visited[i][j]=true;
        printf("Image number %d contains %d war eagles.\n",c++,count);
    }
    return 0 ;
}
