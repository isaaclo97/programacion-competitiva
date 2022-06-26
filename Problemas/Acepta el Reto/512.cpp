#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        double n,n1; scanf("%lf%lf",&n,&n1);
        printf("%d\n",int(floor((n/(n+n1))*100)));
    }
    return 0;
}
