#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 10-8
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
};

double dist(point p1, point p2) {                // Euclidean distance
  return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double

int circumCircle(point p1, point p2, point p3, point &ctr, double &r){
  double a = p2.x - p1.x, b = p2.y - p1.y;
  double c = p3.x - p1.x, d = p3.y - p1.y;
  double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
  double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
  double g = 2.0 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));
  if (fabs(g) < EPS) return 0;

  ctr.x = (d*e - b*f) / g;
  ctr.y = (a*f - c*e) / g;
  r = dist(p1, ctr);  // r = distance from center to 1 of the 3 points
  return 1; }

int main()
{
    double a,b,c,d,e,f;
    while(scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f)==6)
    {
        vector<point> V; V.push_back(point(a,b)); V.push_back(point(c,d)); V.push_back(point(e,f));
        point o;
        double r2;
        circumCircle(V[0],V[1],V[2],o,r2);
        r2 = (a-o.x)*(a-o.x)+(b-o.y)*(b-o.y);
        char c1, c2, c3;
        if(o.x >= 0)    c1 = '-';
        else    c1 = '+';
        if(o.y >= 0)    c2 = '-';
        else    c2 = '+';
        if(r2-o.x*o.x-o.y*o.y >= 0) c3 = '-';
        else    c3 = '+';
        printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n", c1, fabs(o.x), c2, fabs(o.y), sqrt(r2));
        printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n\n", c1, fabs(2*o.x), c2, fabs(2*o.y), c3, fabs(r2-o.x*o.x-o.y*o.y));
    }
    return 0;
}
