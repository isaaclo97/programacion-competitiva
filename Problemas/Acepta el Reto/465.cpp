#include <bits/stdc++.h>
using namespace std;

int di[]={-1,0,1,0}; //4 directions up rigth down left priority
int dj[]={0,1,0,-1};
char arr[105][105];
bool visited[105][105];
int r,c,lf,ri,j_,i_,p_;

void dfs(int a, int b, int p){
    visited[a][b]=true;
    for(int i=0;i<4;i++){
    int I=a+di[i];
    int J=b+dj[i];
    if(I>=0 && I<r && J>=0 && J<c &&  arr[I][J]=='#' && !visited[I][J]){
    j_=J; i_=I; p_=i;
    if(i==4) dfs(I,J,i);
    if(i==0) { if(p==1) lf++; if(p==3) ri++; dfs(I,J,i); }
    else if(i==1) { if(p==0) ri++; if(p==2) lf++; dfs(I,J,i); }
    else if(i==3) { if(p==0) lf++; if(p==2) ri++; dfs(I,J,i); }
    else { if(p==1) ri++; if(p==3) lf++; dfs(I,J,i); }
    }
  }
}

int main()
{
    while(scanf("%d%d",&c,&r)==2)
    {
        int i1,j1;
        for(int i=0; i<r;i++)
            for(int j=0; j<c;j++) { cin>>arr[i][j]; visited[i][j]=false; if(arr[i][j]=='O') {i1=i; j1=j;} }
        lf=ri=0;
        dfs(i1,j1,4);
        for(int i=0;i<4;i++){
            int I=i_+di[i];
            int J=j_+dj[i];
            if(I>=0 && I<r && J>=0 && J<c && arr[I][J]=='O')
            {
                if(i==0) { if(p_==1) lf++; if(p_==3) ri++;  }
                else if(i==1) { if(p_==0) ri++; if(p_==2) lf++; }
                else if(i==3) { if(p_==0) lf++; if(p_==2) ri++; }
                else { if(p_==1) ri++; if(p_==3) lf++;  }
                break;
            }
        }
        if(lf>ri){ int f = lf; lf=ri; ri=f;}
        printf("%d %d\n",lf,ri);
    }
    return 0;
}
