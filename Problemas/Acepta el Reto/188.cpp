#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
string line;
while(getline(cin,line))
{
    istringstream iss(line);
    vector<string> v((istream_iterator<string>(iss)),istream_iterator<string>());
    bool flag = true;
    int f=1;
    char a,b;
    for(auto word:v)
    {
       if(f==1){ f=2; a=word[word.length()-1]; b=word[word.length()-2]; continue;}
       if(a!=word[1] || b!=word[0]) flag=false;
       if(flag==false) break;
       a=word[word.length()-1]; b=word[word.length()-2];
    }
    if(flag) cout<<"SI\n";
    else cout<<"NO\n";
}
  return 0;
}
