#include <bits/stdc++.h>
using namespace std;

int main()
{
    double h,m;
    while(scanf("%lf:%2lf",&h,&m)==2 && (h!=0 || m!=0))
    {
       h*=5;
       if (h < m) h += 60;
       double ans = (h - m + m / 12.0) * 6;
       ans = (ans > 180 ? 360 - ans : ans);
       printf("%.3lf\n", (ans >= 0 ? ans : -ans));
    }
    return 0;
}
