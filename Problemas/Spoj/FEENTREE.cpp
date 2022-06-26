#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
long long bit[MAX];

long long query(int indx){
    long long sum = 0;
    while (indx) {
        sum += bit[indx];
        indx -= (indx & -indx);
    }
    return sum;
}

void update(int indx, int x){
   while (indx < MAX) {
        bit[indx] += x;
        indx += (indx & -indx);
    }
}

int main() {
    int n;
    while(scanf("%d",&n)==1)
    {
        long long a[n+1];
        for (int i = 1; i <= n; i++) { //EMPEZAR EN 1
            scanf("%lld",&a[i]);
            update(i, a[i]);
        }
        int q; scanf("%d",&q);
        while (q--) {
            string choice;
            cin >> choice;
            if (choice == "q") {
                int l, r;
                scanf("%d%d",&l,&r);
                printf("%lld\n",query(r) - query(l-1));
            } else {
                int p; long long int x;
                scanf("%d%lld",&p,&x);
                update(p, x);
            }
        }
    }
}
