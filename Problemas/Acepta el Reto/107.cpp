#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

bitset<100005> bs;
vector<int> primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (unsigned int i = 2; i < bs.size(); i++)
        if (bs[i]) {
            for (long long j = (long long) i * i; j < bs.size(); j += i) bs[j] = 0;
            primes.push_back(i);
        }
}

int main()
{
    double delta[6] = {1, .1, .01, .001, .0001, .00001};
    sieve();
    int n,m;
    while(scanf("%d%d",&n,&m)==2 && (n!=0 || m!=0))
    {
        if (m == 1)  cout << "Menor\n";
        else {
            int pi = distance(primes.begin(), upper_bound(primes.begin(), primes.end(), n));
            double error = abs((double) pi / n - (double) 1 / log(n));
            if (error < delta[m]) cout << "Menor\n";
            else if (error == delta[m]) cout << "Igual\n";
            else cout << "Mayor\n";
        }
    }
    return 0;
}
