/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-11-03 23:30:04
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int main() {
    //N total cakes, t time per round, k max round, d time to create second oven
    int n,t,k,d; scanf("%d %d %d %d",&n,&t,&k,&d);
    int aux=d;
    while(aux>=0){
        n-=k;
        aux-=t;
    }
    if((n>0 && aux<0)||(aux==0 && n>=aux+1)) printf("YES\n");
    else printf("NO\n");
    return 0;
}
