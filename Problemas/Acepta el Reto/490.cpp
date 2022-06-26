#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)==2)
    {
        int arr[n];
        int add[n];
        for(int i=0; i<n;i++)scanf("%d",&arr[i]);
        long long int res = 0,sol=0;
        for(int i=1; i<n;i++)
        {
            if(i<k)
            {
                if(arr[i]<arr[i-1]) { add[i-1] = -(arr[i-1]-arr[i]); res-=arr[i-1]-arr[i]; }
                else { add[i-1]=arr[i]-arr[i-1]; res += arr[i]-arr[i-1]; }
            }
            else
            {
                sol =  max(abs(res),sol);
                res-=add[i-k];
                if(arr[i]<arr[i-1]) { add[i-1] = -(arr[i-1]-arr[i]); res-=arr[i-1]-arr[i]; }
                else { add[i-1]=arr[i]-arr[i-1]; res += arr[i]-arr[i-1]; }
            }
        }
        sol =  max(abs(res),sol);
        printf("%lld\n",sol);
    }
    return 0;
}
