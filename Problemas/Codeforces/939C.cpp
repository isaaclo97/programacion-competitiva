#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    long long int cases,s,f,sum=0,k=1,msum,ans=1;
    cin>>cases;
    long long int arr[cases+1];
    for(int i=1; i<=cases;i++) cin>>arr[i];
    cin>>s>>f;
    for (int i=s; i<f; i++) sum+=arr[i];
    msum=sum;
        for (int i=s-1; k<=cases; i--)
        {
            k++;
            if (i<1) i=cases;
            sum+=arr[i];
            int last=(i+(f-s))%cases==0?cases:(i+(f-s))%cases;
            sum-=arr[last];
            if (sum>msum)
            {
                ans=k;
                msum=sum;
            }
        }
        cout<<ans<<endl;
    return 0;
}
