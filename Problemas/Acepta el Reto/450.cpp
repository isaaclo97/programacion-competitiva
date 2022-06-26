#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
    {
        int arr1[a];
        int arr2[b];
        for(int i=0; i<a;i++) cin>>arr1[i];
        for(int i=0; i<b;i++) cin>>arr2[i];
        int res = INF, n=INF,count=0,resaux=0;
        for(int i=0; i<b;i++)
        {
            if(count==1 && arr1[0]==arr2[i]) resaux=0;
            else if(count!=0 && arr1[0]==arr2[i] && n==INF) n=i;
            if(arr1[count]==arr2[i]) { if(count==0) resaux=0; count++; }
            resaux++;
            if(res<=resaux && n!=INF) { count=0; i=n-1; n=INF;}
            if(count==a) { res=min(res,resaux); count=0; if(n!=INF) i=n-1; n=INF;}
        }
        cout<<res<<'\n';
    }
}
