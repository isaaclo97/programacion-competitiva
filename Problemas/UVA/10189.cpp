#include <bits/stdc++.h>
using namespace std;

int sx[]={1,-1,0,0,1,-1,-1,1}; //8 directions
int sy[]={0,0,1,-1,1,-1,1,-1};
char arr[105][105];
int arrsol[105][105];
int r,c;
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
int main(){
    int ca=1;
    
    while(scanf("%d%d",&r,&c)==2 && (r!=0 || c!=0))
    {
    if(ca!=1) cout<<endl;
    memset(arrsol,0,sizeof(arrsol));
    for(int i=0; i<r;i++)
        for(int j=0; j<c;j++) cin>>arr[i][j];
    for(int i=0; i<r;i++)
        for(int j=0; j<c;j++) if(arr[i][j]=='*') solve(i,j);
    printf("Field #%d:\n",ca++);
        for(int i=0; i<r;i++)
        {
            for(int j=0; j<c;j++)
            {
              if(arr[i][j]=='*') cout<<'*';
              else cout<<arrsol[i][j];
            }
            cout<<endl;
        }

    }
return 0;
}
