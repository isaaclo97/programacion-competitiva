#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

struct Date{
    int d, m, y;
};

long long int getDifference(Date dt1, Date dt2)
{
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long long int n1 = dt1.y*365 + dt1.d;
    for (int i=0; i<dt1.m - 1; i++)  n1 += month[i];
    long long int n2 = dt2.y*365 + dt2.d;
    for (int i=0; i<dt2.m - 1; i++) n2 += month[i];
    return (n2 - n1);
}

int main()
{
    int d1,d2,m1,m2,an1,an2;
    while(scanf("%d%d%d%d%d%d",&d1,&m1,&an1,&d2,&m2,&an2) == 6 && (d1!=0 || d2!=0 || m1!=0 || m2 !=0 || an1 != 0 || an2 !=0 ))
    {
          long long int res = 0;
          Date dt1 = {d1, m1, an1};
          Date dt2 = {d2, m2, an2};
          if(!(d1==d2 && m1 == m2))
          {
              res = getDifference(dt1, dt2);
              res-=(an2-an1-1);
              if((d2>d1 && m2==m1)|| m2>m1) res--;
          }
          printf("%lld\n",res);
    }
    return 0;
}
