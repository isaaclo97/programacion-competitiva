#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int cnt(int n)
{
    int di = 0;
    while (n > 0) {
        di++;
        n/=10;
    }
    return di;
}
int cntNum(int n)
{
    int d = cnt(n),p = 10, s = 1;
    if (n < 1) return 0;
    if (d == 1) return n;
    for (int i = 1; i <= d-2; i++) {
        s += p * (i+1);
        p *= 10;
    }
    return 9*s + d * (n-p+1);
}
int getCount(int ini,int fin)
{
    return cntNum(fin)-cntNum(ini-1);
}
int main()
{
    int ini,fin;
    while(scanf("%d%d",&ini,&fin)==2 && (ini!=0||fin!=0))
    {
        int i=ini,j=fin,m,mid=(getCount(ini,fin))/2;
        while(i<=j)
        {
           m = (i+j)/2;
           int d1 = getCount(ini,m);
           if(d1==mid) break;
           if(d1<mid) i = m+1;
           else j = m-1;
        }
        if(getCount(ini,m)>getCount(m+1,fin)) m--;
        printf("%d\n",m);
    }
    return 0;
}
