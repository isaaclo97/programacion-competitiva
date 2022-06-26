#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;


long long int memo[300002][5];
bool visited[300002][5];
int v[]={50,25,10,5,1};

long long int DP(int n,int i)
{
    if(n==0) return 1;
    if(n<0||i>4) return 0;
    long long int &best = memo[n][i];
    if(visited[n][i]) return best;
    visited[n][i]=true;
    return best=DP(n-v[i],i)+DP(n-v[i+1],i+1)+DP(n-v[i+2],i+2)+DP(n-v[i+3],i+3)+DP(n-v[i+4],i+4);
}
int main()
{
    memset(visited,false,sizeof(visited));
    memset(memo,0,sizeof(memo));
    int num;
    while(scanf("%d",&num)==1)
    {
    long long int n = DP(num,0);
    if(n==1) printf("There is only 1 way to produce %d cents change.\n",num);
    else printf("There are %lld ways to produce %d cents change.\n",n,num);
    }
    return 0;
}
