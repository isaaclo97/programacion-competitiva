#include <bits/stdc++.h>
using namespace std;

/*
Get triangle with the center points of circles (1 1 1), divide it by 2 (0.5 0.5 0.5),
then get the length of the triangle´s height (0.5 0.25 x) solve x, multiply by 2 and that is the "extra height"
*/
int skew(double x, double y){
    double diff = 1-0.13397459621556135323627682924706;
    if (y<1) return 0;
    int a = floor(x), b = floor((y-1)/diff)+1;
    if (x>=a+0.5) return a*b;
    if (b%2==0) return a*b/2+(a-1)*b/2;
    return a*(b+1)/2+(a-1)*(b-1)/2;
}

int main()
{
    double x,x1;
    while(scanf("%lf%lf",&x,&x1)==2)
    {
        int crew = floor(x)*floor(x1);
        int skewres = skew(x,x1); skewres=max(skewres,skew(x1,x));
        if(skewres>crew) printf("%d skew\n",skewres);
        else printf("%d grid\n",crew);
    }
}
