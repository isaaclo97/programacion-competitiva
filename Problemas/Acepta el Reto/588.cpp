
#include <bits/stdc++.h>
using namespace std;

//2^63 requiere de uso de long long int, si no dará WA

int main(){
    long long int n;
    while(scanf("%lld",&n) == 1 && n!=0){
        string number = "";
        while (n > 0) {
            number += (char)('0'+(n % 2));
            n = n / 2;
        }
        string finalNumber = "";
        int m,x;
        for (m = 0; m < number.length(); m++)
            if(number[m]!='0') break;
        for (x =  number.length()-1; x>=0; x--)
            if(number[x]!='0') break;
        for(int i=m; i<=x;i++)
            finalNumber+=number[i];

        bool flag = true;
        for (unsigned int i = 0; i < finalNumber.length()/2 && flag; i++)
            if(finalNumber[i]!=finalNumber[finalNumber.length()-1-i]) flag=false;
        if(flag) printf("SI\n");
        else printf("NO\n");
    }
    return 0;
}
