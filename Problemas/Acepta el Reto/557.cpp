
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        long long int n,t,m,d,i; scanf("%lld %lld %lld %lld %lld",&n,&t,&m,&d,&i);
        long long int tiempoLargos = n*t;
        long long int series = n/m;
        if(series*m!=n) series++;
        series--;
        long long int tiempoDescanso = series*(series+1)/2*i+series*d-series*i;
        printf("%lld\n",tiempoLargos+tiempoDescanso);
    }
    return 0;
}
