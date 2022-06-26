#include <bits/stdc++.h>
using namespace std;

struct state{
  int tropasN,quedan;
  bool operator<(const state &other)const{
      if(quedan == other.quedan) return tropasN<other.tropasN;
      return quedan < other.quedan;
  }
};
int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
         int s,b,r,auxi= 0,res = 0;
         priority_queue<state> pq;
         for(int i=0; i<n;i++)
         {
             cin>>s>>b>>r;
             s=max(s,b+r);
             if(s<=(b+r)) b=0;
             else b=s-b-r;
             pq.push(state{s,b});
         }
         while(!pq.empty())
         {
            state aux = pq.top(); pq.pop();
            if(auxi<aux.tropasN) { res+=(aux.tropasN-auxi); auxi=aux.quedan;}
            else { auxi-=aux.tropasN; auxi+=aux.quedan;}
         }
         cout<<res<<'\n';
    }
    return 0;
}
