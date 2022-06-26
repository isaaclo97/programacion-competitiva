
#include <bits/stdc++.h>
using namespace std;
//1501 al 1600
int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int year; scanf("%d",&year);
        int siglo = year/100;
        if(year%100!=0) siglo++;
        printf("%d\n",siglo);
    }
    return 0;
}
