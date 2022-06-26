#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,on,off,res=0,k,num;
    scanf("%d",&n); on=n; off=0;
    bool arr[n+1];
    memset(arr,true,sizeof(arr));
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d",&num);
        for(int i=num; i<=n; i+=num)
        {
            if(arr[i-1]) { off++; on--; arr[i-1]=false;}
            else {off--; on++; arr[i-1]=true;}
        }
        res = max(off,res);
    }
    printf("%d\n",res);
    return 0;
}
