#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
 int n,m,cases=1;
 while(scanf("%d%d",&n,&m)==2 && (n!=0 || m!=0))
 {
    int arr[n];
    int query;
    for(int i=0; i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    printf("CASE# %d:\n",cases++);
    for(int i=0; i<m;i++)
    {
        cin>>query;
        int flag=1;
        for(int i=0; i<n;i++)
        {
            if(arr[i]==query) { printf("%d found at %d\n",query,i+1); flag=0; break;}
            else if(arr[i]>query) {   printf("%d not found\n",query); flag=0; break;}
        }
        if(flag==1) printf("%d not found\n",query);
    }
 }
 return 0;
}
