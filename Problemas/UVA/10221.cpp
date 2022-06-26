#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;

double DEG_to_RAD(double d) { return d * PI / 180.0; }

int main()
{
    double s,a,arc; char st[4];
    while(scanf("%lf %lf %s",&s,&a,st)==3)
    {
       if(st[0]=='m') arc = a/=60;
       if(a > 180) a = 360-a;
       s += 6440; arc = s*DEG_to_RAD(a);
       double d= 2*sqrt(s*s-pow(s*cos(a/360*PI), 2));
       printf("%.6lf %.6lf\n", arc,d);
   }
    return 0;
}
