#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2 && (n!=0 || m!=0))
    {
        vector<int> V;
        for(int i=0; i<n;i++) {int aux; scanf("%d",&aux); V.push_back(aux);}
        sort(V.begin(),V.end());
        long long int res = 0;
        vector<int>::iterator lower;
        for(int i=0; i<n;i++)
        {
           lower = lower_bound (V.begin(), V.end(), m-V[i]+1);
           int val = (lower-(V.begin()+i))-1;
           if(val>0)res+=val;
        }
        printf("%lld\n",res);
    }
    return 0;
}
