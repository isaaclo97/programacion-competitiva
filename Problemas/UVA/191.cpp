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



int intersect( PT p1, PT p2, PT p3, PT p4)
{
    PT r;
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

int main ()
{
    int cases; scanf("%d",&cases);
    while (cases--)
    {
        PT p1,p2,p3,p5,p4;
        scanf("%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y); // 4 9 11 2
        scanf("%lf%lf%lf%lf",&p3.x,&p3.y,&p5.x,&p5.y); // 1 5 7 1
        p4.x = p3.x; p4.y=p5.y; // 1 1 a 7 1
        bool res = intersect(p1,p2,p4,p5);
        res = res || intersect(p1,p2,p4,p3); //1 1 a 1 5
        p4.x = p5.x; p4.y = p3.y;
        res = res || intersect(p1,p2,p4,p3); // 7 5 a 7 1
        res = res || intersect(p1,p2,p4,p5); // 7 5 a 1 5
        res = res || (min(p3.x,p5.x)<=min(p1.x,p2.x) && max(p3.x,p5.x)>=max(p1.x,p2.x) && min(p3.y,p5.y)<=min(p1.y,p2.y) && max(p3.y,p5.y)>=max(p1.y,p2.y)); //inside
        if(res) printf("T\n");
        else printf("F\n");
    }
    return 0;
}
