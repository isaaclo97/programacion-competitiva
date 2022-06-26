#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int n,k,a,b;
int main()
{
    long long int n,k,a,b;
    long long int  ans=0;
    cin>>n>>k>>a>>b;
        while(n>1) {
            ans+=n%k*a;
            n-=n%k;
            if((n-n/k)*a>=b){ n/=k;ans+=b;}
            else {
                ans+=(n-1)*a;
                break;
            }
        }
        cout<<ans<<endl;
        return 0;
}
