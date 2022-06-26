#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int pow(int x, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int x1 = pow(x, n/2);
        return (x1 * x1) % 31543;
    } else {
        int x1 = pow(x, (n-1)/2);
        return (((x1 * x1) % 31543) * (x % 31543)) % 31543;
    }
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)==2 && (a!=0||b!=0))
    {
            cout<<pow(a,b)<<endl;
    }
    return 0;
}
