#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int l;
void solve(int nD, long long n) {
    if (nD <= l && n%nD == 0) {
        printf("%lld\n",n);
        for (int i = 0; i < 10; i++) solve(nD + 1, n * 10 + i);
    }
}

int main()
{
    long long int n;
    while(scanf("%lld%d",&n,&l)==2)
    {
        solve(to_string(n).length(),n);
        printf("---\n");
    }
    return 0;
}
