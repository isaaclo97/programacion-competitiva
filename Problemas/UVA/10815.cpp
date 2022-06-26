#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    string line;
    set<string> S;
    while(getline(cin,line))
    {
        if(line=="") continue;
        istringstream iss(line);
        vector<string> v((istream_iterator<string>(iss)),istream_iterator<string>());
        for(auto word:v)
        {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            string aux2;
            for(unsigned int i=0; i<word.length();i++) if(word[i]>='a'&&word[i]<='z') aux2+=word[i]; else { S.insert(aux2); aux2="";}
            if(aux2.length()>0) S.insert(aux2);
        }
    }
    for(auto word:S) if(word!="") cout<<word<<'\n';

    return 0;
}
