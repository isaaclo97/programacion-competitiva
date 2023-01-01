#include <bits/stdc++.h>
using namespace std;

bitset<100005> bs;
vector<int> primes;

void sieve() {
    bs.set();
    primes.push_back(2);
    bs[0] = bs[1] = 0;
    for (unsigned int i = 2; i < bs.size(); i++)
        if (bs[i]) {
            for (long long j = (long long) i * i; j < bs.size(); j += i) bs[j] = 0;
            primes.push_back(i);
        }
}

int main(){
    long long int n;
    sieve();
    //https://iq.opengenus.org/number-of-x-y-solutions-for-1-x-1-y-1-n/
    //https://www.toppr.com/ask/question/let-sn-denote-the-number-of-ordered-pairs-x-y-satisfying-dfrac1x-dfrac1y/
    while(scanf("%lld",&n)==1){
        long long int total = 1;
        for (int i = 0; i < primes.size(); i++){
            long long int count = 0;
            if (primes[i] * primes[i] > n) break;
            if (n % primes[i] == 0) {
                while (n % primes[i] == 0) {
                    n = n / primes[i];
                    count++;
                }
                total = total * (2*count + 1);
            }
        }
        if (n != 1) total *= 3;
       printf("%lld\n",(total+1)/2);
    }
    return 0;
}
