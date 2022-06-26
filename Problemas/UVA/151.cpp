#include <bits/stdc++.h>
using namespace std;

int josephus(int num,int jump)
{
    int jos=1;
    for(int i=2; i<=num;i++)
    {
        jos=((jos+jump-1)%i)+1;
    }
    return jos;
}

int main()
{
   int a;
   while(scanf("%d",&a)==1 && a!=0)
   {
      for(int i=1; i<0x3f3f3f3f;i++)
      {
          int res = josephus(a-1,i)+1;
          if(res==13) { printf("%d\n",i); break;}
      }
   }
}
