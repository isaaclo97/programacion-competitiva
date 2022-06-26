#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main() {
    map<int, set<long long int> > M;
    int n; cin>>n;
    while(n--) {
        long long int ret; scanf("%lld", &ret);
        long long int now = ret, cnt = 0;
        while(now % 3 == 0) { now /= 3; cnt++; }
        M[cnt].emplace(ret);
    }
    for(auto it = M.rbegin(); it != M.rend(); ++it) {
        for(auto x : it->second) printf("%lld ", x);
    }
    return 0;
}
