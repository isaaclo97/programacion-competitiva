#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,m,l,q,p,d,res=0; scanf("%lld%lld%lld",&n,&m,&l);
    long long int arr[n];
    for(int i=0; i<n;i++) scanf("%lld",&arr[i]);
    bool first=false;
    int memo[n]; memset(memo,0,sizeof(memo));
    for(int i=0; i<n;i++)
    {
        if(arr[i]>l && first) res--;
        else first=false;
        if(arr[i]>l) { first=true; res++; memo[i]=1; }
    }
    while(m--)
    {
        scanf("%lld",&q);
        if(q==0){
            printf("%lld\n",res);
        }
        else{
            scanf("%lld%lld",&p,&d);
            arr[p-1]+=d;
            if(arr[p-1]>l && memo[p-1]!=1)
            {
                memo[p-1]=1; res++;
                if(p!=n) { res-=memo[p]; }
                if(p!=1) { res-=memo[p-2];}
            }
        }
    }
    return 0;
}
