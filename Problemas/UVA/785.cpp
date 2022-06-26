#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int sx[]={1,-1,0,0}; //4 directions
int sy[]={0,0,1,-1};

const int VAL = 150;
char V[VAL][VAL];
bool visited[VAL][VAL];
int c,r;
void dfs(int a,int b, char pr)
{
    visited[a][b]=true;
    for(int i=0;i<4;i++){
    int I=a+sx[i];
    int J=b+sy[i];
    if(I>=0 && I<r && J>=0 && J<101 && !visited[I][J]&& V[I][J]!='X'){
       visited[I][J]=true;
       V[I][J]=pr;
    dfs(I,J,pr);
    }
    }
}
int main()
{
    while(1) {
        r=0;
           while(1) {
               if(!gets(V[r])) return 0;
               if(V[r][0] == '_')  break;
               r++;
           }
           memset(visited, false, sizeof(visited));
           for(int i = 0; i < r; i++)
               for(int j = 0; V[i][j]; j++)
                   if(V[i][j] != 'X' && V[i][j] != ' ' && !visited [i][j])  dfs(i, j, V[i][j]);
           for(int i = 0; i < r; i++)
               puts(V[i]);
           puts("_____________________________");
    }
    return 0;
}
