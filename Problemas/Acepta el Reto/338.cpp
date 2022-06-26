#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
      map<int,int> Maux;
      map<int,int> M;
      queue<int> Q;
      int val,res=0,res1=0,num=0;
      for(int i=0; i<n;i++)
      {
          cin>>val;
          M[val]++;
          Maux[val]++;
          if(Maux[val]>1) res++;
          num++;
          if(num>m) { num--; Maux[Q.front()]--; Q.pop();}
          Q.push(val);

      }
      for(auto m:M) if(m.second>1) res1+=(m.second-1);
      printf("%d %d\n",res1,res);
    }
return 0;
}
