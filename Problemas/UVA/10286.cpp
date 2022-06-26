#include <bits/stdc++.h>
#define PI acos(-1.0)
using namespace std;

int main()
{
    double d1,conv=sin(108*PI/180)/sin(63*PI/180); //radians = length
    while(scanf("%lf",&d1)==1)
        printf("%.10lf\n",d1*conv);
    return 0;
}
