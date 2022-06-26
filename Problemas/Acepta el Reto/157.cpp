#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n; cin>>n;
    while(n--)
    {
       int d,m; cin>>d>>m;
       int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
       int T = arr[m-1]-d;
       for(int i=m;i<12;i++) T+=arr[i];
       cout<<T<<'\n';
    }
    return 0;
}
