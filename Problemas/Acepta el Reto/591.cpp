
#include <bits/stdc++.h>
using namespace std;

//No es necesario guardar la matriz dará RTE

int main(){
    int n;
    while(scanf("%d",&n) == 1){
        map<long long int,long long int> M;
        map<long long int, long long int> realValue;
        for(int i=0; i<n/2;i++){
            realValue[i]=i;
        }
        for(int i=n-1; i>n/2;i--){
            realValue[i]=n-i-1;
        }
        if(n%2!=0) realValue[n/2]=n/2;
        else realValue[n/2]=n/2-1;
        long long int number;
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++) {
                scanf("%lld",&number);
                int maxValue = min(realValue[i],realValue[j]);
                M[maxValue]+=number;
            }
        }
        int middle = n/2;
        if(n%2==0) middle--;
        for(int i=middle; i>=0;i--){
            if(middle==i) printf("%lld",M[i]);
            else printf(" %lld",M[i]);
        }
        printf("\n");
    }
    return 0;
}
