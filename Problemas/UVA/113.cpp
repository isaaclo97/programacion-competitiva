#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    double x,n;
    while(scanf("%lf%lf",&n,&x)==2)
    {
        printf("%.0lf\n",pow(x,1.0/n));
    }
    return 0;
}

