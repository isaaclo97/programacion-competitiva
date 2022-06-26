#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a,b,cases=0;
  while(scanf("%d",&a)!=EOF)
  {
      if (cases++)	puts("");
      cin>>b;
      int vals[60];
      memset(vals,0,sizeof(vals));
      for(int i=1; i<=a;i++)
          for(int j=1;j<=b;j++)
          {
              vals[i+j]++;
          }
      int maximo =0;
      for(int i=1;i<=a+b;i++)
          maximo=max(maximo,vals[i]);
      for(int i=1;i<=a+b;i++)
          if(maximo==vals[i])
              cout<<i<<endl;
  }
  return 0;
}
