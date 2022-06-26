#include <bits/stdc++.h>
using namespace std;

int sx[]={1,-1,0,0}; //4 directions
int sy[]={0,0,1,-1};
int r,c,res;
char arr[110][110];
bool visited[110][110];

void dfs(int a, int b)
{
visited[a][b]=true;
    for(int i=0;i<4;i++){
        int I=a+sx[i];
        int J=b+sy[i];
        if(I>=0 && I<r && J>=0 && J<c && arr[I][J]=='#' && !visited[I][J]){
            visited[I][J]=true;
         res++; dfs(I,J);
        }
    }
}
int main(){
    while(scanf("%d%d",&r,&c)==2)
    {
    for(int i=0; i<r;i++)
        for(int j=0; j<c;j++) { arr[i][j]='\0'; visited[i][j]=false;}
    cin.ignore();
    for(int i=0; i<r;i++) gets(arr[i]);

    int total = 0;
    for(int i=0; i<r;i++)
        for(int j=0; j<c;j++)
            if(arr[i][j]=='#'&&!visited[i][j])
            {
                res=1;
                dfs(i,j);
                total=max(total,res);
            }

    cout<<total<<'\n';
    }
return 0;
}
