#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

const double PI = 2.0*acos(0.0);
const double EPS = 1e-9; //too small/big?????

struct PT{
    double x,y;
    double length() {return sqrt(x*x+y*y); }
   int normalize()
     {
     double l = length();
     if(fabs(l)<EPS) return -1;
     x/=l; y/=l;
     return 0;
     }
     PT operator-(PT a)
     {
     PT r;
     r.x=x-a.x; r.y=y-a.y;
     return r;
     }
     PT operator+(PT a)
     {
     PT r;
     r.x=x+a.x; r.y=y+a.y;
     return r;
     }
     PT operator*(double sc)
     {
     PT r;
     r.x=x*sc; r.y=y*sc;
     return r;
     }
};
struct line { double a, b, c; };          // a way to represent a line

void pointsToLine(PT p1, PT p2, line &l) {
  if (fabs(p1.x - p2.x) < EPS) {              // vertical line is fine
    l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;           // default values
  } else {
    l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
    l.c = -(double)(l.a * p1.x) - p1.y;
} }

PT sol;

int intersect( PT p1, PT p2, PT p3, PT p4)
{
    PT r;
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

int main ()
{
    int cases; scanf("%d",&cases);
    printf("INTERSECTING LINES OUTPUT\n");
    while (cases--)
    {
        PT p1,p2,p3,p4;
        scanf("%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y);
        scanf("%lf%lf%lf%lf",&p3.x,&p3.y,&p4.x,&p4.y);
        int res = intersect(p1,p2,p4,p3);
        if(res==2) printf("NONE\n");
        else if(res==1) printf("POINT %.2lf %.2lf\n",sol.x,sol.y);
        else printf("LINE\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
