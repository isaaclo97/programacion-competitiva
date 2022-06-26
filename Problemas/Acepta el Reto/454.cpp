#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int L,D;
    while(scanf("%lld%lld",&L,&D)==2)
    {
        long long int res = 1;
        long long int flag = 0;
        long long int L1,D1,La=L,Dt=D;
            while(scanf("%lld%lld",&L1,&D1)==2 && (L1!=0 || D1!=0))
            {
                La-=L1;
                if(D1>0) Dt-=D1;
                if(La<0 || Dt<0) {
                    res++; La=L-L1; Dt=min(D,D-D1);
                }
                if(La<0 || Dt<0) flag=1;
            }
        if(flag==1) cout<<"DESTITUIDO\n";
        else cout<<res<<'\n';
    }
}
