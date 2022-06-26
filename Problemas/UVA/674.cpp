#include <bits/stdc++.h>
using namespace std;

int v[]={50,25,10,5,1};
int memo[7850][5];
bool mark[7850][5];

int f(int a, int b)
{
    if(a==0) return 1; //Si es exactamente 0 PREMIO!
    if(a<0) return 0; //Si es menor que 0 al restar
    if(b>4) return 0; //Si excede el vector
    int &best=memo[a][b];
    if(mark[a][b]) return best;
    mark[a][b]=true;
    return best=f(a,b+1)+f(a-v[b],b);
}

int main(){
    int x;
    while(scanf("%d",&x)!=EOF)
    {
     //   memset(mark,false,sizeof(mark));
     //   memset(memo,0,sizeof(memo));
        cout<<f(x,0)<<endl;
    }
    return 0;
}
