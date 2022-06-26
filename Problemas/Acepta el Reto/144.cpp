#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    string line;
    while(getline(cin,line))
    {
       string res = "";
       int cnt = 0;
       for(unsigned int i=0; i<line.length();i++)
       {
            if(line[i]=='-') {cnt=0;}
            else if(line[i]=='+') {cnt=res.length();}
            else if(line[i]=='*') {if(res.length()>cnt) cnt++;}
            else if(line[i]=='3') { int to = res.length(); if(cnt>=to) continue; string resu = res.substr(0,cnt);  res=res.substr(cnt+1,to); res=resu+res;}
            else  {  int to = res.length();  string resu = res.substr(0,cnt);  res=res.substr(cnt,to); res=resu+line[i]+res; cnt++; }
       }
       cout<<res<<'\n';
    }
    return 0;
}
