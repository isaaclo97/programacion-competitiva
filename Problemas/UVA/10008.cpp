#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

bool so(pair<char,int> A,pair<char,int> B)
{
    if(A.second==B.second) return A.first<B.first;
    return A.second>B.second;
}
int main()
{
    int n; cin>>n; cin.ignore();
    map<char,int> M;
    while(n--)
    {
        string line;
        getline(cin,line);
        for(unsigned int i=0; i<line.length(); i++)
           if(toupper(line[i])<='Z' && toupper(line[i])>='A')  M[toupper(line[i])]++;
    }
    vector<pair<char,int>> V;
    for(auto m:M)
       V.push_back(make_pair(m.first,m.second));
    sort(V.begin(),V.end(),so);
    for(auto v:V)
       cout<<v.first<<" "<<v.second<<'\n';
 return 0;
}

