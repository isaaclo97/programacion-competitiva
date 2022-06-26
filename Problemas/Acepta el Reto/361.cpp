#include <bits/stdc++.h>
using namespace std;

int k;
int arr[5];

bool dp(int val, int cur)
{
    if(val==k && cur==5) return true;
    if(cur==5) return false;
    bool check = false;
    if(arr[cur]!=0 && val%arr[cur]==0) check = dp(val/arr[cur],cur+1);
    return check || dp(val+arr[cur],cur+1) || dp(val*arr[cur],cur+1) || dp(val-arr[cur],cur+1);
}
int main()
{
    while(scanf("%d",&k)==1)
    {
        for(int i=0; i<5;i++) scanf("%d",&arr[i]);
        if(dp(arr[0],1)) printf("SI\n");
        else printf("NO\n");
    }
    return 0;
}
