#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n,m;
    long long int arr[320];
    for(int i=1; i<=320;i++) arr[i]=i*i;
    while(scanf("%d%d",&n,&m)==2 && (n!=0 || m!=0))
    {
        int res=0;
        for(int i=1; i<=320;i++) { if(arr[i]>m) break; else if(arr[i]>=n) res++; }
        cout<<res<<'\n';
    }
    return 0;
}
