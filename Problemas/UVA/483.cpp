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
        int flag=1;
        for(auto word:v)
        {
              if(flag==0) cout<<' ';
              for(int i=word.length()-1; i>=0; i--) cout<<word[i];
              flag=0;
        }
        cout<<'\n';
    }
 return 0;
}

