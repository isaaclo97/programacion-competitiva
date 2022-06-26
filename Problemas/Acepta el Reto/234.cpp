#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases; cin>>cases;
    while(cases--)
    {
       int n,v; cin>>n>>v;
       int arr[n];
       for(int i=0; i<n;i++) cin>>arr[i];
       sort(arr,arr+n);
       int r = n-1,res=0;
       for(int i=0; i<n && i<r;i++)
            if(arr[i]+arr[r]>=v) { res++; r--; }
       cout<<res<<'\n';
    }
return 0;
}
