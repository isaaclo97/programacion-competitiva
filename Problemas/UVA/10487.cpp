#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int A[1000];
    long long int ans, cur, mid;

    int   N, q, cs=1;
    while(scanf("%d", &N) == 1 && N){
        printf("Case %d:\n", cs++);

        for( int i = 0; i < N; i++ )
            cin>>A[i];

        cin>>q;

        while(q--){
        cin>>mid;
        ans = A[0] + A[1];
        for(int i = 0; i < N; i++ ){
            for( int j = i+1; j < N; j++ ){
                cur = A[i] + A[j];
                if( abs(ans - mid) > abs(cur - mid)) ans = cur;
            }
        }
        printf("Closest sum to %lld is %lld.\n", mid, ans);
        }
    }
    return 0;
}
