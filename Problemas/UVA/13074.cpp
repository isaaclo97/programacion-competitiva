#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b) {
while (b > 0) {
long long int temp = b; b = a % b; a = temp; }
return a; }
long long int lcm(long long int a, long long int b){ return a*(b/gcd(a,b));}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n!=0) {
        int arr[105], used[105];
        memset(arr,0,sizeof(arr)); memset(used,0,sizeof(used));
        for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
        long long ret = 1;
        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;
            int j = i, cicle = 0;
            while (!used[j]) //Cycle count
            {
                used[j] = 1;
                cicle++;
                j = arr[j];
            }
            ret = lcm(ret, cicle);  //LCM of cycles
        }
        printf("%lld\n", ret);
    }
    return 0;
}
