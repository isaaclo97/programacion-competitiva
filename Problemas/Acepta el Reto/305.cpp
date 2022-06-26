#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        int arr1[n];
        int arr[n];
        for(int i=0; i<n;i++) cin>>arr1[i];
        for(int i=0; i<n;i++) cin>>arr[i];
        sort(arr,arr+n,greater<int>());
        sort(arr1,arr1+n,greater<int>());
        int res = 0,in=0;
        for(int i=0; i<n;i++)
          if(arr1[i]<=arr[in]) { res++; in++; }
        cout<<res<<'\n';
    }
return 0;
}
