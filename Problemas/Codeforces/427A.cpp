/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-10-27 13:37:41
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int main() {
    int n; scanf("%d",&n);
    int res=0,acu=0,aux;
    for(int i=0; i<n;i++){
        scanf("%d",&aux);
        acu+=aux;
        if(acu<0) { acu=0; res++; }
    }
    printf("%d",res);
    return 0;
}
