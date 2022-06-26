#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    long long int n;
    scanf( "%d", &t );
    while (t--) {
        scanf( "%lld", &n );
        if (n%2==0 ) {
            printf("%lld\n", n/2 );
        }
        else {
            printf( "%lld\n", n / 2 + 1 );
        }
    }
    return 0;
} 
