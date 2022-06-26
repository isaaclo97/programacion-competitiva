#include<bits/stdc++.h>
using namespace std;
int main() {
    int ans = 0;
    string in;
    cin>>in;
    for (unsigned int i = 0; i < in.length(); i++) {
        int l = 0, r = 0;
        for (unsigned int j = i; j < in.length(); j++) {
            if (in[j] == '(') l++, r++;
            if (in[j] == ')') l--, r--;
            if (in[j] == '?') l--, r++;
            if (r < 0) break;
            if (l < 0) l += 2;
            if (l <= 0 && r >= 0 && r % 2 == 0) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
