#include <bits/stdc++.h>
using namespace std;

int main()
{
    double r,n;
    while(scanf("%lf%lf",&r,&n)==2)
        printf("%.3lf\n",r*r*n*sin(2*acos(-1)/n)/2); //area of polygon with circumradio (r*r*n*sin(360/n))/2;
    return 0;
}
