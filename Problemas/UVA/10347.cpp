#include <bits/stdc++.h>
#define EPS 10e-8
using namespace std;

int main()
{
    double d1,d2,d3;
    while(scanf("%lf%lf%lf",&d1,&d2,&d3)==3)
    {
	//Heron Theorem 4/3 with medians
        double res = (d1+d2+d3)/2;
        res=(res-d1)*(res-d2)*(res-d3)*res;
        if(res<EPS) printf("-1.000\n");
        else printf("%.3lf\n",sqrt(res)*4/3);
    }
    return 0;
}
