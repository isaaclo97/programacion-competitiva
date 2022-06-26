#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2 && (n!=0||m!=0))
    {
       int arr[n];
       int res = 1,cnt = 0,actual=0;
       for(int i=0; i<n;i++) scanf("%d",&arr[i]);
       for(int i=0; i<n;i++)
       {
           for(int j=i; j<n;j++)
           {
               if(abs(arr[actual]-arr[j])<m)
               {
               cnt++;
               res = max (res,cnt);
               i=j;
               }
               else
               {
                 cnt--;
                 actual++;
                 i=j-1;
                 break;
               }
           }
       }
       printf("%d\n",res);
    }
    return 0;
}
