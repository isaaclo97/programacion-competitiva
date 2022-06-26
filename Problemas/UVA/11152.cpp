#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 10e-8
#define PI acos(-1.0)
using namespace std;

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

double rCircumCircle(double ab, double bc, double ca) {
  return ab * bc * ca / (4.0 * area(ab, bc, ca)); }


int main()
{
    double d1,d2,d3;
    while(scanf("%lf%lf%lf",&d1,&d2,&d3)==3)
    {
       double violets = area(d1,d2,d3);
       double sunflowers = PI*pow(rCircumCircle(d1,d2,d3),2);
       double roses = PI*pow(rInCircle(d1,d2,d3),2);
       printf("%.4lf %.4lf %.4lf\n",sunflowers-violets,violets-roses,roses);
    }
    return 0;
}
