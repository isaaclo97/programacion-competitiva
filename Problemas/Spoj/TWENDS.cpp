#include <bits/stdc++.h>
using namespace std;
int memo[1001][1001];
bool mark[1001][1001];
int cartas[1001];
int K;
int DP(int start,int end)
{
    if(start>end) return 0;
    int &best = memo[start][end];
    if(mark[start][end]) return best;
    mark[start][end]=true;
 
    best = max(cartas[start+1]>=cartas[end]?DP(start+2,end)+cartas[start]:DP(start+1,end-1)+cartas[start],
               cartas[start]>=cartas[end-1]?DP(start+1,end-1)+cartas[end]:DP(start,end-2)+cartas[end]);
    return best;
}
 
int main()
{
    int cnt=1,sum;
    cin>>K;
    while(K!=0)
    {
        sum=0;
        memset(mark,false,sizeof(mark));
        memset(memo,-1,sizeof(memo));
        for(int i=0; i<K;i++)
        {
            cin>>cartas[i];
            sum+=cartas[i];
        }
        int a=DP(0,K-1);
        cout<<"In game "<<cnt<<", the greedy strategy might lose by as many as "<<a-(sum-a)<<" points.\n";
        cin>>K;
        cnt++;
    }
return 0;
} 
