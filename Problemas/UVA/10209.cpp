#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;

int main()
{
    double a;
    while(scanf("%lf",&a)==1)
    {
        double x, y, z;
        z = a*a - a*a*PI/4;
        z -= a*a*PI/4 - a*a*PI/6 - ( a*a*PI/6 - a*a*sqrt(3.0)/4 );
        y = a*a - a*a*PI/4 - 2*z;
        x = a*a - 4*y - 4*z;
        printf("%.3lf %.3lf %.3lf\n", x, 4*y ,4*z);
        //https://www.mathalino.com/reviewer/plane-geometry/01-arcs-quarter-circle
        //https://www.mathalino.com/reviewer/plane-geometry/02-area-common-arcs-quarter-circles
    }
    return 0;
}
