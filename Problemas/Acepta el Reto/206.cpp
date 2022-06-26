#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        double low,d,la,lb;
        scanf("%lf",&d);
        low = 2*d;
        for(la=d-1;la>=0;la--){
            lb = sqrt(d*d-la*la);
            if((int)lb == lb) { low = lb+la; break;}
        }
        printf("%d\n",(int)low);
    }
    return 0;
}
