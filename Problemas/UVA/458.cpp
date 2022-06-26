#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    string line;
    while(getline(cin,line))
    {
        string aux="";
        for(unsigned int i=0; i<line.length();i++) aux+=(line[i]-7);
        cout<<aux<<'\n';
    }
    return 0;
}
