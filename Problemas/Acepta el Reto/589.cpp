
#include <bits/stdc++.h>
using namespace std;

//No es necesaria una estructura de datos para resolver
//En caso de almacenar todas las copas, dará MLE

int main(){
    int n;
    while(scanf("%d",&n) == 1 && n!=0){
        long long int curMaxValue = 0,number,res=0;
        for(int i=0; i<n;i++) {
            scanf("%lld",&number);
            if(number>curMaxValue) {
                res+=(number-curMaxValue)*i;
                curMaxValue=number;
            }
            else{
                res+=curMaxValue-number;
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
