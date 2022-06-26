#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
int cases,num,go;
string str;
cin>>cases;
while(cases--)
{
    map<int,int> M;
    vector<string> S;
    vector<int> POS;
    int n=10;
    while(scanf("%d",&num)==1 && num!=0)
    {
        cin>>str;
        M[num]=n; n+=10;
        if(str=="RETURN") { S.push_back(str); POS.push_back(-1);}
        else { cin>>go; S.push_back(str); POS.push_back(go);}
    }
    for(unsigned int i=0; i<S.size();i++)
    {
        if(POS[i]!=-1)
        POS[i]=M[POS[i]];
    }
    n=10;
    for(unsigned int i=0; i<S.size();i++)
    {
        if(POS[i]==-1) cout<<n<<" "<<S[i]<<'\n';
        else cout<<n<<" "<<S[i]<<" "<<POS[i]<<'\n';
        n+=10;
    }
    cout<<"---\n";
}
    return 0;
}
