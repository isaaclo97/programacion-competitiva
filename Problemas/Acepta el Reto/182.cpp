#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
int cases; cin>>cases;
while(cases--)
{
    int c=0;
    string s; cin>>s;
    while(s.length()>1)
    {
        int sum=1;
        for(unsigned int i=0; i<s.length();i++) sum*=(s[i]-48);
        s = to_string(sum);
        c++;
    }
    cout<<c<<endl;
}
  return 0;
}
