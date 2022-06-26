#include <bits/stdc++.h>
using namespace std;

double perimeter(double ab, double bc, double ca) {
  return ab + bc + ca; }
double getAngle(double a,double b,double c)
{
 return acos((a*a+b*b-c*c)/(2*a*b));
}
double area(double ab, double bc, double ca) {
  // Heron's formula, split sqrt(a * b) into sqrt(a) * sqrt(b); in implementation
  double s = 0.5 * perimeter(ab, bc, ca);
  return sqrt(s) * sqrt(s - ab) * sqrt(s - bc) * sqrt(s - ca); }

int main()
{
    double r,r1,r2; int cases; scanf("%d",&cases);
    while(cases--)
    {
        scanf("%lf%lf%lf",&r,&r1,&r2);
        double a=r+r1,b=r+r2,c=r1+r2;
        double ar =area(a,b,c); //total area from center
        double an1=getAngle(a,b,c);
        double an2=getAngle(a,c,b);
        double an3=getAngle(b,c,a);
        ar-=((r*r)*(an1/2.0));
        ar-=((r1*r1)*(an2/2.0));
        ar-=((r2*r2)*(an3/2.0));
        /*
        The area of a sector of a circle is 1/2 r*r angle,
        where r is the radius and angle the angle in radians
        subtended by the arc at the centre of the circle.
        */
        printf("%.6lf\n",ar);
    }
}
