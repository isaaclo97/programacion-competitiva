#include <bits/stdc++.h>
using namespace std;

inline void fastInput(long long int &n){
    char ch;
    long long int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {

    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}

long long int trailingZeroes(long long int n){
    long long int cnt = 0;
    while (n > 0) {
        n /= 5;
        cnt += n;
    }
    return cnt;
}

void binarySearch(long long int n, long long int d){
    long long int low = 1;
    long long int high = 1e14+1;
    while (low < high) {
        long long int mid = (low + high) / 2;
        long long int count = trailingZeroes(mid);
        if (count < n)
            low = mid + 1;
        else
            high = mid;
    }
    vector<long long int> result;
    while (trailingZeroes(low) == n) {
        result.push_back(low);
        low++;
    }
    bool flag = true;
    for (long long int i = 0; i < result.size() && flag; i++) {
        if(result[i]%d==0){
            printf("%lld\n",result[i]);
            flag = false;
        }
    }
    if(flag) printf("NINGUNO\n");
}

int main() {
    long long int d, n;
    fastInput(d);
    fastInput(n);
    while ((n!=0 || d!=0)) {
        binarySearch(n,d);
        fastInput(d);
        fastInput(n);
    }
    return 0;
}