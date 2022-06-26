#include <bits/stdc++.h>
using namespace std;

int dx[]={1,-1,0,0}; //4 directions
int dy[]={0,0,1,-1};
bool visited[255][255];
int arr[255][255];
int r,c,num;
void dfs(int a, int b){
visited[a][b]=true;
    for(int i=0;i<4;i++)
    {
        int I=a+dx[i];
        int J=b+dy[i];
        if(I>=0 && I<r && J>=0 && J<c &&!visited[I][J]){
        visited[I][J]=true;
        if(arr[I][J]==1) { num++; dfs(I,J);}
         }
    }
}
int main(){
    while(scanf("%d%d",&r,&c)==2 && (r!=0||c!=0))
    {
    memset(visited,false,sizeof(visited));
    for(int i=0; i<r;i++)
        for(int j=0; j<c;j++) cin>>arr[i][j];
    map<int,int> M;
    int cont = 0;
    for(int i=0; i<r;i++)
        for(int j=0; j<c;j++) if(arr[i][j]==1 && !visited[i][j]){ num=1; dfs(i,j); M[num]++; cont++;}
    cout<<cont<<endl;
    for(auto m:M) cout<<m.first<<" "<<m.second<<endl;

    }
return 0;
}
