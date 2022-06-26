#include <bits/stdc++.h>
using namespace std;

bool canFormTriangle(double a, double b, double c) {
  return (a + b > c) && (a + c > b) && (b + c > a); }

int main()
{
    int cases; scanf("%d",&cases);
    double d1,d2,d3;
    while(cases--)
    {
       scanf("%lf%lf%lf",&d1,&d2,&d3);
       if(canFormTriangle(d1,d2,d3)) printf("OK\n");
       else printf("Wrong!!\n");
    }
    return 0;
}
