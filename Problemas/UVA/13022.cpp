#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<unsigned long long> ret;
    unsigned long long a = 0;
    for (int N = 1; N <= 64; N++) { //Number of ones
        a = a<<1 | 1;
        for (int M = 1; M <= 64; M++) {
            unsigned long long v = a;
            for (int i = N; i <= 64; i += N + M) { //Number of zeros and ones
                ret.push_back(v);
                v = v << M;         //Add 0
                v = v << N | a;     //Add 1
            }
            v = a << M; //zero
            for (int i = N+M; i <= 64; i += N + M) { //Generate ones and zeros
                ret.push_back(v);
                v = v << N | a;     //Add 1
                v = v << M;         //Add 0
            }
        }
    }
    sort(ret.begin(), ret.end()); //Order
    ret.resize(unique(ret.begin(), ret.end()) - ret.begin()); //Delete same numbers
    unsigned long long L, R;
    while (scanf("%llu %llu", &L, &R) == 2) {
        int sum = 0;
        for (unsigned int i=0; i<ret.size(); i++) {
            if(ret[i]<=R&&ret[i]>=L)
            sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
