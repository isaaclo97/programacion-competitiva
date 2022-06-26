#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases; cin>>cases; cin.ignore();
    while(cases--)
    {
        string n,m,n1,m1;
        getline(cin,n); getline(cin,m);
        for(unsigned int i=0; i<n.length();i++) if(n[i]==' ') continue; else n1+=tolower(n[i]);
        for(unsigned int i=0; i<m.length();i++) if(m[i]==' ') continue; else m1+=tolower(m[i]);
        int res = 0;
        for(unsigned int i=0; i<n1.length() && res<m1.length();i++) if(n1[i]==m1[res]) res++;
        if(res==m1.length()) cout<<"SI\n";
        else cout<<"NO\n";
    }
    return 0;
}
