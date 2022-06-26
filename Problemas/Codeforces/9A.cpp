/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-10-27 19:17:31
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int gcd(int a, int b) {
while (b > 0) {
int temp = b; b = a % b; a = temp; }
return a; }
int lcm(int a, int b){ return a*(b/gcd(a,b));}

int main() {
    int n,m; scanf("%d %d",&n,&m); n=max(n,m);
    int aux = gcd(7-n,6);
    printf("%d/%d",(7-n)/aux,6/aux);
    return 0;
}
