#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main() {
    
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b, mon; cin>>a>>b>>mon;
        double ans=mon,field = a + b;
        if (a <= field / 3) ans = 0;
        else if (a < 2 * field / 3) ans = ((double) mon * ((double) a - field / 3.0)) / (field / 3.0);
        printf("%.0lf\n", ans);
    }
    return 0;
}

