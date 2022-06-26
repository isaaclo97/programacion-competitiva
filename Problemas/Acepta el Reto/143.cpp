#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n,aux;
    while(scanf("%d",&n)==1 && n!=-1)
    {
      stack<int> S; S.push(n);
      while(scanf("%d",&n)==1 && n!=-1) S.push(n);
      cin>>n;
      queue<int> Qaux;
      for(int i=0; i<n;i++) {
          cin>>aux; while(aux--) {Qaux.push(S.top());S.pop();}
          while(!Qaux.empty()) {S.push(Qaux.front()); Qaux.pop();}
      }
      cout<<S.top()<<'\n';
    }
    cin>>n;
    return 0;
}
