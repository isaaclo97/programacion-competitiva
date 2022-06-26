#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n,d,cases; cin>>cases;
    while(cases--)
    {
        vector<string> vec;
        string name;
        while(1) { cin>>name; if(name.length()==1 && name[0]=='F') break; vec.push_back(name); }
        cin>>n>>d;
        int cnt = 0; d--;
        int l = vec.size();
        if (n>=l){ cout<<"TODOS TIENEN CAMA\n"; continue; }
        if(n==0) { cout<<"NADIE TIENE CAMA\n"; continue;}
        while(l!=n)
        {
             cnt += d;
             cnt=cnt%l;
             vec.erase(vec.begin() + cnt);
             l--;
        }
        int flag= 0;
        for(auto v:vec) if(flag==0) { cout<<v; flag=1; } else cout<<' '<<v;
        cout<<'\n';
    }
    return 0;
}
