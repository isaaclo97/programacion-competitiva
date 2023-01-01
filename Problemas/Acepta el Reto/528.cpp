#include<bits/stdc++.h>
using namespace std;

long long int binomialCoeff(long long int n, long long int k){
    long long int C[k + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1; // nC0 is 1
    for (long long int i = 1; i <= n; i++){
        for (long long int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[k];
}

int main(){
    long long int N, r = 2;
    while(scanf("%lld",&N)==1 && N!=0) {
        double num;
        long long int n = 0;
        long long int ceroOrOne = 0;
        for(int i=0;i<N;i++){
            scanf("%lf",&num);
            if(floor(num) == ceil(num) && (num==0 || num==1)) ceroOrOne++;
            else if(num>=1.0000) n++; //si el numero es >=1.0 siempre dará superior o igual con enteros y ellos mismos
        }
        printf("%lld\n",binomialCoeff(n, r) + (N-ceroOrOne)*ceroOrOne + binomialCoeff(ceroOrOne, r) + binomialCoeff(N-n-ceroOrOne, r));
    }
    return 0;
}