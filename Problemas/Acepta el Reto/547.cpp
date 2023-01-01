#include <bits/stdc++.h>
using namespace std;

long long int n,start,endV;

long long int solve(long long int bits, long long int totalBinary, long long int valor){
    if(bits==0) return valor>=start && valor<=endV;
    long long int acu = 0;
    for(int i=totalBinary;i>=0;--i){
        long long int value = valor|(1ll<<i);
        if(value>endV) continue;
        acu += solve(bits-1,i-1,value);
    }
    return acu+(valor>=start && valor<=endV);
}

int main(){
    while(scanf("%lld %lld %lld",&n,&start,&endV)==3 && (n!=0 || start!=0 || endV!=0)){
        int numberOfBits = log2(endV);
        long long int res = solve(n,numberOfBits,0);
        printf("%lld\n",res);
    }
    return 0;
}