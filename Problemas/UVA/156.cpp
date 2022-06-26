#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main(){
    string line,lineT;
    while(getline(cin,line))
    {
        if(line=="#") break;
        lineT+=line;
        lineT+=" ";
    }
    map<string,pair<int,int>> M;
    istringstream iss(lineT);
            vector<string> v((istream_iterator<string>(iss)),istream_iterator<string>());
            int i=0;
            for(auto word:v)
            {
                  transform(word.begin(), word.end(), word.begin(), ::tolower);
                  sort(word.begin(),word.end());
                  pair<int,int> aux = M[word];
                  M[word]=make_pair(aux.first+1, i);
                  i++;
            }
    vector<string> sol;
    for(auto ma:M)
    {
        if(ma.second.first==1) sol.push_back(v[ma.second.second]);
    }
    sort(sol.begin(),sol.end());
    for(auto s:sol)
    {
        cout<<s<<endl;
    }
 return 0;
}
