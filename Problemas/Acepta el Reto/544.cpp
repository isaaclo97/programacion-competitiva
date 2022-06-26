#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int N,P;
    while(scanf("%lld %lld",&N,&P)==2){
        long long int res = 0,maxVal=0;
        map<long long int,long long int> M;
        for(int i=0; i<N;i++){
            long long int aux; scanf("%lld",&aux);
            if(aux<=P/2) { M[P/2]++; maxVal=max(aux,maxVal);}
            else if(maxVal+aux<=P) M[aux]++;
        }
        if(maxVal==0 && M.size()>0) { printf("1\n"); continue; }
        else if(maxVal==0){ printf("0\n"); continue; }
        for(auto m:M){
            if(m.first+maxVal<=P && (m.first+m.first)<=P) res+=m.second;
            else if(m.first+maxVal<=P && (m.first+m.first)>P) { maxVal=m.first; res++; }
        }
        printf("%lld\n",res);
    }
    return 0;
}

/*
5 5
1 1 2 4 4
3 5
4 4 4
1 9
10
1 8
5
3 5
1 4 4
*/
