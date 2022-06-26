#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        cout << n*(n+1)*(n+2)/6 << endl;
    }
    return 0;
}
