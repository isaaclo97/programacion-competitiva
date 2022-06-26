#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  while(scanf("%d",&n)==1 && n!=0)
  {
    int res = 0;
    for (int i=1; i<=sqrt(n); i++)
      if (n%i == 0)
      if (n/i == i) res++;
      else  res+=2;
    cout<<res<<'\n';
  }
  return 0;
}
