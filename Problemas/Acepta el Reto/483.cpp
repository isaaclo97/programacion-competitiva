#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        int h,m,s,h1,m1,s1,camp,ne;
        scanf("%2d:%2d:%2d %2d:%2d:%2d",&h,&m,&s,&h1,&m1,&s1);
        scanf("%d%d",&camp,&ne);
        int total = h*3600 +m*60+s;
        int total1 = h1*3600+m1*60+s1;
        if(total>total1) total1+=24*3600;
        int res = abs(total-total1);
        int aux = res/(camp-1);
        ne--;
        aux *=ne;
        aux +=total;
        s = aux%60;
        m = (aux/60)%60;
        h = (aux/3600)%24;
        printf("%02d:%02d:%02d\n",h,m,s);
    }
    return 0;
}
