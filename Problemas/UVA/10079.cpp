#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    long long int n;
    while(scanf("%lld",&n) && n>-1)
        cout<<(n*(n+1))/2+1<<'\n';
    return 0;
}

