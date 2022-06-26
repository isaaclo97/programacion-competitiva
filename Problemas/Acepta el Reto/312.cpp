
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (b) { ll d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}

int main() {
    ll a, x, y;
    while (scanf("%lld",&a) && a != 0) {
        ll sum = a, gcd = a;
        while (scanf("%lld",&a) && a != 0) {
            sum += a;
            gcd = euclid(gcd, a, x, y);
        }
        printf("%lld\n",sum / gcd);
    }
    return 0;
}
