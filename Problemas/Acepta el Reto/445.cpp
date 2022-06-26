#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

struct vec{
    int n1,n2;
};
int compare(vec a,vec b) {return a.n1<b.n1;}
int main()
{
    int cases;
    while(scanf("%d",&cases)==1)
    {
        int res = 0;
        priority_queue<int,vector<int>, greater<int>> PQ;
        vector<vec> V;
        for(int i=0; i<cases;i++) { vec aux; cin>>aux.n1>>aux.n2; V.push_back(aux);}
        sort(V.begin(),V.end(),compare);
        for(int i=0; i<cases;i++)
        {
            if(PQ.empty()) PQ.push(V[i].n2);
            else{
                while(!PQ.empty()&& (PQ.top()<=V[i].n1)) PQ.pop();
                PQ.push(V[i].n2);
            }
            res=max(res,(int)PQ.size());
        }
        cout<<res-1<<'\n';
    }
    return 0;
}
