#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    while(getline(cin,n))
    {
        for(unsigned int i=0; i<n.length();i++) if(i!=n.length()-1) cout<<n[i]<<"0"; else cout<<n[i];
        cout<<'\n';
    }
    return 0;
}
