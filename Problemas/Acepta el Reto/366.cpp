#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

struct node{
int w,t;
bool operator<(const node &o)const{
    if(w==o.w) return t>o.t;
    return w < o.w;
}
};

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        int pu,re;
        priority_queue<node> pq;
        for(int i=0; i<n;i++)
        {
            scanf("%d %d",&pu,&re);
            pq.push(node{pu,re});
        }
        while(!pq.empty())
        {
            node aux = pq.top(); pq.pop();
            printf("%d %d\n",aux.w,aux.t);
        }
        printf("\n");
    }
    return 0;
}
