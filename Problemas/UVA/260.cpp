#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int sx[]={-1,-1,0,0,1,1};
int sy[]={-1,0,-1,1,0,1};

bool visited[205][205];
char arr[205][205];
int c,r,flag;
void dfs(int a,int b, char color)
{
    visited[a][b]=true;
    for(int i=0;i<6;i++){
    int I=a+sx[i];
    int J=b+sy[i];
    if(I>=0 && I<r && J>=0 && J<c && !visited[I][J]&& arr[I][J]==color){
       if(color=='w' && J==(c-1)) flag=0;
       else if(color=='b' && I==(c-1)) flag=1;
       visited[I][J]=true;
    dfs(I,J,color);
    }
    }
}
int main()
{
    int aux,ca=1;
    while(scanf("%d",&aux)==1 && aux!=0)
    {
        r=c=aux;
        for(int i = 0; i <aux; i++)
            for(int j = 0; j<aux; j++) cin>>arr[i][j];
        flag=-1;
        //black
        for(int i = 0; i <aux && flag==-1; i++)
            if(arr[0][i]=='b')
            {
                 memset(visited,false,sizeof(visited));
                    dfs(0,i,arr[0][i]);
            }
        //white
        for(int i = 0; i <aux && flag==-1; i++)
            if(arr[i][0]=='w')
            {
                memset(visited,false,sizeof(visited));
                    dfs(i,0,arr[i][0]);
            }
        if(flag==0) printf("%d W\n",ca++);
        else printf("%d B\n",ca++);

    }
    return 0;
}
