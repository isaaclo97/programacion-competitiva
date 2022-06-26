#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main() {
    int a,res=0; cin>>a;
    string aux; cin>>aux;
    map<pair<char,char>,int> M;
    for(unsigned int i=1;i<aux.length();i++)
        M[make_pair(aux[i-1],aux[i])]++;
    pair<char,char> p;
    for(auto m:M)
    {
        if(m.second > res)
        {
        p = m.first; res=m.second;
        }
    }
    cout<<p.first<<p.second<<endl;
    return 0;
}


