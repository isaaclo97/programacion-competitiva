#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
   int n; char c;
   while(scanf("%d",&n)==1)
   {
       cin>>c;
       if(n==0 && c=='0') break;
       int mi=n+(n-1)*2-(n-1);
       int mj=(n-1)*2-(n-1);
       for(int i=0; i<(n-1)*2+1;i++)
       {
           for(int j=0; j<n+(n-1)*2;j++)
           {
               if(j<mj) cout<<' ';
               else if(j>=mi) break;
               else cout<<c;
           }
           cout<<'\n';
           if(i<n-1) { mj--; mi++;}
           else {mj++; mi--;}
       }
   }
   return 0;
}
