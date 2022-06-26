#include <iostream>
using namespace std;
int main() {
    long long num, den;
    while (cin >> num >> den && num >= den) {
        long long ans = 1;
        for (long long i = den+1; i <= num; i++)
            ans *= i;

        cout << ans << endl;
    }

    return 0;
}
