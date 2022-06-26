#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int solve(int x, int n) {
    int aux, ret; aux=ret= 1;
    for(int i=0; i< n;i++) {
        aux *= x;
        aux %= 1000007;
        ret += aux;
        ret %= 1000007;
    }
    return ret;
}

int main()
{
    int n, x;
        while(scanf("%d%d",&x, &n)==2)
            cout << solve(x, n) << '\n';
    return 0;
}
