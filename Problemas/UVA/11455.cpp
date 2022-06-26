#include <bits/stdc++.h>
using namespace std;

bool canFormQuadrangle(double a, double b, double c,double d) {
  return (a + b + c> d) && (a + c + d > b) && (b + c + d > a) && (a+b+d>c); }

int main()
{
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        double arr[4];
        scanf("%lf%lf%lf%lf",&arr[0],&arr[1],&arr[2],&arr[3]);
        sort(arr,arr+4);
        if((arr[0]==arr[1])&&(arr[2]==arr[3])&&(arr[0]==arr[2])) printf("square\n");
        else if(arr[0]==arr[1] && arr[2]==arr[3]) printf("rectangle\n");
        else if(canFormQuadrangle(arr[0],arr[1],arr[2],arr[3])) printf("quadrangle\n");
        else printf("banana\n");
    }
    return 0;
}
