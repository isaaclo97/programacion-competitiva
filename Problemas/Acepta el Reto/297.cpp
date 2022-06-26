#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        long long int r; string m;
        long long int total =0;
        while(scanf("%lld",&r)==1 && r!=0)
        {
            cin>>m;
            if(m=="o") total+=r;
            else if(m=="da") total+=(r*10);
            else if(m=="h") total+=(r*100);
            else if(m=="k") total+=(r*1000);
            else if(m=="M") total+=(r*1000000);
            else if(m=="G") total+=(r*1000000000);
        }
        if ((total/ 1000000000) * 1000000000 == total) printf("%lld %s\n", total/ 1000000000, "G");
        else if ((total/ 1000000) * 1000000 == total) printf("%lld %s\n", total/ 1000000, "M");
        else if ((total/ 1000) * 1000 == total) printf("%lld %s\n", total/ 1000, "k");
        else if ((total/ 100) * 100 == total) printf("%lld %s\n", total/ 100, "h");
        else if ((total/ 10) * 10 == total) printf("%lld %s\n", total/ 10, "da");
        else printf("%lld %s\n", total, "o");
    }
    return 0;
}
