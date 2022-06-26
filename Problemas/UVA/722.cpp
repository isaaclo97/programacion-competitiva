#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int di[]={1,-1,0,0};
int dj[]={0,0,1,-1};
bool visited[105][105];
int R,C;
char arr[105][105];
int total=1;
void dfs(int a, int b){

    visited[a][b]=true;
    for(int i=0;i<4;i++){
        int I=a+di[i];
        int J=b+dj[i];
        if(I>=0 && I<R && J>=0 && J<C && !visited[I][J]){
            visited[I][J]=true;
            if(arr[I][J]=='0') {total++; dfs(I,J);}
        }
    }
}

int main()
{
    int cases; cin>>cases;
    while(cases--)
    {
        int r,c;
        scanf("%d%d",&r,&c); r--; c--;
        getchar();
        R = 0;
        char str[105];
        while(gets(str)&&strlen(str)>0)
                {
                    strcpy(arr[R],str);
                    R++;
                }
        C = strlen(arr[0]);
        for(int i=0; i<R;i++)
            for(int j=0; j<C;j++)
                visited[i][j]=false;
                if(arr[r][c]=='0')
                {
                    visited[r][c]=true;
                    dfs(r,c);
                    printf("%d\n",total);
                    total=1;
                }
        if(cases!=0) printf("\n");
    }
    return 0 ;
}
