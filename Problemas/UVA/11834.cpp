#include <bits/stdc++.h>
using namespace std;

int main()
{
    double l,w,r,r1;
    while(scanf("%lf%lf%lf%lf",&l,&w,&r,&r1)==4 && (l!=0 || w!=0 || r!=0 || r1!=0))
    {
        int nl = l-r-r1;
        int nw = w-r-r1;
        int nr = r+r1;
        if(r*2>min(l,w) || r1*2>min(l,w)) printf("N\n");
        else if(nl*nl+nw*nw>=nr*nr) printf("S\n"); //diagonal distance more than r diagonal distance
        else printf("N\n");
    }
    return 0;
}
