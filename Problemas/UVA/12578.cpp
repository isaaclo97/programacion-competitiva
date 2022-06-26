#include <bits/stdc++.h>
#define PI acos(-1.0)
using namespace std;

int main()
{
    int cases; scanf("%d",&cases);
    while(cases--)
    {
      double W,H,R; scanf("%lf",&W);
      R=W/5; H=(W*6)/10;
      double AR = W*H;
      double AC = PI * R * R;
      printf("%.2lf %.2lf\n", AC, AR-AC);
    }
    return 0;
}
