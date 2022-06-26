#include <bits/stdc++.h>
using namespace std;
int memo[1001][1001];
int cartas[1001];
int K;
int DP(int start,int end)
{
    if(start>end) return 0;
    int &best = memo[start][end];
    if(memo[start][end]!=-1) return best;
    best = max(cartas[start+1]>=cartas[end]?DP(start+2,end)+cartas[start]:DP(start+1,end-1)+cartas[start],
               cartas[start]>=cartas[end-1]?DP(start+1,end-1)+cartas[end]:DP(start,end-2)+cartas[end]);
    return best;
}

int main()
{
    cin>>K;
    while(K!=0)
    {
        for(int i=0; i<K;i++)
            for(int j=0; j<K;j++)
                memo[i][j]=-1;

        for(int i=0; i<K;i++)
        {
            cin>>cartas[i];
        }
        printf("%d\n",DP(0,K-1));
        cin>>K;
    }
return 0;
}
