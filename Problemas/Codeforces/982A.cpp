#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; string s;
    cin>>n>>s;
    s="0"+s+"0";
    if (s.find("000")==-1 && s.find("11")==-1) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
