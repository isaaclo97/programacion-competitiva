
#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k, int m){
    int i;
    for (m = n - m, i = m + 1; i <= n; i++){
        m += k;
        if (m >= i) m %= i;
    }
    return m + 1;
}

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int n, k; scanf("%d %d",&n,&k);
        printf("%d\n",josephus(n,k,n));
    }
    return 0;
}
