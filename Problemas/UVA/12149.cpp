#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main() {
    int n;
    while(scanf("%d",&n)==1 && n!=0) {
        printf("%d\n",n*(n+1)*(2*n+1)/6);
    }
    return 0;
}

