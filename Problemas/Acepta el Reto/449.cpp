#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

string cases;
int memo[100][100];
bool visited[100][100];
int DP(int l, int r)
{
    if(l==r) return 1;
    if(l>r) return 0;
    int &best = memo[l][r];
    if(visited[l][r]) return best;
    visited[l][r]=true;
    char aux = cases[l];
    int laux=0,raux=0;
    for(unsigned int i=l; i<cases.length();i++) if(cases[i]!=aux) break; else laux++;
    aux = cases[r];
    for(unsigned int i=r; i>0;i--) if(cases[i]!=aux) break; else raux++;
    if(cases[l]==cases[r]) return best=DP(l+laux,r-raux)+1;
    return best= min(DP(l+laux,r),DP(l,r-raux))+1;
}
int main()
{
    while(cin>>cases)
    {
     memset(visited,false,sizeof(visited));
     cout<<DP(0,cases.length()-1)<<'\n';
    }
    return 0;
}
