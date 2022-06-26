#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    string line;
    while(getline(cin,line))
    {
        int n,cnt=0; cin>>n;
        if(n==0) break;
        char aux = line[0];
        int res[line.length()]; res[0]=cnt;
        for(unsigned int i=1; i<line.length();i++)
        {
            if(aux==line[i]) res[i]=cnt;
            else { aux=line[i]; cnt++; res[i]=cnt;}
        }
        for(int i=0; i<n;i++)
        {
            int a,b; cin>>a>>b;
            if(res[a]==res[b]) cout<<"SI\n";
            else cout<<"NO\n";
        }
        cout<<'\n'; cin.ignore();
    }
    return 0;
}
