/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-10-27 19:04:37
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int main() {
    set<int> S;
    int a,b,c,d; scanf("%d %d %d %d",&a,&b,&c,&d); S.insert(a); S.insert(b); S.insert(c); S.insert(d);
    printf("%d",4-S.size());
    return 0;
}
