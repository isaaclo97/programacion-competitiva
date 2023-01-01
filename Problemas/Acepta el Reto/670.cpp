#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--) {
        int N, k; scanf("%d %d",&N,&k);
        long long int arr[N];
        for(int i=0; i<N;i++) scanf("%lld",&arr[i]);
        long long int ans[N];
        ans[N - 1] = arr[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            if (i + k + 1 >= N)
                ans[i] = max(arr[i], ans[i + 1]);
            else
                ans[i] = max(arr[i] + ans[i + k + 1], ans[i + 1]);
        }
        printf("%lld\n",ans[0]);
    }
    return 0;
}