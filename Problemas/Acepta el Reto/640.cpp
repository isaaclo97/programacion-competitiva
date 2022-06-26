
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

int main(){
    long long int number,D;
    while(scanf("%lld %lld",&number,&D)==2 && (number!=0 ||D!=0)) {
        long long int res = findNthNumber(number);
        string num = to_string(res);
        for(int i=0; i<num.length();i++){
            if(num[i]>=D+'0') num[i]++;
            cout<<num[i];
        }
        cout<<endl;
    }
    return 0;
}
