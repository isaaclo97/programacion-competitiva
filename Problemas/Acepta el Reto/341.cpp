#include <bits/stdc++.h>
using namespace std;

struct state{
    int val;
    int index;
    bool operator<(const state &other)const{
        if(val==other.val) return index>other.index;
        return val > other.val;
    }
};
int main()
{
    int n,m,V;
    while(scanf("%d%d",&n,&m)==2)
    {
        priority_queue<state> PQ;
        for(int i=0; i<n;i++)  PQ.push(state{0,i+1});
        for(int i=0; i<m;i++)
        {
           cin>>V;
           state aux = PQ.top(); PQ.pop(); aux.val+=V; PQ.push(aux);
        }
        state aux = PQ.top();
        cout<<aux.index<<'\n';
    }
return 0;
}
