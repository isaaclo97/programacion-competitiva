#include <bits/stdc++.h>
#define PI acos(-1.0)
using namespace std;

int main()
{
    int n,T;
    while(scanf("%d%d",&n,&T)==2)
    {
        double r,t,x=0,y=0;
        for(int i=0; i<n;i++)
        {
            scanf("%lf %lf",&r,&t);
            double angle = T * PI * 2.0 / t;
            x += r * cos(angle); y += r * sin(angle);
            if(i==0) printf("%.4lf", sqrt(x * x + y * y));
            else printf(" %.4lf", sqrt(x * x + y * y));
        }
        printf("\n");
    }
    return 0;
}
