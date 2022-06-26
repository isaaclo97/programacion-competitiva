#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

struct node{
int w,t;
string name;
bool operator<(const node &o)const{
    if(w==o.w) return t<o.t;
    return w < o.w;
}
};

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        int ti;
        string pe,name;
        priority_queue<node> pq;
        for(int i=0; i<n;i++)
        {
            cin>>pe;
            if(pe == "I") { cin>>name>>ti; pq.push(node{ti,n-i,name}); }
            else{
                node aux = pq.top(); pq.pop();
                printf("%s\n",aux.name.c_str());
            }
        }
        printf("----\n");
    }
    return 0;
}
