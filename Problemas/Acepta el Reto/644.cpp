#include <bits/stdc++.h>
using namespace std;

int main(){
    int year;
    int M = 24;
    int N = 5;
    while(scanf("%d",&year)==1 && year!=0){
        int a = year%19;
        int b = year%4;
        int c = year%7;
        int d = (19*a+M)%30;
        int e = (2*b+4*c+6*d+N)%7;
        int fecha1 = (d+e+22);
        int fecha2 = (d+e-9);
        if(d+e<10) {
            printf("%d de marzo\n",fecha1);
        }
        else{
            if(fecha2==26) fecha2=19;
            if(fecha2==25 && d==28) fecha2=18;
            printf("%d de abril\n",fecha2);
        }
    }
    return 0;
}