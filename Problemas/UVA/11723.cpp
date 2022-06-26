#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main() {
    int n, m, ca = 1;
    while(scanf("%d %d", &n, &m) == 2 && (n!=0 || m!=0)) {
        int ans = (n-1)/m;
        if(ans > 26) printf("Case %d: impossible\n", ca++);
        else printf("Case %d: %d\n",ca++, ans);
    }
    return 0;
}

