#include <bits/stdc++.h>
using namespace std;

struct state{
  int inver,con;
};

bool comp(state a, state b)
{
    if(a.inver==b.inver) return a.con>b.con;
    return a.inver>b.inver;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0){
        int inver,con;
        vector<state> V;
        for(int i=0; i<n;i++){
           scanf("%d %d",&inver,&con); V.push_back({inver,con});
        }
        sort(V.begin(),V.end(),comp);
        int cur = V[0].inver,ben,flag=1,i=1;
        ben = V[0].con;
        while(i<n && V[i].inver==cur)
           i++;
        if(i<n){
            cur=V[i].inver;
            ben=V[i-1].con;
            if(V[i].con>=ben) flag=0;
        }
        for(; i<n && flag==1;i++){
            while(V[i].inver==cur && i<n)
                i++;
            if(i<n) cur=V[i].inver;
            ben=min(ben,V[i-1].con);
            if(i<n && V[i].con>=ben) flag=0;
        }
        if(flag==1) printf("SI\n");
        else printf("NO\n");
    }
    return 0;
}
