#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int a,b;
    int L1[100005],R1[100005];
    while(scanf("%d%d",&a,&b)==2 && (a!=0 || b!=0))
    {
        for(int i=0; i<=a;i++)
        {
            L1[i]= i-1;
            R1[i]= i+1;
        }
        int L,R;
        for(int i=0; i<b;i++)
        {
            cin>>L>>R;
            if(L1[L]<1) cout<<"* ";
            else cout<<L1[L]<<" ";
            if(R1[R]>a) cout<<"*\n";
            else cout<<R1[R]<<"\n";
            L1[R1[R]]=L1[L];
            R1[L1[L]]=R1[R];
        }
        cout<<"-\n";
    }
    return 0;
}
