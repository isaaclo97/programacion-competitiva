#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        int total=0,h,h1,m1,m;
        for(int i=0; i<n;i++)
        {
            scanf("%d:%d-%d:%d",&h,&m,&h1,&m1);
            int aux1h=0,aux1m,aux2m,aux2h;
            aux1h=h; aux1m=m;
            aux2h=h1; aux2m=m1;
            while(1)
            {
                if(aux1h==aux2h&&aux1m==aux2m) break;
                total++;
                aux1m++;
                if(aux1m==60) { aux1m=0; aux1h++;}
                if(aux1h==24) aux1h=0;
            }
        }
        h=total/60;
        m=total-(total/60)*60;
        printf("%02d:%02d\n",h,m);
    }
    return 0;
}
