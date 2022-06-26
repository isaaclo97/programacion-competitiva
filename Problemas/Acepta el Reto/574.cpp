
#include <bits/stdc++.h>
using namespace std;

long long int tam(long long int n){
    if (n == 0) return 0;
    return 2 * tam(n - 1) + n + 2;
}

string solve(long long int n, long long int k){
    if(n>1){
        if (k <= tam(n - 1))
            return solve(n - 1, k);
        if (k > tam(n - 1) + 2 + n)
            return solve(n - 1, k - tam(n - 1) - n - 2);
    }
    if (k == tam(n - 1) + 1) return "B";
    else if (k == tam(n - 1) + n + 2) return "H";
    return "U";
}

int main(){
    long long int n,k;
    while(scanf("%lld %lld",&n,&k)==2){
        cout<<solve(n,k)<<endl;
    }
    return 0;
}
