#include <bits/stdc++.h>
using namespace std;
 
long long int memo[55][55];
bool mark[55][55];
long long int N,K,A,B;
 
long long int DP(int a,int b)
{
    if(b==K) return a==B;
    long long int &best=memo[a][b];
    if(mark[a][b]) return best;
    mark[a][b]=true;
    int u = a+1; int v=a-1;
    if(u==N) u=0;
    if(v==-1) v=N-1;
    return best=DP(u,b+1)+DP(v,b+1);
}
 
int main()
{
    cin>>N>>K;
    while(N!=-1&&K!=-1)
    {
        cin>>A>>B;
                A--; B--;
        memset(mark,false,sizeof(mark));
        memset(memo,0,sizeof(memo));
        cout<<DP(A,0)<<endl;
        cin>>N>>K;
    }
    return 0;
} 
