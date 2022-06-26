#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int di[]={1,-1,0,0}; //4 directions
int dj[]={0,0,1,-1};

char matrix[1050][1050];
bool visited[1050][1050];
int r,c,res = 0;

void dfs(int a, int b)
{
    visited[a][b]=true;
    for(int i=0;i<4;i++){
    int I=a+di[i];
    int J=b+dj[i];
    int cont=0;
        if(I>=0 && I<r && J>=0 && J<c &&!visited[I][J]&&matrix[I][J]=='#'){
                for(int i1=0;i1<4;i1++){
                int I1=I+di[i1];
                int J1=J+dj[i1];
                if(I1>=0 && I1<r && J1>=0 && J1<c && matrix[I1][J1]=='#')cont++;
                }
                if(cont>2) res+=cont;
                visited[I][J]=true;
                dfs(I,J);
        }
    }
}
int main() {
    while(scanf("%d%d",&c,&r)==2)
    {
        res=0;
        for(int i=0; i<r;i++)
            for(int j=0; j<c;j++) { cin>>matrix[i][j]; visited[i][j]=false;}
        for(int i=0; i<r;i++)
            for(int j=0; j<c;j++) { if(matrix[i][j]=='#') dfs(i,j); }
        cout<<res<<'\n';
    }
    return 0;
}
