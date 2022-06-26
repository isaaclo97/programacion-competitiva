#include<bits/stdc++.h>
using namespace std;
int res(int n) {
    if(n < 10)	return n;
    int sum = 0;
    while(n) {
        sum += n%10;
        n /= 10;
    }
    return res(sum);
}
int main() {
    int cases;
    while(scanf("%d", &cases) == 1 && cases!=0)
        printf("%d\n", res(cases));
    return 0;
}
