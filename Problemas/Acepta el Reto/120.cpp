#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    while (scanf("%d%d",&n,&k)==2 && (n != 0 || k != 0))
        cout << (n*n*n + n) / 2 + (k-1) * n << '\n';

    return 0;
}
