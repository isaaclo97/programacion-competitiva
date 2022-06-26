#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        int arr[n];
        for(int i=0; i<n;i++) cin>>arr[i];
        int res=1;
        int M = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > M) {
                res++;
                M = arr[i];
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}
