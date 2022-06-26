#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 0
#define PI acos(-1.0)
using namespace std;

struct point{
    long long int x,y;
    point(){x=y=0;}
    point(long long int _x,long long int _y){x=_x,y=_y;}
    bool operator <(point other) const{
           if (x!=other.x)return x<other.x;
           return y<other.y;
       }
};

int main()
{
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        long long int x,y;
        int n; scanf("%d",&n);
        vector<point> V;
        for(int i=0; i<n;i++)
        {
           scanf("%lld%lld",&x,&y);
           V.push_back(point(x,y));
        }
        sort(V.begin(),V.end());
        point res; res.x =  V[0].x + V[n-1].x ; res.y= V[0].y + V[n-1].y ;
        int flag=0;
        for(int i=1; i<n/2 && flag==0;i++)
        {
            if(!(V[i].x + V[n-i-1].x == res.x && V[i].y + V[n-i-1].y == res.y)) flag++;
        }
       if(flag==0) printf("yes\n");
       else printf("no\n");
    }
    return 0;
}
