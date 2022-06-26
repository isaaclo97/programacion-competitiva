
#include <bits/stdc++.h>
using namespace std;
 
string bin(long long int n){
    long long int  i;
    string res = "0";
    for (i = 1 << 30; i > 0; i = i / 2){
        if((n & i) != 0) res+="1";
        else res+="0";
    }
    return res;
}
 
int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int n; scanf("%d",&n);
        int pares = 0;
        int impares = 0;
        int minValue = 0x3f3f3f3f;
        for(int i=0; i<n;i++){
            int num; scanf("%d",&num);
            if(num%2==0) pares++;
            else impares++;
            if(num%2==0) {
                string res = bin(num);
                int sum = 0;
                for (int j = res.length() - 1; j >= 0; j--) {
                    if (res[j] == '1') break;
                    sum++;
                }
                minValue=min(minValue,sum);
            }
        }
        int res = 0;
        if(pares>0) {
            if(impares==0) {
                res += minValue;
                res+= pares-1;
            }
            else
                res+=pares;
        }
        printf("%d\n",res);
    }
    return 0;
}
