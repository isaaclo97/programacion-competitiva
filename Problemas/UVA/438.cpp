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

double perimeter(double ab, double bc, double ca) {
  return ab + bc + ca; }

double area(double ab, double bc, double ca) {
  // Heron's formula, split sqrt(a * b) into sqrt(a) * sqrt(b); in implementation
  double s = 0.5 * perimeter(ab, bc, ca);
  return sqrt(s) * sqrt(s - ab) * sqrt(s - bc) * sqrt(s - ca); }

double rCircumCircle(double ab, double bc, double ca) {
  return ab * bc * ca / (4.0 * area(ab, bc, ca)); }

double rCircumCircle(point a, point b, point c) {
  return rCircumCircle(dist(a, b), dist(b, c), dist(c, a)); }
int main()
{
    double a,b,c,d,e,f;
    while(scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f)==6)
    {
        vector<point> V; V.push_back(point(a,b)); V.push_back(point(c,d)); V.push_back(point(e,f));
        double resu;
        resu = 2*PI*rCircumCircle(V[0],V[1],V[2]);
        printf("%.2lf\n",resu);
    }
    return 0;
}
