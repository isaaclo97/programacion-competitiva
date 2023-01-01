#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int bloques,total=1,n=1;
    vector<long long int> V;
    V.push_back(0);
    while(total<=2000000000){
        V.push_back(total);
        total+=(n+2)*(n+2);
        n+=2;
    }
    V.push_back(total);
    while(scanf("%lld",&bloques)==1 && bloques!=0){
        for(int i=0; i<V.size();i++)
            if(V[i]>=bloques) {
                printf("%d\n", i);
                break;
            }
    }
    return 0;
}