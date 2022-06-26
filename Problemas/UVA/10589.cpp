#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;

int main()
{
    double a,x,y; int n;
    while(scanf("%d %lf",&n,&a)==2 && (n!=0 || a!=0))
    {
       int m = 0;
       for(int i = 0; i < n; i++) {
           scanf("%lf %lf", &x, &y);
           if(x*x+y*y <= a*a && (x-a)*(x-a)+y*y <= a*a &&  x*x+(y-a)*(y-a) <= a*a && (x-a)*(x-a)+(y-a)*(y-a) <= a*a)
               m++;
       }
       printf("%.5lf\n", (double)m*a*a/n);
   }
    return 0;
}
