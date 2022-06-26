#include <bits/stdc++.h>
using namespace std;
bool wayToSort(int i, int j) { return i > j; }
int main()
{
 long long int n,l;
  cin>>n>>l;
      while(n!=0&&l!=0)
      {
          long long int ar[l];
          long long int resul=0,cont=0;
         for(long long int i=0; i<l;i++)
         {
             cin>>ar[i];
         }
         sort(ar,ar+l,wayToSort);
         for(long long int i=0; i<l-resul;i++)
         {
             if(ar[i]>n)
             {
                 cont++;
                 continue;
             }
             if((ar[i]+ar[l-resul-1])<=n)
                 resul++;
             else
                 cont++;
         }
             cout<<resul+cont<<endl;
          cin>>n>>l;
     }
    return 0;
}
