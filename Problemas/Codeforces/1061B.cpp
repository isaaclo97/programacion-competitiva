#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,s, c=0;
    scanf("%lld%lld",&n,&s);
    int arr[n]; s=0;
    for(int i=0;i<n;i++) {scanf("%d",&arr[i]); s+=arr[i]; }
    sort(arr,arr+n);
    for(int i=0;i<n;i++)c+=arr[i]>c;
    printf("%lld",s-n-arr[n-1]+c); //total blocks - number of blocks top - number of block rigth + blocks
    return 0;
}
