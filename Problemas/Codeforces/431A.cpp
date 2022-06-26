/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-10-27 13:42:22
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int main() {
    int a[4],res=0;
    scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]);
    string b; cin>>b;
    for(unsigned int i=0; i<b.length();i++){
        res+=a[b[i]-'0'-1];
    }
    printf("%d",res);

    return 0;
}
