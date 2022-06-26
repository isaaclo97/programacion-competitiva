#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main() {
    
    double d;
    int T;
    cin>>T;
    while(T--){
        long long int x,lo=0, hi=10000000000,ans=0;
        cin>>x;
        while(lo<=hi)
        {
            long long  mid=(lo+hi)/2;
            long long  temp=mid*(mid+1)/2;
            if(temp<=x)
                {
                    ans=mid;
                    lo=mid+1;
                }
            else  hi=mid-1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
