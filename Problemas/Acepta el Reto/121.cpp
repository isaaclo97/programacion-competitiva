#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main()
{
    long long int ch,en,to,res;
    while(scanf("%lld%lld%lld",&ch,&en,&to)==3&&ch+en+to)
    {
        res=to;
        if(ch<=en && to>=ch)  printf("RUINA\n");
        else if(en==0) printf("%lld %lld\n",res,to);
        else
        {
            while(to>=ch)
            {
                int var = to/ch;
                res+=(var*en);
                to=(var*en+to%ch);
            }
            printf("%lld %lld\n",res,to);
        }
    }
    return 0;
}
