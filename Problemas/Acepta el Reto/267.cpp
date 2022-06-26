#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int l1,l2,dm;
    while(scanf("%d%d%d",&l1,&l2,&dm)==3 && (l1!=0 || l2!=0 || dm!=0))
    {
        int n=4;
        if (l1 > dm) {
            n += 2 * (l1 / dm);
            if (l1%dm == 0) n = n - 2;
        }

        if (l2 > dm){
            n += 2 * (l2 / dm);
            if (l2%dm == 0) n = n - 2;
        }
        printf("%d\n",n);
    }
    return 0;
}
