#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        double x,y,res=-1; int sol=0;
        for(int i=1; i<=n;i++)
        {
            scanf("%lf %lf", &x, &y);
            if (x < y) swap(x, y);
            double size = max((min(x, y) / 2), (min(x / 4, y)));
            if (size > res)
                res = size, sol = i;
            /*
            There are 3 different ways in which we could cut out the 4 squares: all in a row along the height,
            all in a row along the width, or in a 2x2 pattern.
            */
        }
        printf("%d\n",sol);
   }
    return 0;
}
