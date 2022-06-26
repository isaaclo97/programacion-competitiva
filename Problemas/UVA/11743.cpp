#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
  int cases; cin>>cases; cin.ignore();
  while(cases--)
  {
     string credit; getline(cin,credit);
     vector<string> d;
     int n=0,sum=0,c=0;
     for(unsigned int i=0; i<credit.length();i++)
     {
         if(credit[i]==' ') continue;
         if(c%2==0)d.push_back(to_string((credit[i]-48)*2));
         else n+=(credit[i]-48);
         c++;
     }
     for(unsigned int i=0; i<d.size();i++)
     {
         string aux = d[i];
         for(unsigned int i=0; i<aux.length();i++) sum+=(aux[i]-48);
     }
     int res = sum+n;
     if(res%10==0) cout<<"Valid\n";
     else cout<<"Invalid\n";
  }
  return 0;
}
