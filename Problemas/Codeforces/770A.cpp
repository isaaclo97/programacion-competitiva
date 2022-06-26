/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-11-04 17:03:47
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int main() {
    int n,k; scanf("%d %d",&n,&k);
    int flag = 0; k--;
    for(int i=0; i<n;i++){
        if(k>=0) printf("%c",'a'+k);
        else {
            if(flag==0) printf("%c",'b');
            else printf("%c",'a');
            flag++; flag%=2;
        }
        k--;
    }
    return 0;
}
