#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 10e-8
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

double perimeter(double ab, double bc, double ca) {
  return ab + bc + ca; }

double area(double ab, double bc, double ca) {
  // Heron's formula, split sqrt(a * b) into sqrt(a) * sqrt(b); in implementation
  double s = 0.5 * perimeter(ab, bc, ca);
  return sqrt(s) * sqrt(s - ab) * sqrt(s - bc) * sqrt(s - ca); }

double rInCircle(double ab, double bc, double ca) {
  double per = perimeter(ab, bc, ca);
  if(per==0) return 0;
  return area(ab, bc, ca) / (0.5 * per); }


int main()
{
    double d1,d2,d3;
    while(scanf("%lf%lf%lf",&d1,&d2,&d3)==3)
    {
        printf("The radius of the round table is: %.3lf\n",rInCircle(d1,d2,d3));
    }
    return 0;
}
