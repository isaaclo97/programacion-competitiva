#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define PI acos(-1.0)
using namespace std;

struct point { double x, y;   // only used if more precision is needed
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
  bool operator < (point other) const { // override less than operator
    if (fabs(x - other.x) > EPS)                 // useful for sorting
      return x < other.x;          // first criteria , by x-coordinate
    return y < other.y; }          // second criteria, by y-coordinate
  // use EPS (1e-9) when testing equality of two floating points
  bool operator == (point other) const {
   return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); }
};

int main()
{
    point p1,p2,p3,p4,p5;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y,&p4.x,&p4.y)==8)
    {
        if(p1==p3) {p5.x=p2.x-p1.x+p4.x; p5.y=p2.y-p1.y+p4.y; }
        else if(p1==p4) {p5.x=p2.x-p1.x+p3.x; p5.y=p2.y-p1.y+p3.y;}
        else if(p2==p3) {p5.x=p1.x-p2.x+p4.x; p5.y=p1.y-p2.y+p4.y;}
        else if(p2==p4) {p5.x=p1.x-p2.x+p3.x; p5.y=p1.y-p2.y+p3.y;}
        printf("%.3lf %.3lf\n",p5.x,p5.y);
    }
    return 0;
}
