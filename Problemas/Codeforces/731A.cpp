/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-10-27 13:49:14
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int main() {
    string a; cin>>a;
    int res = 0;
    char c = 'a';
    for(unsigned int i=0; i<a.length();i++){
        res+=min(abs(c-a[i]),26-abs(c-a[i]));
        c=a[i];
    }
    printf("%d",res);
    return 0;
}
