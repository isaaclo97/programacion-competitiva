#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
   int n; cin>>n; cin.ignore();
   while(n--)
   {
       int cnt=0,h=0;
       string line;
       map<string,int> M;
       while(getline(cin,line))
       {
           if(line=="====") break;
           string res = "";
           for(unsigned int i=0; i<line.length();i++) { if(line[i]==',') break; res+=tolower(line[i]); }
           cnt++;
           M[res]++;
       }
       for(auto m:M) if(m.second>1) h+=m.second;
       cout<<cnt<<" "<<h<<'\n';
   }
   return 0;
}
