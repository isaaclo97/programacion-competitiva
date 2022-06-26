
#include <bits/stdc++.h>
using namespace std;

long long int solve(long long int n){
    long long int count = 0;
    for (long long int i = 1; i <= n; i++){
        switch (i % 4){
            // for i of form 2k
            case 0:
            case 2:
                count += 20 * pow( 30, ( i / 2 - 1));
                break;
                // for i of form 4k + 3
            case 3:
                count += 100 * pow ( 500, i / 4 );
                break;
                // for i of form 4k + 1 no solution
            case 1:
                break;
        }
    }
    return count;
}
int main(){
    long long int n;
    while(scanf("%lld",&n)==1 && n!=0) {
        printf("%lld\n",solve(n)-solve(n-1));
    }
    return 0;
}
