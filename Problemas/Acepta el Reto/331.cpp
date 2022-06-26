#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

struct state{
  int pos;
  string name;
};
bool ord(state a,state b)
{
    return a.pos<b.pos;
}
int main()
{
    int cases;
    while(scanf("%d",&cases)==1 && cases!=0)
    {
        int pos,flag=0; string name;
        vector<state> V;
        map<int,int> M;
        for(int i=0; i<cases;i++)
        {
            cin>>pos; getline(cin,name);
            V.push_back(state{pos+i+1,name});
            M[pos+i+1]++;
            if(M[pos+i+1]>1 || (pos+i+1)>26 || (pos+i+1)<1) flag=1;
        }
        if(flag==1) cout<<"IMPOSIBLE\n-----\n";
        else {
        sort(V.begin(),V.end(),ord);
        for(auto v:V)
            cout<<v.pos<<v.name<<'\n';
         cout<<"-----\n";
        }
    }
    return 0;
}
