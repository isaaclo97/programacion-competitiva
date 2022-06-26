#include <bits/stdc++.h>
using namespace std;

int sx[]={1,-1,0,0,1,-1,-1,1}; //8 directions
int sy[]={0,0,1,-1,1,-1,1,-1};
char arr[55][55];
bool arra[55][55];
int arrsol[55][55];
int r,c,num;
void solve(int a, int b){
        for(int i=0;i<8;i++)
        {
            int I=a+sx[i];
            int J=b+sy[i];
            if(I>=0 && I<r && J>=0 && J<c){
                if(arr[I][J]!='*')
                    arrsol[I][J]++;
            }
        }
}
void bfs(int a,int b)
{
    queue<pair<int,int>> Q;
    Q.push(make_pair(a,b));
    while(!Q.empty())
     {
        pair<int,int> aux = Q.front(); Q.pop();
        a=aux.first; b=aux.second;
        arra[a][b]=true;
        if(arrsol[a][b]==0)
        {
            for(int i=0;i<8;i++)
            {
                int I=a+sx[i];
                int J=b+sy[i];
                if(I>=0 && I<r && J>=0 && J<c &&!arra[I][J]){
                    arra[I][J]=true;
                    if(arrsol[I][J]==0 && arr[I][J]!='*') Q.push(make_pair(I,J));
                }
            }
        }
    }
}
int main(){
    while(scanf("%d%d",&r,&c)==2)
    {
    memset(arrsol,0,sizeof(arrsol));
    memset(arra,false,sizeof(arra));
    for(int i=0; i<r;i++)
        for(int j=0; j<c;j++) cin>>arr[i][j];
    int k; cin>>k;
    int c1,r1;
    for(int i=0; i<r;i++)
        for(int j=0; j<c;j++) if(arr[i][j]=='*') solve(i,j);
    bool print=true;
    for(int i=0; i<k;i++)
    {
        cin>>c1>>r1;
        c1--; r1--;
        if(arr[c1][r1]=='*') print=false;
        if(print) bfs(c1,r1);
    }
    if(print)
    {
        for(int i=0; i<r;i++)
        {
            for(int j=0; j<c;j++)
            {
                if(arra[i][j] && arrsol[i][j]!=0) cout<<arrsol[i][j];
                else if(arra[i][j] && arrsol[i][j]==0) cout<<"-";
                else cout<<"X";
            }
            cout<<endl;
        }
    }
    else cout<<"GAME OVER\n";
    }
return 0;
}
