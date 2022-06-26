#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    string line,se;
    map<string,string> M;
    getline(cin,line);
    while(line!="")
    {
        stringstream ss(line);
        ss >> line>> se;
        M[se] = line;
        getline(cin, line);
    }
    while(cin>>line)
    {
        if(M[line]!="") cout<<M[line]<<"\n";
        else cout<<"eh\n";
    }
    return 0;
}
