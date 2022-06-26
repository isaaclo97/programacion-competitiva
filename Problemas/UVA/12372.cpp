#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases = 1,a,b,c,number=1;
    cin>>cases;
    while(cases+1!=number)
    {
      cin>>a>>b>>c;
      if(a<=20 && b<=20 && c<=20)
          cout<<"Case "<< number <<": "<<"good\n";
      else
          cout<<"Case "<< number <<": "<<"bad\n";
          number++;
    }
return 0;
}
