#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
int memo[505][505];
bool mark[505][505];
int X[505],Y[505];
int m;
int M(int a,int b)
{
    return abs(X[a]-X[b])+abs(Y[a]-Y[b]);
}
int  DP(int i1,int i2){
    int next=max(i1,i2)+1;
    if(next>m) return 0;
    int &best = memo[i1][i2];
    if(mark[i1][i2]) return best;
    mark[i1][i2]=true;
    return best=min(DP(next,i2)+M(i1,next),DP(i1,next)+M(i2,next));
}
int main(){
    int n;
    cin>>n;
    while(n--){
        cin>>m;
           memset( memo , INF ,sizeof(memo) );
           memset( mark , false ,sizeof(mark) );
           for(int i=1;i<=m;i++){
               cin>>X[i]>>Y[i];
           }
        cout<<DP(0,0)<<'\n';
    }
    return 0;
}
