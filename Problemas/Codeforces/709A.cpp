/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-11-03 23:23:59
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int main() {
    int n,b,d,acu=0,res=0; scanf("%d %d %d",&n,&b,&d);
    for(int i=0; i<n;i++){
        int aux; scanf("%d",&aux);
        if(aux>b) continue;
        acu+=aux;
        if(acu>d) { res++; acu=0; }
    }
    printf("%d\n",res);
    return 0;
}
