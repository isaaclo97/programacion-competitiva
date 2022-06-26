#include <bits/stdc++.h>
using namespace std;

int solve() {
    char c;
    cin >> c;
    int ic = c - '0';
    if (ic < 0 || ic > 9) {
        if(c=='+') ic = solve() + solve();
        else if(c=='-') ic = solve() - solve();
        else if(c=='*') ic = solve() * solve();
        else ic = solve() / solve();
        }
    return ic;
}

int main() {

    int cases;
    cin >> cases;
    for (int i{0}; i < cases; i++) {
        cout << solve() <<'\n';
    }
}
