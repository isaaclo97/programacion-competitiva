#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int di[] = {-1, 0, 1, 0, -1,-1, 1, 1};
int dj[] = { 0, 1, 0,-1, -1, 1,-1, 1};
bool visited[105][105];
int R,C;
char arr[105][105];
int total;
void dfs(int a, int b){

    visited[a][b]=true;
    for(int i=0;i<8;i++){
        int I=a+di[i];
        int J=b+dj[i];
        if(I>=0 && I<R && J>=0 && J<C && !visited[I][J]){
            visited[I][J]=true;
            if(arr[I][J]=='1') {total++; dfs(I,J);}
        }
    }
}

int main()
{
    int cases; cin>>cases;
    char str[105];
    gets(str); gets(str);
    while(cases--)
    {

        R = 0;
        while(gets(str)&&strlen(str)>0)
                {
                    strcpy(arr[R],str);
                    R++;
                }
        C = strlen(arr[0]);
        for(int i=0; i<R;i++)
            for(int j=0; j<C;j++)
                visited[i][j]=false;
        int res = 0;
        total=1;
        for(int i=0;i<R;i++)
            for(int j=0; j<C;j++)
                if(!visited[i][j] && arr[i][j]=='1')
                {
                    visited[i][j]=true;
                    dfs(i,j);
                    res=max(res,total);
                    total=1;
                }
                else  visited[i][j]=true;
        printf("%d\n",res);
        if(cases!=0)  printf("\n");
    }
    return 0 ;
}
