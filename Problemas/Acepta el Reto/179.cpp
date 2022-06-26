#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
   int n;
   while(scanf("%d",&n)==1 && n!=0)
   {
       int arr[n+1]; arr[0]=0;
       for(int i=1;i<=n;i++) { cin>>arr[i]; arr[i]+=arr[i-1];}
       int m,ini,fin; cin>>m;
       for(int i=0; i<m;i++)
       {
           cin>>ini>>fin;
           cout<<arr[fin]-arr[ini-1]<<'\n';
       }
   }
   return 0;
}
