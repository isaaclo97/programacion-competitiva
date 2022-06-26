#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back(i);
        }
}

int main() {
  sieve(20000);
  int n; scanf("%d",&n); cin.ignore();
  while(n--)
  {
    string line;
    getline(cin,line);
    int res = 0;
    for(unsigned int i=0; i<line.length();i++) res+=line[i];
    vector<int>::iterator low1 = lower_bound(primes.begin(), primes.end(), res);
    int num = low1 - primes.begin();
    printf("%d\n",primes[num-1]);
  }
}
