#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

struct node{
  int code,seconds;
  bool operator<(const node &other)const{
      if(other.seconds==seconds) return other.code<code;
      return other.seconds < seconds;
  }
};

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        int val,pos;
        priority_queue<node> pq;
        map<int,int> M;
        for(int i=0; i<n;i++) { scanf("%d%d",&val,&pos); pq.push(node{val,pos}); M[val]=pos;}
        int query; scanf("%d",&query);
        for(int i=0; i<query;i++)
        {
            node res = pq.top(); pq.pop();
            pq.push(node{res.code,M[res.code]+res.seconds});
            printf("%d\n",res.code);
        }
        printf("----\n");
    }
    return 0;
}
