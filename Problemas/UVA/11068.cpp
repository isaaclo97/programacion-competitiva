#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 0
#define PI acos(-1.0)
using namespace std;

struct point{
    double x,y;
    point(){x=y=0;}
    point(double _x,double _y){x=_x,y=_y;}
};
struct line { double a, b, c; };          // a way to represent a line

bool areIntersect(line l1, line l2, point &p) {
    int den = l1.a*l2.b - l1.b*l2.a;
    if(!den) return false; //paralelo o la misma linea
    p.x = l1.c*l2.b - l1.b*l2.c;
    if(p.x)  p.x /= den;
    p.y = l1.a*l2.c - l1.c*l2.a;
    if(p.y)  p.y /= den;
    return true;
}

int main()
{
    double a,b,c,a1,b1,c1;
    while(scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&a1,&b1,&c1)==6 && (a!=0 || b!=0 || c!=0 || a1!=0 || b1!=0 || c1!=0))
    {
        line l1; l1.a=a; l1.b=b; l1.c=c;
        line l2; l2.a=a1; l2.b=b1; l2.c=c1;
        point res;
        if(areIntersect(l1,l2,res)) printf("The fixed point is at %.2lf %.2lf.\n",res.x,res.y);
        else printf("No fixed point exists.\n");
    }
    return 0;
}
