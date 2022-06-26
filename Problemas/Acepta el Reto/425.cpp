#include <bits/stdc++.h>
using namespace std;

#define INF 110

bool mark[110][110];
int memo[110][110];
string s;

int DP(int begin,int end)
{
    if(begin==end) return 0;
     if(begin==end-1) return s[begin]==s[end] ? 0 : 1;
    int &best = memo[begin][end];
    if(mark[begin][end]) return best;
    mark[begin][end] = true;
    if(s[begin]==s[end])
        return best=DP(begin+1,end-1);
    return best = min(DP(begin+1,end),DP(begin,end-1))+1;
}

int main()
{
    while(getline(cin,s))
    {
        memset(mark,false,sizeof(mark));
        memset(memo,INF,sizeof(memo));
        cout<<DP(0,s.length()-1)<<endl;
    }
    return 0;
}
