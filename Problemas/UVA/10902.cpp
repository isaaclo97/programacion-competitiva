#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
using namespace std;

struct point{
    double x,y;
    point(){x=y=0;}
    point(double _x,double _y){x=_x,y=_y;}
    point operator-(point a)
    {
    point r;
    r.x=x-a.x; r.y=y-a.y;
    return r;
    }
    point operator+(point a)
    {
    point r;
    r.x=x+a.x; r.y=y+a.y;
    return r;
    }
    point operator*(double sc)
    {
    point r;
    r.x=x*sc; r.y=y*sc;
    return r;
    }
};

int intersect( point p1, point p2, point p3, point p4)
{
    point r;
    double d = (p4.y - p3.y)*(p2.x-p1.x) - (p4.x - p3.x)*(p2.y - p1.y);
    if( fabs( d ) < EPS ) return 0;
    double ua;
    ua = (p4.x - p3.x)*(p1.y-p3.y) - (p4.y-p3.y)*(p1.x-p3.x);
    ua /= d;
    r = p1 + (p2-p1)*ua;
    //cout<<r.x<<" " << r.y<<'\n';
    if(min(p1.x,p2.x)<=r.x && max(p1.x,p2.x)>=r.x && min(p1.y,p2.y)<=r.y && max(p1.y,p2.y)>=r.y && min(p3.x,p4.x)<=r.x && max(p3.x,p4.x)>=r.x && min(p3.y,p4.y)<=r.y && max(p3.y,p4.y)>=r.y)
        return 1;
    return 0;
}

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        double x,y,x_,y_;
        vector<pair<point,point>> V;
        for(int i=0; i<n;i++)
        {
            scanf("%lf %lf %lf %lf",&x,&y,&x_,&y_);
            V.push_back({point(x,y),point(x_,y_)});
        }
        printf("Top sticks:");
        int res=0;
        for(int i=0; i<n;i++)
        {
            int flag=1;
            for(int j=i+1;j<n && flag==1;j++)
                if(intersect(V[i].first,V[i].second,V[j].first,V[j].second)) flag=0;
            if(flag==1 && res!=0) printf(",");
            if(flag==1) { res++; printf(" %d",i+1);}
        }
        printf(".\n");
    }
    return 0;
}
