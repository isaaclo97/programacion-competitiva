#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int i,start,a,b;
     int A[301];
     cin>>i;
     while(i--)
     {
     cin>>start;
     memset(A,0,sizeof(A));
       while(scanf("%d%d",&a,&b) && (a!=-1 && b!=-1)){
         A[a]++;
         A[b]++;
       }
       bool flag=true;
       for(int k=0;k<301&&flag;k++)
         if(A[k]%2==1) flag=false;
       if(flag) cout<<"YES\n";
       else cout<<"NO\n";
     }
    return 0;
}
