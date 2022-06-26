#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int ini,n;
    while(scanf("%d%d",&ini,&n)==2)
    {
        int h;
        int res = 0;
        long long int mul = 1;
        for(int i=0; i<n;i++)
        {
            scanf("%d",&h);
            if(n%2==0)
            {
                if(i==n/2) { mul = 78787 - (26262*mul)%78787; res = (res + (ini*h*mul)%78787) % 78787; mul = 78787 - (26262*mul)%78787;}
                else if(i<n/2) { res = (res + (ini*h*mul)%78787) % 78787;  mul = (mul*3) % 78787;}
                else { res = (res + (ini*h*mul)%78787) % 78787;  mul = 78787 - (26262*mul)%78787; }
            }
            else
            {
                if(i<n/2) { res = (res + (ini*h*mul)%78787) % 78787; mul = (mul*3) % 78787;}
                else { res = (res + (ini*h*mul)%78787) % 78787; mul = 78787 - (26262*mul)%78787; }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
