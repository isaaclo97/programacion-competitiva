#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
using namespace std;

struct point{
    double x,y;
    point(){x=y=0;}
    point(double _x,double _y){x=_x,y=_y;}
};

double cross(point o, point a, point b) {
    return (a.x-o.x)*(b.y-o.y) - (a.y-o.y)*(b.x-o.x);
}
bool cmp(point a,point b){
    if(a.y!=b.y) return a.y<b.y;
    return a.x<b.x;
}
vector<point> CH(vector<point> P){
    vector<point> res;
    sort(P.begin(),P.end(),cmp);
    int n = P.size();
    int m=0;
    for (int i=0;i<n;i++){
        while (m>1&&cross(res[m-2], res[m-1], P[i]) <= 0)res.pop_back(),m--;
        res.push_back(P[i]),m++;
    }
    for (int i = n-1, t = m+1; i >= 0; i--) {
        while (m>=t&&cross(res[m-2], res[m-1], P[i]) <= 0)res.pop_back(),m--;
        res.push_back(P[i]),m++;
    }
    return res;
}


int main()
{
    int n,cases;
    while(scanf("%d",&cases)==1)
    {
        printf("%d\n",cases);
        while(cases--)
        {
            scanf("%d",&n);
            vector<point> V;
            double x,y;
            for(int i=0; i<n;i++)
            {
                scanf("%lf%lf",&x,&y);
                V.push_back(point(x,y));
            }
            V = CH(V);
            printf("%d\n",V.size());
            for(auto v:V)
            {
                printf("%.0lf %.0lf\n",v.x,v.y);
            }
            if(cases!=0) printf("-1\n");
            scanf("%d",&n);
        }
    }
    return 0;
}
