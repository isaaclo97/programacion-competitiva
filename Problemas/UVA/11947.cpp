#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

bool Bisiesto(int years){return years % 4 == 0 && !(years % 100 == 0 && years % 400 != 0);}
int dayss (int m, int y)
{
    if (m == 11 || m == 4 || m == 6 || m == 9) return 30;
    if (m == 2)  return 28 + Bisiesto (y);
    return 31;
}
int main () {
   int t, i=1, months, day, years;
   cin>>t;
   while(t--)
   {
     scanf("%2d%2d%4d", &months , &day, &years);

      for (int j = 0; j < 40; ++j) {
         int c = dayss(months, years);
         day = (day + 6) % c + 1;
         if (day < 8) {
            months = months % 12 + 1;
            if (months == 1) ++years;
       }
      }

      printf ("%d %02d/%02d/%04d ", i++, months, day, years % 10000);;

     if ((day>=21 && months==1)  || (day<=19 && months==2)) printf("aquarius\n");
     if ((day>=20 && months==2)  || (day<=20 && months==3)) printf( "pisces\n");
     if ((day>=21 && months==3)  || (day<=20 && months==4)) printf( "aries\n");
     if ((day>=21 && months==4)  || (day<=21 && months==5)) printf( "taurus\n");
     if ((day>=22 && months==5)  || (day<=21 && months==6)) printf( "gemini\n");
     if ((day>=22 && months==6)  || (day<=22 && months==7)) printf( "cancer\n");
     if ((day>=23 && months==7)  || (day<=21 && months==8)) printf( "leo\n");
     if ((day>=22 && months==8)  || (day<=23 && months==9)) printf( "virgo\n");
     if ((day>=24 && months==9)  || (day<=23 && months==10)) printf( "libra\n");
     if ((day>=24 && months==10) || (day<=22 && months==11)) printf( "scorpio\n");
     if ((day>=23 && months==11) || (day<=22 && months==12)) printf( "sagittarius\n");
     if ((day>=23 && months==12) || (day<=20 && months==1))  printf( "capricorn\n");
   }
}
