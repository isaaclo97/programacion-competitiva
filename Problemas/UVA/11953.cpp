#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int sx[]={1,-1,0,0}; //4 directions
int sy[]={0,0,1,-1};

const int VAL = 105;
bool visited[VAL][VAL];
char arr[VAL][VAL];
int c,r;
void dfs(int a,int b)
{
    visited[a][b]=true;
    for(int i=0;i<4;i++){
    int I=a+sx[i];
    int J=b+sy[i];
    if(I>=0 && I<r && J>=0 && J<c && !visited[I][J]&& arr[I][J]!='.'){
       visited[I][J]=true;
    dfs(I,J);
    }
    }
}
int main()
{
    int aux,ca=1;
    cin>>aux;
    while(aux--)
    {
        scanf("%d",&r);
        c=r;
        for(int i=0; i<r;i++)
         for(int j=0; j<c;j++) cin>>arr[i][j];
        memset(visited,false,sizeof(visited));
        int cont = 0;
        for(int i=0; i<r;i++)
         for(int j=0; j<c;j++)
             if(arr[i][j]=='x' && !visited[i][j]) { dfs(i,j); cont++;}

        printf("Case %d: %d\n",ca++,cont);
    }
    return 0;
}
