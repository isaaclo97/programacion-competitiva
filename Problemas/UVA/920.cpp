#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 1e-18
#define PI acos(-1.0)
using namespace std;

struct point{
    double x,y;
    point(){x=y=0;}
    point(double _x,double _y){x=_x,y=_y;}
    bool operator <(point other) const{
           if (fabs(x-other.x)>EPS)return x<other.x;
           return y<other.y;
       }
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
struct line { double a, b, c; };          // a way to represent a line

void pointsToLine(point p1, point p2, line &l) {
 if (fabs(p1.x - p2.x) < EPS) {              // vertical line is fine
   l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;           // default values
 } else {
   l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
   l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
   l.c = -(double)(l.a * p1.x) - p1.y;
} }
double dist(point p1, point p2) {                // Euclidean distance
  return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double
point sol;
int intersect( point p1, point p2, point p3, point p4)
{
    point r;
    double d = (p4.y - p3.y)*(p2.x-p1.x) - (p4.x - p3.x)*(p2.y - p1.y);
    line l1,l2; pointsToLine(p1,p2,l1); pointsToLine(p3,p4,l2);
    if( fabs( d ) < EPS && fabs(l1.c - l2.c) < EPS) return 3;
    if( fabs( d ) < EPS ) return 2;
    double ua;
    ua = (p4.x - p3.x)*(p1.y-p3.y) - (p4.y-p3.y)*(p1.x-p3.x);
    ua /= d;
    r = p1 + (p2-p1)*ua;
    sol = r;
    //cout<<r.x<<" " << r.y<<'\n';
    return 1;
}

int main()
{
    int n,cases; scanf("%d",&cases);
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
        sort(V.begin(),V.end());
        point mini = V[n-1];
        double res = 0;
        for(int i=V.size()-1;i>=0;i--)
        {
            if(mini.y<V[i].y)
            {
                //printf("%.3lf %.3lf\n",V[i].x, V[i].y);
                intersect(V[i],V[i+1],mini,point(0,mini.y));
                res+=dist(V[i],sol);
                mini=V[i];
            }
        }
        printf("%.2lf\n",res);
    }
    return 0;
}
