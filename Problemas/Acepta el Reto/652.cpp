#include <bits/stdc++.h>
using namespace std;

// Function to find Nth number in base 9
long long int findNthNumber(long long int N){
    long long int result = 0;
    long long int p = 1;
    while (N > 0) {
        result += (p * (N % 9));
        N = N / 9;
        p = p * 10;
    }
    return result;
}

long long int val(char c) {
    if (c >= '0' && c <= '9') return (long long int)c - '0';
    else return (long long int)c - 'A' + 10;
}

long long int convert_decimal(string str, int base) {
    long long int len = str.length();
    long long int power = 1;
    long long int num = 0;
    for (int i = len - 1; i >= 0; i--) {
        num += val(str[i]) * power;
        power = power * base;
    }
    return num;
}


int main(){
    long long int n,n1;
    int D = 5;
    while(scanf("%lld %lld",&n,&n1)==2) {
        string num = to_string(n);
        string num1 = to_string(n1);
        for(int i=0; i<num.length();i++){
            if(num[i]>=D+'0') num[i]--;
        }
        for(int i=0; i<num1.length();i++){
            if(num1[i]>=D+'0') num1[i]--;
        }
        long long int res = convert_decimal(num,9);
        long long int res1 = convert_decimal(num1,9);

        long long int mult = res*res1;
        //cout<<res<<" "<<res1<<" "<<mult<<endl;
        long long int sol = findNthNumber(mult);
        string numSol = to_string(sol);
        for(int i=0; i<numSol.length();i++){
            if(numSol[i]>=D+'0') numSol[i]++;
        }
        cout<<numSol<<endl;
    }
    return 0;
}