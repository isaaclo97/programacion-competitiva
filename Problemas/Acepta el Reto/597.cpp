
#include <bits/stdc++.h>
using namespace std;

int main() {
    int cases; scanf("%d",&cases);
    while(cases--){
        int n; scanf("%d",&n);
        int numeros[n];
        for (int i = 0; i < n; ++i) scanf("%d",&numeros[i]);
        int res = 0;
        int minID = 0x3f3f3f3f;
        for (int i = n - 1; i >= 0; i--) {
            if (numeros[i] > minID) res++;
            minID = min(minID, numeros[i]);
        }
        printf("%d\n",res);
    }
    return 0;
}
